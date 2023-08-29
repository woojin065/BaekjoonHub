numbers = []
cnt = int(input())
numbers = list(map(int, input().split()))
numbers.sort()
sum = 0
for i in range(cnt+1):
  for j in range(i):
    sum=sum+numbers[j]
print(sum)