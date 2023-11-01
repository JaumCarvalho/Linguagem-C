#include <stdio.h>
#include <string.h>
#include <ctype.h>

void main() {
    // Definindo pseudo registradores
    int state = 0;  // Estado inicial
    int i;
    char current; // Variável para indicar o estado atual
    char name[50]; // Tamanho máximo de um nome de variável
    
    
    
    
    // Array de ponteiros para caracteres
    // Cada elemento do array é um ponteiro que aponta para uma sequência de caracteres (keyword)
    const char *keywords[] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed",
        "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned",
        "void", "volatile", "while"
    };



    // Pseudo microoperação: Entrada de dados
    printf("Digite um nome de variável em C: ");
    scanf("%s", name);
    
    

    // Pseudo microoperação: Comparação de strings com palavras-chave
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(name, keywords[i]) == 0) { // Verifica se name é uma palavra-chave/palavra reservada
            state = -2;
            break; // Saia do loop se uma palavra-chave for encontrada
        }
    }
    
    
    // Pseudo microoperação: Loop para análise de caracteres no nome da variável
    for (i = 0; name[i] != '\0'; i++) {
        
        current = name[i]; // Atribuição do caractere/estado atual à current
        
        
        
        // Pseudo microoperação: Controle de estado
        switch (state) {
            case 0:  // Estado inicial
                if (isalpha(current) || current == '_') { // Verifica se current é uma letra ou um underline
                    state = 1; // Vai para o estado intermediário
                } else {
                    state = -1;  // Estado de erro
                }
                break;

            case 1:  // Estado intermediário
                if (isalpha(current) || isdigit(current) || current == '_') { // Verifica se current é uma letra ou um dígito ou um underline
                    state = 1;
                } else {
                    state = -1;  // Estado de erro
                }
                break;

            default:  // Estado de erro
                break;
        }
        
        // Pseudo microoperação: Verificação de erro
        if (state == -1) {
            break;  // Sai do loop ao encontrar um erro
        }
    }
    
    
    
    // Pseudo microoperação: Saída de dados
    if (state == 1) {
        printf("O nome de variável '%s' é válido em C.\n", name);
    } else if (state == -2) {
        printf("O nome da variável '%s' não é válido em C, pois é uma palavra reservada.\n", name);
    } else {
        printf("O nome de variável '%s' não é válido em C.\n", name);
    }

}
