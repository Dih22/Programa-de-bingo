#include <iostream>
#include <cstdlib> // Para rand() e srand()
#include <ctime>
#include <locale>
#include <fstream>
#include <sstream> // Para std::stringstream

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;


int numerosChamados[75];

// Aqui vai conter a estrutura principar que são as cartelas, essa estrutura se baseia em uma lista encadeada, uma struct
// que vai possuir como dados um vetor bidimencional que sera salvo os numeros da cartela e mais um vetor uni dimencional
// que vai armazenar os numeros já chamados

struct cartelaEstrutura{
	int cartela[5][5];
	cartelaEstrutura *proxi;
};



// Ponteiro global para o início da lista
cartelaEstrutura *inicio = NULL;

// assinaturas das funçoes:
void CriaCartelas();
void mostraLista();
void  jogo();
void verLinhasEColunas();



int main() {
	setlocale(LC_ALL, "portuguese");
	
	//variaveis 
	bool fecha_bingo = false;
	int acao;
	
	do{
		system("cls");
		cout << "========== *-BINGO-* ==========\n";
		
		cout <<
		 "1) Criar cartelas\n" <<
		 "2) Fechar jogo\n" <<
		 "3) Mostrar cartelas\n" <<
		 "4) jogar\n";
		 cin >> acao;
		
		switch(acao){
			case 1:
			CriaCartelas();
		    break;
		    
		    case 2:
		    fecha_bingo = true;
		    break;
		    
		    case 3:
		    mostraLista();
		    break;
		    
		    case 4:
		    jogo();
		    break;
		}
		
		
	}while(fecha_bingo == false);
	
	
	
	
	
	
	
	
	
	
	return 0;
}









// Aqui o usuario escolhe o numero de cartela que ele quer e o programa cria as cartelas com os numeros aleatorios
// e gera arquivos txt que são as cartelas que o usuario solicitou

void CriaCartelas() {
    srand(time(0)); // Inicializa o gerador de números aleatórios
    
    int quantCartelas;
    cartelaEstrutura  *atual = NULL, *anterior = NULL;    // ponteiros de controle
    int aleatorio1=0;
    int aleatorio2=0;
    int aleatorio3=0;
    int aleatorio4=0;
    int aleatorio5=0;
    
    bool repetido;

    cout << "Quantas cartelas você deseja?\n";
    cin >> quantCartelas;
    
    
   
    for (int i = 0; i < quantCartelas; i++) {
    	
    	//coloco a estrutura cartelaEstrutura dentro da variavel de ponteiro atual
        atual = new cartelaEstrutura;
         if (!inicio) {
            inicio = atual; // Define o início da lista encadeada
        } else {
            anterior->proxi = atual; // Conecta o nó anterior ao atual
        }
		
    	
        ofstream arquivo;

        // Inicializa o vetor da cartela com zeros (opcional, para evitar lixo de memória)
        for (int a = 0; a < 5; a++) {
            for (int b = 0; b < 5; b++) {
                atual->cartela[a][b] = 0;
            }
        }


         // =======================================================================================================================================
        // Preenchendo a cartela
        for (int a = 0; a < 5; a++) {  //  <--------------------preenche PRIMEIRA coluna da cartela
            do {
                repetido = false;
                aleatorio1 =0;
                aleatorio1 = rand() % 15 + 1; // Gera um número aleatório entre 1 e 15

                // Verifica se o número já existe na coluna da cartela
                for (int b = 0; b < a; b++) { // Observação: `b < a` garante que só verifica os números já atribuídos
                    if (atual->cartela[b][0] == aleatorio1) {
                        repetido = true;
                        break; // Sai do loop interno ao encontrar um repetido
                    }
                }
            } while (repetido); // Continua gerando números até encontrar um único

            atual->cartela[a][0] = aleatorio1; // Armazena o número na cartela
        }
        
        
        
        
        
        
        
        
        
        

         // =======================================================================================================================================
        // Preenchendo a cartela
        for (int a = 0; a < 5; a++) {  //  <--------------------preenche SEGUNDA coluna da cartela
            do {
                repetido = false;
                aleatorio2 =0;
                aleatorio2 = rand() % 15 + 16; // Gera um número aleatório entre 16 e 30

                // Verifica se o número já existe na coluna da cartela
                for (int b = 0; b < a; b++) { // Observação: `b < a` garante que só verifica os números já atribuídos
                    if (atual->cartela[b][1] == aleatorio2) {
                        repetido = true;
                        break; // Sai do loop interno ao encontrar um repetido
                    }
                }
            } while (repetido); // Continua gerando números até encontrar um único

            atual->cartela[a][1] = aleatorio2; // Armazena o número na cartela
        }
        
        
        
        
        
        
        
        

         // =======================================================================================================================================
        // Preenchendo a cartela
        for (int a = 0; a < 5; a++) {  //  <--------------------preenche TERCEIRA coluna da cartela
            do {
                repetido = false;
                aleatorio3 =0;
                aleatorio3 = rand() % 15 + 31; // Gera um número aleatório entre 31 e 45

                // Verifica se o número já existe na coluna da cartela
                for (int b = 0; b < a; b++) { // Observação: `b < a` garante que só verifica os números já atribuídos
                    if (atual->cartela[b][2] == aleatorio3) {
                        repetido = true;
                        break; // Sai do loop interno ao encontrar um repetido
                    }
                }
            } while (repetido); // Continua gerando números até encontrar um único

            atual->cartela[a][2] = aleatorio3; // Armazena o número na cartela
        }
        
        
        
        
        
        
        
        

         // =======================================================================================================================================
        // Preenchendo a cartela
        for (int a = 0; a < 5; a++) {  //  <--------------------preenche QUARTA coluna da cartela
            do {
                repetido = false;
                aleatorio4 =0;
                aleatorio4 = rand() % 15 + 46; // Gera um número aleatório entre 46 e 60

                // Verifica se o número já existe na coluna da cartela
                for (int b = 0; b < a; b++) { // Observação: `b < a` garante que só verifica os números já atribuídos
                    if (atual->cartela[b][3] == aleatorio4) {
                        repetido = true;
                        break; // Sai do loop interno ao encontrar um repetido
                    }
                }
            } while (repetido); // Continua gerando números até encontrar um único

            atual->cartela[a][3] = aleatorio4; // Armazena o número na cartela
        }
        
        
        
        
        
        
        
        

         // =======================================================================================================================================
        // Preenchendo a cartela
        for (int a = 0; a < 5; a++) {  //  <--------------------preenche QUINTA coluna da cartela
            do {
                repetido = false;
                aleatorio5 =0;
                aleatorio5 = rand() % 15 + 61; // Gera um número aleatório entre 61 e 75

                // Verifica se o número já existe na coluna da cartela
                for (int b = 0; b < a; b++) { // Observação: `b < a` garante que só verifica os números já atribuídos
                    if (atual->cartela[b][4] == aleatorio5) {
                        repetido = true;
                        break; // Sai do loop interno ao encontrar um repetido
                    }
                }
            } while (repetido); // Continua gerando números até encontrar um único

            atual->cartela[a][4] = aleatorio5; // Armazena o número na cartela
        }
        
        
        
        
        


        // Imprime os números gerados para a primeira coluna
        cout << "\n\nCartela " << i + 1 << ":\n";
        for (int d = 0; d < 5; d++) {
        	for(int c = 0; c < 5; c++){
        		if(atual->cartela[d][c] <= 9){
        			cout << "0"<< atual->cartela[d][c] << " ";
				} else{
					if(atual->cartela[d][c] == atual->cartela[2][2]){
						cout << "FE ";
					}else{
						cout << atual->cartela[d][c] << " ";
					}
					
				}
        		
			}
            cout << endl;
        }
        
        
     
	 
	 // Usando stringstream para converter número em string
    stringstream ss;
    ss << "cartela" << (i + 1) << ".txt";
    string nomeArquivo = ss.str();
	 
	 // Abrindo o arquivo em modo de escrita (será criado se não existir)
     arquivo.open(nomeArquivo.c_str());
    // Verificando se o arquivo foi aberto com sucesso
    if (arquivo.is_open()) {
        // Escrevendo dados no arquivo
        
        
        for (int d = 0; d < 5; d++) {
        	for(int c = 0; c < 5; c++){
        		if(atual->cartela[d][c] <= 9){
        			arquivo << "0"<< atual->cartela[d][c] << " ";
				} else{
					if(atual->cartela[d][c] == atual->cartela[2][2]){
						arquivo << "FE ";
					}else{
						arquivo << atual->cartela[d][c] << " ";
					}
					
				}
        		
			}
            arquivo << "\n";
        }
        

        // Fechando o arquivo
        arquivo.close();
    } else {
        cerr << "Erro ao abrir o arquivo!" << endl;
    }   
     
	 
	 
	 
	 atual->proxi = NULL; // Marca o final da lista
        anterior = atual;       // Atualiza o nó anterior
	 
	 
	 
	 
	 
	    
        
        
    }// fim for que cria todas as cartelas desejadas
    
    
    
    
    
    
    
    
    
    
    
    
    
    
   system("pause");
	
	
	
	
}// fim da função 






void mostraLista() {
    cartelaEstrutura *atual = inicio; // Ponteiro para percorrer a lista encadeada
    int contador = 1; // Para numerar as cartelas

    if (!atual) {
        cout << "Nenhuma cartela foi criada ainda.\n";
        system("pause");
        return;
    }

    while (atual) {
        cout << "\nCartela " << contador++ << ":\n";

        for (int linha = 0; linha < 5; linha++) {
            for (int coluna = 0; coluna < 5; coluna++) {
                if (coluna == 2 && linha == 2) {
                    cout << "FE "; // Espaço central da cartela
                } else {
                    cout << (atual->cartela[linha][coluna] < 10 ? "0" : "")
                         << atual->cartela[linha][coluna] << " ";
                }
            }
            cout << endl;
        }

        atual = atual->proxi; // Avança para o próximo nó
    }
    system("pause");
}















void jogo() {
    srand(time(0)); // Inicializa a semente com o tempo atual
    cartelaEstrutura *atual = inicio; // Ponteiro para percorrer a lista encadeada
    int contador = 1; // Para numerar as cartelas
    bool jogando = true;
    int i = 0;

    if (!atual) {
        cout << "Nenhuma cartela foi criada ainda.\n";
        return;
    }

    do {
        system("cls");
        cout << "===== -PARTIDA- =====";	
        atual = inicio;	

        // Mostra as cartelas para o usuário	
        while (atual) {
            cout << endl;

            for (int linha = 0; linha < 5; linha++) {
                for (int coluna = 0; coluna < 5; coluna++) {
                    if (coluna == 2 && linha == 2) {
                        cout << "FE "; // Espaço central da cartela
                    } else {
                        cout << (atual->cartela[linha][coluna] < 10 ? "0" : "")
                             << atual->cartela[linha][coluna] << " ";
                    }
                }
                cout << endl;
            }
cout << endl;
            atual = atual->proxi; // Avança para o próximo nó
        }

        // Descobre o tamanho do vetor
        int tamanho = sizeof(numerosChamados) / sizeof(numerosChamados[0]); // Tamanho do vetor	

        // Loop que percorre o vetor e exibe os números chamados
        //for (int a = 0; a < tamanho; a++) {
           // if (numerosChamados[a] == 0) {
              //  break; // Sai do loop quando encontrar o 0
           // }
           // cout << numerosChamados[a] << " "; // Exibe o número
       // }

        // Verifica se a coluna 1 está completa
        verLinhasEColunas();

        cout << "\nClique em qualquer letra para sortear um número";
        system("pause");

        // Gera um número aleatório não repetido
        int numeroSorteado;
        bool repetido;

        do {
            numeroSorteado = rand() % 75 + 1; // Sorteia um número de 1 a 75
            repetido = false;

            // Verifica se o número sorteado já foi chamado
            for (int b = 0; b < tamanho; b++) {
                if (numerosChamados[b] == numeroSorteado) {
                    repetido = true; // Marca como repetido se já estiver no vetor
                    break;
                }
            }
        } while (repetido); // Continua sorteando até encontrar um número não repetido

        // Adiciona o número sorteado ao vetor
        numerosChamados[i] = numeroSorteado;
        i++;

        // Aqui poderia haver uma verificação de vitória, caso você queira adicionar essa funcionalidade
        // if (verificarVitoria()) {
        //     jogando = false; // Finaliza o jogo caso alguém vença
        // }

    } while (jogando);
}



void verLinhasEColunas() {
    cartelaEstrutura* atual = inicio; // Ponteiro para percorrer a lista de cartelas
    int contadorCartela = 1;         // Contador para identificar cada cartela

    while (atual) {
        cout << "Cartela " << contadorCartela << ":\n";

        // Exibir os números já chamados
        cout << "Numeros chamados: ";
        for (int i = 0; i < 75; i++) {
            if (numerosChamados[i] != 0) {
                cout << numerosChamados[i] << " ";
            }
        }
        cout << endl;

        int numerosFaltando = 0; // Conta quantos números faltam para completar a cartela

        // Verificar colunas (1ª à 5ª)
        for (int coluna = 0; coluna < 5; coluna++) {
            cout << "Numeros na coluna " << coluna + 1 << " que foram chamados: ";
            bool colunaCompleta = true;
            for (int linha = 0; linha < 5; linha++) {
                int numero = atual->cartela[linha][coluna];
                bool encontrado = false;

                for (int j = 0; j < 75; j++) {
                    if (numerosChamados[j] == numero) {
                        encontrado = true;
                        cout << numero << " ";
                        break;
                    }
                }

                if (!encontrado) {
                    colunaCompleta = false;
                    numerosFaltando++;
                }
            }
            cout << endl;

            if (colunaCompleta) {
                cout << "COLUNA " << coluna + 1 << " COMPLETA!" << endl;
            }
        }

        cout << "---------------------------------\n";

        // Verificar linhas (1ª à 5ª)
        for (int linha = 0; linha < 5; linha++) {
            cout << "Numeros na linha " << linha + 1 << " que foram chamados: ";
            bool linhaCompleta = true;
            for (int coluna = 0; coluna < 5; coluna++) {
                int numero = atual->cartela[linha][coluna];
                bool encontrado = false;

                for (int j = 0; j < 75; j++) {
                    if (numerosChamados[j] == numero) {
                        encontrado = true;
                        cout << numero << " ";
                        break;
                    }
                }

                if (!encontrado) {
                    linhaCompleta = false;
                    numerosFaltando++;
                }
            }
            cout << endl;

            if (linhaCompleta) {
                cout << "LINHA " << linha + 1 << " COMPLETA!" << endl;
            }
        }

        // Verificar se a cartela está completa ou faltando apenas 1 número
        if (numerosFaltando == 0) {
            cout << "BINGO! A cartela " << contadorCartela << " foi completada!" << endl;
        } else if (numerosFaltando == 1) {
            cout << "OLHA A BOA! Falta apenas 1 número para completar a cartela " << contadorCartela << "!" << endl;
        }

        cout << "---------------------------------\n";

        atual = atual->proxi; // Avança para a próxima cartela
        contadorCartela++;    // Incrementa o número da cartela
    }
}

