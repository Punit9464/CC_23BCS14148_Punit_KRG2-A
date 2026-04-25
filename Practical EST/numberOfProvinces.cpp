#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

class DSU {
private:
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findParent(int u) {
        if(u == parent[u])
            return u;

        return parent[u] = findParent(parent[u]);
    }

    bool unionBySize(int u, int v) {
        int pu = findParent(u), pv = findParent(v);
        if(pu == pv)
            return false;

        else if(size[pv] > size[pu]) {
            parent[pu] = pv;
            size[pv] += size[pu];
        } else {
            parent[pv] = pu;
            size[pu] += size[pv];
        }

        return true;
    }
};

int numberOfProvinces(vector<vector<int>> &arr) {
    int n = arr.size(), m = arr[0].size();
    int total = n;

    DSU ds(n);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(arr[i][j] == 1) {
                if(ds.unionBySize(i+1, j+1))
                    total -= 1;
            }
        }
    }

    return total;
}

int main() {
    vector<vector<int>> isConnected = {
        {1, 1, 0},
        {1, 1, 0},
        {0, 0, 1}
    };

    int ans = numberOfProvinces(isConnected);
    cout<<ans<<endl;

    return 0;
}
