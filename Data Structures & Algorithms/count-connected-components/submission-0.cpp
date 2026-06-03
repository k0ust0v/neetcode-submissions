class Solution {
private:
    unordered_map<int, vector<int>> adjList;
    set<int> vis;
    void dfs(int i) {
        vis.insert(i);
        for(auto e : adjList[i]) {
            if(vis.count(e))
                continue;
            dfs(e);
            
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; ++i) {
            adjList[i] = {};
        }
        for(auto e : edges) {
            adjList[e[0]].push_back(e[1]);
            adjList[e[1]].push_back(e[0]);
        }
        int count = 0;
        for(int i = 0; i < n; ++i) {
            if(!vis.count(i)) {
                dfs(i);
                ++count;
            }
        }
        return count;
    }
};
