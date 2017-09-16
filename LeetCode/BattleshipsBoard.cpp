#include <stack>
#include <vector>
#include <iostream>


using namespace std;

class Solution 
{
public:
   
   using Board = vector<vector<char>>;

    struct Node
    {  
        char val;
        int col;
        int row;
        bool seen;

        Node( char val, int row, int col) : val(val), row(row), col(col), seen(false) 
        {}

        void see() {seen = true; }

        bool saw() { return seen; }
    };


    void addNull( stack<Node> & dfs_stack, size_t& row, size_t&col,  Board& board)
    {

        if (row +1 < board.size())
        { 
            ++row;
            dfs_stack.push(Node(board[row][col], row, col));
        }
        else if (col +1 < board[0].size())
        {
            row = 0; 
            ++col;
            dfs_stack.push(Node(board[row][col], row, col)); 
    
        }
    }

    int countBattleships ( Board& board)
    {
        size_t row = 0; 
        size_t col = 0;
        int counter = 0;
        bool is_ship = false;
        bool reset = true;
        stack<Node> dfs_stack;
        dfs_stack.push(Node(board[row][col], row, col));
        
        while (!(dfs_stack.empty()) &&  row < board.size() && col < board[0].size() )
        {

            if (board[row][col] != 'X')
            {
                if (is_ship)
                {
                    is_ship = false;
                    ++counter;
                }
                reset = true;
            }
            
            else
            {
                
                is_ship = true;
                dfs_stack.top().see();
            }


            if (row+1 < board.size() && board[row + 1][col] == 'X')
            {
                reset = false;
                ++row;
                if (row < board.size() )
                {
                    is_ship = true;
                    dfs_stack.push(Node(board[row][col], row, col));
                }
            }


            else if (col + 1 < board[0].size() && board[row][col+1] == 'X')
            {
                reset = false;
                ++col;
                if ( col< board[0].size() )
                {
                    is_ship = true;
                   dfs_stack.push(Node(board[row][col], row, col));
               }  
            }

            else
                {
                    if (is_ship) ++counter; // handles the case where the only x is at the current point
                    is_ship = false;
                    reset = true;
                }
          
             
            dfs_stack.pop();
            if (reset) addNull(dfs_stack, row, col, board);
         
        }
        return counter;
    }
};


int main ()
{
    Solution x;
    Solution::Board board;
    board.push_back("");

    cout << x.countBattleships(board) << endl;


    return 0;
}
