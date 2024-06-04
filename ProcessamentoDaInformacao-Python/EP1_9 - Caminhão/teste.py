carga = int(input())

c500 = carga // 500
carga = carga - (c500*500)
print(c500)

c100 = carga // 100
carga = carga - (c100*100)
print(c100)

c25 = carga // 25
carga = carga - (c25*25)
print(c25)

c1 = carga // 1
carga = carga - (c1*1)
print(c1)