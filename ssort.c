#include<stdio.h>
void main()
{
int a[10],swap,i,j,pos,temp;
int n=7;
printf("Enter 7 elements");
for(i=0;i<7;i++)
{
  scanf("%d",&a[i]);
  
}
for(i=0;i<n-1;i++){
pos=i;
for(j=i+1;j<n;j++){
if(a[pos]>a[j]){
pos=j;
}
}
if(pos!=i){
temp=a[i];
a[i]=a[pos];
a[pos]=temp;


}
}
for(i=0;i<7;i++){
printf("%d\t",a[i]);
}

}
