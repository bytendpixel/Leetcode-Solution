modulo = int(1e9 + 7)

class Solution:
    def countVowelPermutation(self, n: int) -> int:
        return (514029000*_fastPow(882979097, n) +
            638771916*_fastPow(653592850, n) +
            784439686*_fastPow(419376480, n) +
            62759413*_fastPow(44051588, n)) % modulo

def _fastPow(x: int, n: int) -> int:
    res = 1
    while True:
        if (n & 1) != 0:
            res = (res * x) % modulo
        n >>= 1
        if n == 0:
            break
        x = (x * x) % modulo
    return res
