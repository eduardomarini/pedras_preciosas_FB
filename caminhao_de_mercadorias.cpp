#include <iostream>
#include <vector>

using namespace std;

// define uma estrutura com os dados da tabela
struct Caixa {
    char tipo;
    int quantidade;
    int volume;
};

// Calcula o número máximo de caixas que podem ser transportadas
int maximoDeCaixas(vector<Caixa>& caixas, int alturaContainer, int larguraContainer, int comprimentoContainer) {
    int maximo = 0;

    // Ordenação manual das caixas por volume em ordem decrescente
    for (int i = 0; i < caixas.size(); ++i) {
        int maiorVolumeIndex = i;
        for (int j = i + 1; j < caixas.size(); ++j) {
            if (caixas[j].volume > caixas[maiorVolumeIndex].volume) {
                maiorVolumeIndex = j;
            }
        }
        swap(caixas[i], caixas[maiorVolumeIndex]);
    }

    // Itera sobre todas as caixas
    for (int i = 0; i < caixas.size(); ++i) {
        Caixa& caixa = caixas[i];
        while (caixa.quantidade > 0 && alturaContainer >= caixa.volume && larguraContainer >= caixa.volume && comprimentoContainer >= caixa.volume) {
            maximo++;
            caixa.quantidade--;
            alturaContainer -= caixa.volume; //  Reduz a altura do container
            larguraContainer -= caixa.volume; // Reduz a largura do container
            comprimentoContainer -= caixa.volume; // Reduz o comprimento do container
        }
    }

    return maximo; // retorna o número máximo de caixas que podem ser transportadas
}

int main() {
    // Cria um vetor de caixas e adiciona cada caixa individualmente
    vector<Caixa> caixas;
    caixas.push_back({'A', 10, 20}); // Volume = 5 * 2 * 2 = 20
    caixas.push_back({'B', 20, 3});  // Volume = 1 * 1 * 3 = 3
    caixas.push_back({'C', 25, 4});  // Volume = 2 * 2 * 1 = 4

    int alturaContainer = 10; // Define altura do container
    int larguraContainer = 10; // Define largura do container
    int comprimentoContainer = 10; // Define comprimento do container

    int maximo = maximoDeCaixas(caixas, alturaContainer, larguraContainer, comprimentoContainer); // Chama a função maximoDeCaixas para calcular o número máximo de caixas que podem ser transportadas

    cout << "Quantidade maxima de caixas que podem ser transportadas: " << maximo << endl;

    return 0; // Retorna 0 para indicar que o programa foi executado com sucesso
}
