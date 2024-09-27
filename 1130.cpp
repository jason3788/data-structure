#include<stdlib.h>
#include<stdio.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

void re_preorder(struct node *node){
	if(node==NULL){
		return;
	}
	printf("%d",node->data);
	re_preorder(node->left);
	re_preorder(node->right);
}

void inorder(struct node *root){
	struct node *temp=root;
	stack<struct node*>s;
	while(1){
		while(temp!=NULL){
			q.push(temp);
			temp=temp->left;
		}
		if(!s.empty()){
			temp=q.pop();
			printf("%d",temp->data);
			temp=temp->right;
		}
		else{
			break;
		}
	}
}
void levelorder(struct node *node){
	struct node *temp=root;
	queue<struct node*>q;
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
	struct node *temp;
	queue<struct node*>q;
	q.enueue(root);
	while(!q.empty()){
		temp=*q.dequeue();
		printf("%d",temp->data);
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
	}
}

struct node* create_node(int add_data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=add_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void insert(struct node *root,int add_data){
	struct node *temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.front();
		q.dequeue();
		if(temp->left==NULL){
			temp->left=create_node(add_data);
			return;
		}
		else{
			q.enqueue(temp->left);
		}
		if(temp->right==NULL){
			temp->right=create_node(add_data);
			return;
		}
		else{
			q.enqueue(temp->right);
		}
	}
}

void deletenode(struct node *root,int del_data){
	struct node *temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.front();
		q.dequeue();
		if(temp->data==del_data){
			struct node *current=root;
			struct node *prev;
			while(current->right!=NULL){
				prev=current;
				current=current->right;
			}
			temp->data=current->data;
			prev->right=current->left;
			free(current);
			return;
		}
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
	}
	printf("not found");
}

void del_deepnode(struct node *root,struct node *del_node){
	struct node *temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.front();
		q.dequeue();
		if(temp==del_node){
			temp=NULL;
			free(del_node);
			return;
		}
		if(temp->left){
			if(temp->left==del_node){
				temp->left=NULL;
				free(del_node);
				return;
			}
			else{
				q.enqueue(temp->left);
			}
		if(temp->right){
			if(temp->right==del_node){
				temp->right=NULL;
				free(del_node);
				return;
			}
			else{
				q.enqueue(temp->right);
			}	
		}
	}
}


void destorytree(struct node *root){
	if(root==NULL){
		return;
	}
	destorytree(root->left);
	printf("delete %d",root->data);
	destorytree(root->right);
}


bool search(struct node *root,int key){
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
