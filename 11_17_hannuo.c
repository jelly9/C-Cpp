#include <stdio.h>
#include <windows.h>

#pragma  warning(disable:4996)

void move(int n, int x, int y, int z)
{
	if( 1 == n )
	{
		printf("%c-->%c\n",x, z);
	}
	else 
	{
		move (n-1, x, z, y);
		printf("%c-->%c\n\n", x, z);
		move(n-1, y, x, z);
	}
}

int main()
{
	int h;
	printf("�������Ӹ�����");
	scanf("%d", &h);
	printf("�ƶ�%2d�����ӵ�˳�����£�\n", h);
	move(h, 'a', 'b', 'c');
	system("pause");
	return 0;
}