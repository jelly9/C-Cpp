#include <stdio.h>
#include <windows.h>

char *spaceswap( char *str )
{
	char *ret = str;
	char *rear = str;
	while( *rear != '\0') //ʹָ���ַ�����β
	{
		rear++; 
	}

	while( *str != '\0')
	{
		if( *str == ' ')//�ж��Ƿ�Ϊ�ո�
		{
			char *p = rear+2;//Are you ok?'\0'
			char *q = rear+2;
			while( str < rear )//Ԫ�����κ�����λ
			{
				*p = *rear;
				rear--;
				p--;
			}
			*str = '%';
			*(str+1) = '2';
			*(str+2) = '0';
			rear = q;//����rearʹָ��β��
		}
		str++;
	}
	return ret;
}

int main()
{
	char str[100] = " We are happy! ";
	printf("Before swap; %s\n", str);
	printf("After swap: %s\n", spaceswap(str));

	system("pause");
	return 0;
}