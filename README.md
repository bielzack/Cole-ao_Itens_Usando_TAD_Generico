# Trabalho de Implementação 01 - TAD Genérico  
## Grimório de Magias da Frieren

# Sobre o Projeto
Este projeto foi desenvolvido em linguagem C com o objetivo de criar um **TAD Genérico** chamado `gCofo`.

A estrutura funciona como uma coleção capaz de armazenar qualquer tipo de dado utilizando ponteiros genéricos (`void *`).

Para mostrar o funcionamento do TAD na prática, foi criada uma aplicação inspirada no universo da Frieren, onde o usuário pode gerenciar um **Grimório de Magias** pelo terminal.

No programa é possível cadastrar, listar, buscar e remover magias através de um menu interativo.

---

# Estrutura da Magia
Cada magia possui as seguintes informações:

- `char nome[30]` → Nome da magia  
- `int nivel` → Nível da magia  
- `float custo_mana` → Quantidade de mana necessária  

---

# Ambiente de Desenvolvimento
- **Sistema Operacional:** Windows 11 / Linux Ubuntu  
- **Compilador:** GCC / MinGW  
- **Bibliotecas externas:** Nenhuma  

---

# Arquivos do Projeto
- `gcofo.h` → Definições do TAD  
- `gcofo.c` → Implementação das funções do TAD  
- `main.c` → Programa principal e menu do grimório  

---

# Compilação e Execução

## Linux / MacOS
```bash
gcc -g main.c gcofo.c -o app
./app
