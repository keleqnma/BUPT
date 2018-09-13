#include<iostream>

using namespace std;

/*-----------------------------------------------------【类定义】------------------------------------------------------------------------------*/
class Order     //订单类
{
    public:
        string order_number;
        string order_date;
        string id;
        string date;
        string gym_belong;     //所属场馆
        string sports;          //该订单对应的运动类型
        int start;
        int end;
        string check;
        string belong;      //从属于哪个顾客的订单
        void show()
        {
            cout<<"---------------------"<<endl;
            cout<<"订单编号："<<order_number<<endl;
            cout<<"下单日期："<<order_date<<endl;
            cout<<"预定场地编号："<<id<<endl;
            cout<<"预约日期："<<date<<endl;
            cout<<"开始时间："<<start<<endl;
            cout<<"结束时间："<<end<<endl;
            cout<<"订单所有者："<<belong<<endl;
        }
};

class Gym       //场地类
{
    public:
        int order_sum;
        float rent_sum;

        int time[24];
        float rent;
        string location;
        int age_limit_1;
        int age_limit_2;
        string sport_rec;
        string sport_type;
        string belong;
        string id;
        string situation;
        void init(string x,float irent,string ilocation,int iage_limit_1,int iage_limit_2,string isports_rec,string isports_type,string ibelong)       //初始化函数
        {
            id=x;
            rent=irent;
            location=ilocation;
            age_limit_1=iage_limit_1;
            age_limit_2=iage_limit_2;
            sport_rec=isports_rec;
            sport_type=isports_type;
            belong=ibelong;
            order_sum=0;
            rent_sum=0;
        }
        void show() //信息展示函数
        {
            cout<<"------------------"<<endl;
            cout<<"场地id是："<<id<<endl;
            cout<<"场地租金是："<<rent<<endl;
            cout<<"场地所属地域是："<<location<<endl;
            cout<<"场地年龄限制是："<<age_limit_1<<"-"<<age_limit_2<<endl;
            cout<<"场地推荐运动是："<<sport_rec<<endl;
            cout<<"场地运动类型是："<<sport_type<<endl;
            cout<<"所属场馆是："<<belong<<endl;
        }
};

class Guest     //顾客类
{
   public:
        int cancel;//记录爽约次数
        int chance;//记录预约上限

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
            cancel=0;
            chance=3;
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
        
        void modify();
        void gym_order();
        void gym_query();
        void rm_order();
        void query_order();
    protected:
        string password;

};

class Admin     //管理员类
{
    public:
        long phone;
        string sex;
        string name;
        string gym_name;
        string email;
        string id;
        void modify();
        void order_mng();
        void gym_mng();
        void init(string x,string y,string isex,string iname,string igym_name,string iemail,long iphone) //初始化函数
        {
            id=x;
            password=y;
            sex=isex;
            name=iname;
            gym_name=igym_name;
            email=iemail;
            phone=iphone;
        }
        void show() //信息展示函数
        {
            cout<<"您的管理ID是："<<id<<endl;
            cout<<"您的密码是："<<password<<endl;
            cout<<"您的电话号码是："<<phone<<endl;
            cout<<"您的email是："<<email<<endl;
            cout<<"您的姓名是："<<name<<endl;
            cout<<"您的性别是："<<sex<<endl;
            cout<<"您所管辖的场馆名是：："<<gym_name<<endl;
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


/*---------------------------------------------------【UI规范】---------------------------------------------*/

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
    system("clear"); 
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
    system("clear"); 
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
    system("clear"); 
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

void gym_query_ui()
{
    system("clear");
    outputline();
    cout<<"                 场地查询功能模块"<<endl;
    outputline();
    cout<<"                 1.按场地名称查询"<<endl;
    cout<<"                 2.按场馆名称查询"<<endl;
    cout<<"                 3.按场地类别"<<endl;
    cout<<"                 4.所属区域查询"<<endl;
    cout<<"                 5.按空余场地查询"<<endl;
    cout<<"                 6.按租金排序所有场地"<<endl;
    cout<<"                 7.按预定量排序所有场地"<<endl;
    cout<<"                 8.场地预定"<<endl;
    cout<<"                 9.热门推荐"<<endl;
    cout<<"                 0.退出"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void gym_order_ui()
{
    system("clear");
    outputline();
    cout<<"                 场地预定功能模块"<<endl;
    outputline();
}

void rm_order_ui()
{
    system("clear");
    outputline();
    cout<<"                 预定取消功能模块"<<endl;
    outputline();

}

void order_query_ui()
{
    system("clear");
    outputline();
    cout<<"                 订单查询功能模块"<<endl;
    outputline();
}

void order_mng_ui()
{
    system("clear");
    outputline();
    cout<<"                 管理员订单管理模块"<<endl;
    outputline();
    cout<<"                 1.查看场馆订单"<<endl;
    cout<<"                 2.查看场馆订单并按预定量排序"<<endl;
    cout<<"                 3.统计场馆营业额"<<endl;
    cout<<"                 4.统计不同场地年龄层次分布"<<endl;
    cout<<"                 5.按营业额排序场地"<<endl;
    cout<<"                 6.统计针对男士/女士最受欢迎运动"<<endl;
    cout<<"                 7.按时间段排序所有场地"<<endl;
    cout<<"                 8.退出"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void gym_mng_ui()
{
    system("clear");
    outputline();
    cout<<"                 管理员场地管理模块"<<endl;
    outputline();
    
}