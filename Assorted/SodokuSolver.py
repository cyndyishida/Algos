from pprint import pprint

class Sodoku:
    allowed_vals = list(range(10))

    def __init__(self):
        self.BOARD = [[None for i in range(9)] for j in range(9)]
        self.squares_left = 9 * 9 



    def unit_test(self):
        self.BOARD[0][0] = 7
        self.BOARD[0][4] = 3
        self.BOARD[0][6] = 1
        self.BOARD[1][0] = 1
        self.BOARD[1][1] = 3
        self.BOARD[1][4] = 6
        self.BOARD[1][5] = 9
        self.BOARD[1][7] = 2
        self.BOARD[1][8] = 8 
        self.BOARD[2][0] = 9
        self.BOARD[2][3] = 1
        self.BOARD[2][4] = 2
        self.BOARD[2][8] = 5 
        self.BOARD[3][0] = 8
        self.BOARD[3][1] = 5
        self.BOARD[3][2] = 9
        self.BOARD[4][4] = 4
        self.BOARD[5][0] = 5  
        self.BOARD[5][3] = 3
        self.BOARD[5][7] = 7
        self.BOARD[5][8] = 6 
        self.BOARD[6][2] = 8
        self.BOARD[6][3] = 6 
        self.BOARD[6][4] = 1 
        self.BOARD[6][6] = 5 
        self.BOARD[7][0] = 5 
        self.BOARD[7][2] = 6 
        self.BOARD[7][3] = 4 
        self.BOARD[7][4] = 9
        self.BOARD[7][5] = 7
        self.BOARD[7][6] = 2 
        self.BOARD[7][8] = 3 
        self.BOARD[8][1] = 4
        self.BOARD[8][2] = 7
        self.BOARD[8][3] = 8
        self.BOARD[8][5] = 2
        self.BOARD[8][7] = 9 
        self.BOARD[8][8] = 1


if __name__ == "__main__":
    table = Sodoku()
    table.unit_test()
    tbl = table.BOARD
    row,col = 0,0
    while row < 9 and col < 9 :  
        if tbl[row][col]: 
            if col % 9 : 
                col = 0 
                row +=1 
            else:
                col += 1 
        else:

            if col % 9 : 
                col = 0 
                row +=1 
            else:
                col += 1 
