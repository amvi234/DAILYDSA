n = int(input())
states = list(map(int, input().split()))
distances = list(map(int, input().split()))
distance = 0
for i in range(len(distances)-1):
    if(states[i]==0):
        distance = distance + distances[i+1] - distances[i]
print (distance)