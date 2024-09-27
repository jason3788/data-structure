#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data;
	Node *next;
}*top=NULL;

void push(int val){
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->data=val;
	if(top==NULL){
		newnode->next=NULL;
	} 
	else{
		newnode->next=top;
	}
	top=newnode;
	//printf("%d is insert",val);
} 
void pop(){
	if(top==NULL){
		printf("empty");
	}
	else{
		Node *temp=top;
		top=top->next;
		//printf("%d is delete",temp->data);
		free(temp);
	}
}
void display(){
	Node *temp=top;
	while(temp!=NULL){
		printf("%d--->", temp->data);
        temp = temp->next;
	}
}
int main(){
	push(27);
	push(98);
	pop(); 
	push(24);
	push(9);
	push(83);
	pop();
	display();
}
