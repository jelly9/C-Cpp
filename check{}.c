#include<stdio.h> 

int main()
{ 
    int ch = 0;    
    int left = 0;  
    int right = 0;  
    printf("������һ���ַ�:\n");  
    while((ch=getchar())!=EOF)
	{  
  
        if(ch=='{')
		{  
            left++;  
        }  
        if(ch=='}')
		{  
            if(left>right)
			{  
                right++;  
            }
			else
			{
                printf("ƥ��ʧ��!\n");  
                return 0;  
            }  
        }  
    }   
    if(right==left){  
        printf("ƥ��ɹ�!\n");  
    }else{  
        printf("ƥ��ʧ��!\n");  
    }  
    return 0;  
}  

