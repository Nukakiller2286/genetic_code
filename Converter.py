class DefaultNode:
    approve=[]
    type=''
    spec=''
    children = []
    def __init__(self):
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
    approve=['Opt',]


