
# 输入: "25525511135"
# 输出: ["255.255.11.135", "255.255.111.35"]

class Solution:
    def __init__(self):
        self.res = []

    def restore(self, s, index_ip, index_num, ip):
        if index_ip == 4:
            if index_num == len(s):
                self.res.append(ip[:-1])
            return

        # 一个数字
        if index_num == len(s):
            return
        self.restore(s, index_ip+1, index_num+1, ip+s[index_num]+".")
        # 两个数字
        if s[index_num] == '0':
            return
        if index_num + 1 >= len(s):
            return
        self.restore(s, index_ip+1, index_num+2, ip+s[index_num:index_num+2]+".")
        # 三个数字
        if index_num + 2 >= len(s) or int(s[index_num:index_num+3]) > 255:
            return
        self.restore(s, index_ip+1, index_num+3, ip+s[index_num:index_num+3]+".")

    def restoreIpAddresses(self, s: str) -> list:
        self.restore(s, 0, 0, "")
        return self.res
