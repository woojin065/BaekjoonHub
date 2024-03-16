N = int(input())

for i in range(N-1):
  print(" "*(N-i-2),"*"*(2*i+1))
print("*"*(N*2-1))
for i in range(N-1):
  print(" "*(i), "*"*((N-i-2)*2+1))
