#include<stdio.h>
#include<stdlib.h>

struct listnode{
    int data;
    struct listnode* next;
};

void push(struct listnode** head,int newdata){
  struct listnode* newnode=(struct listnode*)malloc(sizeof(struct listnode));
  newnode->data=newdata;
  newnode->next= *head;
  *head =newnode;
}

void append(struct listnode* head , int newdata){

  struct listnode* newnode = (struct listnode*) malloc(sizeof(struct listnode));
  newnode->data=newdata;
  if(head==NULL){
    head=newnode;
    newnode->next=NULL;
    return;
  }

  struct listnode* temp;
  temp=head;
  while(temp->next!=NULL)
    temp=temp->next;
  temp->next=newnode;
}
void printlist(struct listnode* head){
  struct listnode* temp;
  temp=head;
  while(temp!=NULL){
    printf("%d ", temp->data );
    temp=temp->next;
  }
}

int main(){
  struct listnode* head=NULL;
  push(&head,6);
  push(&head,12);
  append(head,15);
  printlist(head);
  return 0;
}
