#include<stdlib.h>
#include<stdio.h>
typedef struct Node{
	int data;
	struct Node *llink;
	struct Node *rlink;
}Node;

void insert(Node *head,int add_data){
	Node *current=head->rlink;
	while(current->data<add_data && current->rlink!=head){
		current=current->rlink;
	}
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->data=add_data;
	if(head->rlink==head && head->llink==head){
		newnode->llink=head;
		newnode->rlink=head;
		head->llink=newnode;
		head->rlink=newnode;
	}
	else if(current->rlink==head && current->data<add_data){ //加在最後面的情況 
		newnode->llink=current;
		newnode->rlink=head;
		current->rlink=newnode;
		head->llink=newnode;
	}
	else{
		newnode->llink=current->llink;
		newnode->rlink=current;
		current->llink->rlink=newnode;
		current->llink=newnode;
	}
}

void deletenode(Node *head,int deldata){
	Node *current=head->rlink;
	while(current->data!=deldata && current!=head){ //cur!=head為了要有不存在delnode的情況  
		current=current->rlink;
	}
	if(current==head){
		printf("error");
		return ;
	}
	if(current->rlink==head){
		current->llink->rlink=head;
		head->llink=current->llink;
	}
	else{
		current->llink->rlink=current->rlink;
		current->rlink->llink=current->llink;
	}
	free(current);
}

void printf(Node *head){
	Node *current=head->rlink;
	while(current!=head){
		printf("%d ",current->data);
		current=current->rlink;
	}
}

int search(Node *head,int key){ 
	Node *current=head->rlink;
	while(current!=head){
		if(current->data=key){
			return 1;
		}
		current=current->rlink;
	}
		return 0;
} 

int main(){
    Node* head = (struct Node*)malloc(sizeof(struct Node));
    head->llink=head;
    head->rlink=head;
	insert(head,3);
	insert(head,1);
	insert(head,5);
	insert(head,2);
	insert(head,10);
	deletenode(head,10); 
	printf(head);
}
