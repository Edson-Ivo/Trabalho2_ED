#include <iostream>
#include <fstream>
#include <sstream>
#include "ArvoreBinaria.h"
using namespace std;

int main() {

    // EDSON IVO E DAVI MAIA 
    // execute com g++ -std=c++14  main.cpp ArvoreBinaria.cpp -o programa 


    string line;
    ifstream arquivo_entrada;
    ofstream arquivo_saida;
    int cont=1;

    int tam = 0;
    arquivo_entrada.open("entrada.txt");
    arquivo_saida.open("ordenados.txt");    
    while(getline(arquivo_entrada, line)){
        stringstream ss(line);
        ss >> tam;

        if(tam == 0){
            arquivo_entrada.close();
            break;
        }
        else{   
            
            int vt[tam]; // vetor no qual vai receber os valores do txt e guarda-los
            getline(arquivo_entrada, line); // olha a linha do txt
            stringstream ss(line); // variavel que recebe os valores da linha
            for(int i = 0; i < tam; i++){
                ss >> vt[i]; //vt recebe os valores de ss
            }

            int *z=arv_cria_base_array1(vt,tam);/* faz a função de ordenação por arvore completa e retorna um ponteiro
                                                 com os valores ordenados */
                    
            string saida_string;// variável que vai receber os valores como string para manda-los para o saida.txt
            string mostrar="Vetor";
           for(int g=0;g<tam;g++){  
                saida_string += to_string(z[g]) + " ";  //aqui concactena os inteiros do ponteiro z para string
           }
            cout<<saida_string<<endl;
            arquivo_saida <<mostrar+to_string(cont)<<'\n';
            arquivo_saida << saida_string << '\n';// e aqui envia para o saida.txt a string  
            arquivo_saida<< '\n';//  com os valores certos

            cont++;
            }

           
        }
        arquivo_saida.close();

    //saida[2,3,4,7,10]    
    //                    2
    //            ///////   \\\\\\
    // 			 2                7
    //  	   /   \           /    \
    //        3     4         7      11
    //       /  \   / \     /  \    /  \
    //      10  3  2   4   7   11  11  11
	//cout<<"pao";
	
    

    return 0;
}
