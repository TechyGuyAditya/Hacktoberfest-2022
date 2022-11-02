#include<stdio.h>

int main(){
    int num;
    int binary_num[100];
    printf("Enter an integer: ");
    scanf("%d",&num);
    int num_copy = num;
    int i = 0;
    while(num > 0){
        binary_num[i] = num%2;
        num /= 2;
        i++;
    }
    int j = i;
    if(num_copy == 0){
        printf("The binary representation of %d is 0",num_copy);
    }
    else{
        printf("The binary representation of %d is ",num_copy);
        for(int j = i-1; j>=0; --j){
            printf("%d",binary_num[j]);
        }
    }
    return 0;
}
