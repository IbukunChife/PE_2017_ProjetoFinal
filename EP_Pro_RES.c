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
/*
int Armazenar(Cheque  *info){
	FILE *arq;
	if ((arq = fopen("Information.txt","wb")) == NULL){
		printf("Erro na abertura \n");
		system("pause");
		exit(1);
	}
	fprintf( arq, " Nome: %s  Valor: %d \n",info->Nome, info->Valor);
	fprintf( arq, " Nome: %s  Valor: %d \n",info->NuDaCCor, info->DV);
	fprintf( arq, " Nome: %s  Valor: %d \n",info->NuDoChK, info->Ag);
	fprintf(arq, "\n");
	rewind(arq);
	fclose(arq);

return 0;
}*/

int Valida(int nc , int dv ){ // nc = NuDaCCor e dv = DV

    int copiaNc = nc;
    int copiaRes , copiarResf;
	int i=1,j=0,x=0,k=0;
	int Inv=0, res , resf;

		// Obtendo o valor inverso do nc veno como um string Ex: nc=205 inv= 502
		while (nc!=0){
			Inv = (Inv *10 )+ (copiaNc%10);
			copiaNc = copiaNc/10;
			}
		printf("inverso do nc: %d\n", Inv);

	/*	//  res = soma a conta com seu inverso
		res = nc + Inv;
		printf("soma a conta com seu inverso: %d\n", res);
        copiaRes = res;

		// contando o digito do res usando a sua copia, lembrando que o contador começa por 1
			while (copiaRes>=0){
				copiaRes = copiaRes/10;
				i++;
				}
            printf("%d\n", copiaRes);
			// Obtençao na ordem em String o valor de res
			//  decaraçao do vetore ajudando a ter o res en string.
		// i+1 porque nos precisaremos do indico de posiçao  partir de 1
			int Vet[i+1];
			for(x=i;x>0;x--){
				Vet[x]= (res%10)*x;
				res = res/10;
			}
			for(x=1;x<i+1;x++){
				resf += Vet[x];
			}
			printf("resf eh: %d",resf);
            copiarResf = resf;
				//contando o numero de digito de resf

				while (copiarResf>=0){
					copiarResf = copiarResf/10;
					j++;
					}
				int Vet1[j];
				for (x=j-1;x>=0;x++){
					Vet1[x]= (resf%10);
					resf = resf/10;
				}

            if (Vet[j-1] != dv){
                   return 1;
                }
        return 0;*/
	}



Cheque Cadastro(Cheque *P){
    int Val;
	//printf ("Digite o Numero do cheque \n");
	//scanf("%d",(*P). );
	printf ("Digite a AgEncia \n");
	scanf("%d",&P->Ag );
	printf ("Digite o Numero da conta corrente \n");
	scanf("%d",&P->NuDaCCor );
	printf ("Digite o DV \n");
	scanf("%d",&P->DV);
	printf ("Digite o Nome \n");
	scanf("%s",&P->Nome[20]);
	printf ("Digite o Valor \n");
	scanf("%f",&P->Valor);
    Valida(P->NuDaCCor,P->DV );

	/*if ( (Valida( P->NuDaCCor ,P->DV )) == 0){
            printf("validado");
        Armazenar(P);
	}*/
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
