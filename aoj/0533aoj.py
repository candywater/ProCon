#python3

w = [int(input()) for i in range(10)]
k = [int(input()) for i in range(10)]

w.sort()
k.sort()

w_score=w[-1]+w[-2]+w[-3]
k_score=k[-1]+k[-2]+k[-3]

print(w_score,k_score)
