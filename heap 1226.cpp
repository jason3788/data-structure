

void heapinsert(int add_data,int heap[],int heapsize){
	int current=++heapsize;
	while(current!=1 && heap[current]<add_data){
		heap[current]=heap[current/2];
		current/=2;
	}
	heap[current]=add_data;
}

void heapdelete(int heap[],int heapsize){
	int x=heap[1];
	int k=heap[heapsize];
	heapsize--;
	int i,j;
	for(i=1;j=2;j<heapsize){
		if(heap[j]<heap[j+1]){
			j++;
		}
		if(k>heap[j]){
			break;
		}
		heap[i]=heap[j];
		i=j;
		j*=2;
	}
	heap[i]=k;
}
