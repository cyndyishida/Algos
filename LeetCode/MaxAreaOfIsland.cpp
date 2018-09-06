class Solution {
public:
    
    int dfs(vector<vector<int>>& grid, int row,  int col)
    {
        
        if (row >= 0 && row < grid.size() && col >= 0 && col < grid[0].size() && grid[row][col] == 1)
        {
            grid[row][col] = 2; // seen 
            
            return dfs(grid, row +1, col) +
            dfs(grid, row -1, col) +
            dfs(grid, row, col+1) + 
            dfs(grid, row, col-1) + 1;
        
            
        }
        
        return 0;
        
    }
    
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max = 0, curr = 0;
        for( int row = 0; row < grid.size() ; ++row)
        {
            for (int col = 0; col < grid[0].size() ; ++col)
            {
                if (grid[row][col] == 1)
                {
                    curr = dfs(grid, row, col);
                    max = curr > max? curr : max; 
                }
                
            }
        }
        
        
        
        
        return max;
        
        
    }
};
