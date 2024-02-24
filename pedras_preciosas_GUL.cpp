#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// estrutura que contém os dados das pedras preciosas
struct pedrasPreciosas {
    string nome;
    float volume;
    int peso;
    int preco;
};

// vetor que contem as pedras preciosas e seus dados
pedrasPreciosas dados[] = {
    {"Diamante", 0.455, 263, 500},
    {"Esmeralda", 0.521, 127,410},
    {"Topazio", 0.857, 254, 320},
    {"Rubi", 0.065, 134, 315},
    {"Jade", 0.012, 111, 280}
};

// Função para comparar pedras preciosas com base em sua razão valor/peso
bool compararPorRazao(const pedrasPreciosas& a, const pedrasPreciosas& b) {
    return (float)a.preco / a.peso > (float)b.preco / b.preco;
}

int main() {
    // Ordena as pedras preciosas com base em sua razão valor/peso
    sort(dados, dados + 5, compararPorRazao);

    int capacidadeMaxima = 400;
    int precoTotal = 0;
    vector<bool>selecaoAtual(5, false);

    // Percorre as pedras preciosas ordenadas e seleciona aquelas que cabem na mochila
    for (int i = 0; i < 5; i++) {
        if (dados[i].peso <= capacidadeMaxima) {
            selecaoAtual[i] = true;
            capacidadeMaxima -= dados[i].peso;
            precoTotal += dados[i].preco;
        }
    }

    // Exibe a seleção de pedras preciosas e o preço total
    for (int i = 0; i < 5; i++) {
        if (selecaoAtual[i])
            cout << "Pedra: " << dados[i].nome << " Volume: " << dados[i].volume << " Peso: " << dados[i].peso << " Preco: " << dados[i].preco << endl;
    }
    cout << "Preco Total: " << precoTotal << endl;

    return 0;
}

// A complexidade sort() é de O(N log N), portanto a complexidade da função sort() desse script é de O(5 log 5), como o número de elementos é constante a complexidade será de O(1).
// O loop que seleciona as pedras O(N), tem uma complexidade constante.
// Portanto a complexidade total do script será de O(N).