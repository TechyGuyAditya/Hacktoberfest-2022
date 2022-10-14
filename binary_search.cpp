#include<bits/stdc++.h>
using namespace std;
int binarysearch(int arr[],int n,int key)
{
    int mid;
    int start=0;
    int end=n-1;
    mid=start + (end-start)/2;

    while(start<=end)
    {
        if(arr[mid]==key)
        {
          return mid;
        }
        if(arr[mid]<key)
        {
            start=mid+1;;
        }
        else
        {
            end=mid-1;
        }
        mid=start+(end-start)/2;

    }
    return -1;
}
int main()
{
    int even_arr[6]={1,2,3,4,5,6};
    int odd_arr[7]={3,5,6,7,8,9,10};
    int a=binarysearch(even_arr,6,5);
    cout<<a<<endl;
    int b=binarysearch(odd_arr,7,5);
    cout<<b<<endl;

return 0;
}
