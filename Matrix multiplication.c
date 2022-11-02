#include<stdio.h>

int main(){
    int arr1[3][3],arr2[3][3];
    printf("Enter the 1st 3x3 matrix:\n");
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            scanf("%d",&arr1[i][j]);
        }
    }
    printf("Enter the 2nd 3x3 matrix:\n");
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            scanf("%d",&arr2[i][j]);
        }
    }
    printf("Multiplication of 1st and 2nd matrix:\n");
    for(int i=0; i<3; ++i){
        for(int j=0; j<3; ++j){
            int sum=0;
            for(int k=0; k<3; ++k){
                sum += arr1[i][k]*arr2[k][j];
            }
            printf("%d ",sum);
        }
        printf("\n");
    }
    return 0;
}
