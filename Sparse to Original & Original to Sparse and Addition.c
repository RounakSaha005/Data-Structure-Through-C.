#include <stdio.h>
#include <ctype.h>
#define MAX 10
void inputSparse(int mat[MAX][MAX],int rw,int col){
    printf("Enter the elements: ");
   int i,j;
   for(i=0;i<rw;i++){
        for(j=0;j<col;j++)
            scanf("%d",&mat[i][j]);
   }
}
void original2Sparse(int x[MAX][MAX],int p[MAX][3],int rw,int col){
    int i,j,k=1,c=0;
    for(i=0;i<rw;i++){
        for(j=0;j<col;j++){
            if(x[i][j]!=0){
                p[k][0] = i;
                p[k][1] = j;
                p[k][2] = x[i][j];
                k++;
                c++;
            }
        }
    }
    p[0][0] = rw;
    p[0][1] = col;
    p[0][2] = c;
}
void addSparse(int p[MAX][3],int q[MAX][3],int r[MAX][3]){
    if (p[0][0] != q[0][0] || p[0][1] != q[0][1]) {
        printf("Matrices dimensions do not match for addition!\n");
        return;
    }
    int i = 1, j = 1, k = 1;
    while(i<=p[0][2] && j<=q[0][2]){
        if(p[i][0]<q[j][0] || (p[i][0] == q[j][0] && p[i][1]<q[j][1])){
            r[k][0] = p[i][0];
            r[k][1] = p[i][1];
            r[k][2] = p[i][2];
            i++;
            k++; 
        }
        else if(p[i][0]>q[j][0] || (p[i][0] == q[j][0] && p[i][1]>q[j][1])){
            r[k][0] = q[j][0];
            r[k][1] = q[j][1];
            r[k][2] = q[j][2];
            j++;
            k++;
        }
        else{
            r[k][0] = p[i][0];
            r[k][1] = p[i][1];
            r[k][2] = p[i][2] + q[j][2];
            i++,j++,k++;
        }
    }
    while(i<=p[0][2]){
        r[k][0] = p[i][0];
        r[k][1] = p[i][1];
        r[k][2] = p[i][2];
        i++;
        k++; 
    }
    while(j<=q[0][2]){
        r[k][0] = q[j][0];
        r[k][1] = q[j][1];
        r[k][2] = q[j][2];
        j++;
        k++;   
    }
    r[0][0] = p[0][0];
    r[0][1] = p[0][1];
    r[0][2] = k - 1;
}
void sparse2Original(int r[][3],int z[MAX][MAX]){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            z[i][j] = 0;
        }
    }
    for(i=1;i<=r[0][2];i++){
        int row = r[i][0];
        int column = r[i][1];
        int value = r[i][2];
        z[row][column] = value;
    }
}
void displayMatrix(int mat[MAX][MAX],int rw,int col){
    int i,j;
    for(i=0;i<rw;i++){
        for(j=0;j<col;j++)
            printf("%d\t",mat[i][j]);
        
        printf("\n");
    }
}
int main(){
    int x[MAX][MAX]={0},y[MAX][MAX]={0},z[MAX][MAX]={0},p[MAX][3],q[MAX][3],r[MAX][3],rw1,rw2,col1,col2;
    printf("Enter the row and column for the first matrix: ");
    scanf("%d %d",&rw1,&col1);
    inputSparse(x,rw1,col1);
    printf("\nEnter the row and column for the second matrix: ");
    scanf("%d %d",&rw2,&col2);
    inputSparse(y,rw2,col2);
    original2Sparse(x,p,rw1,col1);
    original2Sparse(y,q,rw2,col2);
    addSparse(p,q,r);
    sparse2Original(r,z);
    printf("The first matrix: \n");
    displayMatrix(x,rw1,col1);
    printf("The second matrix: \n");
    displayMatrix(y,rw2,col2);
    printf("\nThe resultant matrix (in sparse form): \n");
    for(int i=0;i<=r[0][2];i++)
        printf("%d %d %d\n",r[i][0],r[i][1],r[i][2]);
    printf("The resultant matrix (in original form): \n");
    displayMatrix(z,rw1,col1);
    return 0;
}