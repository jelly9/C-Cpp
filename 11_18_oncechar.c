#include <stdio.h>
#include <windows.h>

char firstchar( char *str )
{
	int i = 0;
	int _char[255] = {0};//�����ַ��ĸ���

	for( i = 0; '\0' != str[i]; i++ )//�����ַ���
	{
		_char[str[i]]++;
	}

	for( i = 0; '\0' != str[i]; i++ )//���ҵ�һ�����ֵ�
	{
		if( 1 == _char[str[i]] )
		{
			return str[i];
		}
	}
	return '\0';
}

int main()
{
	char str[] = "hello bit";

	printf("%c\n", firstchar(str));

	system("pause");
	return 0;
}