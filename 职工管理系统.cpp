#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void menu();
void Add();
void Found();
void Delete();
void Xiugai();
void Paixu();
void ShowAll();
struct Employee
{
	char EmployeeNumber[15];
	char Name[20];
	char Sex[10];
	char EmployeeAge[100];
	char EmployeeDrgree[10];
	char Salary[100];
	char Department[20];
	char PhoneNumber[12];
};
struct Employee Em[100];
int Employeecount = 0;

int main()
{	
	while (1)
	{   
		int choice;
		system("cls");
		menu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:Add();break;
		case 2:Found();break;
		case 3:Delete();break;
		case 4:Xiugai();break;
		case 5:Paixu();break;
		case 6:ShowAll();break;
		case 0:exit;break;
		}
	}
	getchar();
	return 0;
}
void Add()
{   
	int i;
	char flag='y';
	while (flag == 'y')
	{
     printf("请输入需要添加的职工编号:\n");
	 scanf("%s", Em[Employeecount].EmployeeNumber);
	 for ( i = 0; i < Employeecount; i++)
	 {
		 if (strcmp(Em[i].EmployeeNumber, Em[Employeecount].EmployeeNumber) == 0) 
		 {
			 printf("该编号已经存在\n");
			 system("pause");
			 rewind(stdin);
			 return;
		 }
	 }
	 printf("请输入需要添加的职工姓名:\n");
	 scanf("%s", Em[Employeecount].Name);
	 printf("请输入需要添加的职工性别:\n");
	 scanf("%s", Em[Employeecount].Sex);
	 printf("请输入需要添加的职工年龄:\n");
	 scanf("%s", Em[Employeecount].EmployeeAge);
	 printf("请输入需要添加的职工学历:\n");
	 scanf("%s", Em[Employeecount].EmployeeDrgree);
	 printf("请输入需要添加的职工部门:\n");
	 scanf("%s", Em[Employeecount].Department);
	 printf("请输入需要添加的职工电话:\n");
	 scanf("%s", Em[Employeecount].PhoneNumber);
	 printf("请输入需要添加的职工薪水:\n");
	 scanf("%s", Em[Employeecount].Salary);
	 Employeecount ++;
	 printf("是否继续输入?(y/n)\n");
	 getchar();
	 scanf("%c", &flag);
	}
	FILE* fp;
	int j;
	if ((fp = fopen("D://ZhiGongXinXi.txt", "wb")) == NULL)
	{
		printf("error\n");
		exit(0);
	}
	for (j = 0; j < Employeecount; j++)
	{
		if (fwrite(&Em[j], sizeof(struct Employee), 1, fp) != 1)
		{
			printf("写入错误\n");
		}
	}
	fclose(fp);
	system("pause");
	rewind(stdin);
	printf("写入完成\n");
	system("pause");
	rewind(stdin);
}
   
void Found()
{
	int choice = 0;
	int i;
	char Arr[20];
	printf("选择查询方式\n");
	printf("按'1'以学历查询\n");
	printf("按'2'以任职部门查询\n");
	rewind(stdin);
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("学历为:");
		scanf("%s", Arr);
	}
	if (choice == 2)
	{
		printf("任职部门为:");
		scanf("%s", Arr);
	}
	printf("\n编号\t姓名\t性别\t年龄\t学历\t部门\t电话\t薪水\t");
	for (i = 0; i < Employeecount; i++)
	{
		if (choice == 2 && strstr(Em[i].Department,Arr))
		{
			printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
				Em[i].EmployeeNumber,Em[i].Name,Em[i].Sex,Em[i].EmployeeAge,Em[i].EmployeeDrgree,Em[i].Department,
				Em[i].PhoneNumber,Em[i].Salary);
		}
		else if (choice == 1 && strstr(Em[i].EmployeeDrgree, Arr))
		{
			printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
				Em[i].EmployeeNumber, Em[i].Name, Em[i].Sex, Em[i].EmployeeAge, Em[i].EmployeeDrgree, Em[i].Department,
				Em[i].PhoneNumber, Em[i].Salary);
		}
	}
	system("pause");
	rewind(stdin);
}
void Delete()
{
	int i;
	printf("请输入你要删除的员工编号");
	scanf("%d", &i);
	for ( i = 0; i < Employeecount - 1; i++)
	{
		Em[i] = Em[i + 1];
		
	}
	Employeecount--;
	printf("删除成功\n");
	system("pause");
	rewind(stdin);
}
void Xiugai()
{
	int i;
	char name[15];
	rewind(stdin);
	printf("请输入要修改的员工姓名：");
	rewind(stdin);
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0'; // 去除换行符
	int index = -1;
	for (i = 0; i < Employeecount; i++)
	{
		if (strcmp(Em[i].Name, name) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
	{
		printf("未找到该员工\n");
		return;
	}
	Employee temp = Em[index];
	printf("请输入需要添加新的职工编号：");
	fgets(temp.EmployeeNumber, sizeof(temp.EmployeeNumber), stdin);
	temp.EmployeeNumber[strcspn(temp.EmployeeNumber, "\n")] = '\0';
	
}
 
void Paixu()
{
	int i,j;
	printf("按工资排序\n");
	printf("\n编号\t姓名\t性别\t年龄\t学历\t部门\t电话\t薪水\t");
	for ( i = Employeecount -1; i > 0; i--)
	{
		for (j = 0;j < i-1;j++)
		{
			if ((strcmp(Em[i].Salary, Em[j].Salary) > 0))
			{
				Em[i] = Em[j];
				Em[j] = Em[j + 1];
				Em[j + 1] = Em[i];
			}
		}
	}
	for (i = 0; i < Employeecount; i++)
	{
		printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			Em[i].EmployeeNumber, Em[i].Name, Em[i].Sex, Em[i].EmployeeAge, Em[i].EmployeeDrgree, Em[i].Department,
			Em[i].PhoneNumber, Em[i].Salary);	
	}
	system("pause");
	rewind(stdin);
}
void menu()
{
	printf("****************************************************\n");
	printf("*                                                  *\n");
	printf("*                 职工信息管理系统                 *\n");
	printf("*                                                  *\n");
	printf("*                      主菜单                      *\n");
	printf("*                                                  *\n");
	printf("*                  1.添加职工信息                  *\n");
	printf("*                  2.查询职工信息                  *\n");
	printf("*                  3.删除职工信息                  *\n");
	printf("*                  4.修改职工信息                  *\n");
	printf("*                  5.职工排序信息                  *\n");
	printf("*                  6.查看全部职工信息              *\n");
	printf("*                  0.   退出                       *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");
	printf("选择职工信息管理功能：");

}


	

void ShowAll()
{
	int i;
	printf("\n编号\t姓名\t性别\t年龄\t学历\t部门\t电话\t薪水\t");
	for ( i = 0; i < Employeecount; i++)
	{
		printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			Em[i].EmployeeNumber, Em[i].Name, Em[i].Sex, Em[i].EmployeeAge, Em[i].EmployeeDrgree, Em[i].Department,
			Em[i].PhoneNumber, Em[i].Salary);
	}
	system("pause");
	rewind(stdin);
}