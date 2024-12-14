#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tamanho máximo esperado para os números
#define MAX_DIGITS 10000 

// Estrutura para armazenar um caso de teste
typedef struct {
    char num1[MAX_DIGITS + 1];
    char num2[MAX_DIGITS + 1];
    char operator;
} TestCase;

// Função para remover o caractere de nova linha ao ler strings
void remove_newline(char *str) {
    size_t len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
    }
}

// Função para somar dois números gigantescos representados como strings
char* add_big_numbers(const char *num1, const char *num2) {
    static char result[MAX_DIGITS + 2]; // +2 para o caso de overflow (vai um) e '\0'
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, pos = 0;

    // Zerar a string de resultado
    memset(result, 0, sizeof(result));

    // Iterar pelos números de trás para frente
    int i = len1 - 1, j = len2 - 1;
    while (i >= 0 || j >= 0 || carry > 0) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;
        int sum = digit1 + digit2 + carry;

        result[pos++] = (sum % 10) + '0'; // Armazena o dígito menos significativo
        carry = sum / 10; // Calcula o carry para o próximo dígito

        i--;
        j--;
    }

    // Reverter a string do resultado
    for (int k = 0; k < pos / 2; k++) {
        char temp = result[k];
        result[k] = result[pos - k - 1];
        result[pos - k - 1] = temp;
    }
    result[pos] = '\0'; // Finaliza a string
    return result;
}

// Função para ler um caso de teste
TestCase read_input() {
    TestCase test_case;
    fgets(test_case.num1, MAX_DIGITS + 1, stdin);
    remove_newline(test_case.num1);

    fgets(test_case.num2, MAX_DIGITS + 1, stdin);
    remove_newline(test_case.num2);

    scanf(" %c", &test_case.operator);
    getchar(); // Consumir o newline após o operador
    return test_case;
}

// Função para executar a operação especificada
char* perform_operation(const TestCase *test_case) {
    if (test_case->operator == '+') {
        return add_big_numbers(test_case->num1, test_case->num2);
    }
    // Outras operações serão implementadas futuramente
    return "Operação não implementada";
}

int main() {

    TestCase test_case = read_input();
    char *result = perform_operation(&test_case);
    printf("%s\n", result);
    

    return 0;
}
