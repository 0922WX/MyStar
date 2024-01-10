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
     printf("��������Ҫ��ӵ�ְ�����:\n");
	 scanf("%s", Em[Employeecount].EmployeeNumber);
	 for ( i = 0; i < Employeecount; i++)
	 {
		 if (strcmp(Em[i].EmployeeNumber, Em[Employeecount].EmployeeNumber) == 0) 
		 {
			 printf("�ñ���Ѿ�����\n");
			 system("pause");
			 rewind(stdin);
			 return;
		 }
	 }
	 printf("��������Ҫ��ӵ�ְ������:\n");
	 scanf("%s", Em[Employeecount].Name);
	 printf("��������Ҫ��ӵ�ְ���Ա�:\n");
	 scanf("%s", Em[Employeecount].Sex);
	 printf("��������Ҫ��ӵ�ְ������:\n");
	 scanf("%s", Em[Employeecount].EmployeeAge);
	 printf("��������Ҫ��ӵ�ְ��ѧ��:\n");
	 scanf("%s", Em[Employeecount].EmployeeDrgree);
	 printf("��������Ҫ��ӵ�ְ������:\n");
	 scanf("%s", Em[Employeecount].Department);
	 printf("��������Ҫ��ӵ�ְ���绰:\n");
	 scanf("%s", Em[Employeecount].PhoneNumber);
	 printf("��������Ҫ��ӵ�ְ��нˮ:\n");
	 scanf("%s", Em[Employeecount].Salary);
	 Employeecount ++;
	 printf("�Ƿ��������?(y/n)\n");
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
			printf("д�����\n");
		}
	}
	fclose(fp);
	system("pause");
	rewind(stdin);
	printf("д�����\n");
	system("pause");
	rewind(stdin);
}
   
void Found()
{
	int choice = 0;
	int i;
	char Arr[20];
	printf("ѡ���ѯ��ʽ\n");
	printf("��'1'��ѧ����ѯ\n");
	printf("��'2'����ְ���Ų�ѯ\n");
	rewind(stdin);
	scanf("%d", &choice);
	if (choice == 1)
	{
		printf("ѧ��Ϊ:");
		scanf("%s", Arr);
	}
	if (choice == 2)
	{
		printf("��ְ����Ϊ:");
		scanf("%s", Arr);
	}
	printf("\n���\t����\t�Ա�\t����\tѧ��\t����\t�绰\tнˮ\t");
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
	printf("��������Ҫɾ����Ա�����");
	scanf("%d", &i);
	for ( i = 0; i < Employeecount - 1; i++)
	{
		Em[i] = Em[i + 1];
		
	}
	Employeecount--;
	printf("ɾ���ɹ�\n");
	system("pause");
	rewind(stdin);
}
void Xiugai()
{
	int i;
	char name[15];
	rewind(stdin);
	printf("������Ҫ�޸ĵ�Ա��������");
	rewind(stdin);
	fgets(name, sizeof(name), stdin);
	name[strcspn(name, "\n")] = '\0'; // ȥ�����з�
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
		printf("δ�ҵ���Ա��\n");
		return;
	}
	Employee temp = Em[index];
	printf("��������Ҫ����µ�ְ����ţ�");
	fgets(temp.EmployeeNumber, sizeof(temp.EmployeeNumber), stdin);
	temp.EmployeeNumber[strcspn(temp.EmployeeNumber, "\n")] = '\0';
	
}
 
void Paixu()
{
	int i,j;
	printf("����������\n");
	printf("\n���\t����\t�Ա�\t����\tѧ��\t����\t�绰\tнˮ\t");
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
	printf("*                 ְ����Ϣ����ϵͳ                 *\n");
	printf("*                                                  *\n");
	printf("*                      ���˵�                      *\n");
	printf("*                                                  *\n");
	printf("*                  1.���ְ����Ϣ                  *\n");
	printf("*                  2.��ѯְ����Ϣ                  *\n");
	printf("*                  3.ɾ��ְ����Ϣ                  *\n");
	printf("*                  4.�޸�ְ����Ϣ                  *\n");
	printf("*                  5.ְ��������Ϣ                  *\n");
	printf("*                  6.�鿴ȫ��ְ����Ϣ              *\n");
	printf("*                  0.   �˳�                       *\n");
	printf("*                                                  *\n");
	printf("*                                                  *\n");
	printf("****************************************************\n");
	printf("ѡ��ְ����Ϣ�����ܣ�");

}


	

void ShowAll()
{
	int i;
	printf("\n���\t����\t�Ա�\t����\tѧ��\t����\t�绰\tнˮ\t");
	for ( i = 0; i < Employeecount; i++)
	{
		printf("\n%s\t%s\t%s\t%s\t%s\t%s\t%s\t%s\t\n",
			Em[i].EmployeeNumber, Em[i].Name, Em[i].Sex, Em[i].EmployeeAge, Em[i].EmployeeDrgree, Em[i].Department,
			Em[i].PhoneNumber, Em[i].Salary);
	}
	system("pause");
	rewind(stdin);
}