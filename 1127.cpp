
void levelorder(struct node *root){
	struct node *temp;
	queue<struct node*>p;
	q.enquque(root);
	while(!q.empty()){
		temp=q.dequeue();
		printf("%d",temp->data);
		if(temp->left!=NULL){
			q.enqueue(temp->left);
		}
	}
}

struct node{
	int data;
	struct node* left;
	struct node* right;
};
struct node *root=NULL;

struct node* create_node(int add_data){
	struct node* newnode=(struct node*)malloc(sizeof(struct node));
	newnode->data=add_data;
	newnode->left=NULL;
	newnode->right=NULL;
	return node;
}

void insert(struct node *rooo,int add_data){
	struct node* temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue();
		if(temp->left==NULL){
			temp->left=create_node(add_data);
			break;
		}
		else{
			q.enqueue(temp->left);
		}
		if(temp->right==NULL){
			temp->right=create_node(add_data);
			break;
		}
		else{
			q.enqueue(temp->right);
		}
	}
}

void deletenode(struct node* root,int del_data){
	struct node* temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue();
		if(temp->data==del_data){
			struct node* current=root;
			struct node* prev;
			while(current->right!=NULL){
				prev=current;
				current=current->right;
			}
			temp->data=current->data;
			prev->right=current->left;
			free(current);
			return;
		}
	}
}
void delete_deepnode(struct node* root,struct node* del_node){
	struct node* temp;
	queue<struct node*>q;
	q.enqueue(root);
	while(!q.empty()){
		temp=q.dequeue();
		if(temp==del_node){
			temp=NULL;
			delete(del_node);
			return;
		}
		if(temp->left){
			if(temp->left==del_node){
				temp->left=NULL;
				delete(del_node);
				return;
			}
			else{
				q.enqueue(temp->left);
			}		
		}
		if(temp->right){
			if(temp->right==del_node){
				temp->right=NULL;
				delete(del_node);
				return;
			}
			else{
				q.enqueue(temp->right);
			}		
		}
	}
}

void preorder(struct tNode *root)
{
  struct tNode *current=NULL;
  struct sNode *s = NULL;  
  push(&s,root);
  while(!isEmpty(s)){
  	current=pop(&s);
  	printf("%d", current->data);
  	if(current->right!=NULL){
  		push(&s,current->right);	
	}
  	if(current->left!=NULL){
  		push(&s,current->left);	
	}
  }
}    

