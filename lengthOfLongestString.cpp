#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string t = "";
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (t.find(s[i]) != string::npos) {
                ans = max(ans, (int)t.size());
                t = t.substr(t.find(s[i]) + 1);
            }
            t += s[i];
        }
        ans = max(ans, (int)t.size());
        return ans;
    }
};

int main()
{
    Solution s;
    string str = "abcabcbb";
    cout << s.lengthOfLongestSubstring(str);

    return 0;
}
