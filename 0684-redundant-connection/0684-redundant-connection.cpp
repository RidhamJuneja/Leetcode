class Solution {
public:
    bool cycleFound = false;
    void dfs(unordered_map<int, vector<int>> &adj, vector<bool>& visited, 
    stack<pair<int,int>>& st, int node, int prev)
    {
        if(cycleFound) return;
        if(prev != -1)
        {
            st.push({min(prev, node), max(prev,node)});
        }
        if(visited[node])
        {
            cycleFound = true;
            return;
        }
        visited[node] = true;
        for(auto i : adj[node])
        {
            if(i==prev)
            continue;

            // if(!visited[i])
            dfs(adj, visited, st, i, node);

            if(cycleFound)
            return;
        }

        if(!st.empty())
        st.pop();
        return;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>> adj;
      map<pair<int,int>, int> edgeIdx;
        for(int i=0; i<edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
           edgeIdx[{min(u,v), max(u,v)}] = i;
        }
        int n = edges.size()+1;
        vector<bool> visited(n+1, false);
        stack<pair<int,int>> st;
        dfs(adj, visited, st, 1, -1);

        int maxIdx = -1;
        vector<int> result(2);

        int cycleNode1, cycleNode2;
        if(!st.empty())
        {
            pair<int,int> edge = st.top();
            st.pop();
            cycleNode1 = edge.first;
            cycleNode2 = edge.second;
            result[0] = edge.first;
            result[1] = edge.second;
            maxIdx=edgeIdx[edge];
        }
        while(!st.empty())
        {
            if(cycleNode1 == -1 && cycleNode2 == -1)
            break;

            pair<int,int> edge = st.top();
            st.pop();
            if(edge.first == cycleNode1 || edge.second == cycleNode1)
            cycleNode1 = -1;
            if(edge.first == cycleNode2 || edge.second == cycleNode2)
            cycleNode2 = -1;
            if(edgeIdx[edge] > maxIdx)
            {
                result[0] = edge.first;
                result[1] = edge.second;
                maxIdx=edgeIdx[edge];
            }
        }
        return result;
    }
};