#include<stdio.h>
#include<ctype.h>
void create_polly(int a[],int size){
    char ch='y';
    int p,c;
    while(toupper(ch)=='Y') {
        printf("Enter coefficient: ");
        scanf("%d",&c);
        printf("Enter exponent: ");
        scanf("%d",&p);
        a[p]=c;
        printf("Do you want to continue? (Y/N): - ");
        scanf(" %c",&ch); 
    }
}
void display_polly(int a[],int size){
    int i,j;
    for (i=size-1;i>=0;i--){
        if(a[i]!=0){
            printf("%dx^%d",a[i],i);
            if(i>0){
                for(j=i-1;j>=0;j--){
                    if(a[j]!=0){
                        printf(" + ");
                        break;
                    }
                }
            }
        }
    }
    printf("\n");
}
void add_polly(int a[],int b[],int c[],int size){
    int i;
    for (i=0;i<size;i++) {
        c[i]=a[i]+b[i];
    }
}
int main(){
    int p1[20]={0},p2[20]={0},p3[20]={0};
    printf("Enter data for 1st polynomial:-\n");
    create_polly(p1,20);
    printf("Enter data for 2nd polynomial:-\n");
    create_polly(p2,20);
    add_polly(p1,p2,p3,20);
    printf("1st polynomial: ");
    display_polly(p1,20);
    printf("2nd polynomial: ");
    display_polly(p2,20);
    printf("Resultant polynomial: ");
    display_polly(p3,20);
    return 0;
}
