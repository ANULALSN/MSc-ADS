#include<stdio.h>
#include<stdlib.h>
void create(int n);
void forward();
void backward();
struct node{
int data;
struct node *front;
struct node *back;

}*head,*last;
void main(){
int n;
head=NULL;
last=NULL;
printf("Enter the number of nodes you want to create:");
scanf("%d",&n);
create(n);
printf("Doubly linked list in forward direction");
forward();
printf("Doubly linked list in backward direction");
backward();

}

void create(int n){
int i, data;
struct node *newnode;
if(n>=1){
head=(struct node*)malloc(sizeof(struct node));
if(head!=NULL){
printf("Data for node 1:");
scanf("%d",&data);
head->data=data;
head->front=NULL;
head->back=NULL;
last=head;
for(i=2;i<=n;i++){
newnode=(struct node*)malloc(sizeof(struct node));
if(newnode!=NULL){
printf("Data for node %d:",i);
scanf("%d",&data);
newnode->data=data;
newnode->front=last;
newnode->back=NULL;
last->back=newnode;
last=newnode;
}
else
{
printf("Unable To allocate memory:");
}
}

}
else{
printf("Unable to allocate memory:");
}
}


}
void forward(){
struct node *temp;
if(head==NULL){
printf("List is empty");
}
else{
temp=head;
while(temp!=NULL){
printf("%d-->",temp->data);
temp=temp->back;
}
}

}

void backward(){
struct node *temp;
if(last==NULL){
printf("List is empty");
}
else{
temp=last;
while(temp!=NULL){
printf("%d-->",temp->data);
temp=temp->front;
}
}
}
