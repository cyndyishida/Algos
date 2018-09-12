class Solution {
public:

    int minPathSum(vector<vector<int>>& grid) {


        size_t row = 0, col = 0;
        for (; row < grid.size(); ++row)
        {
            for(col = 0; col < grid[0].size(); ++col)
            {
                if (row >0 && col >0 )
                    grid[row][col] += std::min(grid[row-1][col], grid[row][col -1]) ;
                else if (row > 0 )  // boundary
                    grid[row][col] +=  grid[row -1][col];
                else if (col > 0) // boundary
                    grid[row][col] +=  grid[row][col - 1];


            }
        }

        return grid[row - 1][col -1 ];


    }
};
