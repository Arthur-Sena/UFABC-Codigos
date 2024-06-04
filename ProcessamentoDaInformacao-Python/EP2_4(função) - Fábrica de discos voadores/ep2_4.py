#EP2_4(função) - Fábrica de discos voadores
def obter_prazo_entrega(disco1, disco2, disco3):
    if disco1 == disco2 and disco2 == disco3:
      return "5"
    elif disco1 != disco2 and disco2 != disco3 and disco1 != disco3:
      return "30"
    else:
        return "15"
