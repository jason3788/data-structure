#include<stdlib.h>
#include<stdio.h>
int front=0,rear=-1,a[50];
void enqueue(int add_data){
	rear++;
	a[rear]=add_data;
}
void dequeue(){
	front++;
}
void display(){
	int i;
	for(i=front;i<=rear;i++){
		printf("%d ",a[i]);
	}
}
int main(){
	enqueue(5);
	enqueue(2);
	dequeue();
	enqueue(0);
	enqueue(4);
	enqueue(7);
	dequeue();
	display();
	
}
