/**************************************
 请使用Linux/UNIX/MacOS操作系统进行编译运行
 作者：Lidh菜鸟作业小组
 cw ldh xjh
 2018-12-25注释
***************************************/





#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "unistd.h"
#define MAXWORKER 25
#define NONE                 "\e[0m"
#define BLACK                "\e[0;30m"
#define L_BLACK              "\e[1;30m"
#define RED                  "\e[0;31m"
#define L_RED                "\e[1;31m"
#define GREEN                "\e[0;32m"
#define L_GREEN              "\e[1;32m"
#define BROWN                "\e[0;33m"
#define YELLOW               "\e[1;33m"
#define BLUE                 "\e[0;34m"
#define L_BLUE               "\e[1;34m"
#define PURPLE               "\e[0;35m"
#define L_PURPLE             "\e[1;35m"
#define CYAN                 "\e[0;36m"
#define L_CYAN               "\e[1;36m"
#define GRAY                 "\e[0;37m"
#define WHITE                "\e[1;37m"
#define BOLD                 "\e[1m"
#define UNDERLINE            "\e[4m"
#define BLINK                "\e[5m"
#define REVERSE              "\e[7m"
#define HIDE                 "\e[8m"
#define CLEAR                "\e[2J"
#define CLRLINE              "\r\e[K"
#define PREFIX               "[%2u]"
#define SUFFIX                __LINE__

using namespace std;
char root_name[]="roshan";
char root_pass[20]="admin10086";

struct workerinfo {
	char wkid[20];
	char wkname[20];
	int wksex;
	char wkbirth[13];
	char fstdate[13];
	int wkBMnum;
	char wkBM[50];
	int wkGWnum;
	char wkGW[50];
	double essential_salary;
	double GWsalary_level;
	char wkaddress[50];
	char wkphonenumber[20];
	char wkemail[20];
	double wksalary;
	double factsalary;
	double tax_rate;
	double extra_salary;
	char BMJJ[200];
	char GWZZ[200];
	char pswd[20];
}someworker[MAXWORKER];

FILE * fp = fopen("misinfo.dat", "a+b");
int  size = sizeof(struct workerinfo);
int  sizec = sizeof(char);
char update_time[]= "2019-1-8";
char last_update[]="2018-12-25";
char mis_version[]= "1.0.1 beta";

//foo 
void gui_main();
void add_worker(int i);
void id_checker(int i);
void graph_worker();
void output_info(int i , int n);
int findinfo_string(int i , char a[]);
void deleteworker();
void root_check();
void output_salary();
void changeinfo();
void BMinfo();
void GWinfo();
void searchforinfo();
void gui_guest();
//endfoo
int main( void )
{
	system("clear");
	system("figlet Lidh.team");
	system("cal");
	system("date");
	cout<<"\n➤ 回车键继续:";
	char tmp_char1 = getchar();
	system("clear");
	rewind(fp);
	for (int i = 0 ;i < MAXWORKER ; i++)
	fread(&someworker[i], size, 1, fp);
	printf(RED"➤ 🍎 此版本为界面升级版\n" );
	cout<<GREEN<<"➤ 版本号:"<<mis_version<<"\n";
	cout<<BLUE<<"➤ 更新时间:"<<update_time<<"\n";
	cout<<PURPLE<<"➤ 本次更新内容:\n";
	cout<<L_CYAN<<"⟲ 重制文件读写\n";
	cout<<GRAY<<"⤫ 删除冗余代码\n";
	cout<<GREEN<<"+ 增加界面美观度\n";
	cout<<NONE<<"➤ 输入s进入超级用户模式，输入其他进入访客模式:";
	char tmp_char0 = getchar();
	if(tmp_char0=='s') 
	{
		cout<<"➤ 管理员用户名:";
		char tmp_name[20];
		memset(tmp_name, 0, 20*sizec);
		cin>>tmp_name;
		if(strcmp(tmp_name, root_name)!=0)
		{
			cout<<RED"➤ ❌ 用户名错误\n"<<NONE;
			exit(1);
		}
		root_check();
		system("figlet welcome!");
		sleep(2);
		gui_main();
		}
	else gui_guest();	
	
}


//foos
void gui_main()
{
	system("clear");
	system("figlet version 1.0 beta");
		cout<<"|---------------------------------------------|"<<endl;
			cout<<"|=============================================|"<<endl;
			cout<<"|----------------工 资 管 理 系 统------------|"<<endl;
			cout<<"|----------------1. 部 门 信 息---------------|"<<endl;
			cout<<"|----------------2. 岗位信息及分级 -----------|"<<endl;
			cout<<"|----------------3. 员工基本信息 -------------|"<<endl;
			cout<<"|----------------4. 开 除 员 工---------------|"<<endl;
			cout<<"|----------------5. 工 资 信 息---------------|"<<endl;
			cout<<"|----------------6. 退 出 系 统---------------|"<<endl;
			cout<<"|=============================================|"<<endl;
			cout<<"|---------------------------------------------|"<<endl;
			cout<<"➤ 🍺 您选择:";		char tmp;
		cin>>tmp;
		while (tmp >'6' || tmp <'1'){
			cout<<"➤ ❌ 输入错误 ["<<tmp<<"]不是一个合法的选项\n";
			cout<<"➤ 🍺 请重新输入:";
			cin>>tmp;
		}
		cout<<"➤ 🍻输入正确 "<<"["<<tmp<<"]\n";
		fflush(stdin);
		switch (tmp) {
			case '1':
				{
				BMinfo();
				}break;
			case '2':
				{
				GWinfo();
				}break;
			case '3':
				{
				graph_worker();	
				}break;
			case '4':
				{
//				root_check();
				deleteworker();		
				}break;
			case '5':
				{
				output_salary();	
				}break;
			case '6':
				{
				fclose(fp);
				exit(0);	
				}break;	
		}
		
}

void addinfo(int n)
	{
//		root_check();
		int test = 0;
		for(int i= 0 ; test < n && i < MAXWORKER  ; i++)
		{
			if (someworker[i].wkid[0] !='\0' ) 
				continue;
			memset(someworker[i].wkid,0,20*sizeof(char));
			id_checker(i);
			std::cout<<"➤ 请输入姓名:(请使用拼音):";
			memset(someworker[i].wkname,0,20*sizeof(char));
			std::cin>>someworker[i].wkname;
			std::cout<<"➤ 请输入性别: 0或1(分别代表男/女)";
			char tmp;
			cin>>tmp;
			while (tmp >'1' || tmp <'0') {
				cout<<"➤ ❌ 输入错误 请检查并重新输入:";
				cin>>tmp;
			}
			someworker[i].wksex = tmp -'0';	
			std::cout<<"➤ 请输入员工生日  年-月-日:";
			memset(someworker[i].wkbirth,0,13*sizeof(char));
			std::cin>>someworker[i].wkbirth;
			std::cout<<"➤ 请输入员工入职日期  年-月-日:";
			memset(someworker[i].fstdate,0,13*sizeof(char));
			std::cin>>someworker[i].fstdate;
			std::cout<<"➤ 请输入员工部门编号:";
			memset(someworker[i].wkBM,0,50*sizeof(char));
			memset(someworker[i].wkGW,0,50*sizeof(char));
			memset(someworker[i].wkemail,0,20*sizeof(char));
			memset(someworker[i].wkaddress,0,50*sizeof(char));
			memset(someworker[i].wkphonenumber,0,20*sizeof(char));
			std::cin>>someworker[i].wkBMnum;
			std::cout<<"➤ 请输入员工部门名称:";
			std::cin>>someworker[i].wkBM;
			std::cout<<"➤ 请输入员工岗位编号 (岗位编号代表岗位等级 由低到高 最低为1) : ";
			std::cin>>someworker[i].wkGWnum;
			std::cout<<"➤ 请输入员工岗位名称:";
			std::cin>>someworker[i].wkGW;
			std::cout<<"➤ 请输入岗位基本工资:";
			std::cin>>someworker[i].essential_salary;
			std::cout<<"➤ 请输入岗位工资系数:";
			std::cin>>someworker[i].GWsalary_level;
			std::cout<<"➤ 请输入个人税率:(如10%即输入0.1)";
			std::cin>>someworker[i].tax_rate;
			std::cout<<"➤ 请输入奖金和加班费的和:(额外工资)";
			std::cin>>someworker[i].extra_salary;
			std::cout<<"➤ 请输入员工家庭地址:";
			std::cin>>someworker[i].wkaddress;
			std::cout<<"➤ 请输入员工电话:";
			std::cin>>someworker[i].wkphonenumber;
			std::cout<<"➤ 请输入员工工作邮箱:";
			std::cin>>someworker[i].wkemail;
			std::cout<<"➤ 请输入员工密码:";
			memset(someworker[i].pswd, 0, 20*sizeof(char));
			std::cin>>someworker[i].pswd;
			someworker[i].wksalary = someworker[i].essential_salary * someworker[i].GWsalary_level + someworker[i].extra_salary;
			someworker[i].factsalary = someworker[i].wksalary * (0.75 - someworker[i].tax_rate) - 2;
			std::cout<<"➤ 🍻\n";
			sleep(1);
			test++;
		}
		fclose(fp);
		fp = fopen("misinfo.dat", "wb+");
		rewind(fp);
		for (int i = 0;i< MAXWORKER; i++)  {
			fwrite(&someworker[i], size, 1, fp);
		}
		fclose(fp);
		fp =fopen("misinfo.dat", "a+b");
}

void id_checker(int i)
{
	label1: char tempid[20];
	memset(tempid, 0, 20*sizeof(char));
	std::cout<<"➤ 🍺请输入工号:";
	std::cin>>tempid;
	for(int c = 0; c < MAXWORKER ; c++)
	{
		if(c == i) continue;
		if(someworker[c].wkid[0]=='\0')
		continue;
		if(strcmp(someworker[c].wkid,tempid)==0)
		{
			std::cout<<"➤ ❌工号重复！请重新输入!\n";
			goto label1;
		}
	}
	strcpy(someworker[i].wkid, tempid);
	std::cout<<"➤ 🍻输入成功！工号:"<<someworker[i].wkid<<"\n";		
}

void graph_worker()
{
	system("clear");
	std::cout<<"➤					员工基本信息\n";
	int count2 = 0;
	for (int i = 0 ; i < MAXWORKER ; i++)
	if (someworker[i].wkid[0]!='\0') count2++;
	std::cout<<"➤		目前有"<<count2<<"个员工\n";
	std::cout<<"➤		1.增加员工信息\n";
	std::cout<<"➤		2.浏览全部员工信息\n";
	std::cout<<"➤		3.查找员工信息\n";
	std::cout<<"➤		4.修改员工信息\n";
	std::cout<<"➤		0.退出到上一层\n";
	std::cout<<"\n";
	char choose;
	cout<<"➤ 🍺请选择:";
	cin>>choose;
	while (choose < '0' || choose > '4')
	{
		cout<<"➤ ❌ 输入错误 ["<<choose<<"]不是合法选项\n";
		cout<<"➤ 🍺 请重新输入:";
		cin>>choose;
	}
	cout<<"➤ 🍻\n";
	fflush(stdin);
	switch (choose) {
		case '1':{
			std::cout<<"➤ 请输入需要增加的员工数:"<<NONE;
			int n; std::cin>>n;
			addinfo(n);
		}break;
		case '0':{
			gui_main();
		}break;
		case '2':{
			system("clear");
			cout<<"➤		🍺 请选择模式\n";
			cout<<"➤		1.审查模式\n";
			cout<<"➤		2.浏览模式\n";
			char tmp_char1;
			cout<<"➤ 🍺您选择:";
			cin>>tmp_char1;
			while(tmp_char1 > '2' || tmp_char1 < '1')
			{
				cout<<"➤ ❌ 输入错误\n➤ 您选择:";
				cin>>tmp_char1;
			}
			cout << "➤ 🍻\n";		
			for(int i=0;i < MAXWORKER; i++)
			{
				if(someworker[i].wkid[0] =='\0') continue;
				 std::cout<<"➤\n";
				for(int i2=1;i2<=18;i2++)
				{
				output_info(i, i2);
				}
				std::cout<<"➤\n";
				if (tmp_char1 == '1') sleep(3);
			}
		}break;	
		case '3':{
			searchforinfo();
			
		}break;
		case '4':{
			changeinfo();
		}break;
	}
	cout<<"➤ 🍺 输入任意字符继续(回车键除外):";
	char t;
	cin>>t;
	gui_main();
}

void output_info(int i,int n) //i为第几个员工、n为第几项信息
	{
		switch(n)
		{
			
				case 1:{
					std::cout<<"➤ 工号:";
					puts(someworker[i].wkid);
					}
					break;
				case 2:{
					std::cout<<"➤ 姓名:";
					puts(someworker[i].wkname);
				//std::cout<<strlen(someworker[i].wkname)<<"\n";
					}break;
				case 3:{
					std::cout<<"➤ 性别:";
					if(someworker[i].wksex==0)
					std::cout<<"男\n";
					else 
					std::cout<<"女\n";
				}
				break;
				case 4:
					{
						std::cout<<"➤ 生日:";
						puts(someworker[i].wkbirth);
					}break;
				case 5:
					{
						std::cout<<"➤ 入职时间:";
						puts(someworker[i].fstdate);
						}break;
				case 6:{
					std::cout<<"➤ 部门编号:";
					std::cout<<someworker[i].wkBMnum<<"\n";}break;
				case 7 :{
					std::cout<<"➤ 部门名称:";
					puts(someworker[i].wkBM);}
				 break;
				case 8:{
					std::cout<<"➤ 岗位编号(等级):";
					std::cout<<someworker[i].wkGWnum<<"\n";}
				break;
				case 9:{
					std::cout<<"➤ 岗位名称:";
					puts(someworker[i].wkGW);}break;
				case 10:{
					std::cout<<"➤ 员工地址:";
					puts(someworker[i].wkaddress);}
				break;
				case 11:{
					std::cout<<"➤ 电话号码:";
					std::cout<<someworker[i].wkphonenumber<<"\n";} break;
				case 12:{
					std::cout<<"➤ 电子邮箱:";
					puts(someworker[i].wkemail);}break;
				case 13:{
					std::cout<<"➤ 岗位基本工资:";
					std::cout<<someworker[i].essential_salary<<"\n";
				}break;
				case 14:{
					std::cout<<"➤ 岗位工资系数：";
					std::cout<<someworker[i].GWsalary_level<<"\n";
				}break;
				case 15:{
					std::cout<<"➤ 个人税率:"<<someworker[i].tax_rate<<"\n";
				}break;
				case 16:{
					std::cout<<"➤ 额外工资:"<<someworker[i].extra_salary<<"\n";
				}break;
				case 17:{
					std::cout<<"➤ 应发工资:"<<someworker[i].wksalary<<"\n";
					std::cout<<"➤ 实发工资:"<<someworker[i].factsalary<<"\n";
				}break;
				case 18:{
					std::cout<<"➤ 员工密码:"<<someworker[i].pswd<<"\n";
				}break;		
		}
}

int findinfo_string(int i,char info[]) 
{
	int count4 = MAXWORKER;
	int found = 0;
	switch(i)				
	{
		case 1:{
		for(int i2=0 ; i2< count4 ; i2++)
		{
			if(someworker[i2].wkid[0]=='\0') continue;
			if( strcmp(info,someworker[i2].wkid)==0 )
			{
			std::cout<<"➤🍻\n";
			std::cout<<"➤		姓名:"<<someworker[i2].wkname<<"\n";
			std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
			found = 1;
			return i2;		
			}
		} 
		if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
		}break;
		case 2:	{
		for(int i2=0;i2<count4;i2++)
		{
			if(someworker[i2].wkid[0]=='\0') continue;
			if(strcmp(info,someworker[i2].wkname)==0)
			{
				cout<<"➤ 🍻\n";
				std::cout<<"➤		姓名:"<<someworker[i2].wkname<<"\n";
				std::cout<<"➤		工号："<<someworker[i2].wkid<<"\n";
				found = 1;
			}
		}
		if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
				}break;
		case 4:{
			
			for(int i2=0;i2<count4;i2++)
			{
				if(someworker[i2].wkid[0]=='\0') continue;
				if(strcmp(info,someworker[i2].wkbirth)==0)
				{
					cout<<"➤ 🍻\n";
					std::cout<<"➤		找到生日为："<<info<<"的职工\n";
					std::cout<<"➤		"<<someworker[i2].wkname<<"\n";
					std::cout<<"➤		该员工工号:"<<someworker[i2].wkid<<"\n";
					found = 1;
				}
			}
			if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;		
			}break;
			case 5:{
				for(int i2=0;i2<count4;i2++)
				{
					if(someworker[i2].wkid[0]=='\0') continue;
					if(strcmp(info,someworker[i2].fstdate)==0)
					{
						cout<<"➤ 🍻\n";
						std::cout<<"➤		找到入职时间为:"<<info<<"的员工\n";
						std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
						std::cout<<"➤		姓名:"<<someworker[i2].wkname<<"\n";
						found = 1;
					}
				}
				if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
			}break;
				case 7:
					{
					std::cout<<"➤		部门："<<info<<"\n";
					for(int i2=0;i2<count4;i2++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(strcmp(info,someworker[i2].wkBM)==0)
						{
							cout<<"➤ 🍻\n";
							std::cout<<"➤		姓名"<<someworker[i2].wkname<<"\n";
						std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";	
						found = 1;
						return i2;
						}
					}
				if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
					}break;
				case 9:
					{
					std::cout<<"➤		岗位："<<info<<std::endl;
					int i2;
					for( i2=0;i2<count4;i2++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(strcmp(info, someworker[i2].wkGW)==0)
						{
							cout<<"➤ 🍻\n";
							std::cout<<"➤		姓名:"<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
							found =1 ;
						}
					}
					if (found== 1)return i2;
				if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
				}break;
				case 10:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(strcmp(info, someworker[i2].wkaddress)==0)
						{
							cout<<"➤ 🍻\n";
							std::cout<<"➤		姓名:"<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}
					}
					if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;					}break;
				case 11:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(strcmp(info, someworker[i2].wkphonenumber)==0)
						{
							cout<<"➤ 🍻\n";
							std::cout<<"➤		姓名:"<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}
						}
						if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
					}break;
				case 12:
					{
					for(int i2=0;i2<count4;i2++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(strcmp(info, someworker[i2].wkemail)==0)
						{
							cout<<"➤ 🍻\n";
							std::cout<<"➤		"<<info<<std::endl;
							std::cout<<"➤		姓名:"<<someworker[i2].wkname;
							std::cout<<"\n";
							std::cout<<"➤		工号:"<<someworker[i2].wkid<<"\n";
							found = 1;
							return i2;
						}		
					}
					if(found == 0) std::cout<<RED<<"➤ ❌ 未找到相应信息.\n"<<NONE;
					}break;
				}
				return -1;
}

void deleteworker()
{
	std::cout<<"➤ 请输入要删除员工的工号:";
	char info[20];
	memset(info, 0, 20*sizeof(char));
	std::cin>>info;
	rewind(fp);
			int findyes = 0;
			for(int i2=0;i2< MAXWORKER ;i2++)
			{
				if(strcmp(info,someworker[i2].wkid)==0)
				{
		std::cout<<"➤ "<<someworker[i2].wkname<<"\n";
				std::cout<<"➤	工号:"<<someworker[i2].wkid<<"\n";
				std::cout<<"➤	姓名:"<<someworker[i2].wkname<<"\n";
				memset(someworker[i2].wkid, 0, 20*sizeof(char));
				memset(someworker[i2].wkname, 0, 20*sizeof(char));
				memset(someworker[i2].wkbirth, 0, 13*sizeof(char));
				memset(someworker[i2].fstdate, 0, 13*sizeof(char));
				memset(someworker[i2].wkBM, 0, 50*sizeof(char));
				memset(someworker[i2].wkGW, 0, 50*sizeof(char));
				memset(someworker[i2].wkaddress, 0, 50*sizeof(char));
				memset(someworker[i2].wkphonenumber, 0, 20*sizeof(char));
				memset(someworker[i2].wkemail, 0, 20*sizeof(char));
				memset(someworker[i2].BMJJ, 0, 200*sizeof(char));
				memset(someworker[i2].GWZZ,0,200*sizec);
				memset(someworker[i2].pswd, 0, 20*sizeof(char));
				someworker[i2].wksalary = 0;
				someworker[i2].extra_salary = 0;
				someworker[i2].tax_rate = 0;
				someworker[i2].factsalary = 0;
				someworker[i2].wkBMnum = 0;
				someworker[i2].wkGWnum = 0;
				findyes = 1;
				}
			}
			if(findyes == 0) std::cout<<RED<<"➤ 未找到工号为"<<info<<"的员工!\n"<<NONE;
			else std::cout<<GREEN<<"➤ 删除成功!\n"<<NONE;
			fclose(fp);
			fp = fopen("misinfo.dat", "wb+");
			rewind(fp);
		for(int i=0;i< MAXWORKER ;i++)
		{
			fwrite(&someworker[i], size, 1, fp);
		}
		fclose(fp);
		fp = fopen("misinfo.dat","a+b");
		fflush(stdin);
		sleep(3);
		gui_main();
}

void root_check()
{
	fflush(stdin);
	char tmp_pass[20];
	char *p;
	p = getpass("➤ 请输入管理员密码:");
	strcpy(tmp_pass, p);
if(strcmp(root_pass,tmp_pass)==0) ;
else {
	cout<<RED<<"❌ 密码错误\n"<<NONE;
	 sleep(1); 
	exit(0);
}
		
}

void output_salary()
{
	system("clear");
	std::cout<<GREEN<<"➤			1.审查模式\n";
	std::cout<<NONE<<"➤			2.浏览模式\n";
	char c;
	cout<<"➤ 🍺请选择:";
	cin>>c;
	fflush(stdin);
	while (c >'2' || c <'1')
	{
		cout<<"➤ ❌ 输入错误\n➤ 请重新输入:";
		cin>>c;
	}
	for(int i = 0 ; i < MAXWORKER ; i++)
	{
		if(someworker[i].wkid[0]=='\0') continue;
		output_info(i, 1);
		output_info(i, 2);
		output_info(i, 17);
		std::cout<<"➤ 🍻\n";
		if(c == '1') sleep(1);
	}
	cout<<"➤ 🍺 输入任意字符继续(回车键除外):";
	char t;
	cin >> t;
	gui_main();
}

void changeinfo()
{
	system("clear");
	std::cout<<"---                 1.修改工号\n";
	std::cout<<"---                 2.修改姓名\n";
	std::cout<<"---                 3.修改生日\n";
	std::cout<<"---                 4.修改入职日期\n";
	std::cout<<"---                 5.修改岗位\n";
	std::cout<<"---                 6.修改岗位编号(等级)\n";
	std::cout<<"---                 7.修改部门\n";
	std::cout<<"---                 8.修改部门编号\n";
	std::cout<<"---                 9.修改电话\n";
	std::cout<<"---                 10.修改电子邮箱\n";
	std::cout<<"---                 11.修改住址\n";
	std::cout<<"---                 12.修改岗位基本工资\n";
	std::cout<<"---                 13.修改岗位工资系数\n";
	std::cout<<"---                 14.修改个人税率\n";
	std::cout<<"---                 15.修改额外工资\n";
	std::cout<<"---                 16.修改密码\n";
	std::cout<<"---                 0.返回上一层\n";
	std::cout<<"➤ 🍺 请选择:";
	int mode = 0 ;
	std::cin>>mode;
	if (mode == 0 )graph_worker();
	std::cout<<"➤ 🍻 请输入即将操作的工号：";
	char info[20];
	memset(info, 0, 20*sizeof(char));
	std::cin>>info;
	int test = findinfo_string(1, info);
	if(test == -1)
	{
		std::cout<<RED"➤ ❌ 未找到工号！\n\n"<<NONE;
		graph_worker();
	}
//	root_check();
	switch(mode)
	{
		case 1:
			{
			std::cout<<"➤ 🍺 请输入新的工号:";
			char newid[20];
			memset(newid, 0, 20*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkid, newid);
		std::cout<<GREEN<<"➤ 🍻 修改成功！"<<"工号:"<<someworker[test].wkid<<"\n"<<NONE;
			}break;
		case 2:
			{
			std::cout<<"➤ 🍺 请输入新的姓名:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkname, newid);
	std::cout<<GREEN"➤ 🍻 修改成功！"<<"姓名:"<<someworker[test].wkname<<"\n"<<NONE;			
			}break;
		case 3:
			{
			std::cout<<"➤ 🍺 请输入新的生日:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkbirth, newid);
		std::cout<<GREEN<<"➤ 🍻 修改成功！"<<"生日:"<<someworker[test].wkbirth<<"\n"<<NONE;
			}break;
		case 4:
			{
			std::cout<<"➤ 🍺请输入新的入职日期:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].fstdate, newid);
		std::cout<<GREEN<<"➤ 🍻修改成功！"<<"入职日期:"<<someworker[test].fstdate<<"\n"<<NONE;	
			}break;
		case 5:
			{
			std::cout<<"➤ 🍺请输入新的岗位:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkGW, newid);
		std::cout<<GREEN<<"➤ 🍻 修改成功！"<<"岗位:"<<someworker[test].wkGW<<"\n"<<NONE;
			}break;
		case 6:
			{
			std::cout<<"➤ 🍺 请输入新的岗位编号:";
			std::cin>>someworker[test].wkGWnum;
			std::cout<<GREEN<<"➤ 🍻 修改成功！岗位编号:"<<someworker[test].wkGWnum<<"\n"<<NONE;	
			}break;
		case 7:
			{
			std::cout<<"➤ 🍺请输入新的部门:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkBM, newid);
		std::cout<<GREEN"➤ 🍻 修改成功！"<<"部门:"<<someworker[test].wkBM<<"\n"<<NONE;	
			}break;
		case 8:
			{
			std::cout<<"➤ 🍺 请输入新的部门编号:";
			std::cin>>someworker[test].wkBMnum;
			std::cout<<GREEN<<"➤ 🍻 修改成功！部门编号:"<<someworker[test].wkBMnum<<"\n"<<NONE;
			}break;
		case 9:
			{
			std::cout<<"➤ 🍺 请输入新的电话:";
			char newid[200];
			memset(newid, 0, 200*sizeof(char));
			std::cin>>newid;
			strcpy(someworker[test].wkphonenumber, newid);
		std::cout<<GREEN<<"➤ 🍻 修改成功！"<<"电话:"<<someworker[test].wkphonenumber<<"\n"<<NONE;		
			}break;
		case 10:
			{
				std::cout<<"➤ 🍺 请输入新的电子邮箱:";
				char newid[200];
				memset(newid, 0, 200*sizeof(char));
				std::cin>>newid;
				strcpy(someworker[test].wkemail, newid);
			std::cout<<GREEN"➤ 🍻 修改成功！"<<"部门:"<<someworker[test].wkemail<<"\n"<<NONE;	
			}break;
		case 11:
			{
				std::cout<<"➤ 🍺 请输入新的住址:";
				char newid[200];
				memset(newid, 0, 200*sizeof(char));
				std::cin>>newid;
				strcpy(someworker[test].wkaddress, newid);
			std::cout<<GREEN"➤ 🍻 修改成功！"<<"部门:"<<someworker[test].wkaddress<<"\n"<<NONE;	
			}break;
		case 12:{
				std::cout<<"➤ 🍺 请输入新的岗位基本工资:";
				std::cin>>someworker[test].essential_salary;
				std::cout<<GREEN<<"➤ 🍻 修改成功！"<<"岗位基本工资:"<<someworker[test].essential_salary<<"\n"<<NONE;
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		case 13:{
				std::cout<<"➤ 🍺 请输入新的岗位工资系数:";
				std::cin>>someworker[test].GWsalary_level;
				std::cout<<GREEN"➤ 🍻 修改成功！岗位工资系数:"<<someworker[test].GWsalary_level<<"\n"<<NONE;
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		case 14:
			{
				std::cout<<"➤ 🍺 请输入新的个人税率:";
				std::cin>>someworker[test].tax_rate;
				std::cout<<GREEN<<"➤ 🍻 修改成功！个人税率:"<<someworker[test].tax_rate<<"\n"<<NONE;
				someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
				someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
			}break;
		case 15:{
			std::cout<<"➤ 🍺 请输入新的额外工资:";
			std::cin>>someworker[test].extra_salary;
			std::cout<<GREEN"➤ 🍻 修改成功！额外工资:"<<someworker[test].extra_salary<<"\n"<<NONE;
			someworker[test].wksalary = someworker[test].essential_salary * someworker[test].GWsalary_level + someworker[test].extra_salary;
			someworker[test].factsalary = someworker[test].wksalary * (0.75 - someworker[test].tax_rate) - 2;
		}break;
		case 16:{
			std::cout<<"➤ 🍺 请输入新的员工密码:";
			memset(someworker[test].pswd, 0, 20*sizeof(char));
			std::cin>>someworker[test].pswd;
		std::cout<<GREEN<<"➤ 🍻 修改成功！新的员工密码:"<<someworker[test].pswd<<"\n"<<NONE;
		}break;
		default :
			{
				std::cout<<RED"➤ ❌ 请检查您的输入是否合法\n"<<NONE;
			}break;
	}
	fclose(fp);
	fp = fopen("misinfo.dat", "wb+");
	rewind(fp);
for(int i=0;i<MAXWORKER;i++)
{
	fwrite(&someworker[i], size, 1, fp);
}
fclose(fp);
fp = fopen("misinfo.dat","a+b");
system("clear");
graph_worker();
}

void BMinfo()
{	
	int c = 0;
	for(int i = 0 ;i < MAXWORKER ;i++)
	{
		if(someworker[i].wkid[0] == '\0')
		continue;
		if(someworker[i].wkBMnum > c) c = someworker[i].wkBMnum;
	}
	system("clear");
	std::cout<<"➤ 🍻\n";
	std::cout<<"➤ ✔️ 现有"<<RED<<c<<NONE<<"个部门\n";
	std::cout<<"---               1.更改部门简介\n";
	std::cout<<"---               2.显示部门简介\n";
	std::cout<<"---               3.浏览部门信息\n";
	std::cout<<"---               0.返回上一层\n";
	int mode;
	std::cout<<"➤ 🍺 请输入选项：";
	std::cin>>mode;
	switch (mode)
	{
		case 0 :
			{
				gui_main();
			}break;
		case 1 :
			{
//				root_check();
				std::cout<<"➤ 🍺 请输入要修改简介的部门编号:";
				int a = 0;
				std::cin>>a;
			if (a <= 0 || a > c) 
			{
			std::cout<<RED"➤ ❗️ 输入错误！目前只有"<<c<<"个部门!\n"<<NONE;
			BMinfo();
			}
			for(int i =0 ;i< MAXWORKER ; i++)
			{
				if(someworker[i].wkBMnum == a)
				{
				std::cout<<"➤ 部门:"<<someworker[i].wkBM<<"\n";
				break;
				}
			}
			std::cout<<"➤ 🍺 请输入部门简介(用英文或者拼音):";
			char tempjj[200];
			memset(tempjj, 0, 200*sizeof(char));
			std::cin>>tempjj;
			for(int i = 0; i< MAXWORKER  ;i++)
			{
				if(someworker[i].wkid[0]=='\0') continue;
				if(someworker[i].wkBMnum == a )
				strcpy(someworker[i].BMJJ, tempjj);
			}
			}break;
		case 2 :
			{
			int putter = 0;
			if (c == 0)
			{
				cout<<RED<<"➤ ❗️ 当前暂无部门\n"<<NONE;
				sleep(2);
				BMinfo();
			}
			std::cout<<"➤ 请输入要显示简介的部门编号：";
			std::cin>>putter;
			while(putter <= 0 || putter > c)
			{
				std::cout<<RED<<"➤ ❌ 输入错误！请重新输入:"<<NONE;
				std::cin>>putter;
			}
			for(int i =0 ;i < MAXWORKER ;i++)
			{
				if(someworker[i].wkid[0] == '\0') continue;
				if(someworker[i].wkBMnum == putter)
				{
					if(someworker[i].BMJJ[0]== '\0')
					std::cout<<RED<<"➤ ❗️ 该部门暂无部门简介!\n"<<NONE;
					std::cout<<someworker[i].wkBM<<"\n";
					std::cout<<someworker[i].BMJJ<<"\n";
					sleep(3);
					break;
				}
			}
			BMinfo();
			}break;
			case 3:
				{
				for(int i =1; i <= c ;i++)
				{
					for(int i2=0 ; i2< MAXWORKER ;i2 ++)
					{
						if(someworker[i2].wkid[0]=='\0') continue;
						if(someworker[i2].wkBMnum == i)
						{
							std::cout<<GREEN<<"➤ 部门编号:"<<someworker[i2].wkBMnum<<"\n"<<NONE;
							std::cout<<"➤ 部门名称:"<<someworker[i2].wkBM<<"\n";
							std::cout<<"➤ 部门简介:"<<someworker[i2].BMJJ;
							if(someworker[i2].BMJJ[0]=='\0') std::cout<<" 暂无";
							std::cout<<"\n";
							break;
						}
					}
				}
				sleep(5);
					}break;
				}
	fclose(fp);
	fp = fopen("misinfo.dat", "wb+");
	rewind(fp);
for(int i=0;i< MAXWORKER ;i++)
{
	fwrite(&someworker[i], size, 1, fp);
}
fclose(fp);
fp = fopen("misinfo.dat","a+b");
BMinfo();
}

void GWinfo()
{
	fflush(stdin);
	// system("clear");
	std::cout<<"➤ 🍻\n";
	std::cout<<"---                1.搜索岗位信息\n";
	std::cout<<"---                2.修改岗位职责\n";
	std::cout<<"---                3.显示岗位职责\n";
	std::cout<<"---                0.回到主菜单\n";
	int mode = 0;
	std::cout<<"➤ 🍺 请选择:";
	std::cin>>mode;
	switch (mode)
	{
		case 0 :
			{
				gui_main();
			}break;
		case 1 :
			{
				std::cout<<"➤ 请输入该岗位名称:";
				char tempGW[50];
				memset(tempGW, 0, 50*sizeof(char));
				std::cin>>tempGW;
				 int test = findinfo_string(9, tempGW);
				if(test == -1)
				{
				 std::cout<<"➤ ❗️ 未找到岗位:";
				 std::cout<<tempGW<<"\n";
				sleep(2);
				GWinfo();
				}	
			}break;
		case 2 :
			{
			std::cout<<"➤ 请输入要修改简介的岗位名称:";
			char tempGW[50];
			memset(tempGW, 0, 50*sizeof(char));
			std::cin>>tempGW;
			int test = findinfo_string(9, tempGW);
			if(test == -1)
			{
				std::cout<<"➤ ❗️ 无此岗位！\n";
				sleep(2);
				GWinfo();
			}
			std::cout<<"➤ 🍺 请输入岗位职责:";
			char tempZZ[200];
			memset(tempZZ, 0, 200*sizeof(char));
			std::cin>>tempZZ;
			for(int i = 0; i< MAXWORKER ;  i++)
			{
				if(someworker[i].wkid[0]=='\0')
				continue;
				if(strcmp(someworker[i].wkGW,tempGW)==0)
				strcpy(someworker[i].GWZZ,tempZZ);
			}
			}break;
		case 3:
			{
			std::cout<<"➤ 🍺 请输入要查看职责的岗位:";
			char tempGW[50];
			memset(tempGW,0,50*sizeof(char));
			std::cin>>tempGW;
			int test = findinfo_string(9, tempGW);
			if( test == -1)
			{
				std::cout<<"➤ ❗️ 无此岗位!\n";
				sleep(2);
				GWinfo();
			}
			for(int i = 0; i< MAXWORKER ;  i++)
			{
				if(someworker[i].wkid[0]=='\0')
				continue;
				if(strcmp(someworker[i].wkGW,tempGW)==0)
				{
				if(someworker[i].GWZZ[0]=='\0')
				{
				std::cout<<"➤ ❗️ 暂无职责信息！";
				sleep(2);
				break;
				}
				std::cout<<"➤ 岗位职责:"<<someworker[i].GWZZ<<"\n";
				sleep(5);
				break;
				}
			}
			}break;
	}
	fclose(fp);
	fp = fopen("misinfo.dat", "wb+");
	rewind(fp);
	for(int i=0;i< MAXWORKER ;i++)
	{
		fwrite(&someworker[i], size, 1, fp);
	}
	fclose(fp);
	fp = fopen("misinfo.dat","a+b");
	GWinfo();
}

void searchforinfo()
{
	cout<<"➤  🍺\n";
	std::cout<<"---                 1.通过工号查找\n";
	std::cout<<"---                 2.通过姓名查找\n";
	std::cout<<"---                 5.通过入职日期查找(格式如2018-12-20)\n";
	std::cout<<"---                 7.通过部门名称查找\n";
	std::cout<<"---                 9.通过岗位名称查找\n";
	std::cout<<"---                 11.通过电话号码查找\n";
	int mode;
	std::cin>>mode;
	char info[50];
	memset(info, 0, 50*sizec);
	switch(mode)
	{
		case 1:
			{
				std::cout<<"➤ 请输入工号:";
				memset(info, 0, 20*sizeof(char));
				std::cin>>info;
				int i = findinfo_string(1, info);
				if (i != -1)
				for(int c=1;c<=18;c++) output_info(i, c);
				sleep(3);
			}break;
		case 2:
			{
				std::cout<<"➤ 请输入姓名:";
				memset(info,0,20*sizeof(char));
				std::cin>>info;
				findinfo_string(2,info);
				sleep(3);
			}break;
		case 5:
			{
				std::cout<<"➤ 请输入入职日期:";
				memset(info, 0, 13*sizeof(char));
				std::cin>>info;
				findinfo_string(5, info);
				sleep(3);
			}break;
		case 7:
			{
				std::cout<<"➤ 请输入部门名称:";
				memset(info,0,50*sizeof(char));
				std::cin>>info;
				findinfo_string(7, info);
				sleep(3);
			}break;
		case 9:
			{
				std::cout<<"➤ 请输入岗位名称:";
				memset(info, 0, 50*sizeof(char));
				std::cin>>info;
				findinfo_string(9, info);
				sleep(3);	
			}break;
		case 11:
			{
				std::cout<<"➤ 请输入电话号码:";
				memset(info, 0, 20*sizeof(char));
				std::cin>>info;
				findinfo_string(11,info);
				sleep(3);	
			}break;
	}
	graph_worker();
}

void gui_guest()
{
	std::cout<<"➤ 🍻 请输入即将查询的工号：";
	char info[20];
	memset(info, 0, 20*sizeof(char));
	std::cin>>info;
	int test = findinfo_string(1, info);
	if(test == -1)
	{
		std::cout<<RED"➤ ❌ 未找到工号！\n\n"<<NONE;
		exit(0);
	}
	char pswdTmp[20];
	
	char *p;
	p = getpass("➤ ❗️请输入该员工的个人密码:");
	strcpy(pswdTmp, p);
	if(strcmp(someworker[test].pswd, pswdTmp)==0)
	{
	for(int i =1 ;i <=18;i++) output_info(test, i);
	}
	else
	{
		std::cout<<"➤ ❌ 密码错误！\n\n";
		exit(0);
	}

}





