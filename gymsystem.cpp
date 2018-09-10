#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<string>
#include<fstream>

#define START 6
#define END 22

using namespace std;

class Order
{
    public:
        string order_number;
        string order_date;
        string id;
        string date;
        string start;
        string end;
        string check;
};

class Gym
{
    public:
        long id;
        float rent;
        string location;
        int age_limit;
        string sport_rec;
        string sport_type;
        string venue;
        string situation;
};

class Guest
{
   public:
        int age;
        int phone;
        float count;
        char sex;
        string name;
        string email;
        string location;
        string id;
        void init(string x,string y)
        {
            id=x;
            password=y;
        }
        void show()//调试函数
        {
            cout<<id<<endl;
            cout<<password<<endl;
        }
        int checkpwd(string pwd)//密码检测函数
        {
            if(pwd==password)
                return 1;
            else 
                return 0;
        }
    protected:
        string password;

};

class Admin
{
    public:
        int phone;
        char sex;
        string name;
        string gym_name;
        string email;
        string id;
        void login();
        void modify();
        void order_mng();
        void gym_mng();
        void init(string x,string y)
        {
            id=x;
            password=y;
        }
        int checkpwd(string pwd)//密码检测函数
        {
            if(pwd==password)
                return 1;
            else 
                return 0;
        }

    protected:
        string password;
};

/*-----------------------------------------------------【类定义-全局变量分割线】------------------------------------------------------------------------------*/

int guests=3,admins=3,mode=0;
Admin *admin = new Admin[10];
Guest *guest = new Guest[10];

/*-----------------------------------------------------【全局变量-函数定义分割线】----------------------------------------------------------------------------*/

void init()
{
    guest[0].init("123456","ohmygod");
    guest[1].init("654321","wtfwtf");
    guest[2].init("888888","aswecan");
    admin[0].init("123456","ohmygod");
    admin[1].init("654321","wtfwtf");
    admin[2].init("888888","aswecan");
}

void login(int operation)
{
    int sub_operation;
    string password,id;
    if(operation==1)
    {   
        int login_try=3;
        while(1)
        {
            cout<<"输入您的顾客ID:"<<endl;
            cin>>id;
            for(int i=0;i<guests;i++)
            {
                if(guest[i].id==id)
                {
                    cout<<"已确认顾客ID！请输入密码:"<<endl;//<<"1.重新选择ID"<<"2.输入密码"<<endl;
                    while(login_try!=0)
                    {
                        cin>>password;
                        if(guest[i].checkpwd(password))
                        {
                            cout<<"登录成功！请按回车进入下一步！"<<endl;
                            mode=1;
                            getchar();
                            break;
                        }
                        else 
                            cout<<"登录失败了呀小老弟！你还有"<<login_try--<<"次机会！"<<endl<<"请重新输入你的密码："<<endl;    
                    }
                    if(mode==1||login_try==0)
                        break;
                }
            }
            if(mode==1)
                break;
            else if(login_try==0)
            {
                cout<<"你已经用完了所有机会！告辞！"<<endl;
                getchar();
                break;
            }
            else
                cout<<"没有找到你的ID啊小老弟!重新";
        }         
    }
    else if(operation==2)
    {
       int login_try=3;
        while(1)
        {
            cout<<"输入您的管理员ID:"<<endl;
            cin>>id;
            for(int i=0;i<admins;i++)
            {
                if(admin[i].id==id)
                {
                    cout<<"已确认管理员ID！请输入密码:"<<endl;//<<"1.重新选择ID"<<"2.输入密码"<<endl;
                    while(login_try!=0)
                    {
                        cin>>password;
                        if(admin[i].checkpwd(password))
                        {
                            cout<<"登录成功！请按回车进入下一步！"<<endl;
                            mode=2;
                            getchar();
                            break;
                        }
                        else 
                            cout<<"[*]登录失败了呀小老弟！你还有"<<login_try--<<"次机会！"<<endl<<"请重新输入你的密码："<<endl;    
                    }
                    if(mode==2||login_try==0)
                        break;
                }
            }
            if(mode==2)
                break;
            else if(login_try==0)
            {
                cout<<"你已经用完了所有机会！告辞！"<<endl;
                getchar();
                break;
            }
            else
                cout<<"没有找到你的ID啊小老弟!重新";
        }
    }
    
}

void outputline()
{
    cout<<"---------------------------------------------"<<endl;
}

void index()
{
    outputline();
    cout<<"                 欢迎！请先登录！                " <<endl;
    outputline();
    cout<<"                 1.顾客登录"<<endl;
    cout<<"                 2.管理员登录"<<endl;
    cout<<"                 3.退出系统"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

/*------------------------------------------------------------【函数定义-主函数分割线】------------------------------------------------------------------------*/

int main()
{
    Guest *guest = new Guest[sizeof(Guest)];
    Admin *admin = new Admin[sizeof(Admin)];
    Order *order = new Order[sizeof(Order)];
    Gym *gym = new Gym[sizeof(gym)];
    //Guest guest[10];
    //guest.login(123.23333);
    //cout<<guest[0].login(123,233)<<endl;
    //cout<<guest[1].login(1234,2333)<<endl;
    //login(guest);
    //da
    int operation;
    init();
    index();
    while(1)
    {
        cin>>operation;
        if(operation==1||operation==2)
        {
            login(operation);
            break;
        }
    else if(operation==3)
        return 0;
    else
        cout<<"怎么回事小老弟？再给你一次机会！1或者2！"<<endl;
    }
    system("clear");

    if(mode==1)
        cout<<"进入顾客系统！"<<endl;
    else if(mode==2)
        cout<<"进入管理员系统!"<<endl;
    else
        cout<<"[*]进入系统失败!按任意键退出!"<<endl;
    getchar();
    
    getchar();
}
