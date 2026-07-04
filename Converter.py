class DefaultNode:
    approve=[]
    type=''
    spec=''
    children = []
    available=[]

    def __init__(self):
        self.children = []


    def check_children(self):
        pass

class Sequence(DefaultNode):
    type = 'Sequence'
    approve=['Unl','Operation']

class OperationIf(DefaultNode):
    type = 'Operation'
    spec='If'
    approve=['Condition','Sequence','Unl_Opt','Else']

class Condition(DefaultNode):
    type = 'Condition'
    approve=['Math','Unl_Opt','Compare','Math','Unl_Opt_End']

class Math(DefaultNode):
    type = 'Math'
    approve=['Term','Unl_Opt','Addiction','Term','Unl_Opt_End']

class Term(DefaultNode):
    type = 'Term'
    approve=['Factor','Unl_Opt','Multiplication','Factor','Unl_Opt_End']

class Factor(DefaultNode):
    type = 'Factor'
    approve = ['One','Variable','Constant','Math','One_End']

class Variable(DefaultNode):
    type = 'Variable'
    available = [int,bool]
    def __init__(self,data):
        super().__init__()
        self.data=data

class Constant(DefaultNode):
    type = 'Constant'
    available = [int,bool]
    def __init__(self,data):
        super().__init__()
        self.data=data

class Return(DefaultNode):
    type = 'Operation'
    spec='Return'
    approve = ["Factor"]

class Assignment(DefaultNode):
    type = 'Operation'
    spec='Assignment'
    approve = ["Variable",'Math']



