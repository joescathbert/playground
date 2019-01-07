# import pickle


class Node:
    def __init__(self, n):
        self.left = None
        self.right = None
        self.height = 1
        self.slope = 0
        self.parent = None
        try:
            if len(n) > 0:
                self.data = n[0]
                for r in range(1, len(n)):
                    self.insert(n[r])
        except:
            self.data = n

    def rightrotation(self):
        a = self.data
        b = self.right.data
        node1 = self.left
        node2 = self.right.left
        node3 = self.right.right
        self.data = b
        self.left = Node(a)
        self.left.parent = self
        self.right = node3
        if node3 is not None:
            node3.parent = self
            node3.heightfunc()
            node3.slopefunc(setvalue=True)
        self.left.left = node1
        if node1 is not None:
            node1.parent = self.left
            node1.heightfunc()
            node1.slopefunc(setvalue=True)
        self.left.right = node2
        if node2 is not None:
            node2.parent = self.right
            node2.heightfunc()
            node2.slopefunc(setvalue=True)
        self.left.heightfunc()
        self.heightfunc()
        self.slopefunc(setvalue=True)
        self.left.slopefunc(setvalue=True)
        #print(self.height)

    def balance(self):
        if self.slope < -1:
            self.rightrotation()

    def heightfunc(self, nodeparam=None):
        temp = self if nodeparam is None else nodeparam
        leftheight = 0
        rightheight = 0
        while temp.left is not None:
            temp = temp.left
            leftheight += 1
        temp = self if nodeparam is None else nodeparam
        while temp.right is not None:
            temp = temp.right
            rightheight += 1
        if nodeparam is not None:
            return max(leftheight + 1, rightheight + 1)
        self.height = max(leftheight + 1, rightheight + 1)

        # print(self.height)

    def slopefunc(self, nodeparam=None, returnvalue=None, setvalue=None):
        returnvalue = returnvalue if returnvalue is not None else False
        setvalue = setvalue if setvalue is not None else False
        temp = self if nodeparam is None else nodeparam
        if temp.right is not None and temp.left is not None:
            # print(temp.data, temp.left.height, temp.right.height)
            slopep = temp.left.height - temp.right.height
        elif temp.right is not None:
            slopep = -temp.right.height
        elif temp.left is not None:
            slopep = temp.left.height
        else:
            slopep = 0
        if setvalue:
            self.slope = slopep
        if returnvalue:
            return slopep

    def find(self, num, returnobj=None):
        returnobj = returnobj if returnobj is not None else False
        temp = self
        while temp is not None:
            if num < temp.data:
                temp = temp.left
            elif num > temp.data:
                temp = temp.right
            elif temp.data == num:
                if returnobj:
                    return temp
                else:
                    return 1
        else:
            if returnobj:
                return None
            else:
                return 0

    def insert(self, n):
        if n < self.data:
            if self.left is None:
                self.left = Node(n)
                self.left.parent = self
                self.heightfunc()
                self.slope = self.slopefunc(returnvalue=True)
            else:
                self.left.insert(n)
                self.heightfunc()
                self.slope = self.slopefunc(returnvalue=True)
                self.balance()
                self.heightfunc()
        elif n > self.data:
            if self.right is None:
                self.right = Node(n)
                self.right.parent = self
                self.heightfunc()
                self.slope = self.slopefunc(returnvalue=True)
            else:
                self.right.insert(n)
                self.heightfunc()
                self.slope = self.slopefunc(returnvalue=True)
                self.balance()
                self.heightfunc()

    def inOrder(self):
        print(self.data, self.height, self.slope)
        if self.left is not None:
            self.left.inOrder()
        if self.right is not None:
            self.right.inOrder()


root = Node([6,3,2,1,8])
root.inOrder()

'''for i in range(19,0,-1):
    root.insert(i)
    root.inOrder()
    print()'''

