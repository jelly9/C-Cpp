#include <stdio.h>
#include <windows.h>
#include <assert.h>

char *mystrstr( const char *str1,const char *str2)
{
	//   ˼·:
	//   str1   abcabcdef   
	//   str2   abcd        |
	//           abcd       |
	//            abcd      V
	//             abcd        �ҵ��ˣ�����


	const char *p = str1;
	const char *q = str2;
	const char *s = NULL;
	assert(str1);
	assert(str2);
	if('\0' == *q)//���ַ���Ϊ���򷵻�ĸ�ַ���
	{
		return (char*)p;
	}
	while(*p)
	{
		s = p;
		while( *p && *q && *p == *q )//�����Ƚ�         // abcabcdef -> abcabcdef  -> abcabcdef -> abcabcdef
		{//                                              abcd      ->  abcd      ->   abcd    ->    abcd    ->  �ҵ��ˣ�����
			p++;
			q++;
		}
		if('\0' == *q)//���ַ���ָ��\0����˵��ĸ�ַ����������ַ���
		{
			return (char *)s;
		}
		p = s+1;//�����ĸ�ַ�����һ��Ԫ�رȽ�
		q = str2;
	}
	return NULL;//ֱ��str1ָ���ʱ��δ�ҵ��򷵻ؿ�
}


int main()
{
	char str1[100] = "abcabcdefg";
	char str2[100] = "abcd";
	printf("%s\n", mystrstr(str1, str2));

	system("pause");
	return 0;
}






