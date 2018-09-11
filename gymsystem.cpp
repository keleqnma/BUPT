#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<string>
#include<regex>
#include<fstream>
#include "gymsystem.h"
#define ADMIN 1 //定义初始管理员数目
#define GUEST 1 //定义初始顾客数目

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
        float rent;
        string location;
        int age_limit;
        string sport_rec;
        string sport_type;
        string venue;
        string situation;
        string id;
};

class Guest
{
   public:
        int age;
        long phone;
        float count;
        string sex;
        string name;
        string email;
        string location;
        string id;
        void init(string x,string y,string iname,int iage,string isex,float icount,long iphone,string iemail,string ilocation)//初始化函数
        {
            id=x;
            password=y;
            name=iname;
            age=iage;
            sex=isex;
            count=icount;
            phone=iphone;
            email=iemail;
            location=ilocation;
        }
        void show() //信息展示函数
        {
            cout<<"您的id是："<<id<<endl;
            cout<<"您的密码是："<<password<<endl;
            cout<<"您的姓名是："<<name<<endl;
            cout<<"您的年龄是："<<age<<endl;
            cout<<"您的性别是："<<sex<<endl;
            cout<<"您的账户余额是："<<count<<endl;
            cout<<"您的电话号码是："<<phone<<endl;
            cout<<"您的email是："<<email<<endl;
            cout<<"您的所在地域是："<<location<<endl;
        }
        void changepwd(string new_pwd)//密码修改函数
        {
            password = new_pwd;
        }
        void changephone(long new_phone)//电话号码修改函数
        {
            phone=new_phone;
        }
        void changemail(string new_email)//email修改函数
        {
            email=new_email;
        }
        void changelocation(string new_location)//地域修改函数
        {
            location=new_location;
        }

        int checkpwd(string pwd)//密码验证函数
        {
            if(pwd==password)
                return 1;
            else 
                return 0;
        }
        int checkphone(long phone_num)//电话号码检验函数
        {
            if(phone_num>=10000000000 && phone_num<=99999999999)
                return 1;
            else
                return 0;
        }
        int checkemail(string email_num)//email检验函数
        {
            /*  
                此处是利用regex库正则匹配E-Mail，
                其中用户名可以匹配所有数字和大小写字母，但不能匹配特殊符号，
                邮箱域名可以匹配所有小写字母，
            */
            regex pattern("([0-9A-Za-z]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
            if(regex_match(email_num, pattern))
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
        long phone;
        char sex;
        string name;
        string gym_name;
        string email;
        string id;
        void modify();
        void order_mng();
        void gym_mng();
        void init(string x,string y) //初始化函数
        {
            id=x;
            password=y;
        }
        void show() //信息展示函数
        {
            cout<<"您的电话号码是："<<phone<<endl;
            cout<<"您的email是："<<email<<endl;
            cout<<"您的密码是："<<password<<endl;
        }
        void changepwd(string new_pwd)//密码修改函数
        {
            password = new_pwd;
        }
        void changephone(long new_phone)//电话号码修改函数
        {
            phone=new_phone;
        }
        void changemail(string new_email)//email修改函数
        {
            email=new_email;
        }
        int checkphone(long phone_num)//电话号码检验函数
        {
            if(phone_num>=10000000000 && phone_num<=99999999999)
                return 1;
            else
                return 0;
        }
        int checkemail(string email_num)//email检验函数
        {
            /*  
                此处是利用regex库正则匹配E-Mail，
                其中用户名可以匹配所有数字和大小写字母，但不能匹配特殊符号，
                邮箱域名可以匹配所有小写字母，
            */
            regex pattern("([0-9A-Za-z]+)@([0-9a-z]+\\.[a-z]{2,3}(\\.[a-z]{2})?)");
            if(regex_match(email_num, pattern))
                return 1;
            else
                return 0; 
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

int mode=0,login_num;
int guests=GUEST,admins=ADMIN;
Admin *admin = new Admin[10];
Guest *guest = new Guest[10];
Order *order = new Order[10];
Gym *gym = new Gym[10];

/*-----------------------------------------------------【成员函数】------------------------------------------------------------------------------*/

void Guest::modify()        //顾客个人信息修改功能
{
    int flag=0;
    while(1)
    {
        int operation;
        system("clear");
        outputline();
        cout<<"                 个人信息修改模块"<<endl;
        outputline();
        cout<<"                 1.修改电话"<<endl;
        cout<<"                 2.修改密码"<<endl;
        cout<<"                 3.修改邮箱"<<endl;
        cout<<"                 4.修改地址"<<endl;
        cout<<"                 5.退出"<<endl;
        outputline();
        Guest::show();
        outputline();

        cout<<"在此处继续选择您的操作："<<endl;
        //scanf("%d",&operation);
        cin>>operation;
        switch(operation)
        {
            case 1://修改电话号码
            {
                long phone;
                while(1)
                {
                    cout<<"[*]请输入新的电话号码："<<endl;
                    cin>>phone;
                    if(checkphone(phone))
                    {
                        
                        changephone(phone);
                        cout<<"[*]电话号码修改成功，现在您的电话号码是："<<phone<<endl;
                        getchar();
                        break;
                    }
                    else 
                        cout<<"[*]您输入的电话号码格式有误！修改失败！"<<endl;
                }
                break;
            }
            case 2://修改密码
            {
                string old_pwd,new_pwd;
                char cmd;
                while(1)
                {
                    cout<<"[*1]请先输入旧密码：";
                    cin>>old_pwd;
                    if(checkpwd(old_pwd))
                    {
                        cout<<endl<<"[*2]密码正确！请输入新密码：";
                        cin>>new_pwd;
                        if(new_pwd.length()<6)
                            cout<<"系统检测到您的密码安全性为：低，请问确定使用新密码吗？（y/n）";
                        else if(new_pwd.length() >= 6 && new_pwd.length() <= 8)
                            cout<<"系统检测到您的密码安全性为：中，请问确定使用新密码吗？（y/n）";
                        else if(new_pwd.length() > 8)
                            cout<<"系统检测到您的密码安全性为：高，请问确定使用新密码吗？（y/n）";
                        cin>>cmd;
                        if(cmd=='n' || cmd=='N')
                            break;
                        else 
                        {
                            changepwd(new_pwd);
                            cout<<"密码修改成功，现在您的密码是："<<new_pwd<<endl;
                            getchar();
                            break;
                        }
                    }
                    else 
                        cout<<"密码不正确请重新输入!"<<endl;
                }
                break;
            }
            case 3://修改邮箱
            {
                string email;
                while(1)
                {
                    cout<<"[*]请输入新的email："<<endl;
                    cin>>email;
                    if(Guest::checkemail(email))
                    {
                        
                        changemail(email);
                        cout<<"[*]email修改成功，现在您的email是："<<email<<endl;
                        getchar();
                        break;
                    }
                    else 
                        cout<<"[*]您输入的email格式有误！修改失败！"<<endl;
                }
                break;
            }
            case 4://修改地域
            {
                string location;
                cout<<"[*]请输入新的location："<<endl;
                cin>>location;
                changelocation(location);
                cout<<"[*]location修改成功，现在您的电话号码是："<<location<<endl;
                getchar();
                break;
            }
            case 5:{flag=1;break;}
            default:break;
        }
        if(flag==1)
            break;
    }  
}

void Guest::gym_query()     //顾客场地查询功能
{

}

void Guest::gym_order()     //顾客场地预定功能
{

}

void Guest::rm_order()      //顾客取消订单功能
{

}

void Guest::query_order()   //顾客查询订单功能
{

}

///----------------成员函数分割线----------------------//


void Admin::modify()        //管理员个人信息管理功能
{
    int flag=0;
    while(1)
    {
        int operation;
        system("clear");
        outputline();
        cout<<"                 个人信息修改模块"<<endl;
        outputline();
        cout<<"                 1.修改电话"<<endl;
        cout<<"                 2.修改密码"<<endl;
        cout<<"                 3.修改邮箱"<<endl;
        cout<<"                 4.退出"<<endl;
        outputline();
        Admin::show();
        outputline();

        cout<<"在此处继续选择您的操作："<<endl;
        //scanf("%d",&operation);
        cin>>operation;
        switch(operation)
        {
            case 1://修改电话号码
            {
                long phone;
                while(1)
                {
                    cout<<"[*]请输入新的电话号码："<<endl;
                    cin>>phone;
                    if(Admin::checkphone(phone))
                    {
                        
                        changephone(phone);
                        cout<<"[*]电话号码修改成功，现在您的电话号码是："<<phone<<endl;
                        getchar();
                        break;
                    }
                    else 
                        cout<<"[*]您输入的电话号码格式有误！修改失败！"<<endl;
                }
                break;
            }
            case 2://修改密码
            {
                string old_pwd,new_pwd;
                char cmd;
                while(1)
                {
                    cout<<"[*1]请先输入旧密码：";
                    cin>>old_pwd;
                    if(checkpwd(old_pwd))
                    {
                        cout<<endl<<"[*2]密码正确！请输入新密码：";
                        cin>>new_pwd;
                        if(new_pwd.length()<6)
                            cout<<"系统检测到您的密码安全性为：低，请问确定使用新密码吗？（y/n）";
                        else if(new_pwd.length() >= 6 && new_pwd.length() <= 8)
                            cout<<"系统检测到您的密码安全性为：中，请问确定使用新密码吗？（y/n）";
                        else if(new_pwd.length() > 8)
                            cout<<"系统检测到您的密码安全性为：高，请问确定使用新密码吗？（y/n）";
                        cin>>cmd;
                        if(cmd=='n' || cmd=='N')
                            break;
                        else 
                        {
                            changepwd(new_pwd);
                            cout<<"密码修改成功，现在您的密码是："<<new_pwd<<endl;
                            getchar();
                            break;
                        }
                    }
                    else 
                        cout<<"密码不正确请重新输入!"<<endl;
                }
                break;
            }
            case 3://修改邮箱
            {
                string email;
                while(1)
                {
                    cout<<"[*]请输入新的email："<<endl;
                    cin>>email;
                    if(Admin::checkemail(email))
                    {
                        
                        changemail(email);
                        cout<<"[*]email修改成功，现在您的email是："<<email<<endl;
                        getchar();
                        break;
                    }
                    else 
                        cout<<"[*]您输入的email格式有误！修改失败！"<<endl;
                }
                break;
            }
            case 4:{flag=1;break;}
            default:break;
        }
        if(flag==1)
            break;
    }  
}


void Admin::order_mng()        //管理员订单管理功能
{

}

void Admin::gym_mng()       //管理员场地管理功能
{

}

/*-----------------------------------------------------【函数定义】----------------------------------------------------------------------------*/

void init()         //原始数据初始化函数
{
    guest[0].init("luty","123456","骚气卢",18,"男",2000.00,18810727622,"1774243057@qq.com","北京");
    admin[0].init("admin","123456");
}

void login(int operation)   //登录功能函数
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

void regist_guest()         //顾客注册函数
{
    string pwd;
    system("clear");
    outputline();
    cout<<"                 顾客注册页面"<<endl;
    outputline();

    cout<<"请输入您的ID:"<<endl;
    cin>>guest[guests].id;
    cout<<"请输入您的姓名:"<<endl;
    cin>>guest[guests].name;
    cout<<"请输入您的性别:"<<endl;
    cin>>guest[guests].sex;
    cout<<"请输入您的年龄:"<<endl;
    cin>>guest[guests].age;
    cout<<"请输入您的电话:"<<endl;
    cin>>guest[guests].phone;

    cout<<"请输入您的密码:"<<endl;
    cin>>pwd;
    guest[guests].changepwd(pwd);

    cout<<"请输入您的邮箱:"<<endl;
    cin>>guest[guests].email;
    cout<<"请输入您的账户余额:"<<endl;
    cin>>guest[guests].count;
    cout<<"请输入您的所属地理区域:"<<endl;
    cin>>guest[guests].location;
    
    cout<<"注册成功!您的信息为："<<endl;
    outputline();
    guest[guests].show();
    guests++;

}

void regist_admin()         //管理员注册函数
{

}

void regist_index()         //注册索引
{
    int operation;
    regist_ui();
    cin>>operation;
    switch(operation)
    {
        case 1:{regist_guest();break;}
        case 2: 
        case 3: break;
        default: break;
    }
}

void main_index()           //主索引
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
        regist_index();
    else if (operation==4)
        exit(0);
    else
        cout<<"怎么回事小老弟？再给你一次机会！1或者2！"<<endl;
    }
    system("clear");
}

void guest_index()          //顾客功能索引
{
    int operation;
    cout<<login_num<<endl;
    cin>>operation;
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

void admin_index()          //管理员功能索引
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
    init();
    main_ui();
    main_index();
    
    if(mode==1)
    {
        guest_ui();
        guest_index();

    }
    else if(mode==2)
    {
        admin_ui();
        admin_index();
    }
    else
        cout<<"[*]进入系统失败!按任意键退出!"<<endl;

    getchar();
    getchar();
}
