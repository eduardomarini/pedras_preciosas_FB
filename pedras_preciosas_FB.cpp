#include <iostream>
#include <string>
#include <vector>
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

// varíaveis globais para armazenar o preço máximo e a melhor seleção de itens
int capacidadeMaxima = 400;
int maxPreco = 0;
vector<bool> melhorSelecao; 

// Função para calcular o preço total de uma seleção de itens
int calculaPrecoTotal(const vector<bool>& selecao) { // 
    int precoTotal = 0;
    int pesoTotal = 0;
    // Itera sobre os itens calcula o preço total e o peso total da seleção
    for(int i = 0; i < 5; i++) {
        if (selecao[i]) { // Verifica se o item atual esta selecionado
        precoTotal += dados[i].preco;
        pesoTotal += dados[i].peso;
        }
    }
    // Se o peso total excede a capacidade, retornamos preço inválido (-1)
    if (pesoTotal > capacidadeMaxima) 
        return -1;
    return precoTotal;
}

// Função recursiva para encontrar a seleção que maximiza o preço total
void forcaBruta(int index, vector<bool>& selecaoAtual) {
    // Verifica se já iterou por todos os itens
    if (index == 5) {
        //Calcula o preço total da seleção atual
        int precoTotal = calculaPrecoTotal(selecaoAtual);
        // Se o preço total é maior que o máximo encontrado até agora,
        // atualiza o máximo e a seleção
        if (precoTotal > maxPreco) {
            maxPreco = precoTotal; // Atualiza o preço máximo
            melhorSelecao = selecaoAtual; // Atualiza melhor seleção
        }
        return; // para encerrar a recursão
    }
    // Inclui o item atual na seleção e chama a função recursivamente para o próximo item
    selecaoAtual[index] = true; // Marca o item atual como selecionado
    forcaBruta(index + 1, selecaoAtual); // Chama a função recursivamente para o próximo item
    // Exclui o item atual da seleção e chama a função recursivamente para o proximo item
    selecaoAtual[index] = false; // Marca o item atual como não selecionado
    forcaBruta(index + 1, selecaoAtual); // Chama a função recursivamente para o proximo item
}

int main() {
    // Inicializa a seleção atual com nenhum item selecionado
    vector<bool> selecaoAtual(5,false);
    // Chama a função de força bruta para encontrar a melhor seleção de itens
    forcaBruta(0, selecaoAtual);

    // Exibe a melhor seleção de itens e preço total
    cout << "Melhor selecao de itens para obter o preco maximo dentro da capacidade do carrinho: " << endl;
    for (int i = 0; i < 5; i++) {
        if (melhorSelecao[i]) 
            cout << "Pedra: " << dados[i].nome << " Volume: " << dados[i].volume << " Peso: " << dados[i].peso << " Preco: " << 
            dados[i].preco << endl; // Exibe os dados dos itens selecionados
    }
    cout << "Preco total: " << maxPreco << endl; // Exibe o preço total da melhor seleção
    return 0;
}


// Analise da complexidade assintótica
// calculaPreco() -> número de iterações não aumenta conforme o tamanho do vetor -> O(1)
// forcaBruta() -> para cada itens existe duas chamadas recursivas, uma incluindo o item e outra excluindo, portanto a qauntidade de chamadas será exponencial -> O(2^N)
// main() -> chamamos a função força bruta uma vez [O(2^N)], loop para definir a melhor seleção [O(1)], portanto main() será de -> O(2^N)
// A complexidade assintótica total do script é de O(2^N)

