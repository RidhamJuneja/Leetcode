class Solution {
public:
    bool cycleFound = false;
    void dfs(unordered_map<int,vector<int>> &adj, int node, int prev, 
    stack<pair<int,int>> &st, vector<bool> &visited, vector<bool> &inPath)
    {
        if(cycleFound)
        return;
        if(visited[node] && !inPath[node]) return;
        inPath[node] = true;
        if(prev != -1)
        {
            st.push({prev, node});
        }
        if(visited[node])
        {
            cycleFound = true;
            return;
        }
        visited[node] = true;
        for(auto v : adj[node])
        {
            dfs(adj, v, node, st, visited, inPath);

            if(cycleFound)
            return;
        }

        if(!st.empty())
        st.pop();

        inPath[node] = false;
        return;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        unordered_map<int, vector<int>> adj;
        unordered_map<int, vector<int>> adjIn;
        map<pair<int,int> , int> edgeIdx;
        int node_2deg = -1;
        for(int i=0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adjIn[v].push_back(u);
            edgeIdx[{u,v}] = i;

            if(adjIn[v].size() == 2)
            node_2deg = v;
        }

        pair<int,int> result;
        vector<int> ans(2);
        //additional edge at 1;
        vector<bool> inPath(n+2, false);
        vector<bool> visited(n+1, false);
        stack<pair<int,int>> st;
        if(node_2deg == -1)
        {
            for(int i=1; i<=n+1; i++)
            {
                if(cycleFound)
                break;
                dfs(adj, i, -1, st, visited, inPath);
            }

          
            int maxIdx = -1;
            while(!st.empty())
            {
                pair<int,int> temp = st.top();
                st.pop();
                if(edgeIdx[temp] > maxIdx)
                {
                    result = temp;
                    maxIdx = edgeIdx[temp];
                }
            }
        }
        else 
        //additional edge in betweem
        {
            dfs(adj, node_2deg, -1, st, visited, inPath);
            if(cycleFound)
            {
                result = st.top();
            }
            else
            {
                int maxIdx = -1;
                for(auto u : adjIn[node_2deg])
                {
                    pair<int,int> temp = {u,node_2deg};
                    if(edgeIdx[temp] > maxIdx)
                    {
                        result = temp;
                        maxIdx = edgeIdx[temp];
                    }
                }
            }
        }

        ans[0] = result.first;
        ans[1] = result.second;
        return ans;
    }
};