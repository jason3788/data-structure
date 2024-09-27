#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *root=NULL;

struct node* search(struct node *root,int key){
	if(root==NULL || root->data==key){
		return root;
	}
	if(key>root->data){
		return search(root->right,key);
	}
	else{
		return search(root->left,key);
	}	
}
void preorder(struct node* root)
{
    if (root != NULL) {
    	printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct node* newnode(int new_data){
	struct node *newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=new_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

struct node* insert(struct node *root,int add_data){
	if(root==NULL){
		return newnode(add_data);
	}
	
	if(add_data<root->data){
		root->left=insert(root->left,add_data);
	}
	else if(add_data>root->data){
		root->right=insert(root->right,add_data);
	}
	return root; //¾ã­Óbinary treeªºroot	
}

struct node* maxkeynode(struct node *root){
	struct node *current=root;
	while(current->right!=NULL){
		current=current->right;
	}
	return current;
}

struct node* delnode(struct node *root,int del_data){
	if(root==NULL){
		return root;
	}
	
	if(del_data<root->data){
		root->left=delnode(root->left,del_data);
	}
	else if(del_data>root->data){
		root->right=delnode(root->right,del_data);
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
		
		struct node *temp=maxkeynode(root->left);
		root->data=temp->data;
		root->left=delnode(root->left,temp->data);
	}
	return root;
}
int height(struct node *root){
	if(root == NULL)
		return 0;    
	else{	
        int left_height=height(root->left);   
        int right_height=height(root->right); 
        if (left_height > right_height)          
        	return left_height+1; 
        else
        	return right_height+1;
	}
}
int main()
{
    /* Let us create following BST
              50
           /     \
          30      70
         /  \    /  \
       20   40  60   80 */
    struct node* root = NULL;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

 
    printf("Inorder traversal of the given tree \n");
    preorder(root);
    printf("Tree height=%d",height(root));
    
 
    return 0;
}
