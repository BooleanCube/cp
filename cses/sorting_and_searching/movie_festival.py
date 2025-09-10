c=1
i=input
print(len([c:=a for a,b in sorted(tuple(map(int,i().split()))[::-1]for _ in"."*int(i()))if b>=c]))