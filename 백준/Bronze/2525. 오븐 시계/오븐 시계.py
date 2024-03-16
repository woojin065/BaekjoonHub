ho, m = map(int, input().split())
p = int(input())

sum1 = ho*60+m+p

print(sum1//60-24 if sum1//60>23 else sum1//60, sum1%60)

