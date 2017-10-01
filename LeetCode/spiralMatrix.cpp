/*
n*m time, keep  track of row/col upper lower boundaries and move 2 pointers around denoting the (i,j) coordinate of matrix  
*/

class Solution {
public:
    enum class DIR :int { RIGHT = 0, DOWN = 1, LEFT = 2, UP = 3 };
    
    using Matrix = vector<vector<int>>;
    vector<int> spiralOrder(Matrix& matrix) {

        if (matrix.empty())
            return {};
        
        int rows = matrix.size() ;
        int cols = matrix[0].size() ;
        int max = rows * cols;
        vector<int> spiral_traversal(max);

        
        int row_ub= rows - 1 ;
        int col_ub = cols - 1 ;
        int row_lb = 0;
        int col_lb = 0;
        
        
        DIR direction = DIR::RIGHT;
        int counter = 0,  r = 0, c= 0;
        bool skip_iter = false;
        
        while(counter < max)
        {
            if (!skip_iter)
                spiral_traversal[counter++] = matrix[r][c];
            
            skip_iter = false;
            
            switch(direction)
            {
                case DIR::RIGHT:
                {
                    if (c + 1 <= col_ub )
                        ++c;
                    else
                    {
                        ++row_lb;
                        direction = DIR::DOWN;
                        skip_iter= true;
                    }
                     
                    break;
                }
                case DIR::DOWN:
                {
                    if (r + 1 <= row_ub  )
                        ++r;
                    else
                    {
                        --col_ub;
                        direction = DIR::LEFT;
                        skip_iter= true;                        
                    }
                    break;
                }                    
                case DIR::LEFT:
                {
                    if (c - 1 >= col_lb )
                        --c;
                    else
                    {
                        --row_ub;
                        direction = DIR::UP;
                        skip_iter= true;
                    }
                    break;
                }
                case DIR::UP:
                {
                    if (r - 1 >= row_lb  )
                        --r;
                    else
                    {
                        ++col_lb;
                        direction = DIR::RIGHT;
                        skip_iter= true;
                    }
                }
            }
        }
        
        
        return spiral_traversal;
    }
};
