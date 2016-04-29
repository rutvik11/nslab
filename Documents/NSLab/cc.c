#include<stdio.h>
#include<string.h>
#include<ctype.h>

void main()
{
int key,len,i,temp;
char input[10],output[10];


printf("\n\n\tENTER THE DATA TO BE ENCRYPTED : ");
gets(input);

len = strlen(input);

printf("\n\n\tENTER THE KEY : ");
scanf("%d",&key);

//encrypt

for(i=0;i<len;i++){

if (isalpha(input[i]))
{
    temp = input[i];
    temp = temp+key;
    //printf("%d",temp);
    if(isupper(input[i]) && temp>90)
    {
         temp = temp-90;
         temp = 65+temp-1;
    }
    else if(islower(input[i]) && temp>122)
    {
         temp = temp-122;
         temp = 97+temp-1;
    }
    
    output[i] = (char)temp;
     //printf("final:%d  %c__",temp,output[i]);
}
else {

      temp = input[i];
      printf("%d",temp);
      temp = temp+key; 
      if(temp>57)
      {
          temp = temp-57;
          temp = temp+48-1;
      }

      output[i] = temp;
}
}
printf("\n\n\tTHE ENCRYPTED STRING IS : ");
puts(output);
/*
for(i=0;i<len;i++){
if(isalpha(input[i])){
printf("%c",output[i]);
}
else{
printf("%c",output[i]);
}
}*/
}
