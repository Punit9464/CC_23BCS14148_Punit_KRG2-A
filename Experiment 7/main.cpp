#include <bits/stdc++.h>
using namespace std;

class Triplet {
public:
    int stops, cost, node;
    Triplet(int s, int c, int n) {
        stops = s;
        cost = c;
        node = n;
    }
};

class Pair {
public:
    int node, cost;
    Pair(int n, int c) {
        node = n;
        cost = c;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        // Adjacency list
        vector<vector<Pair>> adj(n);
        for (auto &flight : flights) {
            int u = flight[0];
            int v = flight[1];
            int w = flight[2];
            adj[u].push_back(Pair(v, w));
        }

        // Queue: {stops, cost, node}
        queue<Triplet> q;
        q.push(Triplet(0, 0, src));

        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        while (!q.empty()) {
            Triplet tp = q.front();
            q.pop();

            int stops = tp.stops;
            int cost = tp.cost;
            int node = tp.node;

            if (stops > k) continue;

            for (auto &p : adj[node]) {
                int adjNode = p.node;
                int edgeCost = p.cost;

                if (cost + edgeCost < dist[adjNode]) {
                    dist[adjNode] = cost + edgeCost;
                    q.push(Triplet(stops + 1, cost + edgeCost, adjNode));
                }
            }
        }

        return (dist[dst] == INT_MAX) ? -1 : dist[dst];
    }
};
