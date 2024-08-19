#include<stdio.h>
int partition(int a[],int beg,int end);
void qsort(int a[],int beg,int end);
void main()
{
int i,n;
printf("Enter the no.of elements:");
scanf("%d",&n);
int a[n];
printf("Enter the elements");
for(i=0;i<n;i++)
{
 scanf("%d",&a[i]);
}
qsort(a,0,n-1);
printf("The sorted array is:\n");
for(i=0;i<n;i++)
{
printf("%d\t",a[i]);
}

}
int partition(int a[],int beg,int end){

int left,right,temp,pivot,flag;
left=pivot=beg;
right=end;
flag=0;
while(flag!=1){
while(a[pivot]<=a[right] && pivot!=right)
right--;
if(pivot==right)
flag=1;
else if(a[pivot]>a[right]){
temp=a[pivot];
a[pivot]=a[right];
a[right]=temp;
pivot=right;
}
if(flag!=1){
while(a[pivot]>a[left] && pivot!=left)
left++;
if(pivot==left)
flag=1;
else if(a[pivot]<a[left]){
temp=a[pivot];
a[pivot]=a[left];
a[left]=temp;
left=pivot;
}
}
}
return pivot;
}

void qsort(int a[],int beg,int end){
int pivot;
if(beg<end)
{
pivot=partition(a,beg,end);
qsort(a,beg,pivot-1);
qsort(a,pivot+1,end);
}
}
