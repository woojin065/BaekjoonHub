def solution(edges):
    # max_vertex = max(max(edges))
    # in_edges = [ 0 for _ in range(max_vertex)]
    # out_edges = [ 0 for _ in range(max_vertex)]
    
    vertex = {}
    
    for a, b in edges:
        if not vertex.get(a):
            vertex[a] = [0, 0]
        if not vertex.get(b):
            vertex[b] = [0, 0]
        
        vertex[a][0]+=1
        vertex[b][1]+=1
    
    answer = [0, 0, 0, 0]
    
    for key, counts in vertex.items():
        if counts[0] >= 2 and counts[1]==0:
            answer[0]=key
        elif counts[0]==0 and counts[1]>=0:
            answer[2]+=1
        elif counts[0]>=2 and counts[1]>=2:
            answer[3]+=1
    
    answer[1]=vertex[answer[0]][0]-answer[2]-answer[3]
    
    return answer