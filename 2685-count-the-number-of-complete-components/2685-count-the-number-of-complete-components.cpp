class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> vis;

    void dfs(int u, int &nodes, int &degreeSum) {
        vis[u] = true;
        nodes++;
        degreeSum += adj[u].size();

        for (int v : adj[u]) {
            if (!vis[v])
                dfs(v, nodes, degreeSum);
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        adj.assign(n, {});
        vis.assign(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                int nodes = 0;
                int degreeSum = 0;

                dfs(i, nodes, degreeSum);

                int actualEdges = degreeSum / 2;
                int requiredEdges = nodes * (nodes - 1) / 2;

                if (actualEdges == requiredEdges)
                    ans++;
            }
        }

        return ans;
    }
};