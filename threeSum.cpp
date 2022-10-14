#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        vector<int> pp;
        int zeroctr = 0;
        int a,b,c, target;
        map<int,int> p,n;
        for(auto i : nums) {
            if(i == 0) {
                zeroctr++;
            }
            else if(i > 0) {
                p[i]++;
            }
            else {
                n[i]++;
            }
        }
        if(zeroctr >= 3) {
            pp.push_back(0);
            pp.push_back(0);
            pp.push_back(0);
            ret.push_back(pp);
            pp.clear();
        }
        if(zeroctr > 0) {
            for(auto i : p) {
                if(i.first == 0) {
                    continue;
                }
                a = 0 - i.first;
                if(n.find(a) != n.end()) {
                    pp.push_back(a);
                    pp.push_back(0);
                    pp.push_back(i.first);
                    ret.push_back(pp);
                    pp.clear();
                }
            }
        }

        for(auto i : p) {
            for(auto j : p) {
                if(i == j)
                    continue;
                target = 0 - (i.first + j.first);
                if(n[target] > 0) {
                    pp.push_back(target);
                    pp.push_back(i.first);
                    pp.push_back(j.first);
                    ret.push_back(pp);
                    pp.clear();
                }
            }
            target = 0 - (i.first + i.first);
            if(n[target] > 1) {
                pp.push_back(target);
                pp.push_back(i.first);
                pp.push_back(i.first);
                ret.push_back(pp);
                pp.clear();
            }
        }
        for(auto i : n) {
            for(auto j : n) {
                if(i == j)
                    continue;
                target = 0 - (i.first + j.first);
                if(p[target] > 0) {
                    pp.push_back(i.first);
                    pp.push_back(j.first);
                    pp.push_back(target);
                    ret.push_back(pp);
                    pp.clear();
                }
            }
            target = 0 - (i.first + i.first);
            if(p[target] > 1) {
                pp.push_back(i.first);
                pp.push_back(i.first);
                pp.push_back(target);
                ret.push_back(pp);
                pp.clear();
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {-1,0,1,2,-1,-4,-2};
    vector<vector<int>> ret = s.threeSum(nums);
    for(auto i : ret) {
        for(auto j : i)
            cout << j << " ";
        cout << endl;
    }

    return 0;
}
