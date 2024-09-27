#include<stdlib.h>
#include<stdio.h>
struct node{
	int val;
	struct node *next;
};
typedef struct node(Node);

void pushback(Node **head,int add_data){
    Node *newnode=(Node *)malloc(sizeof(Node));
    newnode->val=add_data;
    newnode->next= NULL;
    if(*head==NULL)
         *head=newnode;
    else{
        Node *current = *head;
        while(current->next != NULL){
            current = current->next;
        }
        current->next = newnode;
    }
}

void printList(Node **head){
  Node *current=*head;
  while (current != NULL)
  {
     printf(" %d ", current->val);
     current = current->next;
  }
}

void deleteNode(Node **head, int key)
{
    Node *cur=NULL;
	Node *pre=NULL;
	for(cur=*head; cur!=NULL && cur->val!=key ;cur=cur->next){
		pre=cur;
	}
	if(cur==*head){
		*head=cur->next;
		free(cur);
	}
	else{
	  pre->next=cur->next;
	  free(cur);	
	}
}
int main(){
	Node *head=NULL;
    pushback(&head,3);
    pushback(&head,5);
	pushback(&head,7);
	pushback(&head,9);
	pushback(&head,11);
	deleteNode(&head,3);
    printList(&head);
}
