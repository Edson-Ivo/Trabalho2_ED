#include <iostream>
#include "ArvoreBinaria.h"
using namespace std;

int main() {

     int v[]={10,3,2,4,7};

     //cout txt =  {2,}
    NoArv* raiz = arv_cria_base_array(v,5); // veto={2,3}
    //                    2
    //            ///////   \\\\\\
    // 			 2                7
    //  	   /   \           /    \
    //        3     2         7      11
    //       /  \   / \     /  \    /  \
    //      10  3  2   4   7   11  11  11
	//cout<<"pao";
	
    

    return 0;
}
