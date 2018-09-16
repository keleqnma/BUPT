#include<iostream>
#include<cstring>
#include<regex>
#include<ctime>
#include<fstream>

#include "gymsystem.h"

using namespace std;



/*-----------------------------------------------------【全局变量】------------------------------------------------------------------------------*/

int mode=0,login_num;
int guests=0,admins=0,gyms=0,orders=0,sportstypes=0;    //常量变量化
FILE *fin,*fout;
Admin *admin = new Admin[15];
Guest *guest = new Guest[15];
Order *order = new Order[15];
Gym *gym = new Gym[15];
Sportstype *sportstype = new Sportstype[10];
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
                string phone;
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
                    if(checkemail(email))
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
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            break;
    }  
}

void Guest::gym_query()     //顾客场地查询功能
{
    int flag=0;
    while(1)
    {
        int operation;
        gym_query_ui();
        cin>>operation;
        switch(operation)
        {
            case 1:
            {
                string j;
                int empty=0;
                cout<<"请输入场地编号"<<endl;
                cin>>j;
                for(int i=0;i<gyms;i++)
                {
                    if(j==gym[i].id)
                    {
                        gym[i].show();
                        empty=1;
                    }
                }
                query_result(empty);
                getchar();getchar();break;
            }
            case 2:
            {
                string j;
                int empty=0;
                cout<<"请输入场馆名称"<<endl;
                cin>>j;
                for(int i=0;i<gyms;i++)
                {
                    if(j==gym[i].belong)
                    {
                        gym[i].show();
                        empty=1;
                    }
                }
                query_result(empty);
                getchar();getchar();break;
            }
            case 3:
            {
                string j;
                int empty=0;
                cout<<"请输入场地类别"<<endl;
                cin>>j;
                for(int i=0;i<gyms;i++)
                {
                    if(j==gym[i].sport_type)
                    {
                        gym[i].show();
                        empty=1;
                    }
                }
                query_result(empty);
                getchar();getchar();break;
            }
            case 4:
            {
                string j;
                int empty=0;
                cout<<"请输入场地所属地域"<<endl;
                cin>>j;
                for(int i=0;i<gyms;i++)
                {
                    if(j==gym[i].location)
                    {
                        gym[i].show();
                        empty=1;
                    }
                }
                query_result(empty);
                getchar();getchar();break;
            }
            case 5: 
            {
                int empty=0,start,end;
                string date,startt,endd;
                while(1)
                {
                    cout<<"输入想要查询的日期(格式：yyyy:mm:dd）："<<endl;
                    cin>>date;
                    if(checkdate(date))
                        break;
                    else 
                        cout<<"您的输入不符合格式！请重新输入！"<<endl; 
                }
                
                while(1)
                {
                    cout<<"输入开始时间(06:00-22:00)："<<endl;
                    cin>>startt;
                    start=strtoint(startt);
                    if(checktime(startt)==1 && (start>=6 && start<=22))
                        break;
                    else 
                        cout<<"您的输入不符合格式！请重新输入！"<<endl;
                }

                while(1)
                {
                    cout<<"输入结束时间(06:00-22:00)："<<endl;
                    cin>>endd;
                    end=strtoint(endd);
                    if(checktime(endd)==1 && (end>=6 && end<=22))
                        break;
                    else 
                        cout<<"您的输入不符合格式！请重新输入！"<<endl;
                }



                for(int i=0;i<gyms;i++)
                {
                    int flag=0;
                    if(gym[i].order_sum>0)
                    {
                        for(int j=0;j<orders;j++)
                        {
                            if(order[j].id==id && order[j].date==date)
                            {
                                if((start<order[j].start&&end<=order[j].start)||(start>=order[j].end&&end>order[j].end))
                                    continue;
                                else
                                {
                                    flag=1;
                                    break;
                                }

                            }
                        }
                    }
                    if(flag==0)
                    {
                        gym[i].show();
                        empty=1;
                    }
                }

                query_result(empty);
                getchar();getchar();break;
            }
            case 6:
            { 
                int temp=0,a[gyms]={0};
                for(int j=0;j<gyms;j++)
                {
                    float min=gym[0].rent;
                    temp=j;
                    for(int i=0;i<gyms;i++)
                    {
                        
                        if(min>=gym[i].rent && a[i]==0)
                        {
                            min=gym[i].rent;
                            temp=i;
                        }
                    }
                    if(a[temp]==0)
                    {
                        gym[temp].show();
                        a[temp]=1;
                    }
                }
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 7:
            {
                int temp,a[gyms]={0};
                for(int j=0;j<gyms;j++)
                {
                    int max=gym[0].order_sum;
                    temp=j;
                    for(int i=0;i<gyms;i++)
                    {
                        if(max<=gym[i].order_sum && a[i]==0)
                        {
                            max=gym[i].order_sum;
                            temp=i;
                        }
                    }
                    if(a[temp]==0)
                    {
                        
                        gym[temp].show();
                        cout<<endl<<"预定量:"<<gym[temp].order_sum<<endl;
                        a[temp]=1;
                    }
                }
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 8:gym_order();break;               //查询后可以预定
            case 9:                                 //热门推荐(单纯按照预定量推荐)
            {
                cout<<endl<<"我们将根据最高预定数目的场地为您推荐！"<<endl;
                string rec="test123";
                int max=gym[0].order_sum,temp;
                for(int i=0;i<gyms;i++)
                {
                    if(gym[i].order_sum>max)
                    {
                        max=gym[i].order_sum;
                        rec=gym[i].id;
                        temp=i;
                    }
                }
                cout<<"推荐场地："<<rec<<endl;
                cout<<"预定数目："<<gym[temp].order_sum;
                cout<<endl<<"推荐完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 0:{flag=1;break;}
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        
        if(flag==1)
            break;
    }
}

void Guest::gym_order()     //顾客场地预定功能
{
    while(1)        
    {
        int start,end,num,flag=0,giveup=0;
        char cmd;
        string id,date,changguan;
        string startt,endd;
        gym_order_ui();

        for(int i=0;i<orders;i++)
            if(order[i].check==0)
                giveup++;
        if(giveup>=3)
        {
            cout<<"您历史爽约次数已超3次！失去预定资格！"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();
            break;
        }


        if(chance==0)
        {
            cout<<"您本次预定次数已打上限三次！按回车键退出！";
            getchar();
            break;
        }

        
        cout<<"输入你想预定的场馆:"<<endl;
        cin>>changguan;
        if(changguan!="场馆一" && changguan!="场馆二" && changguan!="场馆三")
        {
            cout<<"场馆不存在"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }

        cout<<"输入你想要预定的场地编号:"<<endl;
        cin>>id;

        for(int i=0;i<gyms;i++)
        {
            if(id==gym[i].id)
            {
                cout<<"进来了！"<<endl;
                if(gym[i].belong==changguan)
                { 
                    cout<<"进来了2"<<endl;
                    flag=0;
                    num=i;
                    break;
                }
                else  
                    flag=1;
            }
            else if(flag!=1)
                flag=2;
        }
        if(flag==1)
        {
            cout<<"这个场地不属于"<<changguan<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }
        else if(flag==2)
        {
            cout<<"这个场地不存在!"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }

        
        cout<<"-------------------------------------"<<endl;
        cout<<"您的下单时间为："<<timetostr((int)nowtime())<<endl;
        cout<<"-------------------------------------"<<endl;

        while(1)
        {
            cout<<"输入你想要租借日期(格式：yyyy:mm:dd）："<<endl;
            cin>>date;
            if(checkdate(date))
                break;
            else 
                cout<<"您的输入不符合格式！请重新输入！"<<endl; 
        }
        if(((int)strtotime(date))-((int)nowtime())<(7*24*60*60) && ((int)strtotime(date))<((int)nowtime()))
        {
            cout<<"预定失败！您预定场地的时间需与当前时间间隔一周以上！"<<endl;
            cout<<"按回车键退出并重新预定！"<<endl;
            getchar();
            getchar();
            break;
        }

            
        
        while(1)
        {
            cout<<"输入你想要预定的开始时间(06:00-22:00)："<<endl;
            cin>>startt;
            start=strtoint(startt);
            if(checktime(startt)==1&&(start>=6 && start<=22))
                break;
            else 
                cout<<"您的输入不符合格式！请重新输入！"<<endl;
        }
        
        while(1)
        {
            cout<<"输入你想要预定的结束时间(06:00-22:00)："<<endl;
            cin>>endd;
            end=strtoint(endd);
            if(checktime(endd)&& (end>=6 && end<=22))
                break;
            else 
                cout<<"您的输入不符合格式！请重新输入！"<<endl;
        }



        int flag1=0;
        for(int j=0;j<orders;j++)
        {
            if(order[j].date==date)
            {
                if((start<order[j].start&&end<=order[j].start)||(start>=order[j].end&&end>order[j].end))
                    continue;
                else
                {
                    flag1=1;
                    break;
                }
            }
        }
        if(flag1==1)
        {
            cout<<"抱歉！你选择的时间段已有其他预定！请重新预定！"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }


        if(count-gym[num].rent<0)
        {
            cout<<"您的余额不足支付该场地租金！请换场地或充值！"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }
        if(age > gym[num].age_limit_2 || age < gym[num].age_limit_1)
        {
            cout<<"您的年龄不适合该项运动！请换场地或再等几年！"<<endl;
            cout<<"按回车键退出..."<<endl;
            getchar();getchar();
            break;
        }

        //此处开始生成订单
        order[orders].order_number=guest[login_num].id+timetostr((int)nowtime());
        order[orders].order_date=timetostr((int)nowtime());
        order[orders].id=id;
        order[orders].date=date;
        order[orders].start=start;
        order[orders].end=end;
        order[orders].belong=name;
        order[orders].gym_belong=changguan;
        order[orders].age=age;
        order[orders].sports=gym[num].sport_type;
        order[orders].check=1;
        /*---------------------------------------------------------------*/
        for(int i=0;i<sportstypes;i++)
        {
            if(sportstype[i].type==gym[num].sport_type)
            {
                if(sex=="男")
                    sportstype[i].male++;
                else if(sex=="女")
                    sportstype[i].female++;
                    
            }
        }


        gym[num].order_sum++;               //所预定场地预定量
        gym[num].rent_sum+=gym[num].rent;   //所预定场地营业额增加
                                            //订单总数+1
        chance--;                           //该用户本次租借机会-1
        count-=gym[num].rent;               //用户租金减少

        for(int k=0;k<sportstypes;k++)
        {
            if(gym[num].sport_type==sportstype[k].type)
            {
                if(sex=="男")
                    sportstype[k].male++;
                else if(sex=="女")
                    sportstype[k].female++;
            }
        }

        cout<<"订单生成完毕，具体信息如下："<<endl;
        order[orders].show();

        orders++;
        cout<<endl<<"[*]你想要继续预定吗？(y/n)"<<endl;
        cin>>cmd;
        if(cmd=='n' || cmd=='N')
            break;
    }
}

void Guest::rm_order()      //顾客取消订单功能
{
    char cmd;
    while(1)
    {
        int flag=0;
        string rm_id,result;
        rm_order_ui();

        cout<<"您拥有的订单如下："<<endl;
        for(int i=0;i<orders;i++)
            if(order[i].belong==id)
                order[i].show();

        cout<<"在此键入您想删除的订单编号："<<endl;
        cin>>rm_id;
        for(int i=0;i<orders;i++)
        {
            if(order[i].belong==name && rm_id==order[i].order_number)
            {
                if(((int)strtotime(order[i].date))-((int)nowtime())<(24*60*60))
                {
                    cout<<"预定取消失败！！距离预约事件不足24小时！"<<endl;
                    cout<<"按回车键退出...！"<<endl;
                    getchar();
                    getchar();
                    break;
                }
                
                order[i].belong=="trush";       //改变从属场馆进行删除,tursh场馆不会存入文件
                flag=1;
                cout<<endl<<"[*]订单删除成功！按回车继续！"<<endl;
                orders--;                       //订单总数减少
                gym[i].rent_sum-=gym[i].rent;   //场地营业额减少
                gym[i].order_sum--;              //场地预定量减少
                count+=gym[i].rent;             //返还金额

                for(int k=0;k<sportstypes;k++)
                {
                    if(order[i].sports==sportstype[k].type)
                    {
                        if(sex=="男")
                            sportstype[k].male--;
                        else if(sex=="女")
                            sportstype[k].female--;
                    }
                }
                getchar();
            }
        }
        if(flag==0)
            cout<<"删除失败！没有找到此订单或此订单不属于您！"<<endl;
        cout<<endl<<"[*]你想要继续删除订单吗吗？(y/n)"<<endl;
        cin>>cmd;
        if(cmd=='n' || cmd=='N')
            break;
    }
}

void Guest::query_order()   //顾客查询订单功能
{
    order_query_ui();
    cout<<"您拥有的订单如下："<<endl;;
        for(int i=0;i<orders;i++)
            if(order[i].belong==name && order[i].belong!="trush")
                order[i].show();
    cout<<"查询完毕！若无显示代表没有订单！按回车键返回..."<<endl;
    getchar();getchar();
}

///----------------------------成员函数分割线-------------------------------------//


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
                string phone;
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
                    if(checkemail(email))
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
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            break;
    }  
}


void Admin::order_mng()        //管理员订单管理功能
{
    int flag=0;
    while(1)
    {
        int operation;
        order_mng_ui();
        cin>>operation;
        switch(operation)
        {
            case 1:
            {
                int empty=0,flag=0;
                for(int i=0;i<orders;i++)
                    if(order[i].gym_belong==gym_name)
                        order[i].show();

                query_result(empty);
                getchar();getchar();break;
            }
            case 2:
            {
                int temp,a[gyms]={0};
                for(int j=0;j<gyms;j++)
                {
                    for(int i=0;i<gyms;i++)
                    {
                        float min=gym[0].order_sum;
                        if(min>=gym[i].order_sum && a[i]==0)
                        {
                            min=gym[i].order_sum;
                            temp=i;
                        }
                    }
                    if(a[temp]==0)
                    {
                        if(gym_name==gym[temp].belong)
                            gym[temp].show();
                        a[temp]=1;
                    }
                }
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 3:
            {
                float sum=0.0;
                for(int i=0;i<gyms;i++)
                    if(gym_name==gym[i].belong)
                        sum+=gym[i].rent_sum;
                cout<<"您所在场馆的营业额为："<<setiosflags(ios::fixed)<<setprecision(2)<<sum<<endl;
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 4:
            {
                cout<<"年龄分布如下："<<endl;
                for(int i=0;i<gyms;i++)
                {
                    if(gym_name==gym[i].belong)
                    {
                        int a=0,b=0,c=0,d=0,e=0;
                        for(int j=0;j<orders;j++)
                        {
                            if(order[j].id==gym[i].id)
                            {
                                if(order[j].age>0 && order[j].age<12)
                                    a++;
                                else if(order[j].age>12 && order[j].age<20)
                                    b++;
                                else if(order[j].age>20 && order[j].age<40)
                                    c++;
                                else if(order[j].age>40 && order[j].age<60)
                                    d++;
                                else if(order[j].age>60)
                                    e++;
                            }
                        }
                        cout<<"-----------------------------------------"<<endl;
                        cout<<"[-]场地"<<gym[i].id<<"中0-12岁的人数有："<<a<<endl;
                        cout<<"[-]场地"<<gym[i].id<<"中12-20岁的人数有："<<b<<endl;
                        cout<<"[-]场地"<<gym[i].id<<"中20-40岁的人数有："<<c<<endl;
                        cout<<"[-]场地"<<gym[i].id<<"中40-60岁的人数有："<<d<<endl;
                        cout<<"[-]场地"<<gym[i].id<<"中60岁+的人数有："<<e<<endl;
                    }
                }
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 5:
            {
                int temp,a[gyms]={0};
                for(int j=0;j<gyms;j++)
                {
                    for(int i=0;i<gyms;i++)
                    {
                        float min=gym[0].rent_sum;
                        if(min>=gym[i].rent_sum && a[i]==0)
                        {
                            min=gym[i].rent_sum;
                            temp=i;
                        }
                    }
                    if(a[temp]==0)
                    {
                        if(gym_name==gym[temp].belong)
                        {
                            gym[temp].show();
                            cout<<endl<<"营业额："<<setiosflags(ios::fixed)<<setprecision(2)<<gym[temp].rent_sum;
                        }
                        a[temp]=1;
                    }
                }
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 6:
            {
                int max1,max2,temp1=0,temp2=0;
                max1=sportstype[0].male;
                max2=sportstype[0].female;
                for(int i=0;i<sportstypes;i++)
                {
                    if(sportstype[i].male>max1)
                    {
                        max1=sportstype[i].male;
                        temp1=i;
                    }
                    if(sportstype[i].female>max2)
                    {
                        max2=sportstype[i].female;
                        temp2=i;
                    }
                }
                
                cout<<endl<<"最受男士欢迎的运动项目是："<<sportstype[temp1].type<<endl;
                cout<<"最受女士欢迎的运动项目是："<<sportstype[temp2].type<<endl;
                cout<<endl<<"统计完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 7:
            {
                
                for(int i=0;i<gyms;i++)
                {  
                    if(gym[i].belong==gym_name)
                    {
                        cout<<"场地"<<gym[i].id<<"时间占用情况:"<<endl;
                        cout<<"----------------------------------"<<endl;
                        for(int k=6;k<=22;k++)
                        {
                            string res = "【空闲】               0";
                            if(k<10)
                                cout<<k<<":00  :       ";
                            else
                                cout<<k<<":00 :       ";
                            for(int j=0;j<orders;j++)
                            {
                                if(order[j].id==gym[i].id)
                                {
                                    if(k>=order[j].start&&k<=order[j].end)
                                        res="【占用】               100";
                                }
                            }
                            cout<<res<<"%"<<endl;
                        }
                        cout<<"----------------------------------"<<endl;
                    }
                }
                
                cout<<endl<<"查询完成！按回车键继续..."<<endl;
                getchar();getchar();
                break;
            }
            case 8:{flag=1;break;}
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            break;
    }
}

void Admin::gym_mng()       //管理员场地管理功能
{
    while(1)
    {
        char cmd;
        int k;
        gym_mng_ui();
        for(int i=0;i<gyms;i++)
            gym[i].show();
        cout<<endl<<"所有场地信息显示完毕!是否选择添加一个新的场地？(y/n)："<<endl;
        cout<<"[*]注：选择不添加场地将会自动退出该模块！"<<endl;
        cin>>cmd;
        if(cmd=='n' || cmd=='N')
            break;
        while(1)
        {
            cout<<"输入新场地的编号："<<endl;
            cin>>gym[gyms].id;
            if(checkid(gym[gyms].id))
                break;
            else 
                cout<<"您的输入不符合格式！请重新输入！"<<endl;
        }
        cout<<"输入新场地的租金："<<endl;
        cin>>gym[gyms].rent;
        cout<<"输入新场地的所属区域"<<endl;
        cin>>gym[gyms].location;
        cout<<"输入新场地的年龄下限："<<endl;
        cin>>gym[gyms].age_limit_1;
        cout<<"输入新场地的年龄上限："<<endl;
        cin>>gym[gyms].age_limit_2;
        cout<<"输入新场地的推荐运动："<<endl;
        cin>>gym[gyms].sport_rec;
        cout<<"输入新场地适合的运动类型："<<endl;
        cin>>gym[gyms].sport_type;

        for(k=0;k<sportstypes;k++)
        {
            cout<<"进来了"<<endl;
            if(sportstype[k].type==gym[gyms].sport_type)
                sportstype[k].sum++;
        }
        cout<<k<<sportstypes<<endl;

        if(k==sportstypes)
        {
            sportstype[sportstypes].sum=1;
            sportstype[sportstypes].type=gym[gyms].sport_type;
            sportstypes++;
        }

        gym[gyms].belong=gym_name;
        gym[gyms].order_sum=0;
        gym[gyms].rent_sum=0;




        cout<<"--------------------------------"<<endl;
        cout<<"新场点点添加成功！信息如下："<<endl;
        gym[gyms].show();
        gyms++;
        cout<<"按回车继续..."<<endl;
        getchar();getchar();
    }
}



/*-----------------------------------------------------【函数定义】----------------------------------------------------------------------------*/


void init()         //初始化数据：文件数据载入内存
{
    ifstream guestin("guest.txt",ios::in);
    while(!guestin.eof())    
    {
        string a,b,c,d,e,f,t;
        int g,cancel;
        float h;
        guestin>>a>>b>>c>>d>>e>>f>>g>>h>>t>>cancel;
        guest[guests].init(a,b,c,d,e,f,g,h,t,cancel);
        guests++;
    }
    guestin.close();

    
    ifstream adminin("admin.txt",ios::in);
    while(!adminin.eof())
    {
        string a,b,c,d,e,f,t;
        adminin>>a>>b>>c>>d>>e>>f>>t;
        admin[admins].init(a,b,c,d,e,f,t);
        admins++;
    }
    adminin.close();
    
    ifstream orderin("order.txt",ios::in);
    while(!orderin.eof())
    {
        string a1,a2,a3,a4,a5,a6,a7;
        int b1,b2,b3,b4;
        orderin>>a1>>a2>>a3>>a4>>a5>>a6>>a7>>b1>>b2>>b3>>b4;
        if((int)strtotime(a4)-((int)nowtime())<(7*24*60*60))
            b4=0;
        order[orders].init(a1,a2,a3,a4,a5,a6,a7,b1,b2,b3,b4);
        orders++;
    }
    orderin.close();
    
    ifstream gymin("gym.txt",ios::in);
    while(!gymin.eof())
    {
        string a1,a2,a3,a4,a5;
        int b1,b2,b3,time1[24];
        float c1,c2;

        gymin>>a1>>a2>>a3>>a4>>a5;
        gymin>>b1>>b2>>b3;
        gymin>>c1>>c2;
        gym[gyms].init(a1,a2,a3,a4,a5,b1,b2,b3,c1,c2);
        gyms++;
    }
    gymin.close();
    

    ifstream sportstypein("sportstype.txt",ios::in);
    while(!sportstypein.eof())
    {
        int a1,a2,a3;
        string type;
        sportstypein>>a1>>a2>>a3>>type;
        sportstype[sportstypes].init(a1,a2,a3,type);
        sportstypes++;
    }
    sportstypein.close();
    orders--;
    gyms--;
    guests--;
    admins--;
    sportstypes--;

    /*
                用于检测初始化数据量
            cout<<sportstypes<<endl;
            cout<<gyms<<endl;
            cout<<orders<<endl;
            cout<<admins<<endl;
            cout<<guests<<endl;
            getchar();
    */

    

}

void done()           //保存数据：内存数据写入文件
{
    ofstream guestout("guest.txt",ios::out);
    for(int i=0;i<guests;i++)
        guestout<<guest[i].id<<endl<<guest[i].password<<endl<<guest[i].name<<endl<<guest[i].sex<<endl<<guest[i].email<<endl<<guest[i].location<<endl<<guest[i].age<<endl<<guest[i].count<<endl<<guest[i].phone<<endl<<guest[i].cancel<<endl<<endl;
    guestout.close();

    ofstream adminout("admin.txt",ios::out);
    for(int i=0;i<admins;i++)
        adminout<<admin[i].id<<endl<<admin[i].password<<endl<<admin[i].sex<<endl<<admin[i].name<<endl<<admin[i].gym_name<<endl<<admin[i].email<<endl<<admin[i].phone<<endl<<endl;
    adminout.close();

    ofstream orderout("order.txt",ios::out);
    for(int i=0;i<orders;i++)
        if(order[i].belong!="trush")
            orderout<<order[i].order_number<<endl<<order[i].order_date<<endl<<order[i].id<<endl<<order[i].date<<endl<<order[i].gym_belong<<endl<<order[i].sports<<endl<<order[i].belong<<endl<<order[i].start<<endl<<order[i].end<<endl<<order[i].age<<endl<<order[i].check<<endl<<endl;
    orderout.close();

    ofstream gymout("gym.txt",ios::out);
    for(int i=0;i<gyms;i++)
        if(gym[i].belong!="trush")
            gymout<<gym[i].id<<endl<<gym[i].location<<endl<<gym[i].sport_rec<<endl<<gym[i].sport_type<<endl<<gym[i].belong<<endl<<gym[i].age_limit_1<<endl<<gym[i].age_limit_2<<endl<<gym[i].order_sum<<endl<<setiosflags(ios::fixed)<<setprecision(2)<<gym[i].rent<<endl<<gym[i].rent_sum<<endl<<endl;
    gymout.close();

    ofstream sportstypeout("sportstype.txt",ios::out);
    for(int i=0;i<sportstypes;i++)
        sportstypeout<<sportstype[i].male<<endl<<sportstype[i].female<<endl<<sportstype[i].sum<<endl<<sportstype[i].type<<endl<<endl;
    sportstypeout.close();
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
                    cout<<"已确认顾客ID！请输入密码:"<<endl;
                    while(login_try!=0)
                    {
                        cin>>password;
                        if(guest[i].checkpwd(password))
                        {
                            cout<<"已确认密码！登录成功！请按回车进入下一步！"<<endl;
                            mode=1;
                            login_num=i;
                            getchar();
                            break;
                        }
                        else 
                            cout<<"未能确认密码！登录失败！你还有"<<login_try--<<"次机会！"<<endl<<"请重新输入你的密码："<<endl;    
                    }
                    if(mode==1||login_try==0)
                        break;
                }
            }
            if(mode==1)
                break;
            else if(login_try==0)
            {
                cout<<"你已经用完了所有机会！按回车键退出重新登录！"<<endl;
                getchar();getchar();
                break;
            }
            else
                cout<<"没有找到你的ID!重新";
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
                    cout<<"已确认管理员ID！请输入密码:"<<endl;
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
                            cout<<"未能确认密码！登录失败！你还有"<<login_try--<<"次机会！"<<endl<<"请重新输入你的密码："<<endl;    
                    }
                    if(mode==2||login_try==0)
                        break;
                }
            }
            if(mode==2)
                break;
            else if(login_try==0)
            {
                cout<<"你已经用完了所有机会！按回车键退出重新登录！"<<endl;
                getchar();getchar();
                break;
            }
            else
                cout<<"没有找到你的ID!重新";
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

    while(1)
    {
        cout<<"请输入您的ID:"<<endl;
        cin>>guest[guests].id;
        if(checkid(guest[guests].id))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    }

    while(1)
    {
        cout<<"请输入您的电话:"<<endl;
        cin>>guest[guests].phone;
        if(checkphone(guest[guests].phone))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    } 
    cout<<"请输入您的姓名:"<<endl;
    cin>>guest[guests].name;
    cout<<"请输入您的性别:"<<endl;
    cin>>guest[guests].sex;
    cout<<"请输入您的年龄:"<<endl;
    cin>>guest[guests].age;

    while(1)
    {
        char cmd;
        cout<<"请输入您的密码:"<<endl;
        cin>>pwd;
        if(pwd.length()<6)
            cout<<"系统检测到您的密码安全性为：低，请问确定使用新密码吗？（y/n）";
        else if(pwd.length() >= 6 && pwd.length() <= 8)
            cout<<"系统检测到您的密码安全性为：中，请问确定使用新密码吗？（y/n）";
        else if(pwd.length() > 8)
            cout<<"系统检测到您的密码安全性为：高，请问确定使用新密码吗？（y/n）";
        cin>>cmd;
        if(cmd=='n' || cmd=='N')
            cout<<"已取消此次密码设置！请重新设置！"<<endl;
        else
            break;
    }
    guest[guests].changepwd(pwd);

    while(1)
    {
        cout<<"请输入您的邮箱:"<<endl;
        cin>>guest[guests].email;
        if(checkemail(guest[guests].email))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    }
    
    cout<<"请输入您的账户余额:"<<endl;
    cin>>guest[guests].count;
    cout<<"请输入您的所属地理区域:"<<endl;
    cin>>guest[guests].location;
    
    cout<<"注册成功!您的信息为："<<endl;
    outputline();

    guest[guests].show();
    guests++;
    
    
    cout<<endl<<"按回车键继续..."<<endl;
    getchar();getchar();
}

void regist_admin()         //管理员注册函数
{
    string pwd;
    system("clear");
    outputline();
    cout<<"                 管理员注册页面"<<endl;
    outputline();
    while(1)
    {
        cout<<"请输入您的ID:"<<endl;
        cin>>admin[admins].id;
        if(checkid(admin[admins].id))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    }

    while(1)
    {
        cout<<"请输入您的电话:"<<endl;
        cin>>admin[admins].phone;
        if(checkphone(admin[admins].phone))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    } 

    while(1)
    {
        cout<<"请输入您的邮箱:"<<endl;
        cin>>admin[admins].email;
        if(checkemail(admin[admins].email))
            break;
        else 
            cout<<"您的输入不符合格式！请重新输入！"<<endl;
    }
    while(1)
    {
        char cmd;
        cout<<"请输入您的密码:"<<endl;
        cin>>pwd;
        if(pwd.length()<6)
            cout<<"系统检测到您的密码安全性为：低，请问确定使用新密码吗？（y/n）";
        else if(pwd.length() >= 6 && pwd.length() <= 8)
            cout<<"系统检测到您的密码安全性为：中，请问确定使用新密码吗？（y/n）";
        else if(pwd.length() > 8)
            cout<<"系统检测到您的密码安全性为：高，请问确定使用新密码吗？（y/n）";
        cin>>cmd;
        if(cmd=='n' || cmd=='N')
            cout<<"已取消此次密码设置！请重新设置！"<<endl;
        else
            break;
    }
    admin[admins].changepwd(pwd);

    cout<<"请输入您的姓名:"<<endl;
    cin>>admin[admins].name;
    cout<<"请输入您的性别:"<<endl;
    cin>>admin[admins].sex;
    cout<<"请输入您所管辖的区域:"<<endl;
    cin>>admin[admins].gym_name;
    
    cout<<"注册成功!您的信息为："<<endl;
    outputline();
    admin[admins].show();
    admins++;
    
    cout<<endl<<"按回车键继续..."<<endl;
    getchar();getchar();
}

void regist_index()         //注册索引
{
    int flag=0;
    while(1)
    {
        int operation;
        regist_ui();
        cin>>operation;
        switch(operation)
        {
            case 1:regist_guest();break;
            case 2:regist_admin();break;
            case 3:flag=1;break;
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            cout<<"test"<<endl;
            break;
    }
}

void guest_index()          //顾客功能索引
{
    int flag=0;
    while(1)
    {
        int operation;
        guest[login_num].chance=3;
        guest_ui();
        cin>>operation;
        switch(operation)
        {
            case 1:guest[login_num].gym_query();break;
            case 2:guest[login_num].gym_order();break;
            case 3:guest[login_num].rm_order();break;
            case 4:guest[login_num].query_order();break;
            case 5:guest[login_num].modify();break;
            case 6:flag=1;break;
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            break;
    }
}

void admin_index()          //管理员功能索引
{
    int flag=0;
    while(1)
    {
        int operation;
        admin_ui();
        cin>>operation;
        switch(operation)
        {
            case 1:admin[login_num].order_mng();break;
            case 2:admin[login_num].gym_mng();break;
            case 3:admin[login_num].modify();break;
            case 4:{flag=1;mode=0;break;}
            default:{cout<<"非法操作！按回车键重新输入！"<<endl;getchar();getchar();break;}
        }
        if(flag==1)
            break;
    }
}

void main_index()           //主索引
{
    int operation;
    while(1)
    {
        main_ui();
        cin>>operation;
        if(operation==1||operation==2)
        {
            login(operation);
            break;
        }
        else if(operation==3)
        {
            regist_index();
            break;
        }
        else if (operation==4)
        {
            done();
            exit(0);     
        }       //windows下使用exit即可
        else
        {
            cout<<"没有这个功能！按回车重新选择操作！"<<endl;
            getchar();getchar();
            break;
        }
    }
    system("clear");
}




/*------------------------------------------------------------【主函数】------------------------------------------------------------------------*/

int main()      //主函数
{
    init();
    while(1)
    {
        main_index();
        
        if(mode==1)
            guest_index();
        else if(mode==2)   
            admin_index();
        else if(mode!=0)
        {
            cout<<"[*]进入系统失败!按任意键退出!"<<endl;
            break;
        }
    }
    done();
    getchar();
    getchar();
}
