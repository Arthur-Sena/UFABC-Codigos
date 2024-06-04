#EP1_10 - Desempenho preditivo
def calculo_acuracia(vp, fn, fp, vn):
    return (vp + vn) / (vp + vn + fp + fn)

def calculo_precisao(vp, fp):
    return vp / (vp + fp)

def calculo_sensibilidade(vp, fn):
    return vp / (vp + fn)

def main():
    vp = int(input())
    fn = int(input())
    fp = int(input())
    vn = int(input())

    acuracia = calculo_acuracia(vp, fn, fp, vn)
    precisao = calculo_precisao(vp, fp)
    sensibilidade = calculo_sensibilidade(vp, fn)

    print("%.2f"%(acuracia))
    print("%.2f"%(precisao))
    print("%.2f"%(sensibilidade))

main()