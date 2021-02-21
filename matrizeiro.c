/*
  Síntese
programador: "Luiz Araujo"
Objetivo: Fazer uma mistura de jogo da velha, batalha naval e campo minado.
data: 20/02/21 15:51
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//#include <conio2.h>
#include <ctype.h>
#include <windows.h>
//#include <time.h>

#define MAX 5

////PROTÓTIPOS
int leValidaPonto();
int inicioJogo(int tab[MAX][MAX]);
int apresentarTabuleiro(int tab[MAX][MAX], int x);
int menuDificuldade();

int main(void){
////DESCLARAÇÕES
	char nome[30], dificuldade;
	int acertos, total, axisX, axisY, linha, coluna, qtdJogadores, fim;
	int tabuleiro[MAX][MAX];
	total = axisX = axisY = linha = coluna = 0;
	
////INSTRUÇÕES	

	//MENU DE JOGADORES

	dificuldade = menuDificuldade();
	
	total = inicioJogo(tabuleiro);		//início jogo: distribuição no tabuleiro
	apresentarTabuleiro(tabuleiro, -1);
	
	//ENTRADAS
	//printf("INFORME O SEU NOME:");
	//gets(nome);	
	do{		
		printf("\nLINHA : ");
		axisX = leValidaPonto();
		apresentarTabuleiro(tabuleiro, axisX);
		
		printf("\nLINHA : %d\n", axisX);
		printf("COLUNA: ");
		axisY = leValidaPonto();
		
		if(tabuleiro[axisX][axisY] == 1){			
			//printf("\n\n");
			//printf("ACERTO MIZERAVI");
			//printf("\n\n");
			tabuleiro[axisX][axisY] = 9;	//escolhi esse num para ficar mais "visível"
		} 
		if(tabuleiro[axisX][axisY] == 0){			
			//printf("\n\n");
			//printf("EROU!");
			//printf("\n\n");
			tabuleiro[axisX][axisY] = 5;	//escolhi esse num para ficar mais "visível"
		}
		
		fim = apresentarTabuleiro(tabuleiro, -1);
	//}while ((x >= 0 && x <= (MAX - 1)) && (y >= 0 && y <= (MAX - 1)));
	}while (fim != 1);
	
	for(linha = 0; linha < MAX; linha++){
		for(coluna = 0; coluna < MAX; coluna++){
			if(tabuleiro[linha][coluna] == 9){
				acertos++;
			}
		}
	}
	
	apresentarTabuleiro(tabuleiro, -1);
	
//	system("PAUSE");
	return 0;
}

////FUNÇÕES

	//MENUS
int menuDificuldade(){
	int cont = 0, dif = 0;
	char caracter;
	
	//ainda estou implementando a dific
	do{
		if((cont == 0) || (cont == 2) || (cont == 5)){
			printf("\nSELECIONE A DIFICULDADE: ");
			printf("\n1 - FACIL");
			printf("\n2 - MEDIA");
			printf("\n3 - DIFICIL");
			printf("\nOPCAO: ");
		} else {
			printf("\nOPCAO INVALIDA: ");
		}
		do{
			fflush(stdin);
			scanf("%c", &caracter);
			if(!isdigit(caracter))
				printf("NUM INVALIDO: ");
		}while(!isdigit(caracter));
		dif = caracter - '0';		
	}while((dif < 1) || (dif > 3));
	
	return dif;
}

int inicioJogo(int tab[MAX][MAX]){
	int total = 0, linha, coluna;
	for(linha = 0; linha < MAX; linha++){
		for(coluna = 0; coluna < MAX; coluna++){
			tab[linha][coluna] = rand() % 2;
			if(tab[linha][coluna] == 1){
				total++;
			}
		}
	}
	return total;
}

int leValidaPonto(){
	char caracter;
	int ponto = 0, flag = 1;
		
	while(!isdigit(caracter)){
		fflush(stdin);
		scanf("%c", &caracter);
		if(!isdigit(caracter))
			printf("NUM INVALIDO: ");
	} 
	ponto = caracter - '0';		//atoi() não estava funfando: tempo de execução simplesmente acaba travando.
	//teste para ver se virou int
	//printf("\n\nTamanho da var caracter: %d\n\n", sizeof(caracter));
	//printf("\n\nTamanho da var ponto: %d\n\n", sizeof(ponto));
	//printf("\n\VALOR da var ponto: %d\n\n", (ponto));
	return ponto;
}
		
int apresentarTabuleiro(int tab[MAX][MAX], int x){
	int lin, col;
	int acertos = 0, erros = 0, restantes = 0;
	system("CLS");

	for(lin = 0; lin < MAX; lin++){
		for(col = 0; col < MAX; col++){
			if(tab[lin][col] == 1){
				restantes++;
			}
			if(tab[lin][col] == 9){
				acertos++;
			}
			if(tab[lin][col] == 5){
				erros++;
			}
		}
	}
	textcolor(WHITE);
	printf("ACERTOS: ");
	if(acertos == 0 && erros == 0){
		printf("0");
	} else if(acertos < erros){
		textcolor(RED);
		printf("%d", acertos);
	} else if(acertos > erros){
		textcolor(GREEN);
		printf("%d", acertos);
	} else if(acertos == erros){
		textcolor(YELLOW);
		printf("%d", acertos);
	} else {
		textcolor(WHITE);
		printf("%d", acertos);
	}
	
	textcolor(WHITE);
	printf("\nERROS  : ");
	if(acertos == 0 && erros == 0){
		printf("0");
	} else if(acertos > erros){
		textcolor(GREEN);
		printf("%d", erros);
	} else if(acertos < erros){
		textcolor(RED);
		printf("%d", erros);
	} else if(acertos == erros){
		textcolor(YELLOW);
		printf("%d", erros);
	} else {
		textcolor(WHITE);
		printf("%d", erros);
	}
	textcolor(WHITE);
	printf("\nFALTAM : ");
	if(restantes == 1){
		textcolor(RED);
		printf("1");
	} else if(restantes == 2){
		textcolor(YELLOW);
		printf("2");
	} else {
		textcolor(GREEN);
		printf("%d\n", restantes);
	}
	textcolor(WHITE);
		
	printf("\n");
//	tabuleiro em si
	printf("\n  ");
	for(lin = 0; lin < MAX; lin++){
		if(lin <= 9){
			printf(" ");
		}
		printf("%d", lin); 
	}
	printf("\n");
	
	for(lin = 0; lin < MAX; lin++){
		if(lin <= 9){
			printf(" ");
		}
		
		//mudar a cor da linha selecionada
		if(lin == x){
			textcolor(LIGHTGREEN);
		}
		printf("%d ", lin);		
		if(lin == x){
			textcolor(WHITE);
		}
		
		for(col = 0; col < MAX; col++){
			
			if((tab[lin][col] == 0) || (tab[lin][col] == 1)){
				textcolor(WHITE);
				printf("# ");
			} else if(tab[lin][col] == 9){
				textcolor(GREEN);
				printf("O ");
			} else {
				textcolor(RED);
				printf("X ", tab[lin][col]);
			}	
		}
		textcolor(WHITE);
		printf("\n");
	}
	if(restantes > 0){
		return 0;
	} else {
		printf("\n\n############ RESULTADO ############");
		if(acertos > erros){
			textcolor(GREEN);
			printf("\n\n  A SORTE ESTAVA DO SEU LADO...");
			printf("\n    PARABENS, VOCE GANHOU!!!");			
			textcolor(WHITE);
		} else if(acertos < erros) {		
			textcolor(RED);
			printf("\n\n   VIXE, VOCE PERDEU!!!");
			printf("\nMAIS SORTE DA PROXIMA VEZ...");		
			textcolor(WHITE);
		} else {		
			textcolor(YELLOW);
			printf("\n\nNAO PERDEU, MAS DEIXOU DE GANHAR...");
			printf("\n NAO ESTA BOM, MAS NAO ESTA RUIM.");		
			textcolor(WHITE);
		}
		printf("\n\n###################################\n\n\n");
		return 1;
	}
}

void textcolor(iColor){
    HANDLE hl = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    BOOL b = GetConsoleScreenBufferInfo(hl, &bufferInfo);
    bufferInfo.wAttributes &= 0x00F0;
    SetConsoleTextAttribute (hl, bufferInfo.wAttributes |= iColor);
}























