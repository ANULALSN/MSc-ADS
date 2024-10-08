#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
}*top=NULL;
void push(int);
void pop(void);
void display();
void main(){

int choice,value;
printf("*******STACK USING LINKED LIST *******");
while(1){
printf("\n PUSH \n POP \n DISPLAY\n");
scanf("%d",&choice);
switch(choice){
case 1:printf("Enter the value to be inserted");
       scanf("%d",&value);
       push(value);
       break;
case 2:pop();
       break;
case 3:display();
       break;
case 4:exit(0);
       break;
default:printf("Enter the correct choice");
}


}
}
void push(int val){
struct node *newnode=(struct node *)malloc(sizeof(struct node));
newnode->data=val;

if(top==NULL){
newnode->next=NULL;
}
else{
newnode->next=top;
}
top=newnode;
printf("Insertion success");
}
void pop(){
if(top==NULL){
printf("Stack is empty");
}
else{
struct node *temp=top;
printf("%d is deleted",temp->data);
top=temp->next;
free(temp);
}
}
void display(){
struct node *temp=top;
if(top==NULL){
printf("Stack empty");
}
else{
while(temp->next!=NULL){
printf("%d-->",temp->data);
temp=temp->next;
}
printf("%d-->NULL",temp->data);

}
}
