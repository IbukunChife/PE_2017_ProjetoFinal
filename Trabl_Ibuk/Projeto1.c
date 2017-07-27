/*         								UNIVERSIDADE FEDERAL DE RORAIMA
									 DEPARTAMENTO DE CIENCIA DA COMPUTACAO
									  DISCIPLINA: PROGRAMACAO ESTRUTURADA
								    PROJETO FINAL DDE CONCLUSAO DA DISCILINA
									 ESTUDANTE: Ibukun Chife Didier Adjitche
									         MATRICULA: 2016030686
									              DATA: 22/07/2017

RESUMO DO PROJETO: o seguinte projeto tem como objectivo de armazenar os dados de cheque de diversos pessoas ou nao, e de retornar ao fim da
* exécuçao a soma total do saldo dum usuario ao digistar na busca nome o usario. para a sua concepçao foi utulisada
*  dois struct: Cheque e Lista.
*  dois arquivos txt. Informaçoes e Soma de modo binario.
*  oito funçoes: Cadastro, Valida, Ordenar,Armazenar, Ler,Imprimir,SomaChk e Busca  .
* uma funçao: main que coordena tudo o algoritmo.
 
 Cadastro : ela serve para cadastrar os dados quando o numero de conta è diferente de 0. Usei inclusive para cadastrar apenas o struct lista.
 Valida: retorna o ultino digito depois aa soma do Numero de conta e seu inverso e os calculo seguinte. se esse ultimo digito é igual ao 
 * disque verificador o cadastro sera valida caso contrario o usuario digite os dados novamente.
 Ordena: depois que o usuario digitar 0 . essa funcoes ordena as informacoes cadastradas do vetor de struct e da lista de nome.
 Armazenar: ela armazena os dados cadastrados no arquivo Information.txt depois a sua ordenaçao.
 ler:ela armazena os dados do arquivo Information.txt para memoria para seu uso.
 imprimir: funcoes para imprimir os dados da memorias depois a leitura do arquivo.
 SomaChk: ela soma os valores dos cheques por nome e os amazena no arquivo Soma.txt.
 Busca: ela primeiro abre o arquivo Soma.txt. pede para o usuario digitar o nome e procura o saldo do cliente.


o compilador utilisado é o GCC 4.6 do Ubunto.
* para compilar digitei o seguinte comando: gcc Projeto1.c -o Projeto1.exe
* para executar: ./Projeto1.exe

												Resoluçao:
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/* Numero do cheque = NuDoChK 
 * Agência = Ag
 * Numero da conta corrente = NuDaCCor
 * DV = DV
 * Nome = Nome
 * Valor = Valor
*/
typedef struct Cheque{
	int NuDoChK, Ag, NuDaCCor,DV;
	float Valor;
	char Nome[20];
	}Cheque;
	
typedef struct NomeList{
	char  Name[20];
	float SaldoTotal;
	}Lista;
	
int Buscar(Lista l[],int n){
	FILE *arq;
	char  E;
	char nome[20];
	int x;
	
	// abrindo o arquivo Soma.txt para a busca
	if ((arq = fopen("Soma.txt","rb")) == NULL){
		printf("Erro ao ler o arquivo \n");
		system("pause");
		return 0;
	}
	fread( l,sizeof(Lista),n,arq);
	fclose(arq);
	printf("As informacoes  de Soma por pessoa sao  lidas  com sucesso no arquivo binario Soma.txt\n");
	// pedindo o usuario digitar o nome para a busca do saldo.
	setbuf(stdin,NULL);
	printf ("Desejando procurar un nome no Banco de dados ?\n");
	printf (" Digite S: (SIM) ou N: (Nao) \n");
	scanf("%c",&E);
	while ( E == 'S'){
		printf("Digite o nome procurado\n");
		setbuf(stdin,NULL);
		scanf("%s",nome);
		setbuf(stdin,NULL);
		for(x=0;x<n;x++){
			if ( strcmp(nome,l[x].Name) == 0){
				printf("%s tem um saldo total de %.2f R$\n",l[x].Name,l[x].SaldoTotal);
				break;
			}
		}
	printf ("Continuando procurando informacoes no Banco de dados ?\n");
	printf (" Digite S: (SIM) ou N: (Nao) \n");
	scanf("%c",&E); 
		}
	return 0;
}

int SomaChk(Lista l[],Cheque P[],int n){
	FILE * arq;
	// azendo a soma dos valores de cheque por pessoa
	int x,y;
	for(x=0;x<n;x++){
		for(y=0;y<n;y++){
			if (strcmp(l[x].Name,P[y].Nome)==0){
				l[x].SaldoTotal += P[y].Valor;
				}
			}
		}
	// abrindo o arquivo Soma para inserir os dados.
	if ((arq = fopen("Soma.txt","wb")) == NULL){
		printf("Erro na abertura \n");
		system("pause");
		return 0;
	}
	fwrite( l,sizeof(Lista),n,arq);
	fclose(arq);
	printf("As informacoes  de Soma por pessoa sao gravadas com sucesso no arquivo binario Soma.txt\n");
	return 0;
}


void imprimir(Cheque P[],int n){
	// imprimindo para veriicar o cadastro dos dados validos
	int x=0;
	for (x=0;x<n;x++){
		printf(" 		Cheque N° %d     \n", x+1);
		printf("O nome do Client e: %s\n",P[x].Nome);
		printf("O valor o cheque e: %.2f R$.\n",P[x].Valor);
		printf("O numero da Conta corrente: %d\n",P[x].NuDaCCor);
		printf("O disco Verificador e: %d\n",P[x].DV);
		printf("A Agencia e: %d\n",P[x].Ag);
		printf("\n");
		}
}

int Ler(Cheque  P[],int n){
	FILE *arq;
	if ((arq = fopen("Information.txt","rb")) == NULL){
		printf("Erro ao ler o arquivo \n");
		system("pause");
		return 0;
	}
	fread( P,sizeof(Cheque),n,arq);
	fclose(arq);
	printf("As informacoes lidas com sucesso do arquivo binario\n");
	imprimir(P,n);
return 0;
}
	
int Armazenar(Cheque  P[],int n){
	FILE *arq;
	if ((arq = fopen("Information.txt","wb")) == NULL){
		printf("Erro na abertura \n");
		system("pause");
		return 0;
	}
	fwrite( P,sizeof(Cheque),n,arq);
	fclose(arq);
	printf("As informacoes gravadas com sucesso no arquivo binario\n");
return 0;
}


void Ordenar(Cheque P[],int n , Lista l[]){
	int x=0,y=0; Cheque aux; Lista au;
	//ordenaçao do arquivo cadastrado por cheque
	for(x=0;x<n;x++){
		for(y=0;y<n-1;y++){
			if(strcmp(P[y+1].Nome,P[x].Nome) <0){
				aux = P[y];
				P[y]=P[y+1];
				P[y+1] = aux;
				}
		 }
	}
	//ordenaçao da lista de nome simple.
	for(x=0;x<n;x++){
		for(y=0;y<n-1;y++){
			if(strcmp(l[y+1].Name,l[x].Name) <0){
				au = l[y];
				l[y]=l[y+1];
				l[y+1] = au;
				}
		 }
	}
}

int Valida(Cheque P[] ,int n ){ 
	int  nc= P[n].NuDaCCor , dv= P[n].DV ;
	int  i=0,j=0,x=0;
	int res =0 , resf=0,Inv=0;
	int copiaRes=0 , ultimD=0, copiaNc=0;
	int *v;
	
		copiaNc=nc;
		while (copiaNc!= 0){
			Inv = (Inv *10 )+ (copiaNc%10);
			copiaNc = copiaNc/10;
			}
		//  res = soma a conta com seu inverso
		res = nc + Inv;
		copiaRes = res;
		while (copiaRes != 0){
				copiaRes = copiaRes/10;
				i++;
				}
  
        v = (int *)malloc((i+1)*sizeof(int));
        for(x=i;x>0;x--){
				v[x]= (res%10)*x;
				res = res/10;
			}
			for(x=1;x<i+1;x++){
				resf += v[x];
			}
			free(v);
           ultimD= resf%10 ;
	return ultimD;
	}

Cheque Cadastro(Cheque P[], int n,Lista l[]){

	printf ("Digite a Agência\n");
	scanf("%d",&P[n].Ag );
	printf ("Digite o Numero da conta corrente\n");
	scanf("%d",&P[n].NuDaCCor );
	printf ("Digite o DV \n");
	scanf("%d",&P[n].DV);
	printf ("Digite o Nome\n");
	setbuf(stdin,NULL);
	gets(P[n].Nome);
	strcpy(l[n].Name,P[n].Nome);
	//strupr(P[n].Nome);
	setbuf(stdin,NULL);
	printf ("Digite o Valor\n");
	scanf("%f",&P[n].Valor);
}


int main(){
	int cont=1;
	int n=0;
	int ult;
	Cheque Pessoa[1000];
	Lista L[1000];
	printf ("Digite o Numero do cheque N°: %d \n",cont);
	scanf("%d", &Pessoa[n].NuDoChK);
	while( Pessoa[n].NuDoChK != 0 ){
		Cadastro(Pessoa,n,L);
		ult =Valida (Pessoa,n);
			if (ult == Pessoa[n].DV){ 
				printf("Cadastrado com sucesso!\n\n");
				cont++;
				n++;
				} else{
				printf("Digito verificador invalido\n\n");
					}
		printf ("Digite o Numero do cheque N° %d \n",cont);
		scanf("%d", &Pessoa[n].NuDoChK);
		}
	Ordenar(Pessoa,n,L);
	Armazenar(Pessoa,n);
	Ler(Pessoa,n);
	SomaChk(L,Pessoa,n);
	Buscar(L,n);
	return 0;
}						 
