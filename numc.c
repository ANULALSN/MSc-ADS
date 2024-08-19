#include<stdio.h>
#include<ctype.h>
#include<string.h>
void main(){
int x,i,alpha=0,num=0,sp=0;
char a[50];
printf("Enter the string:");
fgets(a,sizeof(a),stdin);
for(i=0;i<=strlen(a)-1;i++)
{
  if(isalpha(a[i]))
  {
  alpha++;
  }
  else if (isdigit(a[i])){
  num++;
  }
  else if(!isspace(a[i]))
  sp++;
}

printf("\nNumber of alphabets=%d , numbers=%d , special characters =%d ",alpha,num,sp);
int total=alpha+num+sp;
printf("\nTotal number of elements=%d",total);
}
