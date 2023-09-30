
def sigma(n):
    return (n * (n + 1)) // 2

q = int(input())
for _ in range(q):
    x, k = map(int, input().split())
    low = 1
    high = 10**18
    ans = -1
    while(low <= high) :
        mid = (low + high) // 2
        T2 = sigma(mid-1) + k*mid
        if(T2 >= x) :
            ans = mid
            high = mid - 1
        else :
            low = mid + 1
    T1 = ans * k
    if(T1 > x):ans = -1
    print(ans)

