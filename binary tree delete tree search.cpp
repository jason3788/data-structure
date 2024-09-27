#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node *left,*right;
};
struct node *root=NULL;

void deletetree(struct node* node){
	if(node==NULL){
		return;
	} 
	deltree(node->left);
	deltree(node->right);
	printf("delete node:%d",node->data);
	free(node);
}

bool search(struct node *root,int key){
	if(root==NULL){
		return false;
	}
	else if(search(root->left,key)){
		return true;
	}
	else{
		return search(root->right,key);
	}
}
