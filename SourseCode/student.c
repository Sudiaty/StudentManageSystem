/****************************************
* Author:LiuXL;
* Description:Function related with
*	ppStudent class.
****************************************/
#include "stdafx.h"

/****************************************
* Author:LiuXL;
* Function:addStudent();
* Description:Add a student's record.
****************************************/
int addStudent(Student *ppStu[MAX_STU_NO], Form *ppForm[MAX_ROW], int *stuNum)
{
	int iStuCourseNo = 0,iStuNo=0,status=1;
	if (strcmp(ppForm[2]->m_cpContent, "��")&&strcmp(ppForm[2]->m_cpContent, "Ů")&&strcmp(ppForm[2]->m_cpContent, "f")&&strcmp(ppForm[2]->m_cpContent, "m"))
		status = -1;
	for (iStuNo = 0; iStuNo < MAX_STU_NO&&ppStu[iStuNo]!=NULL; iStuNo++)
	{
		if (strcmp(ppStu[iStuNo]->m_cpNo, ppForm[0]->m_cpContent) == 0)
		{
			status = 0;
			break;
		}
	}
	if (status==1)
	{
		DST_SPPI(Student, ppStu, *stuNum);
		strcpy(ppStu[*stuNum]->m_cpNo, ppForm[0]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpName, ppForm[1]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpGender, ppForm[2]->m_cpContent);
		strcpy(ppStu[*stuNum]->m_cpClass, ppForm[3]->m_cpContent);
		for (iStuCourseNo = 0; iStuCourseNo<MAX_SUB_NO; iStuCourseNo++) strcpy(ppStu[*stuNum]->m_cpMajor[iStuCourseNo], "\0");
		(*stuNum)++;
		return 1;
	}
	else if(status==0)
	{
		printf("ѧ����ע�ᣡ\n\n");
		return 0;
	}
	else
	{
		printf("�Ա𲻺Ϸ�������/Ů������f/m������\n\n");
		return 0;
	}
}


/****************************************
* Author:LiuXL;
* Function:saveStudent();
* Description:Save the info to Student.dat.
****************************************/
void saveStudent(Student *ppStu[MAX_STU_NO])
{
	FILE *fp;
	int i;

	//��ȡStudent.txt
	if ((fp = fopen("Student.dat", "wb")) == NULL)
	{
		printf("Fail to open file!\n");
		exit(0);
	}

	for (i = 0; i<MAX_STU_NO&&ppStu[i]!=NULL; i++)
	{
		//д��������Student.dat
		if (fwrite(ppStu[i], sizeof(Student), 1, fp) != 1)
			printf("д��ʧ�ܣ�\n\n");
	}
	fclose(fp);
}


/****************************************
* Author:JiaZG,LiuXL;
* Function:getStudent();
* Description:get the info to Student.txt.
****************************************/
void getStudent(Student *ppStu[MAX_STU_NO], int *stuNum)
{
	FILE *fp;
	int i=0;
	//��ȡStudent.dat
	if ((fp = fopen("Student.dat", "rb")) == NULL)
	{
		return;
	}
	do
	{
		Student *pTmp=(Student*)malloc(sizeof(Student));
		ppStu[i]=pTmp;
	}while(fread(ppStu[i++],sizeof(Student),1,fp)&&i<MAX_STU_NO);
	ppStu[--i]=0x0;
	(*stuNum)=i;
	fclose(fp);
}

/****************************************
* Author:JiaZG;
* Function:searchStudent();
* Description:ͨ��ѧ�Ż�ȡѧ������
****************************************/
long searchStudent(Student *ppStu[MAX_STU_NO])
{
	long i = 0;
	char cpNo[10];
	printf("\n������ѧ����ѧ�ţ�");
	scanf("%s", cpNo);
	for (i = 0; ppStu[i]!=NULL&&i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpNo, cpNo) == 0)
		{
			printf("\n��ѧ����¼���£�\n");
			printf("|\tѧ��\t|\t����\t|\t�Ա�\t|\n");
			printf("|\t%s\t|\t%s\t|\t%s\t|\n\n", ppStu[i]->m_cpNo, ppStu[i]->m_cpName, ppStu[i]->m_cpGender);
			return i+1;
		}
	}
	printf("\n�����ڸ�ѧ����¼��\n\n");
	return 0;
}

/****************************************
* Author:LiuXL;
* Function:echoStudent();
* Description:list all of the students
****************************************/
char **echoStudent(Student *ppStu[MAX_STU_NO])
{
	char **cpStuTable;
	cpStuTable = (char **)malloc((MAX_STU_NO * 4 + 4) * sizeof(char*));
	for (int i = 0; i < MAX_STU_NO*4+4; i++) cpStuTable[i] = 0x0;
	cpStuTable[0] = "ѧ��";
	cpStuTable[1] = "����";
	cpStuTable[2] = "�Ա�";
	cpStuTable[3] = "�༶";
	int j = 4;
	for (int i = 0; i<MAX_STU_NO&&ppStu[i]!=NULL; i++)
	{
		cpStuTable[4 * i + 4] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpNo);
		cpStuTable[4 * i + 5] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpName);
		cpStuTable[4 * i + 6] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpGender);
		cpStuTable[4 * i + 7] = (char *)malloc(20 * sizeof(char));
		strcpy(cpStuTable[j++], ppStu[i]->m_cpClass);
	}
	return cpStuTable;
}


/****************************************
* Author:SunZT,LiuXL;
* Function:delStudent();
* Description:Delete info of Student.txt.
****************************************/
void delStudent(Student *ppStu[MAX_STU_NO], long stuNo, int *stuNum)
{
	for (int j = stuNo-1; j<MAX_STU_NO&&ppStu[j]->m_cpNo!=NULL; j++)
	{
		ppStu[j] = ppStu[j + 1];
	}
	(*stuNum)--;
}


/****************************************
* Author:SunZT,JiaZG,LiuXL;
* Function:altStudent();
* Description:alt a student's record.;
****************************************/
int altStudent(Student *ppStu[MAX_STU_NO], long lNo)
{
	char c,cpTmp[20];
	int status=0;
	lNo--;
	printf("Ҫ�޸�������Ϣ��(����n���Ա�s���༶c)\n");
	scanf("%s", &c);
	switch (c)
	{
	case 'n':
		printf("\n�޸ĺ������Ϊ��");
		scanf("%s", ppStu[lNo]->m_cpName);
		break;
	case 's':
		printf("\n�޸ĺ���Ա�Ϊ��");
		scanf("%s", ppStu[lNo]->m_cpGender);
		break;
	case 'c':
		printf("\n�޸ĺ�İ༶Ϊ��");
		scanf("%s", ppStu[lNo]->m_cpClass);
		break;
	default:
		printf("�Ƿ����룡\n\n");
		return 0;
	}
	return 1;
}

/****************************************
* Author:JiaZG;
* Function:searchClass();
* Description:��ѯ�༶�Ƿ����
****************************************/
char* searchClass(Student *ppStu[MAX_STU_NO],char cpClass[20])
{
	int i = 0;
	printf("\n������༶(*��ʾ���а༶)��");
	scanf("%s", cpClass);
	for (i = 0; ppStu[i]!= NULL&&i<MAX_STU_NO; i++)
	{
		if (strcmp(ppStu[i]->m_cpClass, cpClass) == 0 || strcmp("*", cpClass) == 0)
			return cpClass;
	}
	printf("\n�����ڸð༶��\n\n");
	return NULL;
}