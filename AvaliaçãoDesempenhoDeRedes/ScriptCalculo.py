import matplotlib.pyplot as plt

def simular_vazao():
    # Parâmetros da rede
    CAPACIDADE_LINK_GBPS = 10
    OVERHEAD_MACSEC_BYTES = 32
    OVERHEAD_OTN_BYTES = 0

    # Tamanhos de quadro Ethernet (em bytes) - do mínimo 64 ao MTU padrão 1518
    tamanhos_quadro = list(range(64, 1519))

    vazao_macsec = []
    vazao_otn = []

    # Cálculo da vazão efetiva por meio do laço de repetição
    for tamanho in tamanhos_quadro:
        # Cálculo para o MACsec (Camada 2)
        eficiencia_macsec = tamanho / (tamanho + OVERHEAD_MACSEC_BYTES)
        vazao_macsec.append(eficiencia_macsec * CAPACIDADE_LINK_GBPS)
        
        # Cálculo para a Criptografia OTN (Camada 1)
        eficiencia_otn = tamanho / (tamanho + OVERHEAD_OTN_BYTES)
        vazao_otn.append(eficiencia_otn * CAPACIDADE_LINK_GBPS)

    # Configuração e Geração do Gráfico
    plt.figure(figsize=(10, 6))
    
    plt.plot(tamanhos_quadro, vazao_macsec, label='MACsec (Camada 2)', 
             color='red', linestyle='--', linewidth=2)
    
    plt.plot(tamanhos_quadro, vazao_otn, label='Criptografia OTN (Camada 1)', 
             color='blue', linewidth=2)

    # Formatação visual para o artigo
    plt.title('Comparação de Vazão Efetiva: MACsec vs. Criptografia OTN')
    plt.xlabel('Tamanho do Quadro (bytes)')
    plt.ylabel('Vazão Efetiva (Gbps)')
    plt.legend()
    plt.grid(True, linestyle=':', alpha=0.7)
    
    # Salva o gráfico em alta resolução e o exibe
    plt.savefig('comparacao_vazao_adr.png', dpi=300)
    plt.show()

if __name__ == '__main__':
    simular_vazao()