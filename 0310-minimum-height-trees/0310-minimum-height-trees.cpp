class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return {0};
        vector<int> indegree(n,0);
        vector<int> result;
        unordered_map<int,vector<int>> adj;
        for(auto i : edges)
        {
            int u = i[0];
            int v = i[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> leafNodes;
        for(int i=0; i<n; i++)
        {
            if(indegree[i]==1)
            leafNodes.push(i);
        }
        while(n>2)
        {
            int size=leafNodes.size();
            n-=size;
            for(int i=1; i<=size; i++)
            {
                int u = leafNodes.front();
                leafNodes.pop();
                indegree[u]--;
                for(auto v : adj[u])
                {
                    indegree[v]--;

                    if(indegree[v]==1)
                    leafNodes.push(v);
                }
            }
        }
        while(!leafNodes.empty())
        {
            result.push_back(leafNodes.front());
            leafNodes.pop();
        }
        return result;
    }
};