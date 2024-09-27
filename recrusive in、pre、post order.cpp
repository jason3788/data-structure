#include<stdlib.h>
#include<stdio.h>
struct node{
	int data;
	struct node* left;
	struct node* right;
};
typedef struct node Node;


void recursive_inorder(Node *root){
	if(root==NULL){
		return;
	}
	recursive_inorder(root->left);
	printf("%d\n",root->data);
	recursive_inorder(root->right);
}

void recursive_preorder(Node *root){
	if(root==NULL){
		return;
	}
	printf("%d\n",root->data);
	recursive_preorder(root->left);
	recursive_preorder(root->right);
}

void recursive_postorder(Node *root){
	if(root==NULL){
		return;
	}
	recursive_postorder(root->left);
	recursive_postorder(root->right);
	printf("%d\n",root->data);
}
struct node* create_node(int key){
	Node *newnode=(Node *)malloc(sizeof(Node));
    
	newnode->data=key;
	newnode->left=NULL;
	newnode->right=NULL;
	return newnode;
}

void destorytree(struct node* root){
	if(root==NULL){
		return;
	}
	destorytree(root->left);
	printf("%d is delelte\n",root->data);
	destorytree(root->right);
	free(root);
}

bool search(struct node* root,int key){
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
		printf("search %d\n",root->data);
	}
}
/*void levelorder1(struct node *root){
	struct node *temp;
	queue<struct node*>q;
	q.enquque(root);
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

void levelorder2(struct node *root){
	struct node *temp=root;
	queue<struct node*>p;
	while(tmep!=NULL){
		printf("%d",temp->data);
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
		if(temp->right!=NULL){
			q.enqueue(temp->right);
		}
		temp=q.dequeue();
	}
}*/

struct node* insert_left(struct node *root,int key){
	root->left=create_node(key);
	return root->left;
}

struct node* insert_right(struct node *root,int key){
	root->right=create_node(key);
	return root->right;
}
int main() {
  struct node* root = create_node(1);
  insert_left(root, 2);
  insert_right(root, 3);
  insert_left(root->left, 4);

  printf("Inorder traversal \n");
  recursive_inorder(root);

  printf("\nPreorder traversal \n");
  recursive_preorder(root);

  printf("\nPostorder traversal \n");
  recursive_postorder(root);
  
  search(root,500);
}
