class Solution {
public:
    int replacer = 2;
    void dfs(vector<vector<int>>& isConnected, int row)
    {
        for(int col=0; col<isConnected.size(); col++)
        {
            if(isConnected[row][col] == 0 || row == col)
            isConnected[row][col] = replacer;
            else
            {
                isConnected[row][col] = replacer;
                if(isConnected[col][0] == 0 || isConnected[col][0] == 1)
                {
                dfs(isConnected, col);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int components = 0;
        int n = isConnected.size();
        for(int i=0; i<n; i++)
        {
            if(isConnected[i][0] == 0 || isConnected[i][0] == 1)
            {
                components++;
                dfs(isConnected, i);
            }
        }
        return components;
    }
};