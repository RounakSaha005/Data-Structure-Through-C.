#include<stdio.h>
int linear_search(int a[],int key,int n){
	int i;
	for(i=0;i<=n;i++){
		if (a[i]==key)
		return i;
	}
	return -1;
}
int main(){
	int a[10],n,i,key;
	printf("Enter the number of elements: ");
	scanf("%d",&n);
	printf("Enter the elements:\n");
	for(i=0;i<n;i++)
	scanf("%d",&a[i]);
	printf("Enter the elements you want to search: ");
	scanf("%d",&key);
	i=linear_search(a,key,n);
	if(i==-1)
	printf("%d is not found",key);
	else
	printf("%d is found at %d position",key,i+1);
	return 0;
}
