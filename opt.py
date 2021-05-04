import copy
import math
import sys

#global variable
flag_const = 0


#function to check whether the given string is a number
def arg_is_dig(str_arg):
    	
    for i in str_arg:
    	temp = ord(i)

    	if (temp<48 or temp>57) and i!='.':
    	    return 0

    return 1

#function to check whether the given string is a character
def arg_is_char(str_arg):
    	
    if str_arg[0] == '\'':

    	str_arg = ord(str_arg[1])
    	return str_arg

    return 0

#function to retreive the value of a variable from the quadruple data structure
def quad_ds_retrieve(quad_ds, curr_line, var):

    global flag_const

    for i in range(curr_line-1,-1,-1):
    	line = quad_ds[i]
    	
    	if line['op'] == '=' and line['res'] == var:
    	    if arg_is_dig(line['arg1']):
    	    	flag_const = 1
    	    	return line['arg1']

    	    else:
    	    	flag_const = 0
    	    	return -1

    flag_const = 0
    return -1


#function to check if a number is a power of 2 or not
def is_power_of_2(n):

    return n and (not(n&(n-1)))



#function to perform constant folding optimisation
def constant_folding_opt(quad_ds):

    c3 = 0
    for i in range(len(quad_ds)):

    	line = quad_ds[i]

    	#binary operators
    	if len(line)==4:
    	    arg1_c = arg_is_char(line['arg1'])
    	    arg2_c = arg_is_char(line['arg2'])
    	    
    	    if arg1_c:
    	    	line['arg1'] = str(arg1_c)

    	    if arg2_c:
    	    	line['arg2'] = str(arg2_c)

    	    #binary plus : '+'
    	    if line['op'] == '+':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])
    	    	
    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) + float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) + int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg1_f and line['arg1'] == '0':
    	    	    temp_eval = line['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = temp_eval
    	    	    del quad_ds[i]['arg2']
    	    	    c3 = 1

    	    	elif arg2_f and line['arg2'] == '0':
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c3 = 1


    	    #binary minus : '-'
    	    elif line['op'] == '-':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) - float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) - int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg1_f and line['arg1'] == '0':
    	    	    temp_eval = "-" + line['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = temp_eval
    	    	    del quad_ds[i]['arg2']
    	    	    c3 = 1

    	    	elif arg2_f and line['arg2'] == '0':
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c3 = 1
    	    	


    	    #binary star : '*'
    	    elif line['op'] == '*':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) * float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) * int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    elif line['arg1'] == '1':
    	    	    	temp_eval = line['arg2']
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    elif line['arg2'] == '1':
    	    	    	quad_ds[i]['op'] = '='
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    
    	    #binary divide : '/'
    	    elif line['op'] == '/':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) / float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) / int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	print("Division By Zero Error\n")
    	    	    	exit()

    	    	    elif line['arg2'] == '1':
    	    	    	quad_ds[i]['op'] = '='
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary modulus : '%'
    	    elif line['op'] == '%':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) % float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) % int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	print("Division By Zero Error\n")
    	    	    	exit()

    	    	    elif line['arg2'] == '1':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary LT : '<'
    	    elif line['op'] == '<':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])
    	    	#print("Entering for",line['arg1'],line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) < float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) < int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary GT : '>'
    	    elif line['op'] == '>':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) > float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) > int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary LTE : '<='
    	    elif line['op'] == '<=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) <= float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) <= int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary GTE : '>='
    	    elif line['op'] == '>=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) >= float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) >= int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1


    	    #binary EQ : '=='
    	    elif line['op'] == '==':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) == float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) == int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    #binary NEQ : '!='
    	    elif line['op'] == '!=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) != float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) != int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1
    	    	    	
    	     #binary LEFT SHIFT : '<<'
    	    elif line['op'] == '<<':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])
    	    	print("Entering for",line['arg1'],line['arg2'])

    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	print("Loop 1")
    	    	    	temp_eval = float(line['arg1']) * (2**float(line['arg2']))
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	print("Loop 2")
    	    	    	temp_eval = int(line['arg1']) * (2**int(line['arg2']))
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c3 = 1

    return c3
    	    	


#function to perform constant propagation optimisation
def constant_propagation(quad_ds):

    global flag_const
    c4 = 0
    for i in range(len(quad_ds)):

    	line = quad_ds[i]

    	#binary operators
    	if len(line)==4:

    	    #binary plus : '+'
    	    if line['op'] == '+':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])
    	    	print(line['arg1'],arg1_f,line['arg2'],arg2_f)      #######

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) + float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) + int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg1_f and line['arg1'] == '0':
    	    	    temp_eval = line['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = temp_eval
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1

    	    	elif arg2_f and line['arg2'] == '0':
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1


    	    #binary minus : '-'
    	    elif line['op'] == '-':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) - float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) - int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg1_f and line['arg1'] == '0':
    	    	    temp_eval = "-" + line['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = temp_eval
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1

    	    	elif arg2_f and line['arg2'] == '0':
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1


    	    #binary star : '*'
    	    elif line['op'] == '*':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) * float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) * int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    elif line['arg1'] == '1':
    	    	    	temp_eval = line['arg2']
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    elif line['arg2'] == '1':
    	    	    	quad_ds[i]['op'] = '='
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary divide : '/'
    	    elif line['op'] == '/':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) / float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) / int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	print("Division By Zero Error\n")
    	    	    	exit()

    	    	    elif line['arg2'] == '1':
    	    	    	quad_ds[i]['op'] = '='
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary modulus : '%'
    	    elif line['op'] == '%':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) % float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) % int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	elif arg1_f:

    	    	    if line['arg1'] == '0':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    	elif arg2_f:

    	    	    if line['arg2'] == '0':
    	    	    	print("Division By Zero Error\n")
    	    	    	exit()

    	    	    elif line['arg2'] == '1':
    	    	    	temp_eval = "0"
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = temp_eval
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1



    	    #binary LT : '<'
    	    elif line['op'] == '<':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) < float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) < int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary GT : '>'
    	    elif line['op'] == '>':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) > float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) > int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary LTE : '<='
    	    elif line['op'] == '<=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) <= float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) <= int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary GTE : '>='
    	    elif line['op'] == '>=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) >= float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) >= int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary LTE : '<='
    	    elif line['op'] == '<=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) <= float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) <= int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary EQ : '=='
    	    elif line['op'] == '==':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) == float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) == int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1


    	    #binary NEQ : '!='
    	    elif line['op'] == '!=':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])


    	    	#both the arguments are constants
    	    	if arg1_f and arg2_f:

    	    	    #one or both the arguments are floating point numbers
    	    	    if '.' in line['arg1'] or '.' in line['arg2']:
    	    	    	temp_eval = float(line['arg1']) != float(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    	    #the arguments are integers
    	    	    else:
    	    	    	temp_eval = int(line['arg1']) != int(line['arg2'])
    	    	    	quad_ds[i]['op'] = '='
    	    	    	quad_ds[i]['arg1'] = str(temp_eval)
    	    	    	quad_ds[i]['arg1'] = 'true' if quad_ds[i]['arg1']=='True' else 'false'  
    	    	    	del quad_ds[i]['arg2']
    	    	    	c4 = 1

    	    #AND : '&&'
    	    elif line['op'] == '&&':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])
    	    	print(line['arg1'], line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2

    	    	if line['arg1'] == 'true' and line['arg2'] == 'true':
    	    	    del quad_ds[i]['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = 'true'
    	    	    c4 = 1

    	    	else:
    	    	    quad_ds[i]['arg1'] = 'false'
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1

    	    #OR : '||'
    	    elif line['op'] == '||':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	if line['arg1'] == 'false' and line['arg2'] == 'false':
    	    	    del quad_ds[i]['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = 'false'
    	    	    c4 = 1

    	    	else:
    	    	    quad_ds[i]['arg1'] = 'true'
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1
    	
    	   

    	   #LEFT SHIFT : '<<'    	##left shift
    	    elif line['op'] == '<<':
    	    	arg1_f = arg_is_dig(line['arg1'])
    	    	arg2_f = arg_is_dig(line['arg2'])

    	    	#arg1 is a digit, arg2 is a variable
    	    	if arg1_f and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res

    	    	#arg1 is a variable, arg2 is a digit
    	    	elif not(arg1_f) and arg2_f:
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	#arg1 and arg2 are variables
    	    	elif not(arg1_f) and not(arg2_f):
    	    	    flag_const = 0
    	    	    res = quad_ds_retrieve(quad_ds,i,line['arg1'])
    	    	    if flag_const:
    	    	    	line['arg1'] = res

    	    	    flag_const = 0
    	    	    res2 = quad_ds_retrieve(quad_ds,i,line['arg2'])
    	    	    if flag_const:
    	    	    	line['arg2'] = res2


    	    	if line['arg1'] == 'false' and line['arg2'] == 'false':
    	    	    del quad_ds[i]['arg2']
    	    	    quad_ds[i]['op'] = '='
    	    	    quad_ds[i]['arg1'] = 'false'
    	    	    c4 = 1

    	    	else:
    	    	    quad_ds[i]['arg1'] = 'true'
    	    	    quad_ds[i]['op'] = '='
    	    	    del quad_ds[i]['arg2']
    	    	    c4 = 1
    	    	     
    	elif len(line)==3:
            arg1_f = arg_is_dig(line['arg1'])
            #arg1 is a  variable
            if not(arg1_f):
                flag_const = 0
                res = quad_ds_retrieve(quad_ds,i,line['arg1'])
                if flag_const:
                        line['arg1'] = res

            if line['op'] == '!':
                arg1_f = arg_is_dig(line['arg1'])

                #arg1 is a variable, arg2 is a digit
                if line['arg1'] == 'false':
                    quad_ds[i]['op'] = '='
                    quad_ds[i]['arg1'] = 'true'

                else:
                    quad_ds[i]['arg1'] = 'false'
                    quad_ds[i]['op'] = '='

    return c4    	    
    	    


import re
import sys
icg_file = "Outputs/ICG.txt"

istemp = lambda s : bool(re.match(r"^t[0-9]*$", s)) 
isid = lambda s : bool(re.match(r"^[A-Za-z][A-Za-z0-9_]*$", s)) #will match temp also

def printicg_QUAD(list_of_lines, message = "") :

    fin=open("Outputs/QUAD1.txt",'w')
    print(message.upper())
    
    print("##"*30)
    print("\n")
    for line in list_of_lines :
    	print(line.strip())
    	line_parts = line.strip().split()
    	if len(line_parts) == 5 and line_parts[1] == '=':
    	    print(line_parts[3],line_parts[2],line_parts[4],line_parts[0], file=fin)
    	elif len(line_parts) == 4 and line_parts[0] == 'if':
    	    print(line_parts[0],line_parts[1],line_parts[3], file=fin)
    	elif len(line_parts)==2 and line_parts[0] == 'goto':
    	    print(line_parts[0],line_parts[1], file=fin)
    	elif len(line_parts)==2 and line_parts[1] == ':':
    	    print("label",line_parts[0], file=fin)
    	elif len(line_parts)==3 and line_parts[1] == '=':
    	    print(line_parts[1],line_parts[2],line_parts[0], file=fin)
    	elif len(line_parts)==4 and line_parts[2] == '!':
            print(line_parts[2],line_parts[3],line_parts[0], file=fin)

    fin.close()


def make_subexpression_dict(list_of_lines) :
    expressions = {}
    variables = {}
    for line in list_of_lines :
    	tokens = line.split()
    	if len(tokens) == 5 :
    	    # print("variables",variables)
    	    if tokens[0] in variables and variables[tokens[0]] in expressions :
    	    	print("here")
    	    	print(tokens[0], variables[tokens[0]], expressions[variables[tokens[0]]])
    	    	del expressions[variables[tokens[0]]]
    	    rhs = tokens[2] + " " + tokens[3] + " " + tokens[4]
    	    if rhs not in expressions :
    	    	expressions[rhs] = tokens[0]
    	    	if isid(tokens[2]) :
    	    	    variables[tokens[2]] = rhs
    	    	if isid(tokens[4]) :
    	    	    variables[tokens[4]] = rhs
    return expressions

def eliminate_common_subexpressions(list_of_lines) :
    expressions = make_subexpression_dict(list_of_lines)
    # print(expressions)
    lines = len(list_of_lines)
    new_list_of_lines = list_of_lines[:]
    for i in range(lines) :
    	tokens = list_of_lines[i].split()
    	if len(tokens) == 5 :
    	    rhs = tokens[2] + " " + tokens[3] + " " + tokens[4]
    	    if rhs in expressions and expressions[rhs] != tokens[0]:
    	    	new_list_of_lines[i] = tokens[0] + " " + tokens[1] + " " + expressions[rhs]
    return new_list_of_lines



#function to print the quadruple data structure in table format
def print_quad(quad_ds, f = sys.stdout):

    print(file=f)
    print(file=f)
    print('%-12s' % "Operator",'%-12s' % "Arg1",'%-12s' % "Arg2",'%-12s' % "Result", file=f)

    for i in range(len(quad_ds)):

    	line = quad_ds[i]

    	if len(line) == 4:
    	    print('%-12s' % line['op'],'%-12s' % line['arg1'],'%-12s' % line['arg2'],'%-12s' % line['res'], file=f)

    	elif len(line) == 3:
    	    print('%-12s' % line['op'],'%-12s' % line['arg1'],'%-12s' % "",'%-12s' % line['res'], file=f)

    	elif len(line) == 2:
    	    print('%-12s' % line['op'],'%-12s' % "",'%-12s' % "",'%-12s' % line['res'], file=f)


    print()
    print()



#function to print the intermediate code from the quadruple data structure
def print_icg(quad_ds, f=sys.stdout):

    print(file=f)
    print(file=f)

    for i in range(len(quad_ds)):
    	line = quad_ds[i]

    	if len(line) == 4:
    	    print(line['res'],"=",line['arg1'],line['op'],line['arg2'], file=f)

    	elif len(line) == 3:
    	    
    	    if line['op'] == '=':
    	    	print(line['res'],"=",line['arg1'], file=f)

    	    elif line['op'] == 'if':
    	    	print(line['op'],line['arg1'],"goto",line['res'], file = f)

    	elif len(line) == 2:

    	    if line['op'] == "goto":
    	    	print(line['op'],line['res'], file=f)
    	    else:
    	    	print(line['res'], ":", file=f)
    	    

    
    print(file=f)
    print(file=f)


def existslabel(lines, i):
    if(i == 0):
    	return 0
    while(i>=0):
    	if(len(lines[i].split()) == 2):
    	    return 1
    	i = i - 1
    return 0

def exists_lhs(lines, variable, start, end):
    for i in range(start, end):
    	if(lines[i].split()[0] == variable):
    	    return 1
    return 0
    	
    	
def loop_block(lines):

    label_dict = dict() # stores the lines of the form Ln : , n is int, with the label and index (line_no - 1)
    goto_dict = dict() #stores the lines which have goto Ln with the label they go to and index (line_no - 1)
    loop_range = [] # stores the index of the start and end of the loop, ie, label index and goto index

    for i in range(len(lines)):

    	if(len(lines[i].split()) == 2 and lines[i].split()[1] == ':'):
    	    label_dict[lines[i].split()[0]] = i

    	if(len(lines[i].split())==2 and lines[i].split()[0] == 'goto'):
    	    goto_dict[lines[i].split()[1]] = i
    	
    for key in goto_dict:

    	try:
    	    if(goto_dict[key]>label_dict[key]): #loops will have goto instruction to labels present above them
    	    	loop_range.append([label_dict[key], goto_dict[key]])
    	except:
    	    pass

    # print(goto_dict)
    # print(label_dict)
    # print(loop_range)
    return loop_range


def move_loop_invariants(lines):
    for i in range(len(lines)):
    	lines[i] = lines[i].strip("\n")

    #print(lines)

    loop_range = loop_block(lines)
    for i in loop_range:
    	start = i[0]
    	end = i[1]
    	for j in range(i[0], end):
    	    	    	    
    	    if(len(lines[j].split()) == 3 and lines[j].split()[2].isdigit()):   #direct assignment to int, move above loop
    	    	temp = lines.pop(j)
    	    	lines.insert(start, temp)
    	    	start+=1

    	    if(len(lines[j].split())==3):
    	    	var = lines[j].split()[2]
    	    	
    	    	if(not exists_lhs(lines, var, start, end)):  #if value of assigned variables doesnt change in the loop (a=b type, and b does not change)
    	    	    temp = lines.pop(j)
    	    	    lines.insert(start, temp)
    	    	    start+=1

    	    if(len(lines[j].split()) == 5):

    	    	var1 = lines[j].split()[2]
    	    	var2 = lines[j].split()[4]
    	    	
    	    	if(var1.isdigit() and var2.isdigit()):  #if both operands are ints (constant) move before loop
    	    	    temp = lines.pop(j)
    	    	    lines.insert(start, temp)
    	    	    start+=1

    	    	elif(var1.isdigit()):
    	    	    if(not exists_lhs(lines, var2, start, end)):     #first operand is digit, second is unvarying variable -> move above the loop
    	    	    	temp = lines.pop(j)    	    	    	      # a = 5 + b form
    	    	    	lines.insert(start, temp)
    	    	    	start+=1
    	    	    	
    	    	elif(var2.isdigit()):
    	    	    if(not exists_lhs(lines, var1, start, end)):     #second operand is digit, first is unvarying variable -> move above loop
    	    	    	temp = lines.pop(j)    	    	    	     # a = b + 5 form
    	    	    	lines.insert(start, temp)
    	    	    	start+=1
    	    	else:
    	    	    if(not exists_lhs(lines, var1, start, end) and not exists_lhs(lines, var2, start, end)):  #both operands are unvarying variables -> move above
    	    	    	temp  = lines.pop(j)    	    	    	    # a = b + c form 
    	    	    	lines.insert(start, temp)
    	    	    	start+=1    	    	    
    	    	
    print("##"*30)
    fin = open("Outputs/ICG.txt",'w')    
    print(" "*14,"LOOP INVARIANT CODE MOTION")
    print("##"*30)
    print("\n")
    for i in lines:
    	print(i)
    	print(i, file=fin)

    fin.close()
    return lines, loop_range


def elimDeadCode(lines):
    flag = 0
    newlines = []
    for i in range(len(lines)):
    	lines[i] = lines[i].strip("\n")
    	outflag = 0
    	if(existslabel(lines, i) == 1):
    	    
    	    
    	    newlines.append(lines[i])
    	    continue
    	if(len(lines[i].split()) == 5 or len(lines[i].split()) == 3):

    	    lhs = lines[i].split()[0]
    	    
    	    for j in range(i+1, len(lines)):

    	    	if(len(lines[j].split()) == 5):
    	    	    rhs1 = lines[j].split()[2]
    	    	    rhs2 = lines[j].split()[4]
    	    	    if(rhs1 == lhs or rhs2 == lhs):
    	    	    	outflag = 1
    	    	    	flag = 1
    	    	    	break

    	    	elif(len(lines[j].split()) == 3):

    	    	    rhs = lines[j].split()[2]

    	    	    if(rhs == lhs):
    	    	    	outflag =1
    	    	    	flag = 1
    	    	    	break
    	    	
    	    	elif(len(lines[j].split()) == 4):
    	    	    rhs = lines[j].split()[1]
    	    	    l1 = ""
    	    	    l2 = ""
    	    	    fl = 0
    	    	    
    	    	    for x in rhs:
    	    	    	if x in [">", "<", "=", "!"]:
    	    	    	    fl = 1
    	    	    	    continue
    	    	    	if (x == "="):
    	    	    	    continue
    	    	    	if(fl == 0):
    	    	    	    l1 = l1 + x
    	    	    	if(fl == 1):
    	    	    	    l2 = l2 + x
    	    	    
    	    	    if(l1 == lhs or l2 == lhs):
    	    	    	flag = 1
    	    	    	outflag = 1
    	    	    	break
    	    	else:

    	    	    continue

    	    if(outflag == 1):
    	    	
    	    	newlines.append(lines[i])
    	    	    
    	    	    
    	    	
    	else:
    	    newlines.append(lines[i])
    	    continue
    
    return newlines



if __name__ == "__main__":


    fin = open("icg.txt")
    lines = fin.readlines()
    lines, loopblock = move_loop_invariants(lines)
    fin.close()


    # (quad_ds)
    # print_quad(quad_ds)
    print("\n")
    print("##"*30)
    list_of_lines = []
    f = open("icg.txt", "r")
    for line in f :
    	list_of_lines.append(line)
    f.close()

    # printicg(list_of_lines,"ICG")
    eliminated_common_subexpressions = eliminate_common_subexpressions(list_of_lines)
    printicg_QUAD(eliminated_common_subexpressions, "    	    common subexpression elimination")

    #print("--"*30)

    file_quad = open("Outputs/QUAD1.txt","r")
    file_ip = file_quad.readlines()
    file_quad.close()

    #list of dictionaries where each element of the list corresponds 
    # to one record in the quadruple data structure
    #each dictionary has the fields 'op', 'arg1', 'arg2', 'res'
    quad_ds = [] 

    for i in range(len(file_ip)):
    	file_ip[i] = file_ip[i].strip()
    	line = file_ip[i].split()
    	temp = {}

    	no_f = len(line)

    	#all four fields of the quadruple ds are filled
    	if no_f == 4:
    	    temp['op'] = line[0]
    	    temp['arg1'] = line[1]
    	    temp['arg2'] = line[2]
    	    temp['res'] = line[3]


    	#only 3 fields are filled - op, arg1, res
    	elif no_f == 3:
    	    temp['op'] = line[0]
    	    temp['arg1'] = line[1]
    	    temp['res'] = line[2]

    	#only 2 fields are filled - op, res
    	elif no_f == 2:
    	    temp['op'] = line[0]
    	    temp['res'] = line[1]

    	quad_ds.append(temp)

   
    c3 = 1
    c4 = 1

    while(c3 or c4):

    	c4 = constant_propagation(quad_ds)
    	# print_quad(quad_ds)
    	print('\n\n')
    	print("##"*30)
    	print(" "*17,"CONSTANT PROPAGATION")
    	print("##"*30)
    	print_icg(quad_ds)
    	#print("--"*30)

    	c3 = constant_folding_opt(quad_ds)

    	print("##"*30)
    	print(" "*17,"CONSTANT FOLDING")
    	print("##"*30)
    	print()
    	print_icg(quad_ds)


    fin = open("Outputs/ICG_2.txt", "w")
    print_icg(quad_ds, fin)
    fin.close()

    fin = open("Outputs/ICG_2.txt", "r")
    lines = fin.readlines()
    # icg = fin.read()
    fin.close()
    
    lines = elimDeadCode(lines)
    print("##"*30)
    print(" "*17,"DEAD CODE ELIMINATION")
    print("##"*30)
    for i in lines:
    	print(i)
    	
    		
    fin1 = open("Outputs/Optimised_Intermediate_Code.txt", "w")
    for i in lines:
    	fin1.write(i)
    	fin1.write("\n")
    fin1.close()