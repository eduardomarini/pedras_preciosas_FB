#include <iostream>
using namespace std;

// estrutura que contém os dados das pedras preciosas
struct pedrasPreciosas {
    string nome;
    float volume;
    int peso;
    int preco;
};

pedrasPreciosas dados[] = {
    {"Diamante", 0.455, 263, 500},
    {"Esmeralda", 0.521, 127,410},
    {"Topazio", 0.857, 254, 320},
    {"Rubi", 0.065, 134, 315},
    {"Jade", 0.012, 111, 280}
};

int pp[5][401]; // declara uma matriz com os dados 

int precoMaximo(int n, int capacidade) {
    // n -> representa o número de tipos de pedras preciosas
    // capacidade -> capacidade máxima da mochila

    if(n == 0 || capacidade == 0) { // 
        return 0;
    }
}



