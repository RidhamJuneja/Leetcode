class Solution {
public:
    bool cycle = false;
    void dfs(vector<vector<int>>& graph, vector<int> &path, vector<int> &visited, vector<int> &res, int node)
    {
        if(visited[node] == 1)
        return; //safe node already added in res
        else if(visited[node]==0) //non safe node
        {
            cycle = true;
            return;
        }
        else if(path[node]==1)
        {
            cycle = true;
            return;
        }
        else
        {
            path[node]=1;
            for(auto i : graph[node])
            {
                dfs(graph, path, visited, res, i);

                if(cycle == true)
                {
                path[node]=0;
                visited[node] = 0; //marked as non safe
                return;
                }
            }
            visited[node]=1; //mark as safe node
            res.push_back(node);
            path[node]=0;
            return;
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> res;
        vector<int> path(n,0);
        vector<int> visited(n,-1);

        for(int i=0; i<n; i++)
        {
            if(visited[i] == -1)
            {
                cycle = false;
                dfs(graph, path, visited, res, i);
            }
        }
        sort(res.begin(), res.end());
        return res;
    }
};