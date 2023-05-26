#include "sort.h"
using namespace std;

int main() {

    // Inicializando todas as variaveis que serão utilizadas
	int tamanho_vetor;
    char buffer[256];
    string arqnome;
    double pos;
    clock_t start_t, end_t;
    double tempo;

    // Inicializando o stream de I/O, para ler o arquivo de entrada e manipular os arquivos de saída
    ifstream &arquivo = abreArq();
    ofstream saida1 ("saida1.txt", ios_base::out|ios_base::trunc);
    ofstream saida2 ("saida2.txt", ios_base::out|ios_base::trunc);

	while (!arquivo.eof()) {
        if (arquivo >> tamanho_vetor){
            int nVetor[tamanho_vetor];
            int vetorSort[tamanho_vetor];

            for (int i=0; i<tamanho_vetor; i++){
                arquivo >> nVetor[i];
                saida1 << nVetor[i] << " ";
                vetorSort[i] = nVetor[i];
            }
            printf("Numero de elementos na entrada: %d\n", tamanho_vetor);	

            saida1 << "SEQ=SHELL" << endl;
            saida2 << "SHELL," << tamanho_vetor << ",";

            start_t = clock();
            sortSHELL(vetorSort, tamanho_vetor, &pos);
            end_t = clock();

            tempo = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            saida2 << tempo*1000 << "," << dadosProcessador << endl;

            saida1.seekp(pos);
            cout << "Feito SHELLSORT com " << tamanho_vetor << " elementos e escrito no arquivo" << endl;

            for (int i=0; i<tamanho_vetor; i++){
                saida1 << nVetor[i] << " ";
                vetorSort[i] = nVetor[i];
            }

            saida1 << "SEQ=KNUTH" << endl;
            saida2 << "KNUTH," << tamanho_vetor << ",";

            start_t = clock();
            sortKNUTH(vetorSort,tamanho_vetor, &pos);
            end_t = clock();

            tempo = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            saida2 << tempo*1000 << "," << dadosProcessador << endl;

            saida1.seekp(pos);
            cout << "Feito KNUTHSORT com " << tamanho_vetor << " elementos e escrito no arquivo" << endl;

            for (int i=0; i<tamanho_vetor; i++){
                saida1 << nVetor[i] << " ";
                vetorSort[i] = nVetor[i];
            }

            saida1 << "SEQ=CIURA" << endl;
            saida2 << "CIURA," << tamanho_vetor << ",";

            start_t = clock();
            sortCIURA(vetorSort,tamanho_vetor, &pos);
            end_t = clock();

            tempo = (double)(end_t - start_t) / CLOCKS_PER_SEC;
            saida2 << tempo*1000 << "," << dadosProcessador << endl;

            saida1.seekp(pos);
            cout << "Feito CIURASORT com " << tamanho_vetor << " elementos e escrito no arquivo" << endl;
        }
	}
    return 0;
}
