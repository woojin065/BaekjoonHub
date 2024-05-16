N=int(input())
nums=[]
for i in range(N):
    tmp=list(map(int, input().split()))
    nums.append(tmp)
def pooling(size, x, y):
  mid=size//2
  if size==2:
    answer=[nums[x][y], nums[x+1][y], nums[x][y+1], nums[x+1][y+1]]
    answer.sort()
    return answer[-2]
  r1=pooling(mid, x, y)
  r2=pooling(mid, x+mid, y)
  r3=pooling(mid, x, y+mid)
  r4=pooling(mid, x+mid, y+mid)
  answer=[r1, r2, r3, r4]
  answer.sort()
  return answer[-2]
  
print(pooling(N, 0, 0))