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

NoArv* arv_cria(int chave, NoArv* esq, NoArv* dir) {
    NoArv* novo = new NoArv;
    novo->chave = chave;
    novo->esq = esq;
    novo->dir = dir;
    return novo;
}

int* arv_cria_base_array1(int v[], int tam) {


    int n_folhas = 2; // variável no qual será contabilizado todo o tamanho total da base da arvore
    int altura=1;// contando a altura da arvore

    while (n_folhas<=tam){ // Contando o numero de folhas total na base junto com a altura da arvore
        n_folhas*=2;    
        altura++;
    }

      // para esse código imagine a seguinte formação 
    //o v[]={10,3,2,4,7} e tam=5;
    //
    //altura=0                    2               <--((n_folhas/2)/2)/2 = 1
    //                    /            \             
    //altura=1 			 2                7       <-- ((n_folhas/2)/2) = 2
    //             	   /   \           /    \        
    //altura=2        3     2         7      11   <-- (n_folhas/2) = 4
    //               /  \   / \     /  \    /  \  
    // altura=3     10  3  2   4   7   11  11  11 <- BASE = n_folhas = 8


    NoArv *arvore[altura+1][n_folhas]; // criando matriz de folhas

    int campos=n_folhas; // variável que recebe o total de elementos da base e vai ser alterado de 
                        // acordo com a altura ex: altura=4 campos=n_folhas; altura=3 campos=n_folhas/2;
                        // altura = 2 campo = (n_folhas/2)/2 e assim por diante.

    int maior=v[0];    // variavel para criar o maior elemento do vetor
                        // exemplo:
                        //o v[]={10,3,2,4,7} e tam=5;
                        //                ...   ...     ...           ...
                        //               /  \   / \     /  \         /  \  
                        // altura=3     10  3  2   4   7   maior  maior  maior <- BASE = n_folhas = 8    

    for(int i=0;i<tam;i++){// procurará o maior valor do vetor e recebe ele
        if(v[i]>maior){
            maior=v[i];
        }
    }
    maior++;//  e incrementará mais 1, para que o maior se torne literalmente o maior valor



    for(int i=0;i<tam;i++)// aqui será criado todas as folhas da base 
        arvore[altura][i]=arv_cria(v[i],NULL,NULL); // criando base ( preenchendo com os valores do array)
    for(int i=tam;i<n_folhas;i++)
        arvore[altura][i]=arv_cria(maior,NULL,NULL); // criando base ( preechendo com o valor maior)
    
    // exemplo:
        //o v[]={10,3,2,4,7} e tam=5;
        //                ...   ...      ...          ...
        //               /  \   / \     /    \        /  \  
        // altura=3     (10  3  2   4   7)|(maior  maior  maior)     
        //              (valores do vetor)|(valores gerados pelo maior para preencher a base)

    for(int i=altura;i>0;i--) // percorrer cada folha de acordo com a altura da arvore
    {            
                      
        int cont=0;    // variável que mostra a posição da folha superior
        // exemplo:
        //o v[]={10,3,2,4,7} e tam=5;
        //                   ...               ...
        //                 /     \        /           \
        //   posição->  (cont) (cont)   (cont)       (cont)
        //               /  \   / \     /   \        /    \  
        // altura=3     10  3  2   4   7   maior  maior  maior

      
        for(int j=0;j<campos;j+=2){ // aqui a será onde vai criar as folhas no andar superior 
            if(arvore[i][j]->chave<=arvore[i][j+1]->chave)
                arvore[i-1][cont]=arv_cria(arvore[i][j]->chave,arvore[i][j],arvore[i][j+1]); 
                // fazendo a comparação se a folha esquerda é menor ou igual que a direita
                // e criando a folha do andar superior pontando o esq e o direito do andar inferior

            else//se não
                arvore[i-1][cont]=arv_cria(arvore[i][j+1]->chave,arvore[i][j],arvore[i][j+1]);
                // a folha do andar superior recebe o falor da folha direita
                // e criando a folha do andar superior pontando o esq e o direito do andar inferior
            cont++;
       
        }
        campos/=2;   // a cada andar que passa, o numero do total de folhas é dividio por 2 ps: como explicada 
                    // na linha 53
    }

    

    int *saida=new int[tam]; // criando ponteiro para receber em forma ordenada os valores que topo retorna
    saida[0]=arvore[0][0]->chave;// saida recebendo o 1 retorno do topo da arvore

    

    for(int t=1;t<tam;t++){
        int menor=arvore[0][0]->chave; // pegando o menor elemento que é o que está no topo da arvore

        campos=n_folhas;// campos recebendo novamento o tamanho total de folhas da base
        for(int y=0;y<tam;y++){
            if(arvore[altura][y]->chave==menor){
                arvore[altura][y]->chave=maior;  // subistituindo da base o valor menor pelo maior
                break;
                }
        }

        for(int i=altura;i>0;i--) // percorrer cada folha de acordo com a altura
        {                           

            int cont=0;// int cont ps: explicado na linha 88
            
            for(int j=0;j<campos;j+=2){ 
                if(arvore[i][j]->chave<=arvore[i][j+1]->chave)// fazendo a comparação se a folha esquerda é menor ou igual que a direita
                    arvore[i-1][cont]->chave=arvore[i][j]->chave;// caso for, a folha do andar superior recebe o valore da esqueda
                else// se não
                    arvore[i-1][cont]->chave=arvore[i][j+1]->chave;// a folha do andar superior recebe o falor da folha direita
                cont++;
            }
            campos/=2;   // a cada andar que passa, o numero do total de folhas é dividio por 2 ps: como explicada 
                    // na linha 53
        }
        saida[t]=arvore[0][0]->chave; // ponteiro recebendo todos os valores retornados pelo topo da arvore

    }

    return saida;// retorna o ponteiro com todos os valores retornados pelo topo da arvore
}





