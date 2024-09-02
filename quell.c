#include<stdio.h>
#include<stdlib.h>
void ENQUEUE();
void DEQUEUE();
void DISPLAY();
struct node {
int data;
struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;
void main(){
int choice;
printf("\nQUEUE OPERATIONS USING LINKED LIST\n");

while(1){
printf("\n INSERT \nDELETE \nDISPLAY\n");
printf("Enter a choice");
scanf("%d",&choice);
switch(choice){
case 1:ENQUEUE();
       break;
case 2:DEQUEUE();
       break;
case 3:DISPLAY();
       break;
case 4:exit(0);
default:printf("Enter a valid choice:");              



}


}


}
void ENQUEUE(){
struct node *newnode;
int item;
newnode=(struct node*)malloc(sizeof(struct node));
printf("Enter the data :");
scanf("%d",&newnode->data);
if(front==NULL){
front=newnode;
rear=newnode;
front->next=NULL;
rear->next=NULL;
}
else{
rear->next=newnode;
rear=newnode;
rear->next=NULL;
}
}

void DEQUEUE(){
struct node *ptr;
if(front==NULL){
printf("\nUNDERFLOW\n");
}
else{
ptr=front;
printf("%d deleted",ptr->data);
front=front->next;
free(ptr);


}
}

void DISPLAY(){
struct node *temp;
temp=front;
while(temp!=NULL){
printf("%d\t",temp->data);
temp=temp->next;
}

}
