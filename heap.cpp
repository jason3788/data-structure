#include<stdio.h>
#include<stdlib.h>

int currentnode=++heapsize;
while(currentnode!=1 && heap[currentnode/2]<e){
	heap[currentnode]=heap[currentnode/2];
	currentnode/=2;
}
heap[currentnode]=e;


void deletemax(){
	if(!n){
		return 0; 
	}
	x=heap[1];
	k=heap[n];
	n--;
	for(int i=1,j=2;j<n;){
		if(j<n){
			if(heap[j].key<heap[j+1].key){
				j++;
			}
		}
		if(k.key>=heap[j].key){
			break;
		}
		heap[i]=heap[j];
		i=j;
		j*=2;
	}
	heap[i]=k;
	return &x;
}
