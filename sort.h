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

// ShellSort com o método do Shell, potências de 2, retorna a posição de leitura do arquivo
double sortSHELL(int a[], int tam){

    ofstream saidaSHELL ("saida1.txt", ios_base::out|ios_base::app);
    double pos;
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
        for (int i=0; i<tam; i++){
            saidaSHELL << a[i] << " ";
        }
        saidaSHELL << "INCR=" << h << endl;
    }
    pos = saidaSHELL.tellp();
    return pos;
}

// ShellSort com o método do KNUTH, 3h + 1, retorna a posição de leitura do arquivo
double sortKNUTH(int a[], int tam){

    ofstream saidaSHELL ("saida1.txt", ios_base::out|ios_base::app);
    double pos;

    // h = tamanho do espaço entre cada valor escolhido para fazer o sort
    int h = 1;
    while (h < tam)
        h = h*3 + 1;
    h /= 3;

    while (h >= 1){
        // n = fator que escolhe os elementos os quais serão feitos o sort
        for (int n = h; n < tam; n+= 1){
            int valorTemp = a[n];

            // j = posição do elemento
            int j;
            for (j = n; j >= h && a[j - h] > valorTemp; j -= h)
                a[j] = a[j - h];

            a[j] = valorTemp;
        }
        for (int i=0; i<tam; i++){
            saidaSHELL << a[i] << " ";
        }

        saidaSHELL << "INCR=" << h << endl;
        h /= 3;
    }
    pos = saidaSHELL.tellp();
    return pos;
}