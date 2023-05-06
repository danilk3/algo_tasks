class Node:
    def __init__(self, data=None, next=None, prev=None):
        self.data = data
        self.next = next
        self.prev = prev


s = input()
end = Node(s[0])
head = end

for i in range(1, len(s)):
    node = Node(s[i])
    end.next = node
    node.prev = end
    end = node

q = int(input())

reversedString = False

for i in range(q):
    t = input().split(' ')

    if int(t[0]) == 1:
        reversedString = not reversedString
    else:
        node = Node(t[2])
        if int(t[1]) == 1:
            if reversedString:
                end.next = node
                node.prev = end
                end = node
            else:
                node.next = head
                head.prev = node
                head = node
        else:
            if reversedString:
                node.next = head
                head.prev = node
                head = node
            else:
                end.next = node
                node.prev = end
                end = node


if reversedString:
    while end is not None:
        print(end.data, end='')
        end = end.prev
else:
    while head is not None:
        print(head.data, end='')
        head = head.next