class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        vector<int> indegree(n,0);
        vector<int> result;
        if(n==1)
        {
            result.push_back(0);
            return result;
        }
        for(auto i : edges)
        {
            int u = i[0], v = i[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++)
        {
            if(indegree[i] == 1)
            q.push(i);
        }
        int qSize = q.size();
        while(n>2)
        {
            qSize=q.size();
            n -= qSize;
            while(qSize!=0)
            {
                int leafNode = q.front();
                q.pop();
                indegree[leafNode]--;
                for(auto v : adj[leafNode])
                {
                    indegree[v]--;
                    if(indegree[v]==1)
                    q.push(v);
                }
                qSize--;
            }
        }
        if(!q.empty())
        {
            while(!q.empty())
            {
                result.push_back(q.front());
                q.pop();
            }
        }
        return result;
    }
};