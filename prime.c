#include<stdio.h>
#include<math.h>

int main()
{
	int i = 0,j = 0,s = 0;
	for(i = 101;i<=200;i+=2)
	{
		for(j = 2;j<=sqrt(i);j++)
			if(i%j == 0) break;
		if(j>sqrt(i))
		{
			printf("%-6d",i);
			s++;
			if(s%10 == 0)printf("\n"); //����ÿ�����10����
		}
	}
	printf("\n����%d������\n",s);
	system("pause");
	return 0;
}
