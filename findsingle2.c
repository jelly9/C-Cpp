#include <stdio.h>
#include <windows.h>


void bubblesort(int a[], int len)//����
{
	int i = len - 1;
	int j = 0;
	while( i )
	{
		int pos = 0;           //ÿ��ѭ����ʼǰ����δ����
		for( j = 0; j < i; j++)
		{
			if( a[j] > a[j+1] )
			{
				a[j] ^= a[j+1];
				a[j+1] ^= a[j];
				a[j] ^= a[j+1];
				pos = j;                   //��¼������λ��
			}
		}
		i = pos;   //����ֻ��Ƚϵ�posλ�ô���ok
	}
}

int main()
{
	int i = 0;
	int arr[] = {1,2,3,4,5,6,7,1,2,3,4,5,6};
	int len = sizeof(arr)/sizeof(arr[0]);
	for(i = 0; i<len; i++)
	{
		printf("%d  ",arr[i]);
	}
	printf("\n");
	bubblesort(arr, len);//����
	printf("�������ֵ�����Ϊ��");
	for(i = 0; i<len; i+=2)//ÿ����һ�Ƚ�,�����������һ��Ϊ�������ֵ�
	{
		if(arr[i] != arr[i+1])
		{
			printf("%d  ", arr[i]);
			i -= 1;
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}