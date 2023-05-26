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

            for (int i=0; i<tamanho_vetor; i++){
                arquivo >> nVetor[i];
                saida1 << nVetor[i] << " ";
                printf("%d ", nVetor[i]);
            }
            saida1 << "SEQ=SHELL" << endl;
            printf ("Numero de elementos na entrada: %d\n", tamanho_vetor);	

            pos = sortSHELL(nVetor, tamanho_vetor);
            saida1.seekp(pos);

            printf("ShellSort: ");
            for (int i=0; i<tamanho_vetor; i++){
                printf("%d ", nVetor[i]);
            }
            printf("\n");
        }
	}
    return 0;
}
