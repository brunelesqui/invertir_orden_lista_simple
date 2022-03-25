#include <stdio.h>
#include <stdlib.h>
 
typedef struct nodo {
  int info;
  struct nodo* sig;
};
 
struct nodo* crear_nodo(int );
struct nodo* crear_lista_simple ();
void imprimir_lista_simple(struct nodo* );
struct nodo* invertir_lista_simple(struct nodo* );
 
int main() {
    // https://www.lawebdelprogramador.com/foros/C-Visual-C/2125751-Programa-que-permita-invertir-el-orden-de-una-lista-enlazada-sencilla.html
    printf("Invertir lista simple");
 
    struct nodo* raiz = crear_lista_simple();
    imprimir_lista_simple(raiz);
 
    printf("\n");
 
    raiz = invertir_lista_simple(raiz);
    imprimir_lista_simple(raiz);
 
    return 0;
}
 
void imprimir_lista_simple(struct nodo* raiz_) {
    int i=0;
    while (raiz_ != NULL) {
      printf("\n%i.%i ", ++i, raiz_->info);
      raiz_ = raiz_->sig;
    }
}
 
struct nodo* crear_lista_simple () {
    struct nodo* raiz = crear_nodo(0);
    struct nodo* tmp = raiz;
    struct nodo* tmp_1;
    int i;
 
    for (i=1; i< 7; i++) {
        tmp_1 = crear_nodo(i);
        tmp->sig = tmp_1;
        tmp = tmp->sig;
    }
 
    return raiz;
}
 
struct nodo* crear_nodo(int index_) {
    struct nodo* tmp = malloc(sizeof(struct nodo));
    tmp->info = index_;
    tmp->sig = NULL;
 
    return tmp;
}
 
struct nodo* invertir_lista_simple(struct nodo* raiz_) {
    struct nodo* tmp = raiz_;
    struct nodo* tmp_1;
 
    while(raiz_ != NULL) {
        tmp_1 = raiz_;
        raiz_ = raiz_->sig;
 
        if(tmp != tmp_1)
          tmp_1->sig = tmp;
        else
          tmp_1->sig = NULL;
        tmp = tmp_1;
    }
 
    return tmp;
}
