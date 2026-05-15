#ifndef __GCOFO_H_
#define __GCOFO_H_
#define TRUE 1
#define FALSE 0


#ifdef __GCOFO_C_

typedef struct _gcoFo_{
    int numItens;
    int numMAXItens;
    int cur;
    void **item;
}gCofo;

gCofo *gcofCriar( int numMAXItens);
int gcofInserir(gCofo *c, void *item);
void *gcofRemover(gCofo *c, void *key, int(*cmp)(void *, void *));
void *gcofProcurar(gCofo *c, void *key, int(*cmp)(void *, void *));
void *gcofGetFirst( gCofo *c);
void *gcofGetNext( gCofo *c);
int gcofQuantidade( gCofo *c);
int gcofEsvaziar( gCofo *c );
int gcofDestruir( gCofo *c);

#else
typedef struct _gcoFo_ gCofo;

extern gCofo *gcofCriar( int numMAXItens );
extern int gcofInserir( gCofo *c, void *item );
extern void *gcofRemover( gCofo *c, void *key, int (*cmp)(void *, void *));
extern void *gcofProcurar( gCofo *c, void *key, int (*cmp)(void *, void *));
extern void *gcofGetFirst( gCofo *c );
extern void *gcofGetNext( gCofo *c );
extern int gcofQuantidade( gCofo *c);
extern int gcofEsvaziar( gCofo *c );
extern int gcofDestruir( gCofo *c );


#endif


#endif
