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
        printf("2 - Listar magias\n");
        printf("3 - Consultar magia\n");
        printf("4 - Remover magia\n");
        printf("5 - Esvaziar Grimorio\n");
        printf("6 - Destruir Grimorio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);

        if(opcao == 1){
            Magia *m;
            m = (Magia *) malloc(sizeof(Magia));
            if(m != NULL){
                printf("Digite o nome da magia: \n");
                scanf("%s", m->nome);
                printf("Digite o nivel da magia: ");
                scanf("%d", &m->nivel);
                printf("Digite o custo de mana da magia: ");
                scanf("%f", &m->custo_mana);

                if(gcofInserir(cofo, (void *) m) == TRUE){
                    printf("Magia inserida com sucesso!\n");
                } else{
                    printf("Erro ao inserir a magia!\n");
                    free(m);
                }
            }
        }

        else if(opcao == 2){
            Magia *m;
            int i = 1;
            m = (Magia *) gcofGetFirst(cofo);
            while(m != NULL){
                printf("Magia %d Nome: %s",i, m -> nome);
                printf("Nivel de magia: %d", m ->nivel);
                printf("Custo de mana: %f", m->custo_mana);
                m = (Magia *) gcofGetNext(cofo);
                i++;
            }
                
        }
        
        else if(opcao == 3){
            Magia *m;
            int consu;
            
            
            printf("Consultar pelo Nome == 1");
            printf("Consultar pelo nivel == 2"); 
            printf("Consultar pelo custo de mana == 3");
            printf("Informe o campo para a consulta: ");
            scanf("%d", &consu);
            
            if(consu == 1){
                char nome[30];
                printf("Qual  o nome da magia: ");
                fgets(nome, sizeof(nome), stdin);
                m = (Magia *) gcofProcurar(cofo, (void *)nome, cmpNome );
                if( m != NULL){
                    printf("Nome da magia:%s", m->nome);
                    printf("Nivel:%d", m->nivel);
                    printf("Custo de mana:%f",m->custo_mana);
                }else{
                    printf("magia nao encontrada!");
                }
                
            }
            
            if(consu == 2){
                int nivel;
                printf("Digite o nivel da magia:");
                scanf("%d", &nivel);
                m = (Magia *) gcofProcurar(cofo,(void *)&nivel, cmpNivel);
                    if( m != NULL){
                        printf("Nome da magia:%s", m->nome);
                        printf("Nivel:%d", m->nivel);
                        printf("Custo de mana:%f",m->custo_mana);

                    } else {
                        printf("Nao foi encontrado");
                    }
                
                
            }

            if(consu == 3){
                float mana;
                printf("Digite o custo de mana: ");
                scanf("%f", &mana);
    
                m = (Magia *) gcofProcurar(cofo, (void *)&mana, cmpMana);
                if(m != NULL){
                        printf("Nome da magia: %s\n", m->nome);
                        printf("Nivel: %d\n", m->nivel);
                        printf("Custo de mana: %f\n", m->custo_mana);
                        
                } else{
                    printf("NAo encontrado!");
                }
                    
               
                
               
        
            }
            
                
            
            


            
            
            
        }

    }
    while (opcao != 0){

    }
}