#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ITEM 2 
void encrypt();  
void decrypt(); 
int main(){
    int flag;  
    void (*menu[ITEM])()={encrypt,decrypt};  
      
	while (true)
	{
		printf("加密文件——1\n");  
		printf("解密文件——2\n");  
		printf("退出程序——0\n");
		scanf("%d",&flag);  
		if(!flag)  
			exit(1);  
		else if(flag==1||flag==2)  
			menu[flag-1](); 
		else
			exit(1);
	}
    return 0;  
}

void encrypt()
{
	int num;
	char str[1024];
	char cipher[1024];
	printf("输入欲加密字符串：");
	scanf("%s",str);
	printf("输入分组长度：");
	scanf("%d",&num);
	int i=0;
	int k=0;
	int j;
	for(j=0;j<strlen(str);j++)
	{
		
		cipher[j]=str[i];
		i+=num;
		if(i>=strlen(str)){
			k++;
			i=k;
			if(k>num){
				break;
			}
		}
	}
	cipher[j]=0x00;
	printf("密文：%s\n",cipher);

}

void decrypt()
{
	int num;
	char str[1024];
	char cipher[1024];
	printf("输入欲解密字符串：");
	scanf("%s",str);
	while (true)
	{
		printf("输入分组长度-或0退出：");
		scanf("%d",&num);
		if(num==0) return;
		int i=0;
		int k=0;
		int j;
		for(j=0;j<strlen(str);j++)
		{
		
			cipher[j]=str[i];
			i+=num;
			if(i>=strlen(str)){
				k++;
				i=k;
				if(k>num){
					break;
				}
			}
		}
		cipher[j]=0x00;
		printf("明文：%s\n",cipher);
	}
	
}
