# Trabalho de Implementação 01 - TAD Genérico  
## Grimório de Magias da Frieren

# Sobre o Projeto
Este projeto tem como objetivo desenvolver um TAD Genérico chamado gCofo.

A estrutura foi criada para funcionar como uma coleção flexível, permitindo armazenar e organizar diferentes tipos de informações de forma dinâmica e reutilizável.

Para demonstrar seu funcionamento na prática, foi desenvolvida uma aplicação inspirada no universo de Frieren, onde o usuário pode gerenciar um Grimório de Magias através de um menu interativo, realizando operações como cadastro, busca, listagem e remoção de magias.

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
```
# Windows
```bash
gcc -g main.c gcofo.c -o app
.\app.exe
```

---

# Funcionalidades do Programa

## 1 - Criar Grimório
Cria a coleção que irá armazenar as magias utilizando a função `gcofCriar`.

## 2 - Inserir Nova Magia
Adiciona uma nova magia no grimório usando `gcofInserir`.

## 3 - Listar Magias
Mostra todas as magias cadastradas utilizando os iteradores


## 4 - Consultar Magia
Busca uma magia no grimório através da função `gcofProcurar`.

A busca pode ser feita por:

- Nome
- Nível
- Custo de mana

## 5 - Remover Magia
Remove uma magia da coleção usando `gcofRemover`.

## 6 - Esvaziar Grimório
Remove todas as magias cadastradas utilizando `gcofEsvaziar`.

## 7 - Destruir Grimório
Libera toda a memória do TAD através da função `gcofDestruir`.

## 0 - Sair
Encerra o programa realizando a liberação correta da memória.

# Informações Acadêmicas

- **Disciplina:** Estrutura de Dados I 
- **Discente:** Gabriel Serra Bastos
