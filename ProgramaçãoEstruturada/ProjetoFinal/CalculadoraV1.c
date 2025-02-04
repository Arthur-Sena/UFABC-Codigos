/* A fazer e melhorias
1 - [FEITO +/-, Dando erro com num mt grande e num negativo] Soma - NÂO TESTEI COM A ENTRADA DO PROFESSOR NAQUELE ARQUIVO .IN
2 - [FEITO +/-, Dando erro com num mt grande e num negativo] Subtração - NÂO TESTEI COM A ENTRADA DO PROFESSOR NAQUELE ARQUIVO .IN
3 - Multiplicação
4 - Divisao
5 - Melhorias
6 - Precisa rodar naquele bglh la que o professor usa na aula pra ver se tem 
    alguma coisa vazando na memória (não sei fazer isso no windows :´(  
7 - Dividir os arquivos em pastas seguindo o roteiro do prof
8 - Criar a interface
9 - Testar tudo
10 -[FEITO] IMPORTANTE - Declarei o input1 e input2 com tamanho maximo de caractere (10005), acho que não pode ter limite, 
             tem que usar alocação dinaminca de memória, não sei fazer isso
11 - Fazer extras 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#pragma region "Lista duplamente encadeada"
/*
    Region contem a definicao dos "tipos" Node (número quebrado/ algarismo por algarismo) e 
    BigNumber (recebe o ponteiro do primeiro algarismo do número )
    
    Node.previousNode = Ponteiro do nó anterior
    Node.nextNode     = Ponteiro para o proximo nó 

    BigNumber.is_negative = Bool (0 ou 1) verigicando se o nó atual contem número positivo ou negativo
*/
typedef struct Node {
    int digit;
    struct Node *previousNode, *nextNode; 
} Node;

typedef struct {
    Node *head;
    Node *tail;
    int is_negative; 
} BigNumber;
#pragma endregion

#pragma region "Funções que inicializa/imprime/finaliza (liberar memória) um BigNumber a partir de uma String"
Node* create_node(int digitReceived) {
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node->digit = digitReceived;
    new_node->previousNode = NULL;
    new_node->nextNode = NULL;
    return new_node;
}

BigNumber* create_bignumber(const char *str) {
    BigNumber *num = (BigNumber*)malloc(sizeof(BigNumber));
    num->head = NULL;
    num->tail = NULL;
    num->is_negative = (str[0] == '-');
    
    int start = num->is_negative ? 1 : 0;
    for (int i = start; str[i] != '\0'; i++) {
        if (!isdigit(str[i])) 
            continue;

        Node *new_node = create_node(str[i] - '0');
        if (num->tail == NULL)
            num->head = num->tail = new_node;
        else {
            num->tail->nextNode = new_node;
            new_node->previousNode = num->tail;
            num->tail = new_node;
        }
    }
    return num;
}

void free_bignumber(BigNumber *num) {
    Node *current = num->head;
    while (current) {
        Node *temp = current;
        current = current->nextNode;
        free(temp);
    }
    free(num);
}

void print_bignumber(const BigNumber *num) {
    if (num->is_negative) 
        printf("-");
    
    Node *current = num->head;
    while (current) {
        printf("%d", current->digit);
        current = current->nextNode;
    }
    printf("\n");
}
#pragma endregion

#pragma region "Funções de calculo"
BigNumber* add_bignumbers(const BigNumber *firstNumber, const BigNumber *secondNumber) {
    BigNumber *result = (BigNumber*)malloc(sizeof(BigNumber));
    result->head = result->tail = NULL;
    result->is_negative = 0;

    Node *ptrFirstNumber = firstNumber->tail;
    Node *ptrSecondNumber = secondNumber->tail;
    int carry = 0;

    while (ptrFirstNumber || ptrSecondNumber || carry) {
        int digit1 = ptrFirstNumber ? ptrFirstNumber->digit : 0;
        int digit2 = ptrSecondNumber ? ptrSecondNumber->digit : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / 10;

        Node *newNode = create_node(sum % 10);
        if (result->head == NULL)
            result->head = result->tail = newNode;
        else {
            newNode->nextNode = result->head;
            result->head->previousNode = newNode;
            result->head = newNode;
        }

        if (ptrFirstNumber) ptrFirstNumber = ptrFirstNumber->previousNode;
        if (ptrSecondNumber) ptrSecondNumber = ptrSecondNumber->previousNode;
    }
    return result;
}

BigNumber* subtract_bignumbers(const BigNumber *firstNumber, const BigNumber *secondNumber) {
    BigNumber *result = (BigNumber*)malloc(sizeof(BigNumber));
    result->head = result->tail = NULL;
    result->is_negative = 0;

    Node *ptrFirstNumber = firstNumber->tail;
    Node *ptrSecondNumber = secondNumber->tail;
    int borrow = 0;

    while (ptrFirstNumber || ptrSecondNumber || borrow) {
        int digit1 = ptrFirstNumber ? ptrFirstNumber->digit : 0;
        int digit2 = ptrSecondNumber ? ptrSecondNumber->digit : 0;

        digit1 -= borrow;

        if (digit1 < digit2) {
            digit1 += 10;
            borrow = 1;
        } else
            borrow = 0;
        
        Node *newNode = create_node(digit1 - digit2);
        if (result->head == NULL) {
            result->head = result->tail = newNode;
        } else {
            newNode->nextNode = result->head;
            result->head->previousNode = newNode;
            result->head = newNode;
        }

        if (ptrFirstNumber) ptrFirstNumber = ptrFirstNumber->previousNode;
        if (ptrSecondNumber) ptrSecondNumber = ptrSecondNumber->previousNode;
    }

    if (result->head == NULL)
        result->head = result->tail = create_node(0);

    return result;
}
#pragma endregion

int main() {
    char *firstInput = NULL, *secondInput = NULL, operador;
    size_t lenFirstInput = 0, lenSecondInput = 0;

    printf("Primeiro numero: ");
    getline(&firstInput, &lenFirstInput, stdin);
    printf("\nSegundo numero: ");
    getline(&secondInput, &lenSecondInput, stdin);
    printf("\nOperação (+, -, *, /): ");
    scanf(" %c", &operador);

    // Remover o '\n' no final das strings lidas
    firstInput[strcspn(firstInput, "\n")] = '\0';
    secondInput[strcspn(secondInput, "\n")] = '\0';

    BigNumber *num1 = create_bignumber(firstInput);
    BigNumber *num2 = create_bignumber(secondInput);

    BigNumber *result = NULL;

    if (operador == '+')
        result = add_bignumbers(num1, num2);
    else if (operador == '-')
        result = subtract_bignumbers(num1, num2);
    
    print_bignumber(result);

    // Liberar memória
    free_bignumber(num1);
    free_bignumber(num2);
    free_bignumber(result);

    return 0;
}
