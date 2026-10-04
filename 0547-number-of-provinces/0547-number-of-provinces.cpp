class Solution {
public:
    void dfs(unordered_map<int,vector<int>> &adj, vector<bool>& visited, int node)
    {
        visited[node] = true;
        for(auto v : adj[node])
        {
            if(!visited[v])
            dfs(adj, visited, v);
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int, vector<int>> adj;
        int n = isConnected.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j && isConnected[i][j]==1)
                {
                    int u = i, v=j;
                    adj[u].push_back(v);
                }
            }
        }
        vector<bool> visited(n,false);
        int result=0;
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                result++;
                dfs(adj, visited, i);
            }
        }
        return result;

    }
};