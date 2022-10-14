#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
class Solution {
public:
    vector<int> returnPattern(string word) {
        map<int, char> m;
        vector<int> v;
        int pt = 0;
        for(auto i : word) {
            int flag = 0;
            for(auto j : m) {
                if(j.second == i) {
                    v.push_back(j.first);
                    flag = 1;
                }
            }
            if(flag == 0) {
                pt++;
                v.push_back(pt);
                m[pt] = i;
            }
        }
        return v;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<vector<int>> pat;
        for(auto i : words) {
            pat.push_back(returnPattern(i));
        }
        vector<int> src = returnPattern(pattern);
        
        vector<string> ret;
        for(int i = 0; i < words.size(); i++) {
            if(pat[i] == src)
                ret.push_back(words[i]);
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<string> words = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";
    vector<string> ret = s.findAndReplacePattern(words, pattern);
    for(auto i : ret)
        cout << i << endl;


    return 0;
}
