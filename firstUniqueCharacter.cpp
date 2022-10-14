#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int firstUniqChar(string s) {
        string pos;
        vector<int> freq;
        int len = 0;
        for(int i = 0; i < s.length(); i++) {
            if(pos.find(s[i]) == string::npos) {
                pos += s[i];
                freq.push_back(1);
                len++;
            } else {
                freq[pos.find(s[i])]++;
            }
        }
        for(int i = 0; i < len; i++) {
            if(freq[i] == 1) {
                return s.find(pos[i]);
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    cout << s.firstUniqChar("dddccdbba") << endl;

    return 0;
}