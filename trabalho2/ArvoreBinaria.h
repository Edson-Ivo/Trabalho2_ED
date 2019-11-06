#ifndef ARVOREBIN_H
#define ARVOREBIN_H
#include <iostream>

struct NoArv; // Tipo no da arvore

NoArv* arv_criavazia(); // cria arvore vazia

NoArv* arv_cria(int chave, NoArv* esq, NoArv* dir);

int* arv_cria_base_array1(int v[],int tam);// Cria uma arvore e coloca em um arq.txt

bool arv_vazia(NoArv* no); // arvore enraizada em no esta vazia?

void arv_imprime(NoArv* no); // imprime as chaves da arvore

void imp(NoArv* no);

NoArv* arv_libera(NoArv* no); // libera todos os nos alocados

bool arv_pertence(NoArv* no, int chave); // chave pertence?

NoArv* arv_procurar_no(NoArv* no, int chave); // procura no com determinada chave

void pre_ordem(NoArv* no); // percurso em pre-ordem

void pos_ordem(NoArv* no); // percurso em pos-ordem

void in_ordem(NoArv* no); // percurso em ordem simetrica

int arv_numNos(NoArv* no); // numero de nos da arvore

int arv_altura(NoArv* no); // altura da arvore

void preordem_iterativo(NoArv* raiz); // preordem iterativo

void inordem_iterativo(NoArv* raiz); // inordem iterativo

void percurso_em_largura(NoArv* no); // percurso em largura

#endif
