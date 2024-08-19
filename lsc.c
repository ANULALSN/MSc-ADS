#include<stdio.h>
int main()
{
int i,j,r=-1,size;
printf("enter the size of the array : ");
scanf("%d",&size);
int arr[size];

for(i=0;i<size;i++)
{
printf("enter the element number %d :",i);
scanf("%d",&arr[i]);
}

int item;
printf("enter the element to search : ");
scanf("\n%d",&item);

int count = 0;
for(j=0;j<size;j++){
if(arr[j]==item){
r=j;
break;}}
for(j=0;j<size;j++){
if(arr[j]==item){
count++;
}
}
if(r!=-1){
printf("element first founf at index %d and its occurance : %d",r,count);
}
else{
printf("element not found \n");
}
return 0;
}
