#include <iostream> // Entrada e saida
#include <climits> // INT_MAX

using namespace std;

int main()
{
	int custo[100][100]; // 100 -> numero maximo de países
						 // custo[i][j] = custo de ir do país 'i' para o país 'j'
	int pais_inicial; // Primeira e ultimo país
	int n; // numero de países
	
	cout << "Entre com o numero de paises" << endl;
	cin >> n;
	cout << "Entre com o pais inicial (sempre sera = 0)" << endl;
	cin >> pais_inicial;
	
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			cout << "Entre com o custo de ir do pais " << i << " para o pais " << j << endl;
			cin >> custo[i][j];
			custo[j][i] = custo[i][j]; // Custo de i->j = custo de j->i
		}
	}
	
	bool vis[100]; // marca se ja visitou ou nao o país
	int menor_custo; // menor custo da viagem
	int custo_at; // menor custo atual
	int pais_atual; // país atual
	int proximo_pais; // proximo país
		
	// inicializando vetor vis (nenhuma país foi visitado no inicio)
	for(int i = 0; i < n; i++)
		vis[i] = false;
	
	// guloso
	menor_custo = 0;
	pais_atual = pais_inicial;
	for(int i = 0;i < n-1;i++){ // n-1 vezes = qnt de caminhos (exceto a volta para o país inicial)
		vis[pais_atual] = true; // marco que ja visitei o país atual
		// encontrar qual o país mais próximo
		custo_at = INT_MAX;
		for(int j = 0; j < n; j++){
			if(!vis[j] && custo_at > custo[pais_atual][j]){
				proximo_pais = j;
				custo_at = custo[pais_atual][j];
			}	
		}
		menor_custo += custo_at;
		pais_atual = proximo_pais;
	}
	menor_custo += custo[pais_atual][pais_inicial];
	cout << "Menor custo = " << menor_custo << endl;
	
	return 0;
}







