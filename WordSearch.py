# https://leetcode.com/problems/word-search/description/

class Solution:

    def exist(self, board: List[List[str]], word: str) -> bool:
        r = len(board)
        c = len(board[0])
        path = set()

        def check(board: List[List[str]], word: str,i:int,j:int,p:int,r:int,c:int) -> bool:
            if p == len(word):
                return True
            
            if(i<0 or j<0 or i==r or j == c):
                return False

            if(board[i][j]!=word[p]):
                return False

            if (i, j) in path:
                return False

            path.add((i,j))
            dx = [1,0,-1,0]
            dy = [0,-1,0,1]

            for count in range(4):
                x = i+dx[count]
                y = j+dy[count]
                if(check(board,word,x,y,p+1,r,c)):
                    return True
            path.remove((i,j))
            return False


        for i in range(r):
            for j in range(c):
                if(check(board,word,i,j,0,r,c)):
                    return True
        return False





