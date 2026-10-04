class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int row, int replacer)
    {
        for(int col=0; col<isConnected.size(); col++)
        {
            if(isConnected[row][col] == 0 || row == col)
            isConnected[row][col] = replacer;
            else
            {
                if(isConnected[col][0] == 0 || isConnected[col][0] == 1)
                {
                isConnected[row][col] = replacer;
                dfs(isConnected, col, replacer);
                }
                else
                isConnected[row][col] = replacer;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int components = 0;
        int replacer = 2;
        int n = isConnected.size();
        for(int i=0; i<n; i++)
        {
            if(isConnected[i][0] == 0 || isConnected[i][0] == 1)
            {
                components++;
                dfs(isConnected, i, replacer);
                // replacer++;
            }
        }
        return components;
    }
};