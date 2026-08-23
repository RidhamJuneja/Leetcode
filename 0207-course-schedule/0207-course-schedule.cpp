class Solution {
public:
    bool dfs(unordered_map<int,vector<int>> &adj, vector<bool> &visited,
    vector<bool> &processed, int course)
    {
        if(visited[course]) return false;
        if(processed[course]) return true;
        visited[course] = true;
        for(auto i : adj[course])
        {
            if(!dfs(adj, visited, processed, i))
            return false;
        }
        visited[course] = false;
        processed[course] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto i : prerequisites)
        {
            int u = i[1], v = i[0];
            adj[u].push_back(v);
        }
        vector<bool> visited(numCourses, false);
        vector<bool> processed(numCourses, false);
        for(int i=0; i<numCourses; i++)
        {
            if(!dfs(adj, visited, processed, i))
            return false;
        }
        return true;
    }
};