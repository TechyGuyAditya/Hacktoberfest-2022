#include<stdio.h>

int main(){
    int num,fact = 1;
    printf("Enter an integer: ");
    scanf("%d",&num);
    if(num == 0){
        printf("Factorial of 0 is 1");
    }
    else{
        for(int i=2; i<=num; ++i){
            fact *= i;
        }
        printf("Factorial of %d is %d",num,fact);
    }
    return 0;
}
