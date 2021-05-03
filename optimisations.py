import re
import sys
import operator

printContent=True

istemp = lambda s : bool(re.match(r"^r[0-9]*$", s))
isid = lambda s : bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s))

if len(sys.argv) == 2 :
    icg_file = str(sys.argv[1])
elif len(sys.argv) == 3:
    if(sys.argv[2]=="--print"):
        icg_file = str(sys.argv[1])
        printContent=True

def no_quadriples(list_of_lines):
    quad_lines=[]
    fopt=open("quad.txt", "w")
    for line in list_of_lines:
        tokens=line.split()
        if 'if' in tokens[0]:
            quad_lines.append(tokens[0]+"\t\t"+tokens[1]+"\t\t"+tokens[2]+"\t\t"+tokens[3]+"\n")
        elif len(tokens)==3 and tokens[1]=='=':
            quad_lines.append("=\t\t"+tokens[2]+'\t\t \t\t'+tokens[0]+'\n')
        elif len(tokens)>3 and tokens[1]=='=':
            quad_lines.append(tokens[3]+'\t\t'+tokens[2]+'\t\t'+tokens[4]+'\t\t'+tokens[0]+'\n')
        elif tokens[0]=='goto':
            quad_lines.append('goto \t\t \t\t \t\t'+tokens[1]+'\n')
        elif len(tokens)==1:
            quad_lines.append('Label \t\t \t\t \t\t'+tokens[0][:-1]+'\n')
    fopt.writelines(quad_lines)
    print("operation\tval1\t\tval2\t\tdest")
    for line in quad_lines:
        print(line)
    fopt.close()


def quadriples(list_of_lines):
    quad_lines=[]
    fopt=open("optimized_quad.txt", "w")
    for line in list_of_lines:
        tokens=line.split()
        if 'if' in tokens[0]:
            quad_lines.append(tokens[0]+"\t\t"+tokens[1]+"\t\t"+tokens[2]+"\t\t"+tokens[3]+"\n")
        elif len(tokens)==3 and tokens[1]=='=':
            quad_lines.append("=\t\t"+tokens[2]+'\t\t \t\t'+tokens[0]+'\n')
        elif len(tokens)>3 and tokens[1]=='=':
            quad_lines.append(tokens[3]+'\t\t'+tokens[2]+'\t\t'+tokens[4]+'\t\t'+tokens[0]+'\n')
        elif tokens[0]=='goto':
            quad_lines.append('goto \t\t \t\t \t\t'+tokens[1]+'\n')
        elif len(tokens)==1:
            quad_lines.append('Label \t\t \t\t \t\t'+tokens[0][:-1]+'\n')
    fopt.writelines(quad_lines)
    fopt.close()




def eval_binary_expr(op1, oper, op2):
    op1,op2 = int(op1), int(op2)
    if(oper=='+'):
        return op1+op2
    elif(oper=='-'):
        return op1-op2
    elif(oper=='*'):
        return op1*op2
    elif(oper=="/"):
        return op1/op2
    elif(oper=="<"):
        return op1<op2
    elif(oper==">"):
        return op1>op2
    elif(oper=="||"):
        return op1 or op2
    elif(oper=="&&"):
        return op1 and op2



def printICG(list_of_lines):
    for i in list_of_lines:
        print(i.strip())

def add_to_dict(x,y):
    temp_vars[x]=y

def constant_folding(list_of_lines):
    for i in range(len(list_of_lines)):
        if(len(list_of_lines[i].split())==5):
            x=list_of_lines[i].split()
            if x[2].isdigit() and x[4].isdigit():
                s=" "
                t=s.join([x[0],x[1],str(eval_binary_expr(x[2],x[3],x[4])),"\n"])
                list_of_lines[i]=t

def func1(x,i):
    if x[2].isdigit() or x[4].isdigit():
        if x[2].isdigit():
            if(x[4] in temp_vars):
                s=" "
                val=temp_vars[x[4]]
                s=s.join([x[0],x[1],x[2],x[3],val,"\n"])
                list_of_lines[i]=s
                return list_of_lines
        elif x[4].isdigit():
            if(x[2] in temp_vars):
                s=" "
                val=temp_vars[x[2]]
                s=s.join([x[0],x[1],val,x[3],x[4],"\n"])
                list_of_lines[i]=s
                return list_of_lines
    else:
        if(x[2] in temp_vars):
            if(x[4] in temp_vars):
                s=" "
                val1=temp_vars[x[2]]
                val2=temp_vars[x[4]]
                s=s.join([x[0],x[1],val1,x[3],val2,"\n"])
                list_of_lines[i]=s
                return list_of_lines
            else:
                val=temp_vars[x[2]]
                s=" "
                s=s.join([x[0],x[1],val,x[3],x[4],"\n"])
                list_of_lines[i]=s
                return list_of_lines
        if(x[4] in temp_vars):
            val=temp_vars[x[4]]
            s=" "
            s=s.join([x[0],x[1],x[2],x[3],val,"\n"])
            list_of_lines[i]=s
            return list_of_lines



def constant_propagation():
    #print(list_of_lines)
    for i in range(len(list_of_lines)):
        temp_list=list_of_lines[i].split()
        l=len(temp_list)
        #print(temp_list)
        if(l==3):
            add_to_dict(temp_list[0],temp_list[2])
        elif(l==5):
            func1(temp_list,i)

def remove_dead_code(list_of_lines) :
    num_lines = len(list_of_lines)
    temps_on_lhs = set()
    for line in list_of_lines :
        tokens = line.split()
        if istemp(tokens[0]) :
            temps_on_lhs.add(tokens[0])

    useful_temps = set()
    c=0
    for line in list_of_lines :
        tokens = line.split()
        if len(tokens) >= 3 :
            if istemp(tokens[2]) :
                if c>0:
                    useful_temps.add(tokens[2])
                    c=0
                c=+1
        if len(tokens) >= 2 :
            if istemp(tokens[1]) :
                useful_temps.add(tokens[1])

    temps_to_remove = temps_on_lhs - useful_temps
    new_list_of_lines = []

    for line in list_of_lines :
        tokens = line.split()
        c=0
        for i in tokens:
            if i in temps_to_remove :
                c=1
        if c==0:
            new_list_of_lines.append(line)
    if num_lines == len(new_list_of_lines) :
        return new_list_of_lines
    return remove_dead_code(new_list_of_lines)


if __name__ == "__main__" :
        list_of_lines = []
        f = open(icg_file, "r")
        for line in f :
            list_of_lines.append(line)
        f.close()
        temp_list=list()
        temp_vars=dict()
        if(printContent):
            print('ICG: ')
            printICG(list_of_lines)
            print("\n\n")

            print('Quad form: ')
            no_quadriples(list_of_lines)
            print("\n\n")

            print('After Constant Propagation')
            constant_propagation()
            printICG(list_of_lines)
            print("\n\n")


            print('After Constant Folding: ')
            constant_folding(list_of_lines)
            printICG(list_of_lines)
            print("\n\n")

            print('After Dead Code Elimination: ')
            list_of_lines=remove_dead_code(list_of_lines)
            list_of_lines=remove_dead_code(list_of_lines)
            printICG(list_of_lines)
            fopt = open("optimized_icg.txt", "w")
            fopt.writelines(list_of_lines)
            fopt.close()
        else:
            constant_propagation()
            constant_folding(list_of_lines)
            list_of_lines=remove_dead_code(list_of_lines)
            list_of_lines=remove_dead_code(list_of_lines)
            fopt = open("optimized_icg.txt", "w")
            fopt.writelines(list_of_lines)
            fopt.close()
        quadriples(list_of_lines)
