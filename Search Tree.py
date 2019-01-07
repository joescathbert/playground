class SearchTree:
    def __init__(self, stateno=None, statein=None, par=None):
        self.stateinfo = statein
        self.currentstateno = stateno
        self.child = []
        self.noofchilds = 0
        self.parent = par

    def insert(self, inserttree):
        self.child.append(SearchTree(stateno=self.currentstateno+1, statein=inserttree, par=self))
        self.noofchilds += 1

    def find(self, value):    # best thought find alg
        if self.stateinfo == value:
            return self
        else:
            if self.child is not None:
                for i in self.child:
                    temp = i.find(value)
                    if temp is not None:     # the best part - returns only if the returned value is not None
                        return temp

    def printtree(self):
        print(self.stateinfo, self.currentstateno, self.noofchilds)
        if len(self.child) != 0:
            for i in self.child:
                i.printtree()


a = SearchTree(stateno=0, statein=1)
a.insert(5)
a.insert(11)
a.insert(7)
a.child[0].insert(12)
a.child[0].insert(11)
print(a.find(7).parent.stateinfo)
print("Print Tree")
a.printtree()
print("Childs", a.child[0].noofchilds)