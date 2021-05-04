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
        print(line, end = "")
    fopt.close()



if __name__ == "__main__" :
        list_of_lines = []
        f = open("icg.txt", "r")
        for line in f :
            list_of_lines.append(line)
        f.close()
        print('ICG: ')
        for line in list_of_lines:
            print(line, end = "")
        print("\n\n")

        print('Quad form: ')
        no_quadriples(list_of_lines)
        print("\n\n")
