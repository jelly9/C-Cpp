
//Sunʹ��������ȡ�ķ�ʽ�����д������������ѣ�
//��ÿ������ĩȡ�¸��µ�����ѣ��ȼ�������Ϣ��
//1.71%�����д����ʵ����������Ǯ��

#include <stdio.h>
#include <windows.h>

#define RATE  0.0171
#define FETCH 1000

int main()
{
	double corpus[49];
	int i = 0;;
	corpus[48] = (double)FETCH;
	for( i = 47; i > 0; i-- )
	{
		corpus[i] = ( corpus[i+1] + FETCH ) / ( 1 + RATE/12 );
	}
	for( i = 48; i > 0; i-- )
	{
		printf("%d����ĩ��Ϣ���ƣ�%.2f\n", i, corpus[i]);
	}
	system("pause");
	return 0;
}