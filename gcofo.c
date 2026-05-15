#define __GCOFO_C_
#include "gcofo.h"
#include <stdlib.h>

gCofo *gcofCriar( int numMAXItens){
    gCofo *gc;
    if(numMAXItens > 0){
        gc = (gCofo *) malloc(sizeof(gCofo) * 1);
        if(gc != NULL){
            gc->item  = (void **) malloc(sizeof(void*) * numMAXItens);
            if(gc->item != NULL){
                gc->numItens = 0;
                gc->numMAXItens = numMAXItens;
                gc->cur = -1;
                return gc;

            }
            free(gc);
        }
    }
    return NULL;

}

int gcofInserir(gCofo *gc, void *item){
    if(gc != NULL){
        if(gc ->numItens < gc->numMAXItens){
            gc->item[gc->numItens] = item;
            gc->numItens++;
            return TRUE;

        }



    }
    return FALSE;
}

void *gcofGetFirst( gCofo *gc){
    if(gc != NULL){
       if(gc->numItens > 0){
        gc->cur = 0;
        return gc->item[gc->cur];
       }

    }
    return NULL;
}
void *gcofGetNext( gCofo *gc){
    if(gc != NULL){
        if(gc->cur < gc->numItens -1){
            gc->cur++;
            return gc->item[gc->cur];
        }
    }
    return NULL;
}
void *gcofProcurar(gCofo *gc, void *key, int(*cmp)(void *, void *)){
    void * data;
    int i;
    int stat;
    if(gc != NULL && gc -> numItens>0 ){
        i = 0; stat = cmp(key, gc -> item[i]);
        while(i < gc -> numItens - 1 && stat != TRUE){
            i++;
            stat = cmp(key, gc->item[i]);
        }
        if(stat == TRUE) {
            data = gc ->item[i];
            return data;
        }
        

    }
    return NULL;
}

void *gcofRemover(gCofo *gc, void *key, int(*cmp)(void *, void *)){
     void * data;
    int i;
    int stat;
    if(gc != NULL && gc -> numItens > 0){
        i = 0; stat = cmp(key, gc -> item[i]);
        while(i < gc -> numItens - 1 && stat != TRUE){
            i++;
            stat = cmp(key, gc->item[i]);
        }
        if(stat ==TRUE){
            data = gc ->item[i];
            for(int j = i; j < gc->numItens; j++){
                gc->item[j] = gc->item[j+1];
            }
            gc -> numItens--;
            return data;
        }

    }
    return NULL;
}
int gcofEsvaziar( gCofo *gc ){
    int i;
    if(gc != NULL) {
        for(i = 0;i < gc ->numItens; i++){
            free(gc->item[i]);
            
        }
        gc->numItens = 0;
        return TRUE;
        
        
    }
    return FALSE;
}



int gcofDestruir( gCofo *gc){
    if(gc != NULL){
        if(gc->numItens == 0){
            free(gc->item);
            free(gc);
            return TRUE;
        }
    }
    return FALSE;
}
int gcofQuantidade( gCofo *gc){
    if( gc != NULL){
        return gc->numItens;
    }

    return -1;

}




