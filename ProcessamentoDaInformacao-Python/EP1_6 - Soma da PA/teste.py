def calculo_pa():
    a1 = int(input())
    razao = int(input())
    n = int(input())
    return (n*(a1 + (a1+ ((n-1)*razao))))/2

print(calculo_pa())