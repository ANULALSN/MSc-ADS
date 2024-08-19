#include<stdio.h>
#include<stdlib.h>
void create(void);
void display();
void sort();
void delete();
struct node{
    int data;
    struct node *next;
};

struct node *start=NULL;
struct node *current;
struct node *temp;

void main(){
    int key,choice;
    create();
    display();
      printf("\nDo you want to sort the linked list:\n");
    scanf("%d",&choice);
    if(choice==1){
        sort();
    }
    display();
    printf("Enter the value to be deleted:");
    scanf("%d",&key);
    delete(key);
    display();
  
}
void create(void){
    int ch;
    do{
    struct node *newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter the data for node:");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(start==NULL){
        start=newnode;
        current=newnode;
    }
    else{
        current->next=newnode;
        current=newnode;        
        
    }
    printf("Do you want to continue:(1/0)");
    scanf("%d",&ch);
    }while(ch!=0);
}
void delete(int key){
    
    current=start;
    while(current->data!=key){
        if(current->next==NULL){
            printf("Element not found");
            exit(0);
            
        }
        temp=current;
        current=current->next;
        
    }
    temp->next=current->next;
    free(current);
    printf("Deleted %d from the list\n",key);
}

void sort(){
    struct node *index=NULL;
    int local;
    current=start;
    while(current->next!=NULL){
        index=current->next;
        while(index!=NULL){
        if(current->data > index->data)    {
            local=current->data;
            current->data=index->data;
            index->data=local;
            
            
        }
        index=index->next;
            
        }
        current=current->next;
    }
    
}
 void display(){
     
     current=start;
     while(current!=NULL){
         printf("%d-->",current->data);
         current=current->next;
     }
 }