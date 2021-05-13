n = 3
board = [0*n]
pb = board
print(board)
def NQ(n, r):
    for i in range(n):
        if(place(r, i)):
            board[r] = i
            if(r==n-1):
                print(board[i:n])
            else:
                NQ(n, r+1)    

def place(k, i):
    for j in range(1, k):
        if(board[j]==i) or (abs(board[j]-i) == abs(j-k)):
            return False;
    return True;

NQ(n, 0)
print(board)
#rat in a maze