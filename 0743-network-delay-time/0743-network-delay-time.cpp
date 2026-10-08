class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int,int>>> adj;
        for(auto i : times)
        {
            int u = i[0], v = i[1], wt = i[2];
            adj[u].push_back({v,wt});
        }
        //implementing djikstraw
        vector<int> dist(n+1,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            int d = node.first;
            int u = node.second;

            if(d > dist[u])
            continue;

            for(auto i : adj[u])
            {
                int v = i.first;
                int wt = i.second;
                
                int vDist = dist[u] + wt;
                if(vDist < dist[v])
                {
                    dist[v] = vDist;
                    pq.push({vDist,v});
                }
            }
        }
        int time=0;
        for(int i=1; i<=n; i++)
        {
            if(dist[i] == INT_MAX)
            {
                time = -1;
                break;
            }
            time = max(time,dist[i]);
        }
        return time;
    }
};