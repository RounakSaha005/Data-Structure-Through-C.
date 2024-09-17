#include<stdio.h>
typedef struct date {
	int dd;
	int mm;
	int yy;
}Date;
Date calcAge(Date d1,Date d2){
    Date temp;
    if(d1.dd>=d2.dd)
        temp.dd=d1.dd-d2.dd;
    else{
        temp.dd=d1.dd+30-d1.dd;
        d1.mm--;
    }
    if(d1.mm>=d2.mm)
        temp.mm=d1.mm-d2.mm;
    else{
        temp.mm=d1.mm+12-d1.mm;
        d1.yy--;
    }
    temp.yy=d1.yy-d2.yy;
    return(temp);
}
int main(){
    Date cur,dob,age;
    printf("Enter Date of Birth (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&dob.dd,&dob.mm,&dob.yy);
    printf("Enter Current Date (DD/MM/YYYY): ");
    scanf("%d/%d/%d",&cur.dd,&cur.mm,&cur.yy);
    age=calcAge(cur,dob);
    printf("Your Age is %d Years %d Months and %d Days.",age.yy,age.mm,age.dd);
    return 1;
}
