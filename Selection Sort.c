#include<stdio.h>
void selection_sort(int a[],int n){
    int i,j,min,p,temp;
    for(i=0;i<n-1;i++){
        min=a[i];
        p=i;
        for(j=i+1;j<n;j++){
            if(a[j]<min){
                min=a[j];
                p=j;
            }
        }
        if(p!=i){
            temp=a[i];
            a[i]=a[p];
            a[p]=temp;
        }
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
    selection_sort(a,n);
    printf("Sorted array:\n");
    for(i=0;i<n;i++) {
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}
