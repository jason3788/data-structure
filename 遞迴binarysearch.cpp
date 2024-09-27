#include <iostream>
using namespace std;
int binarysearch(int a[],int key,int left,int right){
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(key>a[mid]){
			return binarysearch(a,key,mid+1,right);
		}
		else if(key<a[mid]){
			return binarysearch(a,key,left,mid-1);
		}
		else{
			return mid;
		}
	}
	return -1;
}
int main()
{
    int a[]={1,3,4,7,8,10,12},n;
    n=sizeof(a)/sizeof(a[0]);
    cout<<binarysearch(a,3,0,n-1)<<endl;
 	cout<<binarysearch(a,10,0,n-1)<<endl;
 	cout<<binarysearch(a,8,0,n-1)<<endl;
 	cout<<binarysearch(a,378,0,n-1)<<endl;
 	cout<<binarysearch(a,4,0,n-1)<<endl;
    return 0;
}
