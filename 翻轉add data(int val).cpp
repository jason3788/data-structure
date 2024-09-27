#include<stdlib.h>
#include<stdio.h>
struct node{
	int val;
	struct node *next;
};
typedef struct node(Node);

void Insert (Node **head,int add_data) {
	Node *cur=NULL;
	Node *pre=NULL;
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->val=add_data;
	if(*head == NULL) {
		newnode=*head;
		newnode->next=NULL;
	}
	else{
		for(cur=*head; cur!=NULL && cur->val<=add_data ;cur=cur->next){ 
			pre=cur;
		}
		if(cur==*head){
			newnode->next=*head;
			*head=newnode;
		}
		else{
	 	 	pre->next=newnode;
	  		newnode->next=cur;	
		}	
	}
	
}
void pushfront(Node **head,int add_data){
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->val=add_data;
	newnode->next=*head;
	*head=newnode;
}
void printList(Node **head){
  Node *current=*head;
  while (current != NULL)
  {
     printf(" %d ", current->val);
     current = current->next;
  }
}
int main(){
	Node *head=NULL;
	pushfront(&head,9);
	pushfront(&head,3);
	pushfront(&head,1);
    Insert(&head,10);
	printList(&head);
}

