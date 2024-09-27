#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data;
	struct Node *next;
};
typedef struct Node Node;

void display(Node **head){
	Node *cur=*head;
	while(cur!=NULL){
		printf("%d ",cur->data);
		cur=cur->next;
	}
}

int searchnode(Node **head,int search_data){
	Node *cur=*head;
	while(cur!=NULL){
		if(cur->data==search_data){
			return 1;
		}
		else 
			cur=cur->next;
	}
	return 0;
}

int indexof(Node **head,int key){
	int i=0;
	Node *cur=*head;
	while(cur!=NULL){
		if(cur->data==key){
			return i;
		}
		else{
			i++;
			cur=cur->next;
		}
	}
	return -1;
} 

void pushback(Node **head,int add_data){
	Node *newnode=new Node;
	newnode->data=add_data;
	Node *cur=*head;
	if(*head==NULL){
		*head=newnode;
		newnode->next=NULL;
	}
	else{
		while(cur->next!=NULL){
			cur=cur->next;
		}
		cur->next=newnode;
		newnode->next=NULL;
	}
}

void pushfront(Node **head,int add_data){
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->data=add_data;
	newnode->next=*head;
	*head=newnode;
}

void insertafter(Node *prenode,int add_data){
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->data=add_data;
	newnode->next=prenode->next;
	prenode->next=newnode;
}
void removelast(Node **head){
	Node *cur=*head;
	while(cur->next->next!=NULL){
		cur=cur->next;
	}
	free(cur->next);
	cur->next=NULL;
}
void removefirst(Node **head){
	Node *delnode=*head;
	*head=delnode->next;
	free(delnode);
}

void removeafter(Node *prenode){
	Node *delnode=prenode->next;
	prenode->next=delnode->next;
	free(delnode);
}
void remove_index(Node **head,int n){
	Node *cur=*head;
	int i;
	if(n==0){
		removefirst(head);
	}
	else{
	for(i=1;i<n-1;i++){
		cur=cur->next;
	}
	 Node *delnode=cur->next;
	 cur->next=delnode->next;
	 free(delnode);
	}
}
int size(Node **head){
	int s=0;
	Node *cur=*head;
	while(cur!=NULL){
		s++;
		cur=cur->next;
	}
	return s;
}
int main(){
	Node *head=NULL;  
	pushback (&head,5);    
	pushfront(&head,7);
	pushback (&head,40);
	insertafter(head->next,11);
	remove_index(&head,0);
	display(&head);
	printf("size=%d",size(&head));
}
