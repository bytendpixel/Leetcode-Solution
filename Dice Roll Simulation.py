class Solution:
    def dieSimulator(self, n: int, rollMax: List[int]) -> int:
        MOD = 10 ** 9 + 7
        m = len(rollMax)  # 6
        f = [[0] * m for _ in range(n)]
        f[0] = [1] * m
        s = [0] * n
        s[0] = m
        for i in range(1, n):
            for j, mx in enumerate(rollMax):
                res = s[i - 1]
                if i > mx: res -= s[i - mx - 1] - f[i - mx - 1][j]
                elif i == mx: res -= 1
                f[i][j] = res % MOD
            s[i] = sum(f[i]) % MOD
        return s[-1]
