/*
 * Atividade Avaliativa 2 - Laboratorio de Programacao
 * Engenharia da Computacao - UFMA
 * Prof. Rondineli Seba Salomao
 *
 * Aluno(s): Angélica da Silva Alves
 * Matricula: 20250067604
 * Curso: BICT
 *
 * Descricao: CRUD basico em C 
 */

#include <stdio.h>
#include <string.h>

#define MAX_REGISTROS 50
#define MAX_LETRAS    50

/* Banco de dados: matriz estatica de caracteres */
char banco_dados[MAX_REGISTROS][MAX_LETRAS];


//Limpa o buffer de entrada

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


 //Le uma linha inteira do teclado (aceita espacos)
 // Remove o '\n' do final

void ler_entrada(char destino[], int tamanho) {
    int len;
    fgets(destino, tamanho, stdin);
    len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n') {
        destino[len - 1] = '\0';
    }
}

// Inicializa todas as linhas da matriz como vazias

void inicializar_banco() {
    int i;
    for (i = 0; i < MAX_REGISTROS; i++) {
        banco_dados[i][0] = '\0';
    }
}


//* Busca linear pelo nome na matriz.
 //* Retorna o indice se encontrado, ou -1 se nao encontrado.
 
int buscar_nome(char nome[]) {
    int i;
    for (i = 0; i < MAX_REGISTROS; i++) {
        if (banco_dados[i][0] != '\0' && strcmp(banco_dados[i], nome) == 0) {
            return i;
        }
    }
    return -1;
}


//  Retorna o indice da primeira linha vazia da matriz.
 // Retorna -1 se a matriz estiver cheia.

int primeira_linha_vaga() {
    int i;
    for (i = 0; i < MAX_REGISTROS; i++) {
        if (banco_dados[i][0] == '\0') {
            return i;
        }
    }
    return -1;
}


 // INCLUIR: adiciona um novo nome unico na matriz
 
void incluir() {
    char nome[MAX_LETRAS];
    int vaga;

    printf("\n INCLUIR \n");
    printf("Digite o nome completo do aluno a ser matriculado: ");
    ler_entrada(nome, MAX_LETRAS);

    if (buscar_nome(nome) != -1) {
        printf("Erro: o nome '%s' este aluno ja existe. Por favor, adcione um novo aluno.\n", nome);
        return;
    }

    vaga = primeira_linha_vaga();
    if (vaga == -1) {
        printf("Erro: o banco de dados esta cheio (limite de %d registros).\n", MAX_REGISTROS);
        return;
    }

    strcpy(banco_dados[vaga], nome);
    printf("Aluno '%s' incluido com sucesso na posicao %d.\n", nome, vaga);
}


 // BUSCAR: pesquisa um nome e exibe seu indice
 
void buscar() {
    char nome[MAX_LETRAS];
    int indice;

    printf("\n BUSCAR \n");
    printf("Digite o nome do estudante para pesquisa: ");
    ler_entrada(nome, MAX_LETRAS);

    indice = buscar_nome(nome);

    if (indice != -1) {
        printf("Aluno '%s' esta na posicao (linha) %d.\n", nome, indice);
    } else {
        printf("Aluno nao encontrado.\n");
    }
}


 // MODIFICAR: altera um nome existente por um novo nome
 
void modificar() {
    char nome_atual[MAX_LETRAS];
    char novo_nome[MAX_LETRAS];
    int indice;

    printf("\n MODIFICAR \n");
    printf("Digite o nome do aluno que deseja alterar: ");
    ler_entrada(nome_atual, MAX_LETRAS);

    indice = buscar_nome(nome_atual);

    if (indice == -1) {
        printf("Aluno '%s' nao encontrado no sistema.\n", nome_atual);
        return;
    }

    printf("Digite o novo nome do aluno: ");
    ler_entrada(novo_nome, MAX_LETRAS);

    if (buscar_nome(novo_nome) != -1) {
        printf("Atencao: este aluno '%s' ja existe no sistema. Escolha um novo nome.\n", novo_nome);
        return;
    }

    strcpy(banco_dados[indice], novo_nome);
    printf("Nome do aluno alterado com sucesso para '%s' na posicao %d.\n", novo_nome, indice);
}


 // APAGAR: remove um nome da matriz (marca como vazio)
 
void apagar() {
    char nome[MAX_LETRAS];
    int indice;

    printf("\n APAGAR \n");
    printf("Digite o nome do aluno que deseja remover: ");
    ler_entrada(nome, MAX_LETRAS);

    indice = buscar_nome(nome);

    if (indice == -1) {
        printf("estudante '%s' nao encontrado no sistema.\n", nome);
        return;
    }

    banco_dados[indice][0] = '\0';
    printf("estudante '%s' removido com sucesso da posicao %d.\n", nome, indice);
}


// LISTAR TODOS: exibe todos os nomes salvos e seus indices

void listar_todos() {
    int i;
    int encontrou = 0;

    printf("\n LISTAR TODOS \n");
    printf("%-10s | %s\n", "Posicao", "Nome");
    printf("|\n");

    for (i = 0; i < MAX_REGISTROS; i++) {
        if (banco_dados[i][0] != '\0') {
            printf("%-10d | %s\n", i, banco_dados[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum nome cadastrado no momento.\n");
    }
}


 //Menu principal
 
void exibir_menu() {
    printf("\n-----------------------------\n");
    printf("      SISTEMA ESCOLAR \n");
    printf("-----------------------------\n");
    printf("1. Inclua o nome do aluno a ser matriculado\n");
    printf("2. Buscar nome do aluno\n");
    printf("3. Altere o nome do aluno na matricula\n");
    printf("4. Apague aluno matriculado do sistema\n");
    printf("5. Listar todos os alunos matriculados\n");
    printf("0. Sair\n");
    printf("-----------------------------\n");
    printf("Escolha uma opcao: ");
}


// Funcao principal

int main() {
    int opcao;

    inicializar_banco();

    do {
        exibir_menu();
        scanf("%d", &opcao);
        limpar_buffer(); // limpa o '\n' que sobra apos digitar a opcao 

        switch (opcao) {
            case 1: incluir();      break;
            case 2: buscar();       break;
            case 3: modificar();    break;
            case 4: apagar();       break;
            case 5: listar_todos(); break;
            case 0: printf("\nEncerrando o programa. Ate logo!\n"); break;
            default: printf("\nOpcao invalida. Tente novamente.\n"); break;
        }

    } while (opcao != 0);

    return 0;
}
