#include<stdio.h>
void main()
{
int i,j,n,temp;
printf("Enter the number of elements of the array");
scanf("%d",&n);
int a[n];
printf("Enter the elements of the array");
for(i=0;i<n;i++)
scanf("%d",&a[i]);
for(i=0;i<n;i++){
for(j=0;j<n-i-1;j++){
if(a[j]>a[j+1]){
temp=a[j];
a[j]=a[j+1];
a[j+1]=temp;
}
}

}
printf("The sorted array is:");
for(i=0;i<n;i++){
printf("%d\t",a[i]);

}
}
