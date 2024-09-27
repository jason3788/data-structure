#include<stdlib.h>
#include<stdio.h>
int top=-1;
int a[50];
void push(int add_data){
	top++;
	a[top]=add_data;
} 
void pop(){
	top--;
}
void display(){
	int i;
	for(i=top;i>=0;i--){
		printf("%d ",a[i]);
	}
}
int main(){

	push(5);
	push(2);
	push(0);
	pop();
	push(3);
	push(7);
	pop();
	push(8);
	display();
}

