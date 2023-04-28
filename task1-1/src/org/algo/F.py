n = int(input())

candidates = {}

for i in range(n):
    name = input()
    consignment = input()
    candidates[name] = consignment

maxVote = -1
isUnique = False
winnerName = ""

votes = {}

m = int(input())

for i in range(m):
    name = input()

    if candidates.get(name) is None:
        continue

    votesValue = votes.get(name, 0) + 1

    if votesValue > maxVote:
        winnerName = name
        maxVote = votesValue
        isUnique = True
    elif votesValue == maxVote:
        isUnique = False

    votes[name] = votesValue

if not isUnique:
    print("tie")
else:
    print(candidates[winnerName])
