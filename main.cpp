#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

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
			cout << "cria cartela";
		    break;
		    
		    case 2:
		    fecha_bingo = true;
		    break;
		}
		
		
	}while(fecha_bingo == false);
	
	
	
	
	
	
	
	
	
	
	return 0;
}
