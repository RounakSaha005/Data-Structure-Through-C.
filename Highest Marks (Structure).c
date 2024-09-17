#include<stdio.h>
struct student{
    int roll;
    char name[30];
    int total;
};
int main(){
    struct student s[20];
    int n,max,i,j;
    printf("Enter no. of students: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter Roll No: ");
        scanf("%d",&s[i].roll);
        printf("Enter Name: ");
        fflush(stdin);
        gets(s[i].name);
        printf("Enter total marks: ");
        scanf("%d",&s[i].total);
    }
    max=s[0].total;
    j=0;
    for(i=1;i<n;i++){
        if(s[i].total>max){
            max=s[i].total;
            j=i;
        }
    }
    printf("Highest Marks = %d",max);
    printf("\nAnd Name = %s",s[j].name);
    return 1;
}