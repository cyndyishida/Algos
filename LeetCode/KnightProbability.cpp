class Solution {
public:


    double knightMoves(int N, int row, int col, int K, std::unordered_map<std::string, double>& mem)
    {

        std::string key ="row: " + std::to_string(row) + " col: "+ std::to_string(col) + " left: " +std::to_string(K);
        if (mem.find(key) != mem.end())
            return mem[key];
        
        
        double counter = 0;

        if (row < N && col < N  && row >= 0 && col >= 0)
        {

            if (K == 0)
            {

                counter = 1;

            }
            else
            {


                counter =
                        knightMoves(N, row + 2, col + 1, K - 1, mem) +
                        knightMoves(N, row + 2, col - 1, K - 1, mem) +
                        knightMoves(N, row - 2, col + 1, K - 1, mem) +
                        knightMoves(N, row - 2, col - 1, K - 1, mem) +
                        knightMoves(N, row + 1, col + 2, K - 1, mem) +
                        knightMoves(N, row + 1, col - 2, K - 1, mem) +
                        knightMoves(N, row - 1, col + 2, K - 1, mem) +
                        knightMoves(N, row - 1, col - 2, K - 1, mem);
            }
        }

        mem[key] = counter;
        return counter;
    }

    using Matrix = std::vector<std::vector<int>> ;
    double knightProbability(int N, int K, int r, int c) {

        // create chessboard 
        std::vector<int> temp(N, 0);
        Matrix cBoard(N, temp);
        int curr = 0;
        //for (int i = 0; i < N; ++i)
        //    for (int j = 0; j < N; ++j)
        //        cBoard[i][j] = curr++;

        std::unordered_map<std::string, double> mem;
        double onBoard = knightMoves(N, r, c, K, mem);
        cout << onBoard << endl;

        return onBoard / static_cast<double>(pow(8, K));

    }
};
