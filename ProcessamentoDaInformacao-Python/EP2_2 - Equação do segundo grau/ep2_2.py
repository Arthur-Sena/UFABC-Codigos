#EP2_2 - Equação do segundo grau
def calculo_delta(a, b, c):
    delta = (b**2) - (4*a*c)
    return delta

def main():
    a = int(input())
    b = int(input())
    c = int(input())

    delta = calculo_delta(a, b, c)
    if delta < 0:
        print("Sem solucao real!")
        print("Delta = %.2f"%(delta))
    else:
        x1 = (-b + (delta ** 0.5)) / (2 * a)
        x2 = (-b - (delta ** 0.5)) / (2 * a)
        if x1 == x2:
            print("x = %.2f" % (x2))
        else:
            x = [x1,x2]
            print("x1 = %.2f" % (min(x)))
            print("x2 = %.2f" % (max(x)))

main()