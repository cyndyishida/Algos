
cboard = list(list(i for i in range(j,j + 8)) for j in range(0,8*8, 8))

"""
# memoized solution 
def knight_helper(row, col, dest, steps, mem):
    global cboard

    key = "col: " + str(col) + "row: " + str(row)
    if key in mem:
        return mem[key]

    if not (row >= 0 and row < len(cboard) and col >= 0 and col < len(cboard[0])):
        mem[key] = steps
        return steps
    else:

        if cboard[row][col] == dest:
            mem[key] = steps
            return steps
        else:
            return min([
                knight_helper(row+2, col+1, dest, steps +1, mem),
                knight_helper(row+2, col-1, dest, steps +1, mem),
                knight_helper(row-2, col+1, dest, steps +1, mem),
                #knight_helper(row-2, col-1, dest, steps +1, mem),
                #knight_helper(row+1, col+2, dest, steps +1, mem),
                #knight_helper(row+1, col-2, dest, steps +1, mem),
                #knight_helper(row-1, col+2, dest, steps +1, mem),
                #knight_helper(row-1, col-2, dest, steps +1, mem)
                ])


def answer(src, dest):
    # check if left, right, up, down is the answer or goes past board 
    mem = dict()
    return knight_helper(int(src / 8), src % 8, dest, 0, mem )

"""



"""
def answer(src, dest):

    # dfs 
    global cboard
    # check if left, right, up, down is the answer or goes past board
    dp = list(list(None for i in range(0, 8 )) for j in range(0, 8))
    row = int(src / 8)
    col = src % 8
    dp[row][col] = 0
    while not dp[int(dest /8)][dest % 8]:
        for row in range(8):
            for col in range(8):
                if row+2  >= 0 and row+2 < len(cboard) and col+1 >= 0 and col+1 < len(cboard[0]) and dp[row+2][col+1] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row+2][col+1] + 1)
                if row+2  >= 0 and row+2 < len(cboard) and col-1 >= 0 and col-1 < len(cboard[0]) and dp[row+2][col-1] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row+2][col-1] + 1)
                if row-2  >= 0 and row-2 < len(cboard) and col+1 >= 0 and col+1 < len(cboard[0]) and dp[row-2][col+1] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row-2][col+1] + 1)
                if row-2  >= 0 and row-2 < len(cboard) and col-1 >= 0 and col-1 < len(cboard[0]) and dp[row-2][col-1] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row-2][col-1] + 1)
                if row+1  >= 0 and row+1 < len(cboard) and col+2 >= 0 and col+2 < len(cboard[0]) and dp[row+1][col+2] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row+1][col+2] + 1)
                if row+1  >= 0 and row+1 < len(cboard) and col-2 >= 0 and col-2 < len(cboard[0]) and dp[row+1][col-2] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row+1][col-2] + 1)
                if row-1  >= 0 and row-1 < len(cboard) and col+2 >= 0 and col+2 < len(cboard[0]) and dp[row-1][col+2] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row-1][col+2] + 1)
                if row-1  >= 0 and row-1 < len(cboard) and col-2 >= 0 and col-2 < len(cboard[0]) and dp[row-1][col-2] != None:
                    if dp[row][col] == None:
                        dp[row][col] = 10*9
                    dp[row][col] = min(dp[row][col], dp[row-1][col-2] + 1)

    return dp[int(dest / 8 )][dest % 8]
"""

# bfs
def answer(src, dest):
    global cboard
    queue = [(int(src / 8 ),src %8, 0 )]

    found = False

    while not found:
        row,col,steps = queue.pop(0)
        if row == int(dest / 8 ) and col == dest % 8:
            return steps
        if row+2 < len(cboard) and col+1 < len(cboard[0]):
            queue.append((row+2, col +1, steps +1))

        if row+2 < len(cboard) and col-1 >= 0:
            queue.append((row+2, col -1, steps +1))

        if row-2  >= 0 and  col+1 < len(cboard[0]):
            queue.append((row-2, col +1, steps +1))

        if row-2  >= 0 and col-1 >= 0:
            queue.append((row-2, col -1, steps +1))

        if row+1 < len(cboard) and col+2 < len(cboard[0]):
            queue.append((row+1, col +2, steps +1))

        if row+1 < len(cboard) and col-2 >= 0:
            queue.append((row+1, col -2, steps +1))

        if row-1  >= 0 and col+2 < len(cboard[0]):
            queue.append((row-1, col +2, steps +1))

        if row-1  >= 0  and col-2 >= 0:
            queue.append((row-1, col -2, steps +1))



print(answer(19,36))
