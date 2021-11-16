#include<stdio.h>


extern void add();
extern void sub();


int main()
{
	int a = 0;
	int n1 = 0;
	int n2 = 0;
	while (1)
	{
		printf("*******************************\n");
		printf("****  1.加法      2.减法   ****\n");
		printf("****  3.退出               ****\n");
		printf("*******************************\n");
		printf("请输入要进行的操作：>");
		scanf("%d", &a);
		while ((a>3) || (a<1))
		{
			printf("输入有误，请重新输入\n");
			printf("请输入要进行的操作：>");
			scanf("%d", &a);
		}
		if (a != 3)
		{
			printf("请输入要进行运算的两个整数\n");
			printf("num1: ");
			scanf("%d", &n1);
			printf("num2: ");
			scanf("%d", &n2);
			switch (a)
			{
			case(1) :
				add(n1, n2);
				break;
			case(2) :
				sub(n1, n2);
				break;
			}
		}
		else
		{
			printf("退出成功\n");
			break;
		}
	}
	return 0;
}
 