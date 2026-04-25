#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

void printArr(vector<int> arr) {
    for(auto it: arr)
        cout<<it<<' ';

    cout<<endl;
}

vector<int> buildLps(string pattern) {
    int m = pattern.size();
    vector<int> lps(m, 0);
    int i = 1, len = 0;

    while(i < m) {
        if(pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0)
                len = lps[len-1];
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMP(string text, string pattern) {
    int n = text.size(), m = pattern.size();
    vector<int> ans;
    vector<int> lps = buildLps(pattern);

    int i = 0, j = 0;

    while(i < n) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }

        if(j == m) {
            ans.push_back(i - j);
            j = lps[j-1];
        } else if(i < n && text[i] != pattern[j]) {
            if(j != 0)
                j = lps[j-1];
            else {
                i++;
            }
        }
    }

    return ans;
}

int main() {
    string text = "abcab", pattern = "ab";
    vector<int> kmpArr = KMP(text, pattern);

    printArr(kmpArr);

    return 0;
}
