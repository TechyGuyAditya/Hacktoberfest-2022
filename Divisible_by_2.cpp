#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n <= 0)
            return false;
        float ret = log(n)/log(4);
        if(ret - (int)ret < 0.000000001)
            return true;
        else 
            return false;
    }
};
int main(){
  int n=16;
  Solution s;
  cout<<s.isPowerOfFour(n);
}
