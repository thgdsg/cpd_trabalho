// VERSÃO DO CÓDIGO SEM ESCRITA EM ARQUIVO saida1.txt, FEITA PARA CALCULAR O TEMPO NECESSÁRIO PARA REALIZAR SORTING COM DIFERENTES ALGORITMOS
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <vector>

using namespace std;

// Mudar caso esteja usando um computador diferente
string dadosProcessador = "4.00 GHz Quad-Core Intel Core i7-6700K";

// abre o arquivo
ifstream& abreArq(){
    ifstream *arq = 0;

    for(;;){
        // Coleta o nome do arquivo do usuário e abre
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
void sortSHELL(int a[], int tam, double *pos){

    //ofstream saidaSHELL ("saida1.txt", ios_base::out|ios_base::app);

    // h = tamanho do espaço entre cada valor escolhido para fazer o sort
    int h = 1;
    while (h < tam)
        h = h*2;
    h /= 2;

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
            //saidaSHELL << a[i] << " ";
        }
        // Coloca no arquivo saida1.txt o espaçamento entre cada elemento que está sendo ordenado
        //saidaSHELL << "INCR=" << h << endl;
        h /= 2;
    }
    // Salva a posição de leitura do arquivo para continuar a leitura na função main
    //*pos = saidaSHELL.tellp();
}

// ShellSort com o método do KNUTH, 3h + 1
void sortKNUTH(int a[], int tam, double *pos){

    //ofstream saidaKNUTH ("saida1.txt", ios_base::out|ios_base::app);

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
            //saidaKNUTH << a[i] << " ";
        }
        // Coloca no arquivo saida1.txt o espaçamento entre cada elemento que está sendo ordenado
        //saidaKNUTH << "INCR=" << h << endl;
        h /= 3;
    }
    // Salva a posição de leitura do arquivo para continuar a leitura na função main
    //*pos = saidaKNUTH.tellp();
}

// ShellSort com o método do CIURA, 1, 4, 10, 23, 57, 132, 301, 701, a partir do 701 multiplicar por 2.25
void sortCIURA(int a[], int tam, double *pos){

    //ofstream saidaCIURA ("saida1.txt", ios_base::out|ios_base::app);
    // ciura = tamanho do espaço entre cada valor escolhido para fazer o sort, caso o espaço seja maior que 701
    int ciura = 0;

    // h = tamanho do espaço entre cada valor escolhido para fazer o sort
    int h[8] = {1, 4, 10, 23, 57, 132, 301, 701};
    int count = 0;
    // enquanto o tamanho do vetor for menor que h, aumenta o índice do h, até chegar em 8
    while (h[count] < tam){
        count++;
        if (count > 7)
            break;
    }
    // no momento em que atinge 8, começa a usar a fórmula h[i] = h[i - 1] * 2.25
    if (count == 8){
        ciura = 701;
        while (ciura < tam){
            ciura = floor(ciura * 2.25);
        }
        ciura = ceil(ciura / 2.25);
        count--;
    }
    count--;

    if (ciura >= 701){
        while(ciura >= 701){

            // n = fator que escolhe os elementos os quais serão feitos o sort
            for (int n = ciura; n < tam; n+= 1){
                int valorTemp = a[n];

                // j = posição do elemento
                int j;
                for (j = n; j >= ciura && a[j - ciura] > valorTemp; j -= ciura)
                    a[j] = a[j - ciura];

                a[j] = valorTemp;
            }
            for (int i=0; i<tam; i++){
                //saidaCIURA << a[i] << " ";
            }

            // Coloca no arquivo saida1.txt o espaçamento entre cada elemento que está sendo ordenado
            //saidaCIURA << "INCR=" << ciura << endl;
            ciura = round(ciura / 2.25);
        }
    }
    while (count >= 0){

        // n = fator que escolhe os elementos os quais serão feitos o sort
        for (int n = h[count]; n < tam; n+= 1){
            int valorTemp = a[n];

            // j = posição do elemento
            int j;
            for (j = n; j >= h[count] && a[j - h[count]] > valorTemp; j -= h[count])
                a[j] = a[j - h[count]];

            a[j] = valorTemp;
        }
        for (int i=0; i<tam; i++){
            //saidaCIURA << a[i] << " ";
        }

        // Coloca no arquivo saida1.txt o espaçamento entre cada elemento que está sendo ordenado
        //saidaCIURA << "INCR=" << h[count] << endl;
        count--;
    }
    // Salva a posição de leitura do arquivo para continuar a leitura na função main
    //*pos = saidaCIURA.tellp();
}