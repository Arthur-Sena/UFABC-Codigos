#EP2_3 - Conceito final
def calculo_conceito(t1, t2, t3, p1, p2):
    nota_final = 0.2*((t1+t2+t3)/3) + 0.4*p1 + 0.4*p2
    return nota_final

def main():
    t1 = float(input())
    t2 = float(input())
    t3 = float(input())
    p1 = float(input())
    p2 = float(input())

    nf = calculo_conceito(t1, t2, t3, p1, p2)
    print("%.2f"%(nf))

    if nf >= 9:
        print("A")
    elif nf >=7.5:
        print("B")
    elif nf >= 6:
        print("C")
    elif nf >= 5:
        print("D")
    else:
        print("F")

main()