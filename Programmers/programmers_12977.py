def solution(nums):
    def prime(n):
        for i in range(2, int(n/2)):
            if n % i == 0:
                return False
        return True
    
    def dfs(idx, cnt, m):
        if m == 3:
            if prime(cnt):
                return 1
            else:
                return 0
        if idx == len(nums):
            return 0
        return dfs(idx+1, cnt+nums[idx], m+1) + dfs(idx+1, cnt, m)
    return dfs(0, 0, 0)
