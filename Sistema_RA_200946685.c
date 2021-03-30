#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <ctype.h> //para usar o comando toupper(deixar maiúsculo).
#define TAMLINHA 57
#define ARQUIVO "arquivo.txt"

typedef struct cadastro CADASTRO;
struct cadastro{
	char titulo[41], nome[41], editora[41], edicao[31], isbn[12], tipo;
	int ano, quant, caixa;
};

void menu_principal();
void menucad0();
void menucad1();
void listarObras();
void listarLivros();
void listarRevistas();
void obrasCaixa();
void sair();
void gotoxy();   //permite posicionar o cursor na coluna X e linha Y.
void linhasup(); //cria borda superior.
void linhainf(); //cria borda inferior.
void laterais(); //cria bordas laterais.
void imprime_aluno(); //colaca cabeçalho com meus dados de aluno.

int main(){
	SetConsoleTitle ("Atividade MAPA"); //dá título para a janela do console.
	system("color 0E"); //cor de fundo preto(0) e cor da fonte amarelo(E) - hexadecimal.
	menu_principal();	
	return 0;	
}

void menu_principal(){
	char op;
	do{
		system("cls");
		imprime_aluno();
		printf("\n\n");
		linhasup();
		laterais(44, "\t\tSOFTWARE DE CONTROLE DA VANESSA");
		linhainf();
		linhasup();
		laterais(TAMLINHA, "  1 - CADASTRAR OBRA");
		laterais(TAMLINHA, "  2 - LISTAR TODAS AS OBRAS");
		laterais(TAMLINHA, "  3 - LISTAR TODOS OS LIVROS");
		laterais(TAMLINHA, "  4 - LISTAR TODAS AS REVISTAS");
		laterais(TAMLINHA, "  5 - LISTAR AS OBRAS POR CAIXA");
		laterais(TAMLINHA, "  6 - SAIR");
		linhainf();
		printf("\nDigite a opcao: ");
		scanf(" %c%*[^\n]", &op);
		switch (op){
			case '1':
			menucad0();
			break;
			case '2':
			listarObras();
			break;
			case '3':
			listarLivros();
			break;
			case '4':
			listarRevistas();
			break;
			case '5':
			obrasCaixa();
			break;
			case '6':
			sair();
			break;
			default:
			printf("\t\tOpcao invalida.");
			fflush (stdin);
			printf("\n\t\t");
			system("pause");
			menu_principal();
		}
	}while (op != '6');
}

void menucad0(){
	system("cls");
	char gravar;
	do{
		imprime_aluno();
		gotoxy(1, 5); printf("Deseja cadastrar uma obra [S/N] ? ");  
		scanf("%c", &gravar);
		if ((gravar=='s') || (gravar=='S')){
			imprime_aluno();
			menucad1();
		}

		if((gravar=='n') || (gravar=='N')){
			menu_principal();
		}

		if ((gravar!='n') || (gravar!='N') || (gravar!='s') || (gravar!='S')){
			system("cls");
			printf("\b \b");
		}
	}while((gravar!='n') || (gravar!='N') || (gravar!='s') || (gravar!='S'));
}

void menucad1(){

	FILE *arquivo;
	arquivo = fopen(ARQUIVO, "a+");
	if(arquivo == NULL){
		printf("O arquivo nao pode ser acessado.");
		getch();
		exit(1);
	}

	CADASTRO temp;

	system("cls");
	imprime_aluno();
	int linha = 6;
	int coluna = 0;

	gotoxy(coluna, linha); linhasup();
	gotoxy(coluna, linha+9); linhainf();
	gotoxy(coluna, linha+1); laterais(TAMLINHA, "TITULO DA OBRA: ");
	gotoxy(coluna, linha+2); laterais(TAMLINHA, "NOME DO AUTOR : ");
	gotoxy(coluna, linha+3); laterais(TAMLINHA, "EDITORA       : ");
	gotoxy(coluna, linha+4); laterais(TAMLINHA, "EDICAO        : ");
	gotoxy(coluna, linha+5); laterais(TAMLINHA, "ANO           : ");
	gotoxy(coluna, linha+6); laterais(TAMLINHA, "ISBN-10       : ");
	gotoxy(coluna, linha+7); laterais(TAMLINHA, "QUANTIDADE    : ");  
	gotoxy(coluna, linha+8); laterais(TAMLINHA, "CAIXA N.o     : ");
	do{
		gotoxy(coluna+1, linha-1); fflush (stdin); printf("Cadastrar [L]ivro [R]evista? "); 
		scanf("%c", &temp.tipo); gotoxy(coluna+30, linha-1); temp.tipo=toupper(temp.tipo); printf("%c", temp.tipo);
		if ((temp.tipo=='l') || (temp.tipo=='L') || (temp.tipo=='r') || (temp.tipo=='R')){
			gotoxy(coluna+17, linha+1); fflush (stdin); gets(temp.titulo); gotoxy(coluna+17, linha+1); printf(temp.titulo);
			gotoxy(coluna+17, linha+2); fflush (stdin); gets(temp.nome); gotoxy(coluna+17, linha+2); printf(temp.nome);
			gotoxy(coluna+17, linha+3); fflush (stdin); gets(temp.editora); gotoxy(coluna+17, linha+3); printf(temp.editora);
			gotoxy(coluna+17, linha+4); fflush (stdin); gets(temp.edicao); gotoxy(coluna+17, linha+4); printf(temp.edicao);
			gotoxy(coluna+17, linha+5); fflush (stdin); scanf("%d", &temp.ano); gotoxy(coluna+17, linha+5); printf("%d", temp.ano);
			gotoxy(coluna+17, linha+6); fflush (stdin); gets(temp.isbn); gotoxy(coluna+17, linha+6); printf(temp.isbn);
			gotoxy(coluna+17, linha+7); fflush (stdin); scanf("%d", &temp.quant); gotoxy(coluna+17, linha+7); printf("%d", temp.quant);
			gotoxy(coluna+17, linha+8); fflush (stdin); scanf("%d", &temp.caixa); gotoxy(coluna+17, linha+8); printf("%d", temp.caixa); 

			fwrite(&temp, sizeof(CADASTRO), 1, arquivo);
			gotoxy(coluna+6, linha+11); printf("\t\tDados gravados com sucesso!\n");

			fclose(arquivo);
			printf("\n\n");
			getch();
			menucad0();
		}
	}while((temp.tipo!='l') || (temp.tipo!='L') || (temp.tipo!='r') || (temp.tipo!='R')); 
}

void listarObras(){
  void cima(){
  int i;
  printf("%c", 218);
  for(i=0;i<TAMLINHA;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }
  void baixo(){
  int j;
  printf("%c", 192);
  for(j=0;j<TAMLINHA;j++)
  printf("%c", 196);
  printf("%c", 217);		
}	
  void item(){
  int i;
  printf("%c", 218);
  for(i=0;i<4;i++)
  printf("%c", 196);
  printf("%c\n", 191);
}

	FILE *arquivo;
	arquivo = fopen(ARQUIVO, "r");

	CADASTRO temp;

	system("cls");
	imprime_aluno();
	printf("\n");

	if(arquivo == NULL){
		printf("O arquivo nao pode ser acessado.");
		getch();
		exit(1);
	}else{
		while(fread(&temp, sizeof(CADASTRO), 1, arquivo)==1){
			item();
			printf("%cItem%c\n", 179, 179);
			cima();
			printf(" [%c] TITULO: %s  \n\n     AUTOR:  %s ", temp.tipo, temp.titulo, temp.nome);
			printf("\n\n EDITORA: %s  \n EDICAO:  %s \n ISBN: %s", temp.editora, temp.edicao, temp.isbn);
			printf("\n ANO: %d  \t\t QUANT: %d \t\t CAIXA: %d \n", temp.ano, temp.quant, temp.caixa);
			baixo();
			printf("\n\n");
		}
	}
	fclose(arquivo);
	system("pause");
}

void listarLivros(){
  void cima(){
  int i;
  printf("%c", 218);
  for(i=0;i<TAMLINHA;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }		
  void baixo(){
  int j;
  printf("%c", 192);
  for(j=0;j<TAMLINHA;j++)
  printf("%c", 196);
  printf("%c", 217);
 }			
  void item(){
  int i;
  printf("%c", 218);
  for(i=0;i<4;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }
	
	FILE *arquivo;
	arquivo = fopen(ARQUIVO, "r");

	CADASTRO temp;
	char livro = 'L';
	
	system("cls");
	imprime_aluno();
	printf("\n");

	if(arquivo == NULL){
		printf("O arquivo nao pode ser acessado.");
		getch();
		exit(1);
	}else{
		while(fread(&temp, sizeof(CADASTRO), 1, arquivo)==1){
			if(livro == temp.tipo){
				item();
				printf("%cItem%c\n", 179, 179);
				cima();
				printf(" [%c] TITULO: %s  \n\n     AUTOR:  %s ", temp.tipo, temp.titulo, temp.nome);
				printf("\n\n EDITORA: %s  \n EDICAO:  %s \n ISBN: %s", temp.editora, temp.edicao, temp.isbn);
				printf("\n ANO: %d  \t\t QUANT: %d \t\t CAIXA: %d \n", temp.ano, temp.quant, temp.caixa);
				baixo();
				printf("\n\n");
			}
		}
	}
	fclose(arquivo);
	system("pause");
}

void listarRevistas(){
  void cima(){
  int i;
  printf("%c", 218);
  for(i=0;i<TAMLINHA;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }		
  void baixo(){
  int j;
  printf("%c", 192);
  for(j=0;j<TAMLINHA;j++)
  printf("%c", 196);
  printf("%c", 217);
 }			
  void item(){
  int i;
  printf("%c", 218);
  for(i=0;i<4;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }
	
	FILE *arquivo;
	arquivo = fopen(ARQUIVO, "r");

	CADASTRO temp;
	char revista = 'R';
	
	system("cls");
	imprime_aluno();
	printf("\n");

	if(arquivo == NULL){
		printf("O arquivo nao pode ser acessado.");
		getch();
		exit(1);
	}else{
		while(fread(&temp, sizeof(CADASTRO), 1, arquivo)==1){
			if(revista == temp.tipo){
				item();
				printf("%cItem%c\n", 179, 179);
				cima();
				printf(" [%c] TITULO: %s  \n\n     AUTOR:  %s ", temp.tipo, temp.titulo, temp.nome);
				printf("\n\n EDITORA: %s  \n EDICAO:  %s \n ISBN: %s", temp.editora, temp.edicao, temp.isbn);
				printf("\n ANO: %d  \t\t QUANT: %d \t\t CAIXA: %d \n", temp.ano, temp.quant, temp.caixa);
				baixo();
				printf("\n\n");
			}
		}
	}
	fclose(arquivo);
	system("pause");
}

void obrasCaixa(){
  void cima(){
  int i;
  printf("%c", 218);
  for(i=0;i<TAMLINHA;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }		
  void baixo(){
  int j;
  printf("%c", 192);
  for(j=0;j<TAMLINHA;j++)
  printf("%c", 196);
  printf("%c", 217);
 }			
  void item(){
  int i;
  printf("%c", 218);
  for(i=0;i<4;i++)
  printf("%c", 196);
  printf("%c\n", 191);
 }

  system("cls");
  imprime_aluno();
  int c;
  printf("\n Digite o numero da caixa: ");
  scanf("%d", &c);

	FILE *arquivo;
	arquivo = fopen(ARQUIVO, "r");

	CADASTRO temp;
	char achou = 'f';
	
	if(arquivo == NULL){
		printf("O arquivo nao pode ser acessado.");
		getch();
		exit(1);
	}else{
		while(fread(&temp, sizeof(CADASTRO), 1, arquivo)==1){
			if(c == temp.caixa){
				item();
				printf("%cItem%c\n", 179, 179);
				cima();
				printf(" [%c] TITULO: %s  \n\n     AUTOR:  %s ", temp.tipo, temp.titulo, temp.nome);
				printf("\n\n EDITORA: %s  \n EDICAO:  %s \n ISBN: %s", temp.editora, temp.edicao, temp.isbn);
				printf("\n ANO: %d  \t\t QUANT: %d \t\t CAIXA: %d \n", temp.ano, temp.quant, temp.caixa);
				baixo();
				printf("\n\n");
				achou = 'v';
			}
		}
		if (achou != 'v') printf ("\n Caixa nao cadastrada.\n\n\n");
	}
	fclose(arquivo);
	system("pause");
}

void sair(){
	//system("cls");
	printf("\t\tLOGOFF");
	int i;
	for (i=3; i>=0; i--){
		Sleep(1000);
		printf("\n\t\tSaindo...%d", i);
	}
	exit(0);
}

void gotoxy(int x, int y){
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void linhasup(){
	int i;
	printf("%c", 201);
	for(i=0;i<TAMLINHA;i++)
	printf("%c", 205);
	printf("%c\n", 187);
}

void linhainf(){
	int i;
	printf("%c", 200);
	for(i=0;i<TAMLINHA;i++)
	printf("%c", 205);
	printf("%c\n", 188);			
}

void laterais(int tamX, char str[]){

	int contaletras=0;
	int i;

	for(i=0;i<tamX;i++){
		if(str[i]=='\0')
		break;
		else
		contaletras++;
	}

	printf("%c", 186);
	printf("%s", str);
	while(contaletras<tamX){
		printf("%c", 32);
		contaletras++;
	}
	printf("%c\n", 186);	

}

void imprime_aluno(void){
	printf("**********************************************************\n");   
	printf("*Ricardo Meyer Viaro -Engenharia de Software- RA200946685*\n");
	printf("**********************************************************\n");
}
