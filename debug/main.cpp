/****************************************
* Author:LiuXL;				
* Description:This file is used to test a
function while developing.
****************************************/

#include "student.h"


/****************************************
* Author:SunZT;
* Function:altStudent();				
* Description:Alt info student.dat.
****************************************/
void altStudent(Student *stu)
{ 
	int i=0;
    int j=0;
	int m=0;
	float sum=0; 
	long lNo;
	char c;
	printf("\n 请输入要修改的学生学号:");
	scanf("%ld",&lNo); 
	for(i=0;(i<MAX_STU_NO) && (stu[i]!=NULL);i++) 
	{
	    if(strncmp(stu[i]->nu,lNo,11)==0)
		{ 
		    printf("\n 存在要修改的学生记录!");
			break; 
		}
	}
	if((i==MAX_STU_NO) || (stu[i]==NULL)) 
	{
		printf("\n 不存在要修改的学生记录!");
		return;
	}
    /*开始修改学生信息*/ 
	printf("\n********------------********** 这 是 要 修 改 的 记 录 吗?**********------------********\n"); 
	printf("| 学号 | 班级 | 姓名 | 性别 | 语文 | 数学 | 英语 | 政治 | 总分 |平均分|\n"); 
	printf("|-----------|------|------|------|------|------|------|------|--------|------|\n"); 
	printf("|%-12s|%-6s|%-6s|%-6s|%6d|%6d|%6d|%6d|%6d|%6.2f|\n",stuArray[i]->nu,stuAr ray[i]->cl,stuArray[i]->name,stuArray[i]->sex,stuArray[i]->score[0], stuArray[i]->score[1],stuArray[i]->score[2],stuArray[i]->score[3],stuArray[i]->sum,stuArray[i]>average);
	printf("\n********------------********************------------********\n");
	printf("你确定要修改该记录吗?Y or N\n"); 
	scanf("%s",&c); 
	if((c=='Y') || (c=='y'))
	{ 
		m=1;
	} 
	else
	{ 
		editmenu(stuArray);
	}
	while(m==1)
	{ 
		printf("要修改哪个科目的成绩（语文为 1，数学为 2，英语为 3，政治为 4）\n"); 
		scanf("%d",&j); 
		do
		{
			printf("科目%d 成绩",j); 
			scanf("%d",&stuArray[i]->score[j-1]); 
			if((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)) 
			{ 
				printf("错误数据， 请重新输入!\n"); 
			}}while((stuArray[i]->score[j-1]>100) || (stuArray[i]->score[j-1]<0)); 
			printf("还要继续修改此记录吗?Y or N!\n");
			scanf("%s",&c);
			if((c=='Y') || (c=='y')) 
			{ 
				m=1; } 
			else  { break;} 
			for(j=0;j<MAXSUB;j++)
			{ 
				sum+=stuArray[i]->score[j];
			} 
			stuArray[i]->average=sum/MAXSUB}
            return stuArray[i]; 
/****************************************
* Author:LiuXL;
* Function:main();				
* Description:Debug;
****************************************/
int main()
{
	//瀹炰緥鍖朣tudent
	Student up1602[MAX_STU_NO]={2016016000,"Debugger",1,1,4};
	/*
	瀛﹀彿锛�2016016000
	濮撳悕锛欴ebugger
	鎬у埆锛氱敺
	宸查�夎绋嬬紪鍙凤細1
	GPA锛�4
	*/
	Student *stu=up1602;

	//调用要调试的函数
	delStudent(stu);

	return 0;
}