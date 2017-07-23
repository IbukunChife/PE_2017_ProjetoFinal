/*         								UNIVERSIDADE FEDERAL DE RORAIMA
									 DEPARTAMENTO DE CIENCIA DA COMPUTACAO
									  DISCIPLINA: PROGRAMACAO ESTRUTURADA
								    PROJETO FINAL DDE CONCLUSAO DA DISCILINA
									 ESTUDANTE: Ibukun Chife Didier Adjitche
									         MATRICULA: 2016030686
									              DATA: 22/07/2017
RESUMO DO PROJETO:






												Resoluçao:
*/
									  
#include<stdio.h>
#include<stdlib.h>

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
	
int Armazenar(Cheque  ***info){
	FILE *arq;
	if ((arq = fopen("Information.txt","w")) == NULL){
		printf("Erro na abertura \n");
		system("pause");
		exit(1);
	}
	fprintf( arq, " Nome: %s  Valor: %d \n",***infoNome, ***info.Valor);
	fprintf( arq, " Nome: %s  Valor: %d \n",***info.NuDaCCor, ***info.DV);
	fprintf( arq, " Nome: %s  Valor: %d \n",***info.NuDoChK, ***info.Ag);
	fprintf(arq, "\n");
	rewind(arq);
	fclose(arq);
	
return 0;
}

int Valida(int nc , int dv , Cheque **informacao ){ // nc = NuDaCCor e dv = DV
	int i=0,j=1,x=0,k=0;
	int Inv, res, resf;
	
		// contando o numero de digito de nc, i sendo o contador
		while (nc>=0){
			nc = nc/10;
			i++;
			}
		int Vet[i];
		// obtençao do inverso numa string
		for(x=0;x<i-1;x++){
			Vet[x]=(nc%10);
			nc = nc/10;
		}
		// conversao do string para int
		Inv = atoi(Vet);
		printf("inverso do nc: %d\n", Inv);
		//  res = soma a conta com seu inverso
		res = nc + Inv;
		printf("soma a conta com seu inverso: %d\n", res);
	
			// contando o digito do res, lembrando que o contador começa por 1
			while (res>=0){
				res = res/10;
				j++;
				}
			// Obtençao na ordem em String o valor de res 
			//  decaraçao do vetore ajudando a ter o res en string.
			// j+1 porque nos precisaremos do indico de posiçao  partir de 1
			int Vet1[j+1];
			for(x=j-1;x>0;x--){
				Vet1[x]= res%10;
				res = res/10;
			}
			for(x=1;x<j+1;x++){
				resf +=Vet1[x];
			}
			printf("resf é :%d",resf);
	
				//contando o numero de digito de resf
				while (resf>=0){
					resf = resf/10;
					k++;
					}
				int Vet2[k];
				for (x=k-1;x>=0;x++){
					Vet2[x]= (resf%10);
					resf = resf/10;
				}

				
	if (Vet[k-1] == dv){ printf("Validé\n");
			Armazenar(informacao);
		}
	
	}



Cheque Cadastro(Cheque *P){
	//printf ("Digite o Numero do cheque \n");
	//scanf("%d",(*P). );
	printf ("Digite a Agência \n");
	scanf("%d",&(*P).Ag );
	printf ("Digite o Numero da conta corrente \n");
	scanf("%d",&(*P).NuDaCCor );
	printf ("Digite o DV \n");
	scanf("%d",&(*P).DV);
	printf ("Digite o Nome \n");
	scanf("%s",&(*P).Nome[20]);
	printf ("Digite o Valor \n");
	scanf("%f",&(*P).Valor);
	Valida( (*P).NuDaCCor ,(*P).DV , P);
}




int main(){
	Cheque Pessoa;
	printf ("Digite o Numero do cheque \n");
	while((scanf("%d", &Pessoa.NuDoChK)) != 0){
		Cadastro(&Pessoa);
		printf ("Digite o Numero do cheque \n");
		}
		
	return 0;
}						 
