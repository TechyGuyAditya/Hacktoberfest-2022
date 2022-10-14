#include <bits/stdc++.h>
using namespace std;

int minLenSub(int arr[], int n, int k){
    unordered_map<int,int> m;
    int presum=0, res=INT_MAX;
    for(int i=0;i<n;i++){
        presum+=arr[i];
        if(presum==k) res=min(res,i+1);
        if(m.find(presum-k)!=m.end()){
            res=min(res,i-m[presum-k]);
        }
        m[presum]=i;
    }
    return res;
}

int main() {
    int arr[] = {-8, -8, -3, 8};
    int n=4;
    int k=5;
    cout<<minLenSub(arr,n,k);
}