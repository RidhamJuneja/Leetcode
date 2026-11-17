class Solution {
public:
    void dfs(vector<vector<int>>& graph, vector<vector<int>>& res, vector<int>& path
    , int node, int n)
    {
        path.push_back(node);
        if(node == n-1)
        res.push_back(path);
        else
        {
            for(auto i : graph[node])
            {
                dfs(graph, res, path, i, n);
            }
        }
        path.pop_back();
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        //graph as adj
        int n = graph.size();
        vector<vector<int>> res;
        vector<int> path;
        dfs(graph, res, path, 0, n);
        return res;
    }
};