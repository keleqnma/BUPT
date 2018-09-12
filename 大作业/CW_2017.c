#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int n=5,book[65534]={-1,-1,-1,-1,-1,-1},Flag=0;

struct student
{
	int id;
	char name[11];
	int co[4];
	float avg;
	int num;
	struct student *next;
}head,stu[100]={	{1,"Alice",{90,80,88,70},82.0,1},
					{2,"Bob",{88,30,78,77},68.3,2},
					{3,"Carol",{90,95,90,100},93.8,3},
					{4,"Geek",{100,98,100,100},99.5,4},
					{5,"Dave",{59,59,59,59},59.0,5}};

					
					
void init1()
{
	head.id=-1;
	head.next=&stu[0];
	stu[0].next=&stu[1];
	stu[1].next=&stu[2];
	stu[2].next=&stu[3];
	stu[3].next=&stu[4];
	stu[4].next=&stu[5];
	stu[5].next=NULL;
}

void init2()
{
	head.id=-1;
	head.next=&stu[3];
	stu[3].next=&stu[2];
	stu[2].next=&stu[0];
	stu[0].next=&stu[1];
	stu[1].next=&stu[4];
	stu[4].next=&stu[5];
	stu[5].next=NULL;
}

int menu()
{
	int op;
	printf("**********************Main Menu*********************\n");
	printf("                1.Show Current List\n");
	printf("                2.Inset Student\n");
	printf("                3.Delete Student\n");
	printf("                4.Search Student\n");
	printf("                5.Analyze Course\n");
	printf("                6.Exit the program\n");
	printf("****************************************************\n");
	scanf("%d",&op);
	return op;
}

int mode()
{
	int mod;
	printf("1.Default Mode\n");
	printf("2.Sorted Mode\n");
	scanf("%d",&mod);
	return mod;
}

void show()
{
	struct student t;
	
	t=head;
	printf("**********************List Info*********************\n");
	printf("ID\tName\tCO1\tCO2\tCO3\tCO4\tAVG\t\n");
	while(t.next!=NULL)
	{
		if(t.id!=-1)
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1f\t\n",t.id,t.name,t.co[0],t.co[1],t.co[2],t.co[3],t.avg);
		t=*(t.next);
	}	
	printf("\n**********************List Info*********************\n\n");
}


void insert()
{
	while(1)
	{
		printf("ID of the student\n");
		scanf("%d",&stu[n].id);
		if(book[stu[n].id]!=-1)
			break;
		else
			printf("The Id you enter is repeated,Please enter another one\n");
	}
	
	
	printf("Name of the student\n");
	scanf("%s",stu[n].name);
	printf("Please input the score of CO1\n");
	scanf("%d",&stu[n].co[0]);
	printf("Please input the score of CO2\n");
	scanf("%d",&stu[n].co[1]);
	printf("Please input the score of CO3\n");
	scanf("%d",&stu[n].co[2]);
	printf("Please input the score of CO4\n");
	scanf("%d",&stu[n].co[3]);
	printf("Insert complete\n");
	stu[n].num=n+1;
	stu[n].avg=(float)((stu[n].co[0]+stu[n].co[1]+stu[n].co[2]+stu[n].co[3])/4);
	if(Flag==0)
	{
		stu[n].next=&stu[n+1];
		stu[n+1].next=NULL;
		}
	else
	{
		struct student t,temp;
		t=head;
		while(t.next!=NULL)
		{
			temp=*(t.next);
			if(stu[n].avg<temp.avg&&stu[n].avg>t.avg)
			{
				stu[t.num].next=&stu[n];
				stu[n].next=&stu[temp.num];
				break;
			}
			t=*(t.next);
		}
	}
	book[n]=-1;
	n++;
}


void search()
{
	char name[11];
	struct student t;
	t=head;
	int flag=0;
	printf("Please enter the name of the student to search:\n");
	scanf("%s",name);
	while(t.next!=NULL)
	{
		if(strcmp(t.name,name)==0 && t.id!=-1)
		{
			flag++;
			printf("ID\tName\tCO1\tCO2\tCO3\tCO4\tAVG\t\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.lf\t\n",t.id,t.name,t.co[0],t.co[1],t.co[2],t.co[3],t.avg);
			break;
		}
		t=*(t.next);
	}
	if(flag==0)
		printf("Student not exit!\n");
}

void delete1()
{
	int id,flag=0;
	struct student t;
	t=head;
	printf("Please enter the id of the student to delete:\n");
	scanf("%d",&id);
	
	while(t.next!=NULL)
	{
		if(t.id==id)
		{
			flag++;
			if(t.num==1)
				head.next=&stu[t.num];
			else
			stu[t.num-2].next=&stu[t.num];
			break;
		}
		t=*(t.next);
	}
		if(flag==0)
			printf("Student not exit!\n");
}


void analyze()
{
	int num,max=-1,min=101,i=1,sum=0;
	struct student t;
	t=head;
	
	printf("Please input the course id you want to analyze:\n");
	scanf("%d",&num);
	num--;
	while(t.next!=NULL)
	{
		if(t.id!=-1)
		{
			if(t.co[num]>max)
				max=t.co[num];
			if(t.co[num]<min)
				min=t.co[num];
			sum+=t.co[num];
			i++;
		}
		t=*(t.next);
	}
	printf("i=%d\n",i);
	printf("Max=%d\n",max);
	printf("Min=%d\n",min);
	printf("Avg=%.2f",(float)(sum/i));

}

int main()
{
	int mod=mode();
	if(mod==1)
		init1();
	else if(mod==2)
	{
		init2();
		Flag++;
	}
	else 
		printf("Input Wrong\n");
	
	while(1)
	{
		switch(menu())
			{
				case 1:show();break;
				case 2:insert();break;
				case 3:delete1();break;
				case 4:search();break;
				case 5:analyze();break;
				case 6:return 0;
				default:printf("Input Wrong\n");break;
			}
			printf("Please push any key to back to the main menu...\n");
			getchar();getchar();
			system("cls");
	}
}
