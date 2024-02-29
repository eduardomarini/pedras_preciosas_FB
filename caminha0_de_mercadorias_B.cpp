#include <iostream>
#include <vector>

using namespace std;

struct Caixa {
    char tipo;
    int quantidade;
    int altura;
    int largura;
    int comprimento;
    int preco;

    Caixa(char t, int q, int h, int l, int c, int p) : tipo(t), quantidade(q), altura(h), largura(l), comprimento(c), preco(p) {}
};

int calculaCargaTotal(vector<Caixa>& combinacao) {
    int cargaTotal = 0;
    for (int i = 0; i < combinacao.size(); ++i) {
        cargaTotal += combinacao[i].quantidade * combinacao[i].preco;
    }
    return cargaTotal;
}

void forcaBruta(vector<Caixa>& caixas, vector<Caixa>& melhorComb, vector<Caixa>& combinacaoAtual, int alturaContainer, int larguraContainer, int comprimentoContainer, int& melhorCarga) {
    if (calculaCargaTotal(combinacaoAtual) > melhorCarga) {
        melhorCarga = calculaCargaTotal(combinacaoAtual);
        melhorComb = combinacaoAtual;
    }

    for (int i = 0; i < caixas.size(); ++i) {
        if (caixas[i].quantidade > 0 && alturaContainer >= caixas[i].altura && larguraContainer >= caixas[i].largura && comprimentoContainer >= caixas[i].comprimento) {
            caixas[i].quantidade--;
            combinacaoAtual.push_back(caixas[i]);
            forcaBruta(caixas, melhorComb, combinacaoAtual, alturaContainer - caixas[i].altura, larguraContainer - caixas[i].largura, comprimentoContainer - caixas[i].comprimento, melhorCarga);
            combinacaoAtual.pop_back();
            caixas[i].quantidade++;
        }
    }
}

int main() {
    vector<Caixa> caixas;
    caixas.push_back({'A', 10, 5, 2, 2, 200});
    caixas.push_back({'B', 20, 1, 1, 3, 150});
    caixas.push_back({'C', 25, 2, 2, 1, 100});

    int alturaContainer = 10; // Exemplo de altura do container
    int larguraContainer = 10; // Exemplo de largura do container
    int comprimentoContainer = 10; // Exemplo de comprimento do container

    vector<Caixa> melhorComb;
    vector<Caixa> combinacaoAtual;
    int melhorCarga = 0;

    forcaBruta(caixas, melhorComb, combinacaoAtual, alturaContainer, larguraContainer, comprimentoContainer, melhorCarga);

    cout << "Melhor combinacao de caixas para maximizar o valor da carga total:" << endl;
    for (int i = 0; i < melhorComb.size(); ++i) {
        cout << "Tipo: " << melhorComb[i].tipo << ", Quantidade: " << melhorComb[i].quantidade << ", Preco: " << melhorComb[i].preco << endl;
    }
    cout << "Carga total: " << melhorCarga << endl;

    return 0;
}
