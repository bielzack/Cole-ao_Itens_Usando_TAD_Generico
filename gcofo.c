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



