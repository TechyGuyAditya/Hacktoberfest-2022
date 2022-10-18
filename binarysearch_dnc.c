#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int *arr;
int n;
int step_count;

clock_t start,stop;

void sortArray()
{
    int i,j,t;

    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(arr[i]>arr[j])
            {
                t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
}

void input()
{
   // printf("Enter the size of array : \n");
   // scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));

    for(int i=0;i<n;i++)
    {
        arr[i]=rand();
    }

    sortArray();
    //sorting the array because Binary search works only for sorted array

}

void display()
{
    printf("Array Elements : \n");
    for(int i=0;i<n;i++)
    printf("%d  ",arr[i]);

    printf("\n");
}

int binSearch(int item)
{
    start=clock();

    int low=0,high=n-1,mid;
     step_count=0;

    step_count++;



    step_count++;
    while(low<=high)
    {
        step_count++;



        mid=(low+high)/2;
        step_count++;




        step_count++;
        if(arr[mid]==item)
        {
            step_count++;
            return mid;
        }



        else if(arr[mid]>item)
        {
            step_count++;


        high=mid-1;
            step_count++;
        }

        else
        {
        low=mid+1;
        step_count++;
        }
    }

    stop=clock();


    step_count++;
    return -1; //returns -1 when element not found in array

}

int main()
{

    printf("S.No   Value of n  BestCase  WorstCase(1)  WorstCase(2)  AverageCase \n");

   /* for(n=10000;n<=100000;n=n+10000)
    {
        //input();

        arr=(int*)malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
        {
        arr[i]=rand()%100;
        }

        sortArray();
        
        //check for best case ---> occurs when element occurs at index = n/2
        int a1=binSearch(arr[n/2]);
        double a=((double)stop-start)/CLOCKS_PER_SEC;

        //check for worst case (1) ---> occurs when element is present at index=0 or index=n-1
        int b1=binSearch(arr[0]);
        double b=((double)stop-start)/CLOCKS_PER_SEC;

        //check for worst case (2) ---> occurs when element is not present at all in the array
        int c1=binSearch(-100); //since rand() cannot generate -ve no. , therefore passing -100
        double c=((double)stop-start)/CLOCKS_PER_SEC;

        //check for average case ---> occurs when element is present in array at some index other than 0,n-1,n/2
        int d1=binSearch(arr[rand()%n]);
        double d=((double)stop-start)/CLOCKS_PER_SEC;

        printf("%d      %d      %lf sec    %lf sec     %lf sec      %lf sec \n",(n/10000),n,a,b,c,d);


    } */


    for(n=1000;n<=10000;n=n+1000)
    {
        //input();

        arr=(int*)malloc(n*sizeof(int));

        for(int i=0;i<n;i++)
        {
        arr[i]=rand()%100;
        }

        sortArray();
        
        //check for best case ---> occurs when element occurs at index = n/2
        int a1=binSearch(arr[n/2]);
        int a=step_count;

        //check for worst case (1) ---> occurs when element is present at index=0 or index=n-1
        int b1=binSearch(arr[n-1]);
        int b=step_count;

        //check for worst case (2) ---> occurs when element is not present at all in the array
        int c1=binSearch(-100); //since rand() cannot generate -ve no. , therefore passing -100
        int c=step_count;

        //check for average case ---> occurs when element is present in array at some index other than 0,n-1,n/2
        int d1=binSearch(arr[rand()%n]);
        int d=step_count;

        printf("%d      %d         %d          %d            %d               %d     \n",(n/1000),n,a,b,c,d);


    }

    return 0;
}
