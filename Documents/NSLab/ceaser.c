#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>

int main()
{
	char pt[100],s_val,m_val,i,len,k,cp[100],de[100],bt[100];
	printf("Enter the plain text\n");
	gets(pt);
	len=strlen(pt);
	time_t now;
	struct tm *tm;
	now=time(0);
	
		if((tm=localtime(&now))==NULL)
		{
			printf("Error extracting time\n");
			return 1;
		}
	
		printf("Current date and time:%04d-%02d-%02d\t%02d:%02d:%02d\n",tm->tm_year+1900,tm->tm_mon+1,tm->tm_mday,tm->tm_hour,tm->tm_min,tm->tm_sec);
	s_val=tm->tm_sec;
	m_val=s_val%26;
	printf("Mod value is\t%d\n",m_val);
	
	for(i=0;i<len;i++)
	{
		k=pt[i];
		cp[i]=k+m_val;
	}
	cp[i]='\0';
	
	printf("After Encryption\n");
	//for(i=0;i<len;i++)
		//printf("%s",cp[i]);
		puts(cp);
	printf("After Decryption\n");
	for(i=0;i<len;i++)
	{
		k=cp[i];
		de[i]=k-m_val;
	}
		de[i]='\0';
	//for(i=0;i<len;i++)
		//printf("%s",de[i]);
	puts(de);
	int j;
	printf("Brute Force attack\n");
	for(i=0;i<26;i++)
	{
		for(j=0;j<len;j++)
		{
		k=cp[j];
		bt[j]=k-i;
		}
	bt[i]='\0';
		printf("Key %d\t",i);
		puts(bt);
		printf("\n");	
	}
	

}
