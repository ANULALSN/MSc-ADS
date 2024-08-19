#include<stdio.h>
void main()
{
int i,j,n,temp,key;
printf("Enter the number of elements of the array");
scanf("%d",&n);
int a[n];
printf("Enter the elements of the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
//bubble sort main
for(i=1;i<n;i++){
key=a[i];
j=i-1;

while(j>=0 && a[j]>key){
a[j+1]=a[j];
j=j-1;
}
a[j+1]=key;
}




printf("The sorted array is:");
for(i=0;i<n;i++){
printf("%d\t",a[i]);

}
}
