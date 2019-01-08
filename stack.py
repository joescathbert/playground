class sta:
    def __init__(self, x):
        self.val = x
        self.next = None

    def push(self, x):
        temp = sta(self.val)
        temp.next = self.next
        self.val = x
        self.next = temp

    def pop(self):
        tempv = self.val
        self.val = self.next.val
        self.next = self.next.next
        return tempv
    
    def prints(self):
         temp = self
         while temp.next is not None:
             print(temp.val)
             temp =temp.next
         print(temp.val)

a = sta(3)
a.push(5)
a.push(8)
a.push(6)
a.prints()
print()
print(a.pop())
print()
a.prints()
