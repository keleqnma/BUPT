#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<string>
#include<fstream>

#define START 6
#define END 22

using namespace std;


/*-----------------------------------------------------【类定义】------------------------------------------------------------------------------*/
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
        void modify();
        void gym_order();
        void gym_query();
        void rm_order();
        void query_order();
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
/*-----------------------------------------------------【全局变量】------------------------------------------------------------------------------*/

int guests=3,admins=3,mode=0,login_num;
Admin *admin = new Admin[10];
Guest *guest = new Guest[10];
Order *order = new Order[10];
Gym *gym = new Gym[10];

/*-----------------------------------------------------【成员函数】------------------------------------------------------------------------------*/
void Guest::modify()
{

}

void Guest::gym_query()
{

}

void Guest::gym_order()
{

}

void Guest::rm_order()
{

}

void Guest::query_order()
{

}

///----------------成员函数分割线----------------------//

void Admin::modify()
{

}

void Admin::order_mng()
{

}

void Admin::gym_mng()
{

}

/*-----------------------------------------------------【函数定义】----------------------------------------------------------------------------*/

void init()
{
    guest[0].init("luty","123456");
    guest[1].init("joyce","123456");
    guest[2].init("kay","123456");
    admin[0].init("admin","123456");
    admin[1].init("root","123456");
    admin[2].init("pi","berrypi");
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
                            login_num=i;
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
                            login_num=i;
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

void main_ui()
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

void guest_ui()
{
    outputline();
    cout<<"                 欢迎你！顾客"<<guest[login_num].name<<endl;
    outputline();
    cout<<"                 1.场地查询"<<endl;
    cout<<"                 2.场地预定"<<endl;
    cout<<"                 3.预定取消"<<endl;
    cout<<"                 4.订单查询"<<endl;
    cout<<"                 5.个人信息管理"<<endl;
    cout<<"                 6.注销"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void admin_ui()
{
    outputline();
    cout<<"                 欢迎你！管理员"<<admin[login_num].name<<endl;
    outputline();
    cout<<"                 1.预定管理"<<endl;
    cout<<"                 2.场地管理"<<endl;
    cout<<"                 3.个人信息管理"<<endl;
    cout<<"                 4.注销"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void main_index()
{
    int operation;
    while(1)
    {
        cin>>operation;
        if(operation==1||operation==2)
        {
            login(operation);
            break;
        }
    else if(operation==3)
        exit(0);
    else
        cout<<"怎么回事小老弟？再给你一次机会！1或者2！"<<endl;
    }
    system("clear");
}

void guest_index()
{
    int operation;
    switch(operation)
    {
        case 1:guest[login_num].gym_query();break;
        case 2:guest[login_num].gym_order();break;
        case 3:guest[login_num].rm_order();break;
        case 4:guest[login_num].query_order();break;
        case 5:guest[login_num].modify();break;
        case 6:return;
        default:break;
    }
}

void guest_index()
{
    int operation;
    switch(operation)
    {
        case 1:admin[login_num].order_mng();break;
        case 2:admin[login_num].gym_mng();break;
        case 3:admin[login_num].modify();break;
        case 4:return;
        default:break;
    }
}

/*------------------------------------------------------------【主函数】------------------------------------------------------------------------*/

int main()
{
   

    //Guest guest[10];
    //guest.login(123.23333);
    //cout<<guest[0].login(123,233)<<endl;
    //cout<<guest[1].login(1234,2333)<<endl;
    //login(guest);
    //da
    
    init();
    main_ui();
    main_index();
    

    if(mode==1)
    {
        guest_ui();


    }
    else if(mode==2)
    {
        admin_ui();

    }
    else
        cout<<"[*]进入系统失败!按任意键退出!"<<endl;

    getchar();
    getchar();
}
