//�����㷨��
//	һ��һ�ȵ�ŷ�ڿ�ʼ�ˣ����ڳ����׶β���ѭ����
//	����n�Բμӣ�������������n-1�죬ÿ����Ҫ����
//	���ӽ���һ������������ջ��ֽ������������
//	�����ֿա��밴������Ҫ���ű������֣�����ÿ
//	���ӵĶ���


#include <stdio.h>
#include <windows.h>

#pragma warning(disable:4996)

#define MAXN 64

int a[MAXN+1][MAXN+1] = {0};

void gamecal( int k, int n )
{
	int i, j;
	if( 2 == n )
	{
		a[k][1] = k;
		a[k][2] = k+1;
		a[k+1][1] = k+1;
		a[k+1][2] = k;
	}
	else 
	{
		gamecal( k, n/2 );
		gamecal( k+n/2, n/2 );
		for( i = k; i < k+n/2; i++ )
		{
			for( j = n/2+1; j <= n; j++ )
			{
				a[i][j] = a[i+n/2][j-n/2];
			}
		}
		for( i= k+n/2; i < k+n; i++ )
		{
			for( j = n/2+1; j <= n; j++ )
			{
				a[i][j] = a[i-n/2][j-n/2];
			}
		}
	}
}

int main()
{

	int m, i, j;
	printf("�����������");
	scanf("%d", &m);
	j = 2;
	for( i = 2; i < 8; i++ )
	{
		j *= 2;
		if( j == m )break;
	}
	if( i >8 )
	{
		printf("�������������2���������ݣ����Ҳ��ܳ���64��\n");
		system("pause");
		return 0;
	}
	gamecal( 1, m );
	printf("\n��� ");
	for( i = 2; i <= m; i++ )
	{
		printf("%2d�� ", i-1);
	}
	printf("\n");
	for( i = 1; i <= m; i++ )
	{
		for( j = 1; j <= m; j++ )
		{
			printf("%4d ", a[i][j]);
		}
		printf("\n");
	}


	system("pause");
	return 0;
}
