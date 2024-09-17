#include <stdio.h>
void input(int a[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            scanf("%d",&a[i][j]);
        }
    }
}
void display(int a[10][10],int r,int c){
    int i,j;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
int sparse(int a[10][10],int r,int c){
    int i,j,count=0;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            if(a[i][j]==0){
                count++;
            }
        }
        if(count>((r*c)/2)){
            return 1;
        }
    }
    return 0;
}
int main(){
    int a[10][10],r,c;
    printf("Enter the rows for the matrix: ");
    scanf("%d",&r);
     printf("Enter the coloumns for the matrix: ");
    scanf("%d",&c);
    printf("Enter data for the matrix:-\n");
    input(a,r,c);
    printf("The matrix is:-\n");
    display(a,r,c);
    if(sparse(a,r,c)){
        printf("Its a Sparse Matrix\n");
    }
    else{
        printf("Its not a Sparse Matrix\n");
    }
    return 0;
}
