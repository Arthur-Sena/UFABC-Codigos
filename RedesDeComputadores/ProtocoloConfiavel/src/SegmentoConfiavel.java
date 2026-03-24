// Arthur Sena - 1120223175
import java.io.Serializable;

// Funcionalidade: Implementar o formato (cabeçalho) da mensagem que será transmitida.
public class SegmentoConfiavel implements Serializable {
    private static final long serialVersionUID = 1L;
    
    // Atributo: Identificador do pacote (Número de Sequência ou número de ACK)
    // O professor exigiu que o número de sequência seja por pacote (não por byte)
    private int id; 
    
    // Atributo: Carga útil (dados da mensagem enviada, ex: "oi")
    private String payload; 
    
    // Atributo: Flag para identificar se o segmento é de Dados (false) ou de Reconhecimento/ACK (true)
    private boolean isAck; 

    public SegmentoConfiavel(int id, String payload, boolean isAck) {
        this.id = id;
        this.payload = payload;
        this.isAck = isAck;
    }

    public int getId() {
        return id;
    }

    public String getPayload() {
        return payload;
    }

    public boolean isAck() {
        return isAck;
    }
}