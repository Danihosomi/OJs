a, b, c, n = map(int,input().split())
mod = pow(2,64)
ans=0
if n%2==1:
    ans=(n*((n-1)//2)*(((n-1)//2)+1))//6
else:
    ans=(((n//2)*((n//2)+1)*((n//2)+2))//3) -n
ans%=mod
if a==b==c:
    print(ans)
elif (a==b or a==c or b==c):
    print((ans*3)%mod)
else:
    print((ans*6)%mod)