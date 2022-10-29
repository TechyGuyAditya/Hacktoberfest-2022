/*
Finding pattern in string using KMP Algorithm
Given two strings P ans S consisting of lowercase english letters, find whether P is preent in S as a substring or not.
Input format :
First and only line of Input contains two space separated strings P and S consisting of only lowercase english letters.
Output format :
For each input print YES if string P is present in string S ,otherwise NO.
*/

#include<bits/stdc++.h>
using namespace std;

void Prefix_array(string p, vector<int> &lps) 
{
    int len = 0;
    int index = 1;
    int m = p.size();

    while (index < m)
    {
        if (p[index] == p[len])
        {
            len += 1;
            lps[index] = len;
            index += 1;
        }

        else
        {
            if (len == 0)
            {
                lps[index] = 0;
                index += 1;
            }

            else
            {

                len = lps[len - 1]; 
            }
        }
    }
}

void code()
{
    string p,s;
    cin>>p>>s;
    int m = p.size();
    int n = s.size();
    vector<int> lps(m, 0);

    Prefix_array(p, lps);
    int index1 = 0;
    int index2 = 0;

    while (index1 < n)
    {
        if (s[index1] == p[index2])
        {
            index2++;
            index1++;
            if (index2 == m)
            {
                cout<<"YES"<<endl;
                return;
            }

            if (index1 == n)
            {
                cout<<"NO"<<endl;
                return;
            }
        }
        else
        {
            if (index2 == 0)
            {
                index1 += 1;
            }
            else
            {
                index2 = lps[index2 - 1];
            }
        }
    }

    cout<<"NO"<<endl;
    return;
}
int main(){
    code();
}

/*

Input:
3
xxy yxxyxxy
a baac
cfg cgfgfc

Output:
YES
YES
NO

*/


