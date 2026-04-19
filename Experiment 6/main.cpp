#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

vector<int> adj[26];
bool vis[26], instack[26];
stack<int> topo;

bool dfs(int v) {
    if (instack[v]) return true;
    if (vis[v]) return false;
    vis[v] = true;
    instack[v] = true;
    for (int u : adj[v]) {
        if (dfs(u)) return true;
    }
    instack[v] = false;
    topo.push(v);
    return false;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<string> str(n);
    for (int i = 0; i < n; i++) cin >> str[i];

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            bool found_diff = false;
            int len = min(str[i].length(), str[j].length());
            for (int k = 0; k < len; k++) {
                if (str[i][k] != str[j][k]) {
                    found_diff = true;
                    adj[str[i][k] - 'a'].push_back(str[j][k] - 'a');
                    break;
                }
            }
            if (!found_diff && str[i].length() > str[j].length()) {
                cout << "Impossible" << endl;
                return 0;
            }
        }
    }

    bool cycle = false;
    for (int i = 0; i < 26; i++) {
        if (!vis[i]) {
            if (dfs(i)) {
                cycle = true;
                break;
            }
        }
    }

    if (cycle) {
        cout << "Impossible" << endl;
    } else {
        string result = "";
        vector<bool> in_topo(26, false);
        while (!topo.empty()) {
            int curr = topo.top();
            topo.pop();
            result += (char)(curr + 'a');
            in_topo[curr] = true;
        }
        
        string final_res = "";
        for(int i = 25; i >= 0; i--) {
        
        }
        
        cout << result;
        for (int i = 0; i < 26; i++) {
            if (!in_topo[i]) cout << (char)(i + 'a');
        }
        cout << endl;
    }

    return 0;
}
