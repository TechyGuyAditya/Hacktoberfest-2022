#include<stdio.h>
#include<math.h>

int main(){
    int binary_num;
    int num = 0;
    printf("Enter a binary number: ");
    scanf("%d",&binary_num);
    int binary_copy = binary_num;
    int i = 0;
    while(binary_num > 0){
        int remainder = binary_num%2;
        if(remainder%2 != 0){
            num += pow(2,i);
        }
        binary_num /= 10;
        i++;
    }
    printf("The decimal representation of %d is %d",binary_copy,num);
    return 0;
}
