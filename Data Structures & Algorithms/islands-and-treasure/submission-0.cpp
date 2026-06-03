class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        vector<pair<int,int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        queue<pair<int,int>> q;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                if(grid[i][j] == 0) {
                    q.push(make_pair(i,j));
                    vis[i][j] = true;
                }
            }
        }
        int dist = 0;
        //Multi Source BFS O(mxn)
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                        !vis[nr][nc] && grid[nr][nc] != -1) {

                        grid[nr][nc] = dist + 1;  // Correct distance update
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            ++dist;           
        }
    }
};
