from sortedcontainers import SortedList

class Solution:
    def maxSizeSlices(self, slices: List[int]) -> int:
        n = len(slices)
        L = [i - 1 for i in range(n)]
        L[0] = n - 1
        R = [i + 1 for i in range(n)]
        R[n-1] = 0
        lst = SortedList([(val, i) for i, val in enumerate(slices)])
        ans = 0
        for _ in range(n // 3):
            val, i = lst.pop(-1)
            ans += val
            lst.remove((slices[L[i]], L[i]))
            lst.remove((slices[R[i]], R[i]))
            slices[i] = slices[L[i]] + slices[R[i]] - val
            lst.add((slices[i], i))
            R[L[L[i]]] = i
            L[i] = L[L[i]]
            L[R[R[i]]] = i
            R[i] = R[R[i]]
        return ans

        
