#include<stdlib.h>
#include<stdio.h>
struct Node{
	int val;
	Node *next;
}*front=NULL,*rear=NULL;

void enqueue(int add_data){
	Node *newnode=(Node *)malloc(sizeof(Node));
	newnode->val=add_data;
	if(front==NULL){
		front=rear=newnode;
	}
	else{
		rear->next=newnode;
		rear=newnode;
	}
	newnode->next=NULL;
}
void dequeue(){
	if(front==NULL){
		printf("error");
	}
	else{
		Node *temp=front;
		front=front->next;
		free(temp);
	}
}
void display(){
	Node *cur=front;
	while(cur!=NULL){
		printf(" %d ",cur->val);
		cur=cur->next; 
	}
}
int main(){
	enqueue(3);
	enqueue(7);
	enqueue(8);
	dequeue();
	enqueue(9);
	dequeue();
	enqueue(5);
	enqueue(20);
	dequeue();
	enqueue(18);
	enqueue(33);
	dequeue();
	display();
} 
