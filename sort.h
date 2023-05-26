#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

// abre o arquivo
ifstream& abreArq(){
    ifstream *arq = 0;

    for(;;){
        string arqnome;
        cout << "Insira o nome do arquivo: ";
        cin >> arqnome;

        arq = new ifstream(arqnome.c_str());
        if (arq->good()){
            arq->seekg(0);
            cerr << arqnome << " Aberto com sucesso!" << endl;
            break;
        }
        cerr << arqnome << " Nao foi aberto!" << endl;
        delete arq;
    }
    return *arq;
}

// ShellSort com o método do Shell, potências de 2
void sortSHELL(int a[], int tam){

    // h = tamanho do espaço entre cada valor escolhido para fazer o sort
    for (int h = tam/2; h > 0; h /=2){
        // n = fator que escolhe os elementos os quais serão feitos o sort
        for (int n = h; n < tam; n+= 1){
            int valorTemp = a[n];

            // j = posição do elemento
            int j;
            for (j = n; j >= h && a[j - h] > valorTemp; j -= h)
                a[j] = a[j - h];

            a[j] = valorTemp;
        }
    }
}