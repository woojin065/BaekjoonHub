def solution(friends, gifts):
    gifted = {}
    gift_idx = {}
    
    for friend in friends:
        gifted[friend] = {}
        gift_idx[friend] = 0
        
    for gift in gifts:
        A, B = gift.split(' ')
        if B in gifted[A]:
            gifted[A][B] += 1
        else:
            gifted[A][B] = 1
        gift_idx[A] += 1
        gift_idx[B] -= 1
    
    next_get = [0 for _ in friends]
    for i in range(len(friends)):
        current = friends[i]
        for j in range(i+1, len(friends)):
            another = friends[j]
            a = gifted[current][another] if another in gifted[current] else 0
            b = gifted[another][current] if current in gifted[another] else 0 
            
            if a > b:
                next_get[i] += 1
            elif a < b:
                next_get[j] += 1
            elif a == b:
                ai, bi = gift_idx[current], gift_idx[another]
                if ai > bi:
                    next_get[i] += 1
                elif ai < bi:
                    next_get[j] += 1
    answer = max(next_get)
    return answer