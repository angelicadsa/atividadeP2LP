# Sistema Escolar - CRUD em C

##  Descrição

Este projeto foi desenvolvido como parte da **Atividade Avaliativa 2 da disciplina Laboratório de Programação**, do curso de Engenharia da Computação da Universidade Federal do Maranhão (UFMA).

O programa implementa um **CRUD (Create, Read, Update e Delete)** utilizando a linguagem C e uma matriz estática de caracteres para armazenar os dados dos alunos matriculados.

---

##  Informações do Aluno

* **Aluno:** Angélica da Silva Alves
* **Matrícula:** 20250067604
* **Curso:** BICT
* **Disciplina:** Laboratório de Programação
* **Professor:** Rondineli Seba Salomão
* **Instituição:** Universidade Federal do Maranhão (UFMA)

---

##  Funcionalidades

O sistema permite:

###  Create (Incluir)

Cadastrar um novo aluno no sistema.

###  Read (Buscar)

Pesquisar um aluno pelo nome e informar sua posição no banco de dados.

###  Update (Modificar)

Alterar o nome de um aluno já cadastrado.

###  Delete (Apagar)

Remover um aluno do sistema.

###  Listar Todos

Exibir todos os alunos cadastrados e suas respectivas posições.

---

##  Estrutura do Banco de Dados

Os registros são armazenados em uma matriz estática:

```c
#define MAX_REGISTROS 50
#define MAX_LETRAS 50

char banco_dados[MAX_REGISTROS][MAX_LETRAS];
```

* Capacidade máxima: **50 registros**.
* Cada nome pode possuir até **49 caracteres** (mais o caractere '\0').

---

##  Funções Implementadas

| Função                  | Descrição                              |
| ----------------------- | -------------------------------------- |
| `inicializar_banco()`   | Inicializa a matriz de registros.      |
| `buscar_nome()`         | Realiza busca linear por um nome.      |
| `primeira_linha_vaga()` | Retorna a primeira posição disponível. |
| `incluir()`             | Insere um novo aluno.                  |
| `buscar()`              | Procura um aluno pelo nome.            |
| `modificar()`           | Altera o nome de um aluno existente.   |
| `apagar()`              | Remove um aluno do sistema.            |
| `listar_todos()`        | Lista todos os alunos cadastrados.     |
| `exibir_menu()`         | Exibe o menu principal.                |

---

##  Menu do Programa

```text
-----------------------------
      SISTEMA ESCOLAR
-----------------------------
1. Inclua o nome do aluno a ser matriculado
2. Buscar nome do aluno
3. Altere o nome do aluno na matricula
4. Apague aluno matriculado do sistema
5. Listar todos os alunos matriculados
0. Sair
-----------------------------
```

---

##  Compilação

Para compilar o programa utilizando o GCC:

```bash
gcc sistema_escolar.c -o sistema_escolar.exe
```

##  Execução

No Windows:

```bash
sistema_escolar.exe
```


---

##  Conceitos Utilizados

* Linguagem C
* Matrizes bidimensionais
* Manipulação de strings (`string.h`)
* Estruturas de repetição
* Estruturas condicionais
* Funções
* Busca linear
* Implementação de CRUD (Create, Read, Update e Delete)

---

##  Observações

* O sistema impede a inserção de nomes duplicados.
* Os registros removidos são marcados como vazios e podem ser reutilizados posteriormente.
* O armazenamento é feito em memória, ou seja, os dados são perdidos quando o programa é encerrado.

---


