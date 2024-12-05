#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;



// Aqui vai conter a estrutura principar que s�o as cartelas, essa estrutura se baseia em uma lista encadeada, uma struct
// que vai possuir como dados um vetor bidimencional que sera salvo os numeros da cartela e mais um vetor uni dimencional
// que vai armazenar os numeros j� chamados

struct cartelaEstrutura{
	int cartela[5][5];
	int numerosChamados[75];
	cartelaEstrutura *proxi;
};








// assinaturas das fun�oes:
void CriaCartelas();









int main(int argc, char** argv) {
	
	//variaveis 
	bool fecha_bingo = false;
	int acao;
	
	do{
		cout << "========== *-BINGO-* ==========\n";
		
		cout <<
		 "1) Criar cartelas\n" <<
		 "2) Fechar jogo\n";
		 cin >> acao;
		
		switch(acao){
			case 1:
			CriaCartelas();
		    break;
		    
		    case 2:
		    fecha_bingo = true;
		    break;
		}
		
		
	}while(fecha_bingo == false);
	
	
	
	
	
	
	
	
	
	
	return 0;
}

// Aqui o usuario escolhe o numero de cartela que ele quer e o programa cria as cartelas com os numeros aleatorios
// e gera arquivos txt que s�o as cartelas que o usuario solicitou

void CriaCartelas(){
	srand(time(0));
	
	//variaveis:
	int quantCartelas;
	cartelaEstrutura* inicio, nova, proxima;
	
	cout << "Quantas cartelas voc� deseja?\n";
	cin >> quantCartelas;
	
	
	
	for(int i=0; i<quantCartelas; i++){
		
		cartelaEstrutura* inicio = new cartelaEstrutura;
		
		
		// Esse for adiciona os valores da primeira coluna que s�o de 1 a 15
		for(int a=0; a<5; a++){
			
		// Inicializa o gerador de n�meros aleat�rios
       
        
        inicio->cartela[0][a] = rand() % 15 + 1; // Gera n�mero entre 1 e 100;
			
		}
		
		
        
		for(int a=0; a<5; a++){
			cout << inicio->cartela[0][a] << endl;
		}
		
		
		
	}
	
	
	
	
	
}



