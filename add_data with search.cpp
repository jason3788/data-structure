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
void additem_search(Node **head,int add_data){
	Node *current=*head;
	Node *newnode;
	Node *nextnode;
	if(add_data<current->val){
		newnode=(Node *)malloc(sizeof(Node));
		newnode->val=add_data;
		newnode->next=*head;
		*head=newnode;
	}
	while(current->next->next!=NULL){
		if(add_data>current->val && add_data<current->next->val){
			newnode=(Node *)malloc(sizeof(Node));
			nextnode=current->next;
			newnode->val=add_data;
			newnode->next=nextnode;
			current->next=newnode;
		}
		else{
			current=current->next;
		} 
	}
	if(add_data>current->next->val){
		current->next->next=(Node *)malloc(sizeof(Node));
		current->next->next->val=add_data;
		current->next->next->next=NULL;
	}

}
int main(){
	Node *head=NULL;
    pushback(&head,3);
    pushback(&head,5);
	pushback(&head,7);
	pushback(&head,9);
	pushback(&head,11);
	additem_search(&head,8);
    printList(&head);
    
}
