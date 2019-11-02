/**
 * Implementacao de uma arvore binaria
 */
#include <iostream>
#include <stack>
#include <queue>
#include "ArvoreBinaria.h"
using namespace std;

struct NoArv { // sem ponteiro para no pai
    int chave;
    NoArv *esq; // subarvore esquerda
    NoArv *dir; // subarvore direita
};

NoArv* arv_criavazia() {
    return NULL;
}

NoArv* arv_cria(int chave, NoArv* esq, NoArv* dir) {
    NoArv* novo = new NoArv;
    novo->chave = chave;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

NoArv* arv_cria_base_array(int *v, int tam) {

    int n_folhas = 2;
    int altura=1;

    while (n_folhas<=tam){
        n_folhas*=2;    
        altura++;
    }

   // cout<<"altura = "<<altura<<" / nrm folha = "<<n_folhas<<endl;
    NoArv *arvore[altura+1][n_folhas];
    int campos=n_folhas;
    int maior=v[0];
    for(int i=0;i<tam;i++){
        if(v[i]>maior){
            maior=v[i];
        }
    }
    maior++;

    for(int i=0;i<tam;i++)
        arvore[altura][i]=arv_cria(v[i],NULL,NULL);
    for(int i=tam;i<n_folhas;i++)
        arvore[altura][i]=arv_cria(maior,NULL,NULL);




  //  cout<<"primero no base  = "<<arvore[altura][0]->chave<<" / utimo no base = "<<arvore[altura][n_folhas-1]->chave<<" / PENutimo no base = "<<arvore[altura][n_folhas-2]->chave<<endl;

    for(int i=altura;i>=0;i--) // altura=3, cont=1, campos=8, n_folhas=8, j=2, i = 0;    
    {            
                       //         arvore[3]{1 6 3 4 5 7 3 8}
        int cont=0;             //          arvore[2]{1 3 5 3}
        //cout<<"valor de cont  = "<<cont<<" / valor de i = "<<i<<" / valor de altura = "<<altura<<" / valor de campos = "<<campos<<endl;
        //campos/=2;                //      arvore[1]{1 5}
        for(int j=0;j<campos;j+=2){ //      arvore[0]{1}
            if(arvore[i][j]->chave<=arvore[i][j+1]->chave)
                arvore[i-1][cont]=arv_cria(arvore[i][j]->chave,arvore[i][j],arvore[i][j+1]);
            else
                arvore[i-1][cont]=arv_cria(arvore[i][j+1]->chave,arvore[i][j],arvore[i][j+1]);
            cont++;
           // cout<<"valor de cont  = "<<cont<<" / valor de i = "<<i<<" / valor de altura = "<<altura<<" / valor de campos = "<<campos
         //   <<" / valor de arvore[i][j] = "<<arvore[i][j]->chave<<" / valor de arvore[i][j+1] = "<<arvore[i][j+1]->chave
        //    <<" / valor de arvore[i-1][cont] = "<<arvore[i-1][cont]->chave<<endl;
        }
        campos/=2;   
    }

    //COUT arvore[0][0] COLOCAR SAIDA TXT;

    int saida[tam];
    saida[0]=arvore[0][0]->chave;

    

    for(int t=1;t<tam;t++){
        int menor=arvore[0][0]->chave;

        campos=n_folhas;
        for(int y=0;y<tam;y++){
            if(arvore[altura][y]->chave==menor){
                arvore[altura][y]->chave=maior;
                break;
                }
        }

        for(int i=altura;i>=0;i--) // altura=3, cont=1, campos=8, n_folhas=8, j=2, i = 0;    
        {                            //         arvore[3]{2 6 3 4 5 7 3 8}

            int cont=0;             //          arvore[2]{2 3 5 3}
            //campos/=2;                //      arvore[1]{1 5}
            for(int j=0;j<campos;j+=2){ //      arvore[0]{1}
                if(arvore[i][j]->chave<=arvore[i][j+1]->chave)
                    arvore[i-1][cont]->chave=arvore[i][j]->chave;
                else
                    arvore[i-1][cont]->chave=arvore[i][j+1]->chave;
                cont++;
            }
            campos/=2;   
        }
        saida[t]=arvore[0][0]->chave;

    }

    for(int g=0;g<tam;g++){
        cout<<"RESULT ["<<g<<"] = "<<saida[g]<<endl;
    }
}

bool arv_vazia(NoArv* no) {
    return (no == NULL);
}

void imp(NoArv* no){
    cout<<no->chave;
}

void arv_imprime(NoArv* no) {
    if ( ! arv_vazia(no) ) {
        cout << no->chave << endl;
        arv_imprime(no->esq);
        arv_imprime(no->dir);
    }
}

bool arv_pertence(NoArv* no, int chave) {
    if (no == NULL) 
        return false; // Sub-arvore vazia 
    else 
        return no->chave == chave || 
               arv_pertence(no->esq, chave) || 
               arv_pertence(no->dir, chave);
}

NoArv* arv_libera(NoArv* no) {
    if (no != NULL) {
        no->esq = arv_libera(no->esq);
        no->dir = arv_libera(no->dir);
        cout << "Liberando " << no->chave << endl;
        delete no;
    }
    return NULL;
}

NoArv* arv_procurar_no(NoArv* no, int chave) {
    if (no == NULL || no->chave == chave) 
        return no;
    NoArv* esq = arv_procurar_no(no->esq, chave);
    if (esq != NULL)
        return esq;
    else
        return arv_procurar_no(no->dir, chave);
}

void pre_ordem(NoArv* no) {
    if (no != NULL) {
        cout << no->chave << endl;
        pre_ordem(no->esq);
        pre_ordem(no->dir);
    }
}

void pos_ordem(NoArv* no) {
    if (no != NULL) {
        pos_ordem(no->esq);
        pos_ordem(no->dir);
        cout << no->chave << endl;
    }
}

void in_ordem(NoArv* no) {
    if (no != NULL) {
        in_ordem(no->esq);
        cout << no->chave << endl;
        in_ordem(no->dir);
    }
}

int arv_numNos(NoArv* no) {
	if(no == NULL) return 0;
	return 1 + arv_numNos(no->esq) + arv_numNos(no->dir);
}

int arv_altura(NoArv* no) {
	if(no == NULL) return 0;
	return 1 + std::max(arv_altura(no->esq), arv_altura(no->dir));
}



