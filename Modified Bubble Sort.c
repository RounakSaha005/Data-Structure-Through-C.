#include<stdio.h>
void bubble_sort(int a[],int n){
    int i,j,temp,flag;
    for(j=0;j<n-1;j++){
        flag=1;
        for(i=0;i<n-1-j;i++){
            if(a[i]>a[i+1]){
                temp=a[i];
                a[i]=a[i+1];
                a[i+1]=temp;
                flag=0;
            }
        }
        if(flag==1)
            break;
    }
}
int main(){
    int a[20],n,i;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    printf("Enter %d elements:\n", n);
    for (i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    printf("Sorted array:\n");
    for (i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    printf("\n");
    return 0;
}