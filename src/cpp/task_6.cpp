/*
 * Author: Rakhimberdi
 * Date:
 * Name:
 */
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    vector<vector<pair<int, int>>> graph(n + 1);
    for (const auto& t : times) {
        graph[t[0]].push_back({t[1], t[2]});
    }

    const int INF = 1e9;
    vector<int> dist(n + 1, INF);
    dist[k] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, k});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const auto& [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }

    int max_dist = *max_element(dist.begin() + 1, dist.end());
    return max_dist == INF ? -1 : max_dist;
}

