class Solution {
public:
    void dfs(unordered_map<string, vector<pair<string, double>>> &adj,
    string curr, string target, double &product, bool &targetAchieved, 
    unordered_map<string, bool> &visited, double weightAdded)
    {
        if(targetAchieved) return;
        product *= weightAdded;
        if(curr == target)
        {
            targetAchieved = true;
            return;
        }
        visited[curr] = true;
        for(auto i : adj[curr])
        {
            if(!visited[i.first])
            {
                dfs(adj, i.first, target, product, targetAchieved, visited, i.second);
                if(targetAchieved)
                {
                    visited[curr] = false;
                    return;
                }
            }
        }
        product = product / weightAdded;
        visited[curr] = false;
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adj;
        unordered_map<string, bool> visited;
        int edges = equations.size();
        for(int i=0; i<edges; i++)
        {
            string u = equations[i][0], v = equations[i][1];
            double wt = values[i];
            double revWt = 1.0/wt;
            adj[u].push_back({v,wt});
            adj[v].push_back({u,revWt});
            visited[u]=false;
            visited[v]=false;
        }
        vector<double> result;
        for(auto i : queries)
        {
            string u = i[0], target = i[1];
            if(adj.find(u) == adj.end() || adj.find(target) == adj.end())
            result.push_back(-1);
            else if(u == target)
            result.push_back(1);
            else
            {
                bool targetAchieved = false;
                double product=1;
                // for(auto v : adj[u])
                // {
                //     if(!visited[v.first])
                //     {
                //         dfs(adj, v.first, target, product, targetAchieved, visited,
                //         v.second);
                //         if(targetAchieved)
                //         {
                //             result.push_back(product);
                //             break;
                //         }
                //     }
                // }
                dfs(adj, u, target, product, targetAchieved, visited, 1);
                        if(targetAchieved)
                        {
                            result.push_back(product);
                        }
                        else
                        {
                            result.push_back(-1);
                        }
            }
        }
        return result;
    }
};