#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node *search(struct node *root,int key){
	if(root==NULL || root->data==key){
		return root;
	}
	if(root->data<key){
		return search(root->right,key);
	}
	return search(root->left,key);
}

struct node *new_node(int add_data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=add_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insert(struct node *root,int add_data){
	if(root==NULL){
		return new_node(add_data);
	}
	if(root->data>add_data){
		root->left=insert(root->left,add_data);
	}
	if(root->data<add_data){
		root->right=insert(root->right,add_data);
	}
	return root;
}

struct node *MaxValue(struct node *root){
	struct node *current=root;
	while(current->right!=NULL){
		current=current->right;
	}
	return current;
}

struct node *deletenode(struct node *root,int del_data){
	if(root==NULL){
		return root;
	} 
	if(root->data>del_data){
		root->left=deletenode(root->left,del_data);
	}
	else if(root->data<del_data){
		root->right=deletenode(root->right,del_data);
	}
	else{
		if(root->left==NULL){
			struct node *temp=root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL){
			struct node *temp=root->left;
			free(root);
			return temp;
		}
		struct node *temp=MaxValue(root->left);
		root->data=temp->data;
		root->left=deletenode(root->left,temp->data);
	}
	return root;
}
