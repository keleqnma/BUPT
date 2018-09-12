#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define NAMELEN 10 // Students’ names are no longer than 10 chars.
#define COURSES 4 // There are four courses in the system.

int book[65534]={-1,-1,-1,-1,-1,-1},Flag=0;//Flag is a sentinel used to judge the pattern
typedef struct stu_info
{ 
	char stu_name[NAMELEN];
	int id, score[COURSES];
	float avgScore;
	struct stu_info *next;
}STU_INFO;

stu_info *stu1=(stu_info *)malloc(sizeof(stu_info));
stu_info *stu2=(stu_info *)malloc(sizeof(stu_info));
stu_info *stu3=(stu_info *)malloc(sizeof(stu_info));
stu_info *stu4=(stu_info *)malloc(sizeof(stu_info));
stu_info *stu5=(stu_info *)malloc(sizeof(stu_info));
stu_info *start=(stu_info *)malloc(sizeof(stu_info));

void init()
{
	stu1->id=1;	strcpy(stu1->stu_name,"Alice"); 		stu1->score[0]=90;		stu1->score[1]=80;stu1->score[2]=88;stu1->score[3]=70;		stu1->avgScore=82.0;
	stu2->id=2;	strcpy(stu2->stu_name,"Bob");    		stu2->score[0]=88;		stu2->score[1]=30;stu2->score[2]=78;stu2->score[3]=77;		stu2->avgScore=68.3;
	stu3->id=3;	strcpy(stu3->stu_name,"Carol"); 		stu3->score[0]=90;		stu3->score[1]=95;stu3->score[2]=90;stu3->score[3]=100;	stu3->avgScore=93.8;
	stu4->id=4;	strcpy(stu4->stu_name,"Geek");  		stu4->score[0]=100;		stu4->score[1]=98;stu4->score[2]=100;stu4->score[3]=100;	stu4->avgScore=99.5;
	stu5->id=5;	strcpy(stu5->stu_name,"Dave");   		stu5->score[0]=59;		stu5->score[1]=59;stu5->score[2]=59;stu5->score[3]=59;		stu5->avgScore=59.0;
}
void init1()
{
	start->next=stu1;	
	stu1->next=stu2; 
	stu2->next=stu3;  
	stu3->next=stu4; 
	stu4->next=stu5; 
	stu5->next=NULL;
}

void init2()
{
	start->next=stu4;	
	stu4->next=stu3; 
	stu3->next=stu1;  
	stu1->next=stu2; 
	stu2->next=stu5; 
	stu5->next=NULL;	
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
	printf("Please choose functions:\n");
	scanf("%d",&op);
	return op;
}

void list()
{
	stu_info *t;
	t=start;
	printf("**********************List Info*********************\n");
	printf("ID\tName\tCO1\tCO2\tCO3\tCO4\tAVG\t\n");
	while(1)
	{
		if(t->id!=0)
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1f\t\n",t->id,t->stu_name,t->score[0],t->score[1],t->score[2],t->score[3],t->avgScore);
		if(t->next==NULL)
			break;
		t=t->next;
	}	
	printf("\n**********************List Info*********************\n");
}

void insert()
{
	stu_info *t;
	t=start;
	stu_info *temp=(stu_info *)malloc(sizeof(stu_info));

	while(1)
	{
		printf("ID of the student:\n");
		scanf("%d",&temp->id);
		if(book[temp->id]!=-1)																										//Check whether the input is true
			break;
		else
			printf("The Id you enter is repeated! Please enter another one!\n");
	}
	
	printf("Name of the student:\n");
	scanf("%s",temp->stu_name);
	
	for(int i=0;i<4;i++)
	{
		while(1)
		{
			printf("Please input the score of CO%d:\n",i+1);
			scanf("%d",&temp->score[i]);
			if(temp->score[i]<=100&&temp->score[i]>=0)																	//Check whether the input is true
				break;
			printf("Score wrong! Please input again!\n");
		}
	}
	
	printf("Insert complete!\n");
	temp->avgScore=(float)((temp->score[0]+temp->score[1]+temp->score[2]+temp->score[3])/4);
	
	while(1)
	{
		if(Flag==0)																																//Default mode
		{
			if(t->next==NULL)
			{
				t->next=temp;
				temp->next=NULL;
				break;
			}
		}
		else if(Flag==1)																															//Sorted mode
		{
			if(t->next==NULL || t->next->avgScore < temp->avgScore)
			{
				temp->next=t->next;
				t->next=temp;
				break;
			}
		}
		t=t->next;
	}	
	book[temp->id]=-1;
}

void search()
{
	char name[11];
	stu_info *t;
	t=start;
	int flag=0;
	printf("Please enter the name of the student to search:\n");
	scanf("%s",name);
	while(1)
	{
		if(strcmp(t->stu_name,name)==0 && t->id!=-1)
		{
			flag++;
			printf("ID\tName\tCO1\tCO2\tCO3\tCO4\tAVG\t\n");
			printf("%d\t%s\t%d\t%d\t%d\t%d\t%.1f\t\n",t->id,t->stu_name,t->score[0],t->score[1],t->score[2],t->score[3],t->avgScore);
			break;
		}
		if(t->next==NULL)
			break;
		t=t->next;
	}
	if(flag==0)
		printf("Student not exit!\n");
}

void delete1()
{
	int id,flag=0;
	stu_info *t,*p;
	t=start;
	printf("Please enter the id of the student to delete:\n");
	scanf("%d",&id);
	book[id]=1;
	while(1)
	{
		if(t->id==id && t->id!=0)
		{
			flag++;
			p->next=t->next;
			t->next=NULL;
			free(t);
			break;
		}
		
		if(t->next==NULL)
			break;
		p=t;	
		t=t->next;	
	}
		if(flag==0 || id ==0)
			printf("Student not exit!\n");
		else 
			printf("Delete complete!\n");
}


void analyze()
{
	int num,max=-1,min=101,i=1,sum=0;
	stu_info *t;
	t=start;
	
	printf("Please input the course id you want to analyze:\n");
	scanf("%d",&num);
	num--;
	while(1)
	{
		
		if(t->id!=0)
		{
			if(t->score[num]>max)
				max=t->score[num];
			if(t->score[num]<min)
				min=t->score[num];
			sum+=t->score[num];
			i++;
		}
		
		if(t->next==NULL)
			break;
		t=t->next;
	}
	printf("Max=%d\n",max);
	printf("Min=%d\n",min);
	printf("Avg=%.2f\n",(float)(sum/i));

}

int mode()
{
	int mod;
	printf("1.Default Mode\n");
	printf("2.Sorted Mode\n");
	printf("Please choose mode:\n");
	scanf("%d",&mod);
	return mod;
}


int main()
{
	init();
	int mod;
	while(1)
	{
		mod=mode();
		if(mod==1){init1();break;}
		else if(mod==2){init2();Flag++;break;}
		printf("Wrong Selection!\n");
	}
	while(1)
	{
		
		switch(menu())
			{
				case 1:list();break;
				case 2:insert();break;
				case 3:delete1();break;
				case 4:search();break;
				case 5:analyze();break;
				case 6:return 0;
				default:printf("Input Wrong\n");break;
			}
			system("pause");
			system("cls");
	}
}
