#include <iostream>
#include <climits> // INT_MIN
using namespace std;

int main() {
    int m; // Número de metros de cerca

    // Entrada dos dados
    cout << "Entre com o numero de metros de cerca: ";
    cin >> m;

    int melhor_area = 0; // Inicializa a melhor área encontrada
    int melhor_comprimento = 0; // Inicializa o melhor comprimento
    int melhor_largura = 0; // Inicializa a melhor largura

    // Força bruta para encontrar as dimensões ideais
    for (int comprimento = 1; comprimento <= m / 2; ++comprimento) {
        int largura = m - comprimento;

        // Calcula a área para as dimensões atuais
        int area = comprimento * largura;

        // Verifica se a área atual é melhor que a melhor área encontrada até agora
        if (area > melhor_area) {
            melhor_area = area;
            melhor_comprimento = comprimento;
            melhor_largura = largura;
        }
    }

    // Saída do resultado
    cout << "Dimensoes ideais: " << melhor_comprimento << " x " << melhor_largura << endl;

    return 0;
}
