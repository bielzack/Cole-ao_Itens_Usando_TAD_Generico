#include "gcofo.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _magia_ {
    char nome[30];
    int nivel;
    float custo_mana;

} Magia;

int cmpNome (void *key, void *item){
    char *nome =(char *)key;
    Magia *m = (Magia *)item;

    if(_stricmp(m->nome, nome) == 0){
        return TRUE;
    }
    return FALSE;

}

int cmpNivel(void * key, void * item){
    int *nivel = (int *)key;
    Magia *m = (Magia *)item;

    if(m ->nivel == *nivel){
        return TRUE;
    }
    return FALSE;
}

int cmpMana(void *key, void *item){
    Magia *m = (Magia *)item;
    float *mana = (float *)key;

    if(m->custo_mana == *mana){
        return TRUE;

    }
    return FALSE;
}
void limparBuffer(){

    while(getchar() != '\n');
}

int main(){
    gCofo *cofo = NULL;
    int opcao;
   
    do{
        printf("\n\n===== GRIMORIO DE MAGIAS DA FREIREN ======\n\n");
        printf("1 -Criar um grimorio\n");
        printf("2 - Inserir Nova Magia\n");
        printf("3 - Listar magias\n");
        printf("4 - Consultar magia\n");
        printf("5 - Remover magia\n");
        printf("6 - Esvaziar Grimorio\n");
        printf("7 - Destruir Grimorio\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        limparBuffer();


        if(opcao == 1){
            
            int quant;
            printf("Quantas magias voce quer colocar no Grimorio: \n");
            scanf("%d",&quant);
            limparBuffer();

            cofo = gcofCriar(quant);
            if(cofo == NULL){
                printf("Nao foi possivel criar o Grimorio!");
                
            }
            printf("Grimorio criado com sucesso!\n");
        }
        /*Inserir magia*/
        else if(opcao == 2){
            if(cofo == NULL){
                printf("Crie o grimorio primeiro!\n");
            } else {
                Magia *m;
                m = (Magia *) malloc(sizeof(Magia));
                if(m != NULL){

                    printf("Digite o nome da magia: \n");
                    
                    fgets(m->nome, sizeof(m->nome), stdin);
                    m->nome[strcspn(m->nome, "\n")] = 0;

                    printf("Digite o nivel da magia: ");
                    scanf("%d", &m->nivel);
                    limparBuffer();

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

        }
        /*listar magia*/
        else if(opcao == 3){
            if(cofo == NULL){
            
                printf("Crie o grimorio primeiro!\n");
            }else {
                if(gcofQuantidade(cofo) == FALSE){
                    printf("O grimorio nao possui magias no momento...\n");
                    printf("Adicione novas magias primeiro!\n\n");

                } else {
                    Magia *m;
                    int i = 1;
                    m = (Magia *) gcofGetFirst(cofo);
                    while(m != NULL){
                        printf("Magia %d Nome: %s\n",i, m -> nome);
                        printf("Nivel de magia: %d\n", m ->nivel);
                        printf("Custo de mana: %.2f\n", m->custo_mana);
                        m = (Magia *) gcofGetNext(cofo);
                        i++;
                    }
                    
                }
            }   
                
        }
        /*opcao de procurar pelo tres campos*/
        else if(opcao == 4){
            if(cofo == NULL){
                printf("Crie o grimorio primeiro!\n");
            } else {
                Magia *m;
                int consu;
                
                
                printf("Consultar pelo Nome == 1\n");
                printf("Consultar pelo nivel == 2\n"); 
                printf("Consultar pelo custo de mana == 3\n");
                printf("Informe o campo para a consulta: \n");
                scanf("%d", &consu);
                limparBuffer();
                /*condicional do campo escolhido*/
                
                if(consu == 1){
                    char nome[30];

                    printf("Qual  o nome da magia: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0;

                    m = (Magia *) gcofProcurar(cofo, (void *)nome, cmpNome );
                    if( m != NULL){
                        printf("Nome da magia:%s\n\n", m->nome);
                        printf("Nivel:%d\n\n", m->nivel);
                        printf("Custo de mana\n\n:%.2f",m->custo_mana);
                    }else{
                        printf("magia nao encontrada!\n\n");
                    }
                    
                }
                
                if(consu == 2){
                    int nivel;
                    printf("Digite o nivel da magia:\n");
                    scanf("%d", &nivel);
                    m = (Magia *) gcofProcurar(cofo,(void *)&nivel, cmpNivel);
                        if( m != NULL){
                            printf("Nome da magia:%s\n\n", m->nome);
                            printf("Nivel:%d\n\n", m->nivel);
                            printf("Custo de mana:%2.f\n\n",m->custo_mana);

                        } else {
                            printf("Magia nao  foi encontrado\n\n");
                        }
                    
                    
                }

                if(consu == 3){
                    float mana;
                    printf("Digite o custo de mana: ");
                    scanf("%f", &mana);
        
                    m = (Magia *) gcofProcurar(cofo, (void *)&mana, cmpMana);
                    if(m != NULL){
                            printf("Nome da magia: %s\n\n", m->nome);
                            printf("Nivel: %d\n", m->nivel);
                            printf("Custo de mana: %f\n", m->custo_mana);
                            
                    } else{
                        printf("Magia nao encontrada!");
                    }
            
                }
            }    
                
                
        }
        /*Remove magia*/
        else if( opcao == 5){
            if(cofo == NULL){
                printf("Crie o grimorio primeiro!\n");
            } else {
                Magia *m;
                int delet;

                printf("Remover pelo nome == 1\n\n");
                printf("Remover pelo nivel == 2\n\n"); 
                printf("Remover pelo custo de mana == 3\n\n");
                printf("Informe o campo para a remocao: \n\n");
                scanf("%d", &delet);
                limparBuffer();
            

                if(delet == 1){
                    char nome[30];
                    printf("Qual  o nome da magia: ");
                    fgets(nome, sizeof(nome), stdin);
                    nome[strcspn(nome, "\n")] = 0;

                    m = (Magia *) gcofRemover(cofo, (void *)nome, cmpNome );
                    if( m != NULL){
                        printf("Magia removida com sucesso!\n\n");
                        free(m);
                    }else{
                        printf("magia nao encontrada!\n\n");
                    }
                    
                }
                if(delet == 2){
                    int nivel;
                    printf("Digite o nivel da magia:");
                    scanf("%d", &nivel);
                    m = (Magia *) gcofRemover(cofo,(void *)&nivel, cmpNivel);
                        if( m != NULL){
                            printf("Magia removida com sucesso!\n\n");
                            free(m);
                        } else {
                            printf("Magia não  foi encontrado\n\n");
                        }
                    
                    
                }
                if(delet == 3){
                    float mana;
                    printf("Digite o custo de mana: ");
                    scanf("%f", &mana);
        
                    m = (Magia *) gcofRemover(cofo, (void *)&mana, cmpMana);
                    if(m != NULL){
                        printf("Magia removida com sucesso!\n");
                        free(m);
                    } else{
                        printf("NAo encontrado!\n\n");
                    }
            
                }
            }    
            
                
        }
        /*Esvaziar grimório*/
        else if( opcao == 6){
            if(cofo == NULL){
                printf("Crie o grimorio primeiro!\n");
            } else {

                int vazio = gcofEsvaziar(cofo);
                if(vazio ==  TRUE){
                    printf("As magias do griomorio foram apagadas com sucesso!\n");
                } else {
                    printf("Falha em excluir o grimorio!\n\n");
                }
            }    
        }

        else if(opcao == 7){
            if(cofo == NULL){
                printf("Crie o grimorio primeiro!\n");
            } else {
                int destroy;

                destroy = gcofDestruir(cofo);
                if( destroy == TRUE ){
                    cofo = NULL;
                    printf("O grimorio foi destruido com sucesso\n");
                } else{
                    printf("O grimorio ainda possui magias! Use primeiro a opcao de esvaziar.\n");
                }
            }    
        }
            
        else if( opcao == 0){
            printf("FECHANDO GRIMORIO!\n");
            printf("Ate logo\n");

        } else {
            printf("Opcao invalida!");
        }
        

    } while (opcao != 0);
      if(cofo != NULL){
        gcofEsvaziar(cofo);
        gcofDestruir(cofo);
        printf("Grimorio destruido ao fechar o proframa");
        
    }  
    

    

    
}