#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;

int main(){
	node *curr,*head;
	int i;
	head=NULL;
	for(i=10;i>=1;i--){
		curr = (node*)malloc(sizeof(node));
		curr->data=i;
		curr->next=head;
		head=curr;
	}
	curr=head;
	while(curr!=NULL){
		printf("%d\n",curr->data);
		curr=curr->next;
	}
	return 0;
}
