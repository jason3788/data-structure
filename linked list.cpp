#include<stdlib.h>
#include<stdio.h>
struct node{
	int val;
	node *next;
};
typedef struct node Node;

void printList(Node **head){
  Node *current=*head;
  while (current != NULL)
  {
     printf(" %d ", current->val);
     current = current->next;
  }
}

bool searchnode(Node **head,int key){
	Node *current=*head;
	while(current!=NULL){
		if(current->val==key){
			return 1;
		}
		else
			current=current->next;
	}	
	return 0;
}

int indexof(Node **head,int key){
	Node *current=*head;
	int i=0; //設i=1是因為當找到key時i不會+1，所以會少算一個
	while(current!=NULL){
		if(current->val==key){
			i++;
			return i;
		}
		else{
			i++;
			current=current->next;
		}
	} 
	return -1;
}

void pushback(Node **head,int add_data){
	Node *current=*head;
	while(current->next!=NULL){
		current=current->next;
	}
	current->next=(Node *)malloc(sizeof(Node));
	current->next->val=add_data;
	current->next->next=NULL;
}

void pushfront(Node **head,int add_data){
	Node *newnode;
	newnode=(Node *)malloc(sizeof(Node));
	newnode->val=add_data;
	newnode->next=*head;
	*head=newnode;
}
void insertafter(Node *prenode,int add_data){
	if(prenode==NULL){
		return ;
	}
	else{
		Node *newnode; 
		newnode=(Node *)malloc(sizeof(Node));
		newnode->val=add_data;
		newnode->next=prenode->next; //61 62行不能交換順序 
		prenode->next=newnode;		
	}
}

int removelast(Node **head){
	int removeval;
	Node *current=*head;
	/*if(head->next==NULL){
		removeval=head->val;
		free(head);
		return removeval; 
	}*/
	while(current->next->next!=NULL){
		current=current->next;
	}
	removeval=current->next->val;
	free(current->next);
	current->next=NULL; //需要這行所以要設CURRENT為倒數第二個節點 
	return removeval;
}
int removefirst(Node **head){
	int removeval;
	Node *nextnode=NULL;
	if(head==NULL){
		return -1;
	}
	removeval=(*head)->val;
	nextnode=(*head)->next;
	free(head);
	*head=nextnode;
	return removeval;
}
int removeafter(Node *prenode){
	int removeval;
	Node *delnode;
	if(prenode==NULL){
		return -1;
	}
	delnode=prenode->next;
	prenode->next=delnode->next;
	removeval=prenode->next->val;
	free(delnode);
	return removeval;		
}

int remove_by_index(Node **head,int n){ //講義有問題，自己寫的,記得筆記 
	int i;
	int removeval;
	Node *current=*head;
	Node *delnode;
	for(i=1;i<n-1;i++){
		if(current->next==NULL){
			return -1;
		}
		current=current->next;
	}
	if(current->next==NULL){
		return -1;
	}
	delnode=current->next;
	removeval=delnode->val;
	current->next=delnode->next;
	free(delnode);
	return removeval;	
} 

int main(){
	Node *head=NULL;
    pushfront(&head,7);
	pushback(&head,3);
	pushback(&head,8);
	insertafter(head->next,5);
	pushfront(&head,2);
	insertafter(head->next,0);
    printf("%d",searchnode(&head,5));
	printf("%d",indexof(&head,3));
	removelast(&head);
	removefirst(&head);
	removeafter(head->next);
	remove_by_index(&head,3);
	printList(&head);
	
}
