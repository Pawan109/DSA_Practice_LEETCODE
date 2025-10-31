class Solution {
public:
    int findShortestCycle(int n, vector<vector<int>>& edges) {
         vector<vector<int>> adj(n);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = INT_MAX;

        for (int i = 0; i < n; i++) {
            vector<int> dist(n, -1);
            queue<pair<int, int>> q;

            dist[i] = 0;
            q.push({i, -1});

            while (!q.empty()) {
                auto [node, parent] = q.front();
                q.pop();

                for (int nei : adj[node]) {
                    if (dist[nei] == -1) {
                        dist[nei] = dist[node] + 1;
                        q.push({nei, node});
                    } 
                    else if (nei != parent) {
                        // Found a cycle
                        ans = min(ans, dist[nei] + dist[node] + 1);
                    }
                }
            }
        }

        return (ans == INT_MAX ? -1 : ans);
    }
};