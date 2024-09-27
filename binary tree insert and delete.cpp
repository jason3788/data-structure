#include<stdlib.h>
#include<stdio.h>
/*struct binarytree_node{
	int data;
	struct binarytree_node *left,*right;
};
typedef struct binarytree_node Node;
Node *root=NULL;
*/
struct node{
	int data;
	struct node *left;
	struct node *right;
};
struct node *root=NULL;

struct node *newnode(int data){
	struct node *node=(struct Node *)malloc(sizeof(Node));
	node->data=data;
	node->left=NULL;
	node->right=NULL;
	return node;
}
void insert(struct node *root,int data){
	struct Node *temp;
	queue<struct node *>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.front;
		q.dequeue;
		
		if(temp->left==NULL){
			temp->left=newnode(data);
			break;
		}
		else{
			q.enqueue(temp->left);
		}
		
		if(temp->right==NULL){
			temp->right=newnode(data);
			break;
		}
		else{
			q.enqueue(temp->right);
		}
	}
}

void delnode(struct node *root,int del_data){
	if(root==NULL){
		cout<<"tree is empty";
		return;
	}
	struct node *temp;
	queue<struct node *>q;
    q.enqueue(root);
    while(!q.empty()){
    	temp=q.front();
    	q.dequeue;
    	
    	if(temp->data==del_data){
    		struct node *current;
    		struct node *prev;
    		while(temp->right!=NULL){
    			prev=current;
    			current=current->right;
			}
			temp->data=current->data;
			prev->right=current->left;
			free(current);
			cout<<"finish delete";
			return;
		}
		if(temp->left!=NULL)
			q.enqueue(temp->left);
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
	}
	cout<<"not found";
}





 


