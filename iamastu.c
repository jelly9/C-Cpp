#include <stdio.h>
#include <assert.h>
#include <windows.h>

char *reverse_str(char *str)
{	
	char *left  = str;//ָ���ַ�����ͷ��ָ��
	char *right = str;
	assert( str );   //����ַ���Ϊ���򱨴�
	while( *right != '\0') //ʹָ���ַ�����β
	{
		right++; 
	}

	while( left < right - 1 )//�����ַ�����ת
	{
		char tmp = *left;
		*left = *(right-1);
		*(right-1)= tmp;
		left++;
		right--;
	}
	left = str;
	right = str;
	while( *right != '\0' )
	{
		char *p = right;
		while( *right != ' ' && *right != '\0')//ÿ�����ʷ�ת
		{
			right++;
		}
		p = right;
		while( left < right - 1 ){
			char tmp = *left;
			*left = *(right-1);
			*(right-1)= tmp;
			left++;
			right--;
		}
		if( *p == '\0')
		{
			return str;
		}
		left = p+1;
		right = p+1;
	}
	return str;
}

int main()
{
	char str[100] = "student a am i";
    printf("Before reverse: %s\n", str);
	printf("After reverse: %s\n", reverse_str(str));
	system("pause");
	return 0;
}