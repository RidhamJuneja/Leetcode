class Solution {
public:
    bool dfs(unordered_map<int, vector<int>>& adj, vector<bool>& visited, vector<bool>& processed, vector<int>& res, int crc)
    {
        if(visited[crc]) return false;
        if(processed[crc]) return true;

        visited[crc] = true;
        for(auto i : adj[crc])
        {
            // dfs(adj, visited, processed, res, i);
            if(!dfs(adj, visited, processed, res, i))
            return false;
        }
        visited[crc] = false;
        processed[crc] = true;
        res.push_back(crc);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> adj;
        for(auto i : prerequisites){
            int u = i[1], v = i[0];
            adj[u].push_back(v);
        }
        vector<bool> processed(numCourses,false);
        vector<bool> visited(numCourses,false);
        vector<int> res;
        for(int i=0; i<numCourses; i++){
            if(!dfs(adj, visited, processed, res, i))
            {
                res.clear();
                return res;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};