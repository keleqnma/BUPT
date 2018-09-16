#include<iostream>
#include<iomanip>

using namespace std;

typedef struct times
{
	int Year;
	int Mon;
	int Day;
	int Hour;
	int Min;
	int Second;
}Times;

/*-----------------------------------------------------【类定义】------------------------------------------------------------------------------*/
class Sportstype    //运动类型类
{
    public:
        int sum,male,female;
        string type;
        void init(int smale,int sfemale,int num,string stype)
        {
            male=smale;             //选择某项运动类型男性的数量
            female=sfemale;         //选择某项运动类型女性的数量
            sum=num;                //该运动类型场地数目
            type=stype;             //运动类型
        }
        

};


class Order     //订单类
{
    public:
        string order_number;    //订单编号
        string order_date;      //下单日期（哪天定的）
        string id;              //预定的场地ID
        string date;            //预定的场地日期（哪天去）
        string gym_belong;      //所属场馆
        string sports;          //该订单对应的运动类型
        string belong;          //从属于哪个顾客的订单
        int start;              //开始时间
        int end;                //结束时间
        int age;                //下单顾客的年龄（用于判断）
        int check;              //订单是否爽约（1为暂未爽约，0为爽约）

        void show()
        {
            cout<<"-------------------------"<<endl;
            cout<<"订单编号："<<order_number<<endl;
            cout<<"下单日期："<<order_date<<endl;
            cout<<"预定场地编号："<<id<<endl;
            cout<<"预约日期："<<date<<endl;
            cout<<"开始时间："<<start<<endl;
            cout<<"结束时间："<<end<<endl;
            cout<<"订单所有者："<<belong<<endl;
        }
        void init(string a1,string a2,string a3,string a4,string a5,string a6,string a7,int b1,int b2,int b3,int b4)
        {
            //初始化内存的值
            order_number=a1;
            order_date=a2;
            id=a3;
            date=a4;
            gym_belong=a5;
            sports=a6;
            belong=a7;
            start=b1;
            end=b2;
            age=b3;
            check=b4;
        }
};

class Gym       //场地类
{
    public:
        int order_sum;          //该场地订单总数
        int age_limit_1;        //年龄下限
        int age_limit_2;        //年龄上限
        float rent;             //租金
        float rent_sum;         //营业额
        string location;        //地域
        string sport_rec;       //推荐的运动
        string sport_type;      //运动类型（均已“类型”结尾）
        string belong;          //所属的场馆
        string id;              //场地编号
        

        void init(string x,string ilocation,string isports_rec,string isports_type,string ibelong,int iage_limit_1,int iage_limit_2,int iorder_sum,float irent,float irent_sum)       //初始化函数
        {
            id=x;
            rent=irent;
            location=ilocation;
            age_limit_1=iage_limit_1;
            age_limit_2=iage_limit_2;
            sport_rec=isports_rec;
            sport_type=isports_type;
            belong=ibelong;
            order_sum=iorder_sum;
            rent_sum=irent_sum;
        }


        void show() //信息展示函数
        {
            cout<<"----------------------"<<endl;
            cout<<"场地id是："<<id<<endl;
            cout<<"场地租金是："<<setiosflags(ios::fixed)<<setprecision(2)<<rent<<endl;
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
        int cancel;         //记录爽约次数
        int chance;         //记录预约上限

        int age;            //年龄
        string phone;       //电话号码
        float count;        //账户余额
        string sex;         //性别
        string name;        //姓名
        string email;       //电子邮箱
        string location;    //地域
        string id;          //账户ID
        void init(string x,string y,string iname,string isex,string iemail,string ilocation,int iage,float icount,string iphone,int icancel)//初始化函数
        {
            id=x;
            password=y;
            name=iname;
            age=iage;
            sex=isex;
            count=icount;

            email=iemail;
            location=ilocation;
            phone=iphone;
            cancel=icancel;
        }
        void show() //信息展示函数
        {
            cout<<"您的id是："<<id<<endl;
            cout<<"您的密码是："<<password<<endl;
            cout<<"您的姓名是："<<name<<endl;
            cout<<"您的年龄是："<<age<<endl;
            cout<<"您的性别是："<<sex<<endl;
            cout<<"您的账户余额是："<<setiosflags(ios::fixed)<<setprecision(2)<<count<<endl;
            cout<<"您的电话号码是："<<phone<<endl;
            cout<<"您的email是："<<email<<endl;
            cout<<"您的所在地域是："<<location<<endl;
        }
        void changepwd(string new_pwd)          //密码修改函数
        {
            password = new_pwd;
        }
        void changephone(string new_phone)      //电话号码修改函数
        {
            phone=new_phone;
        }
        void changemail(string new_email)       //email修改函数
        {
            email=new_email;
        }
        void changelocation(string new_location)//地域修改函数
        {
            location=new_location;
        }

        int checkpwd(string pwd)                //密码验证函数
        {
            if(pwd==password)
                return 1;
            else 
                return 0;
        }
        //定义成员函数
        void modify();
        void gym_order();
        void gym_query();
        void rm_order();
        void query_order();
        string password;

};

class Admin     //管理员类
{
    public:
        string phone;           //电话号码
        string sex;             //性别
        string name;            //姓名
        string gym_name;        //管理的场馆
        string email;           //电子邮件
        string id;              //管理员ID
        //定义成员函数
        void modify();
        void order_mng();
        void gym_mng();
        void init(string x,string y,string isex,string iname,string igym_name,string iemail,string iphone) //初始化函数
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
        void changepwd(string new_pwd)      //密码修改函数
        {
            password = new_pwd;
        }
        void changephone(string new_phone)  //电话号码修改函数
        {
            phone=new_phone;
        }
        void changemail(string new_email)   //email修改函数
        {
            email=new_email;
        }
        int checkpwd(string pwd)            //密码检测函数
        {
            if(pwd==password)
                return 1;
            else 
                return 0;
        }
        string password;
};


/*-----------------------------------------------------【特殊功能函数】------------------------------------------------------------------------------*/

int strtoint(string str)            //从"xx:xx"格式中提取数字
{

    int a,b;
	char string[6];
	str.copy(string,5,0);

	a=(int)(string[0]-48);
	b=(int)(string[1]-48);
	return a*10+b;
}
string timetostr(int time)          //时间戳转字符串函数
{
	time_t tick = (time_t)time;
	struct tm tm; 
	char s[100];
	string str; 
	tm = *localtime(&tick);
	strftime(s, sizeof(s), "%Y:%m:%d:%H:%M", &tm);
	str=s;
	return str;
}

time_t nowtime()                    //返回当前时间戳
{
    time_t now = time(0);
    return now;
}

time_t strtotime(string timestring)  //字符串转时间戳函数
{  
    struct tm tm;  
    memset(&tm, 0, sizeof(tm));   
    sscanf(timestring.c_str(), "%d:%d:%d",   
           &tm.tm_year, &tm.tm_mon, &tm.tm_mday  
           );  
    tm.tm_year -= 1900;  
    tm.tm_mon--;  
    return mktime(&tm);  
}

void query_result(int empty)        //查询结果反馈函数（少部分地方用）
{
    cout<<"-----------------------------------"<<endl;
    if(empty==0)
        cout<<"没有找到符合条目！按回车键退出查询！"<<endl;
    else
        cout<<"所有符合条目已列出！按回车键退出查询！"<<endl;
}

int checkphone(string phone_num)      //电话号码格式检验
{
    if(phone_num.length()==11)
        return 1;
    else 
        return 0;
}

int checkemail(string email_num)       //email格式检验
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

int checktime(string times)     //预定日期格式检测
{
    regex pattern("([0-9]{2}):([0-9]{2})$");
    if(regex_match(times, pattern))
        return 1;
    else
        return 0;
}

int checkdate(string date)      //租借日期格式检测
{
    regex pattern("([0-9]{4}):([0-9]{2}):([0-9]{2})$");
    if(regex_match(date, pattern))
        return 1;
    else
        return 0;
}

int checkid(string id)      //ID格式检测
{
    regex pattern("[0-9a-zA-Z]{6,10}$");
    if(regex_match(id, pattern))
        return 1;
    else
        return 0;
}

/*---------------------------------------------------【UI规范】---------------------------------------------------------------------------------------*/

void outputline()           //输出横线
{
    cout<<"--------------------------------------------------"<<endl;
}

void regist_ui()            //注册界面UI
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

void main_ui()              //主界面UI
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

void guest_ui()             //顾客界面UI
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

void admin_ui()             //管理员界面UI
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

void gym_query_ui()         //顾客：场地查询界面UI
{
    system("clear");
    outputline();
    cout<<"                 场地查询功能模块"<<endl;
    outputline();
    cout<<"                 1.按场地名称查询"<<endl;
    cout<<"                 2.按场馆名称查询"<<endl;
    cout<<"                 3.按场地运动类别"<<endl;
    cout<<"                 4.按所属区域查询"<<endl;
    cout<<"                 5.按空余场地查询"<<endl;
    cout<<"                 6.按租金排序所有场地"<<endl;
    cout<<"                 7.按预定量排序所有场地"<<endl;
    cout<<"                 8.场地预定"<<endl;
    cout<<"                 9.热门推荐"<<endl;
    cout<<"                 0.退出"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void gym_order_ui()         //顾客：场地预定界面UI
{
    system("clear");
    outputline();
    cout<<"                 场地预定功能模块"<<endl;
    outputline();
}

void rm_order_ui()          //顾客：预定取消界面UI
{   
    system("clear");
    outputline();
    cout<<"                 预定取消功能模块"<<endl;
    outputline();

}

void order_query_ui()       //顾客：订单查询界面UI
{
    system("clear");
    outputline();
    cout<<"                 订单查询功能模块"<<endl;
    outputline();
}

void order_mng_ui()         //管理员：订单管理界面UI
{
    system("clear");
    outputline();
    cout<<"                 管理员订单管理模块"<<endl;
    outputline();
    cout<<"                 1.查看场馆订单"<<endl;
    cout<<"                 2.查看所管辖场馆并按预定量排序"<<endl;
    cout<<"                 3.统计场馆营业额"<<endl;
    cout<<"                 4.统计不同场地年龄层次分布"<<endl;
    cout<<"                 5.按营业额排序场地"<<endl;
    cout<<"                 6.统计针对男士/女士最受欢迎运动"<<endl;
    cout<<"                 7.按时间段排序所有场地"<<endl;
    cout<<"                 8.退出"<<endl;
    outputline();
    cout<<"请选择您的操作："<<endl;
}

void gym_mng_ui()           //管理员：场地管理界面UI
{
    system("clear");
    outputline();
    cout<<"                 管理员场地管理模块"<<endl;
    outputline();
}

void guest_modify_ui()      //顾客：个人信息修改界面UI
{
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
}

void admin_modify_ui()      //管理员：个人信息修改界面UI
{
        system("clear");
        outputline();
        cout<<"                 个人信息修改模块"<<endl;
        outputline();
        cout<<"                 1.修改电话"<<endl;
        cout<<"                 2.修改密码"<<endl;
        cout<<"                 3.修改邮箱"<<endl;
        cout<<"                 4.退出"<<endl;
        outputline();

}