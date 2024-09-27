#include <iostream>
using namespace std;
template <class T> class stack;
template <class T> class Node{
	friend class stack<T>;
	private:
		T data;
		Node<T> *next;
};

template <class T> class stack{
	private:
		Node<T> *top;
	public:
		stack(){
			top=NULL;
		}
		void push(T val){
			Node<T> *newnode;
			*newnode=new stack()
			if(top==NULL){
				
			}
		}
};
