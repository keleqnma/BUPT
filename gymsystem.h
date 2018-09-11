#include<iostream>

using namespace std;

void outputline()
{
    cout<<"---------------------------------------------"<<endl;
}

void regist_ui()
{
    system("clear");
    outputline();
    cout<<"                 请选择你要注册的账户"<<endl;
    outputline();
    cout<<"                 1.注册顾客"<<endl;
    cout<<"                 2.注册管理员"<<endl;
    cout<<"                 3.退出"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void main_ui()
{
    outputline();
    cout<<"                 欢迎！请先登录！                " <<endl;
    outputline();
    cout<<"                 1.顾客登录"<<endl;
    cout<<"                 2.管理员登录"<<endl;
    cout<<"                 3.注册"<<endl;
    cout<<"                 4.退出系统"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void guest_ui()
{
    outputline();
    cout<<"                 欢迎你！顾客!"<<endl;
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
    cout<<"                 欢迎你！管理员!"<<endl;
    outputline();
    cout<<"                 1.预定管理"<<endl;
    cout<<"                 2.场地管理"<<endl;
    cout<<"                 3.个人信息管理"<<endl;
    cout<<"                 4.注销"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}