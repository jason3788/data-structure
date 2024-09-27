#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
typedef struct node node;
node *root=NULL;

void inorder(node *root){
	if(root==NULL){
		return;
	}
	inorder(root->left);
	printf("%d",root->data);
	inorder(root->right);
}

void level_order(node *root){
	queue<node *>q;
	node *temp=root;
	while(temp!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
		temp=q.dequeue();
	}
}
void levelorder(struct node *node){
	queue<node *>q;
	node *temp;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue();
		printf("%d",temp->data);
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}	
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
	}
}

node *new_node(int add_data){
	node *newnode=(node *)malloc(sizeof(node));
	newnode->data=add_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

node *insert(node *root,int add_data){
	queue<node *>q;
	node *temp;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue();
		if(temp->left==NULL){
			temp->left=new_node(add_data);
			return;
		}
		else{
			q.enqueue(temp->left);
		}
		if(temp->right==NULL){
			temp->right=new_node(add_data);
			return;
		}
		else{
			q.enqueue(temp->right);
		}
	}
}

node deletenode(node *root , int del_data){
	if(root==NULL){
		return;
	}
	queue<node *>q;
	node *temp;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue;
		if(temp->data==del_data){
			node *cur=root;
			node *prev;
			while(cur->right!=NULL){
				prev=cur;
				cur=cur->right;
			}
			temp->data=cur->data;
			prev->right=cur->left;
			free(cur);
			return;
		}
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL){
			q.enqueue(root->right);
		}
	}
}

void deletetree(node *root){
	if(root==NULL){
		return;
	}
	destorytree(root->left);
	printf("delete %d",root->data);
	destorytree(root->right);
	free(root);
}

bool *search(node *root,int key){
	if(root==NULL){
		return 0;
	}
	else{
		if(root->data==key){
			return 1;
		}
		else if(search(root->left,key)){
			return 1;
		}
		else{
			return search(root->right,key);
		}
	}
}
