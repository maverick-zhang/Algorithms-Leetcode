class Solution:
    def __init__(self):
        self.num = 0
        self.res = 0

        # 记录每一列以及对角线上是否有皇后，用于检测冲突
        self.dia1 = []
        self.dia2 = []
        self.col = []

    def collide(self, row, col):
        if self.col[col] or self.dia1[row + col] or self.dia2[row - col + self.num - 1]:
            return True
        else:
            return False



    # 尝试在第row行, 第col列放置一个皇后
    def put_queen(self, row, record):
        if row == self.num:
            self.res += 1


        for col in range(self.num):
            if not self.collide(row, col):
                self.col[col] = True
                self.dia1[col + row] = True
                self.dia2[row - col + self.num - 1] = True
                record.append(col)
                self.put_queen(row + 1, record)
                self.col[col] = False
                self.dia1[col + row] = False
                self.dia2[row - col + self.num -1] = False
                record.pop()


    def solveNQueens(self, n: int):
        if n < 1:
            return []
        self.num = n
        self.dia1 = [False] * (2*n -1)
        self.dia2 = [False] * (2*n -1)
        self.col = [False] * n
        record = []
        self.put_queen(0, record)
        return self.res