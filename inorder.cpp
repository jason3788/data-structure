#include<stdlib.h>
#include<stdio.h>
struct Node{
	int data;
	Node *left;
	Node *right;
};

void inorder(Node *node){
	if(node==NULL){
		return;
	}
	inorder(node->left);
	printf("%d",node->data);
	inorder(node->right); 
}
