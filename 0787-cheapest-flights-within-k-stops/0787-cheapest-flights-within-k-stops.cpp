class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {

        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto it : flights)
        {
            int from = it[0], to = it[1], price = it[2];
            adj[from].push_back({to,price});
        }
        
        vector<int> minDist(n, INT_MAX);
        minDist[src]=0;

        queue<pair<int,int>> bfs;
        bfs.push({src,0});
        int qSize = bfs.size();
        for(int i=0; i<=k; i++)
        {
            for(int j=1; j<=qSize; j++)
            {
                pair<int,int> temp = bfs.front();
                bfs.pop();
                int u = temp.first, dist = temp.second;
                
                for(auto it : adj[u])
                {
                    int v = it.first, price = it.second;
                    int d = dist+price;
                    if(d < minDist[v])
                    {
                        bfs.push({v,d});
                        minDist[v]=d;
                    }
                }
            }

            qSize = bfs.size();
        }
            if(minDist[dst] == INT_MAX)
            return -1;
            else
            return minDist[dst];
    }
};