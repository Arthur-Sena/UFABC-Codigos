codigo = input()

def codificador(x):
    if x == 9:
        return 0
    else:
        return x+1

n1 = codificador(int(codigo[0]))
n2 = codificador(int(codigo[1]))
n3 = codificador(int(codigo[2]))
n4 = codificador(int(codigo[3]))

print(n1,n2,n3,n4, sep="")