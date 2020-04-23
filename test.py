N = eval(input())
x = list(map(int, input().split(' ')))
ans = abs(x[0])
for i in range(1, N):
    x[i] += x[i-1]
    ans += abs(x[i])
print(ans)
