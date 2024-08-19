#include <stdio.h>

int main() {
   int i,a[5],x,flag=0;
    printf("Enter the elements of the array");
    for(i=0;i<5;i++){
    scanf("%d",&a[i]);
    }
    printf("Enter the elements to be searched");
    scanf("%d",&x);
    for(i=0;i<5;i++){
    if(a[i]==x){
    flag=1;
    break;
    }
    }
   if(flag==1)
   printf("Element found at %d",i);
   else
   printf("Element  not found ");
}

