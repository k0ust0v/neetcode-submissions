class Solution {
private:
    map<int, vector<int>> adjList;
    set<int> vis;

    bool dfs(int node, int parent) {
        if (vis.count(node))
            return true; // Cycle detected

        vis.insert(node);
        for (int neighbor : adjList[node]) {
            if (neighbor == parent) continue;
            if (dfs(neighbor, node))
                return true; // Cycle detected in deeper call
        }

        return false; // No cycle found
    }

public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() != n - 1)
            return false; // A tree must have exactly n - 1 edges

        for (int i = 0; i < n; ++i)
            adjList[i] = {};

        for (auto& e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }

        if (dfs(0, -1))
            return false; // Cycle found

        return vis.size() == n; // Check if all nodes are connected
    }
};
