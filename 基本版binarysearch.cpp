#include <iostream>
using namespace std;
int binarysearch(int a[],int key,int n){
	int left=0,right=n-1;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		printf("mid=%d\n",mid);
		if(key>a[mid]){
			left=mid+1;
		}
		else if(key<a[mid]){
			right=mid-1;
		}
		else{
			return mid;
		} 	
	}
	return -1;
}
int main()
{
    int a[]={1,3,4,7,8,10},n;
    n=sizeof(a)/sizeof(a[0]);
    cout<<binarysearch(a,1,n)<<endl;
 	cout<<binarysearch(a,3,n)<<endl;
 	cout<<binarysearch(a,4,n)<<endl;
 	cout<<binarysearch(a,7,n)<<endl;
 	cout<<binarysearch(a,8,n)<<endl;
 	cout<<binarysearch(a,10,n)<<endl;
    return 0;
}
