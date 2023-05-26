#include "sort.h"
using namespace std;

int main() {

	int tamanho_vetor;
    char buffer[256];
    string arqnome;
    double pos;

    ifstream &arquivo = abreArq();
    ofstream saida1 ("saida1.txt", ios_base::out|ios_base::trunc);

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
            pos = sortSHELL(vetorSort, tamanho_vetor);
            saida1.seekp(pos);
            cout << "Feito SHELLSORT com " << tamanho_vetor << " elementos e escrito no arquivo" << endl;

            for (int i=0; i<tamanho_vetor; i++){
                saida1 << nVetor[i] << " ";
                vetorSort[i] = nVetor[i];
            }
            saida1 << "SEQ=KNUTH" << endl;
            pos = sortKNUTH(vetorSort,tamanho_vetor);
            saida1.seekp(pos);
            cout << "Feito KNUTHSORT com " << tamanho_vetor << " elementos e escrito no arquivo" << endl;
        }
	}
    return 0;
}
