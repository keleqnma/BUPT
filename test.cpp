#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include<iostream>
#include<string>
#include<regex>
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
        char sex;
        string name;
        string email;
        string location;
        string id;
        void init(string x,string y)//初始化函数
        {
            id=x;
            password=y;
        }
        void show()
        {
            cout<<"您的电话号码是："<<phone<<endl;
            cout<<"您的email是："<<email<<endl;
            cout<<"您的所在地域是："<<location<<endl;
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
        void changelocation(string new_location)//地域修改函数
        {
            location=new_location;
        }
        void changemail(string new_email)//email修改函数
        {
            email=new_email;
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

void outputline()
{
    cout<<"---------------------------------------------"<<endl;
}

void Guest::modify()
{

    while(1)
    {
        int operation,flag=0;
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
                    if(Guest::checkphone(phone))
                    {
                        
                        changephone(phone);
                        cout<<"[*]电话号码修改成功，现在您的电话号码是："<<phone<<endl;
                        getchar();getchar();
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
                            getchar();getchar();
                            break;
                        }
                    }
                    else 
                        cout<<"密码不正确请重新输入!"<<endl;
                }
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
                        cout<<"[*]email修改成功，现在您的电话号码是："<<email<<endl;
                        getchar();getchar();
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
            case 5:break;
            default:{flag=1;break;}
        }
        if(flag=1)
            break;
    }  
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
    cout<<"                 欢迎你！顾客"<<guest[login_num].id<<endl;
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

void admin_index()
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
