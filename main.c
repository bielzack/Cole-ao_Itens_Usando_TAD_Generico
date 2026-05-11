#include "gcofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _magia_ {
    char nome[30];
    int nivel;
    float custo_mana;

} Magia;

int cmpNome (void *a, void *b){
    Magia *m = (Magia *)a;
    char *nome =(char *)b;

    if(strcmp(m->nome, nome) == 0){
        return TRUE;
    }
    return FALSE;

}

int cmpNivel(void * a, void * b){
    Magia *m = (Magia *)a;
    int *nivel = (int *)b;

    if(m ->nivel == *nivel){
        return TRUE;
    }
    return FALSE;
}

int cmpMana(void *a, void *b){
    Magia *m = (Magia *)a;
    float *mana = (float *)b;

    if(m->custo_mana == *mana){
        return TRUE;

    }
    return FALSE;
}
int main(){
    gCofo *cofo;
    int opcao;

    cofo = gcofCriar(7);
    if(cofo == NULL){
        printf("====ERRO AO CRIAR O GRIMORIO!\n");
        return 1;
    }
    do {
        printf("===== GRIMORIO DE MAGIAS DA FREIREN ======\n");
        printf("1 - Inserir Nova Magia\n");
        printf("2 - Remover magia\n");
        printf("3 - Consultar magia\n");
        printf("4 - Listar magias\n");
        printf("5 - Esvaziar Grimorio\n");
        printf("6 - Destruir Grimorio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao = 1){
            Magia *m;
            m = (Magia *) malloc(sizeof(Magia));
        }

    }
    while (opcao != 0){

    }
}