#include "time.h"
#include <stdlib.h> 
#include "iostream"
#include "string.h"
#include <fstream>
#include <cstring>
#include <algorithm> 
using namespace std;

string week(int i)
{
string day; 
switch(i)
{case 0:day="Mon.";break;
case 1:day="Tues.";break;
case 2:day="Wed.";break;
case 3:day="Thur.";break;
case 4:day="Fri.";break;
case 5:day="Sat.";break;
case 6:day="Sun.";break;} 
return day;
}

string timechoose(int i)
{
string timec; 
switch(i)
{case 0:timec="8:00~10:00";break;
case 1:timec="10:00~12:00";break;
case 2:timec="12:00~14:00";break;
case 3:timec="14:00~16:00";break;
case 4:timec="16:00~18:00";break;
case 5:timec="18:00~20:00";break;
case 6:timec="20:00~22:00";break;
case 7:timec="22:00~00:00";break;
} 
return timec;
}

string department(int i)
{
string depar;
switch(i)
{case 0:depar="D001";break;
case 1:depar="D002";break;
case 2:depar="D003";break;
case 3:depar="D004";break;
case 4:depar="D005";break;
case 5:depar="D006";break;
case 6:depar="D007";break;
case 7:depar="D008";break;
case 8:depar="D009";break;
case 9:depar="D010";break;
case 10:depar="D011";break;
case 11:depar="D012";break;
case 12:depar="D013";break;
case 13:depar="D014";break;
case 14:depar="D015";break;
case 15:depar="D016";break;
case 16:depar="D017";break;
case 17:depar="D018";break;
case 18:depar="D019";break;
case 19:depar="D020";break;
return depar;
}
}

string tags(int i)
{
string tag;
switch(i)
{case 0:tag="film";break;
case 1:tag="reading";break;
case 2:tag="basketball";break;
case 3:tag="programing";break;
case 4:tag="PS";break;
case 5:tag="dance";break;
case 6:tag="sing";break;
case 7:tag="English";break;
case 8:tag="Japanese";break;
case 9:tag="football";break;
case 10:tag="music";break;
case 11:tag="video";break;
case 12:tag="chess";break;
case 13:tag="teaism";break;
case 14:tag="climbing";break;
case 15:tag="bodybuilding";break;
case 16:tag="philosophy";break;
case 17:tag="painting";break;
case 18:tag="handwriting";break;
case 19:tag="acting";break;
return tag;
}
}

int main()
{
	string deno[20],detag[20][10],sno[300],stag[300][10],sapp[300][5];
	//deno存储20个部门编号，deno[0]=D001
	//detag存储对应20个部门的兴趣标签,detag[0][0]表示D001部门的第一个兴趣标签
	//sno存储300个学生学号,sno[0]=031502001
	//stag存储对应300个学生的兴趣标签,stag[0][0]表示031502001学生的第一个兴趣标签
	//sapp存储对应300个学生的部门志愿，sapp[0][0]表示031502001学生的第一志愿 
	int delim[20]; //delim对应20个部门招新人数
	
	int i=300,k=20,m=0,n=0,num,limit;
	string stuno="031502001";
	string day,timec,depar,tag;
	string event,deparno="D001";
	srand((unsigned)time(NULL));  
	freopen("input_data.txt" ,"w", stdout);
	printf("{\n\"student\":[\n");
/************************************************/ 
/*随机生成学生*/ 
/************************************************/ 
	while(i--)
	{
	num=rand()%13+2;
	cout<<'{'<<endl;
	printf("\"free_time\":[\n");
	while(num--)
	{
	day=week(rand()%7);	
	timec=timechoose(rand()%8);
	cout<<'"'<<day<<timec<<"\"";
	if(num!=0)
	cout<<','<<endl;
	}
	cout<<endl<<"],"<<endl;
/*************************************************/
	printf("\"student_no\":\"");
	cout<<stuno<<"\","<<endl;
	
	sno[m]=stuno;
	
	stuno[8]++;
	if(stuno[8]==58)
	{stuno[8]='0';
	stuno[7]++;
	}
	if(stuno[7]==58)
	{stuno[7]='0';
	stuno[6]++;
	}
/*************************************************/
	num=rand()%5;
	printf("\"applications_department\":[\n");
	while(num--)
	{
	depar=department(rand()%20);
	cout<<'"'<<depar<<"\"";
	
	sapp[m][n++]=depar;
	
	if(num!=0)
	cout<<','<<endl; 
	} 
	n=0;
	cout<<endl<<"],"<<endl;
/*************************************************/
	num=rand()%8+2;
	printf("\"tags\":[\n");
	while(num--)
	{
	tag=tags(rand()%20);
	cout<<'"'<<tag<<"\"";
	
	stag[m][n++]=tag;
	
	if(num!=0)
	cout<<','<<endl; 
	} 
	n=0;
	m++;
	cout<<endl<<"]"<<endl;
	cout<<'}'<<','<<endl;
}
cout<<"],"<<endl;    
m=0;
/*************************************************/
/*随机生成部门*/ 
/*************************************************/
	printf("{\n\"department\":[\n");
	
	while(k--)
	{
	cout<<'{'<<endl;
	printf("\"event_schedules\":[\n");
	num=rand()%3+2;
	while(num--)
	{
	day=week(rand()%7);	
	timec=timechoose(rand()%8);
	cout<<'"'<<day<<timec<<"\"";
	if(num!=0)
	cout<<','<<endl;
	}
	cout<<endl<<"],"<<endl;
/*************************************************/
	printf("\"member_limit\":");
	limit=rand()%5+10;
	cout<<limit<<","<<endl;
	
	delim[m]=limit;
/*************************************************/
	printf("\"department_no\":\n");
	cout<<'"'<<deparno<<"\"";
	
	deno[m]=deparno;
	
	deparno[3]++;
	if(deparno[3]==58)
	{deparno[3]='0';
	deparno[2]++;
	}
/*************************************************/
	num=rand()%8+2;
	printf("\"tags\":[\n");
	while(num--)
	{
	tag=tags(rand()%20);
	cout<<'"'<<tag<<"\"";
	
	detag[m][n++]=tag;
	
	if(num!=0)
	cout<<','<<endl; 
	}
	n=0; 
	cout<<endl<<']'<<endl;
	cout<<'}'<<','<<endl;
	m++;
}
cout<<']'<<endl;  
cout<<'}' <<endl;
fclose(stdout); 
return 0;
}

