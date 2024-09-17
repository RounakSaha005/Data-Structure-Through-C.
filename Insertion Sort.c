#include<stdio.h>
void insertion_sort(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0&&a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main(){
    int a[20],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    insertion_sort(a,n);
    printf("Sorted array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}