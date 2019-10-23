#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double* dec2bin(double n);
double* dec2oct(double n);
double* dec2hex(double n);
double **alocaMatriz(int L, int C);
void leMatriz(double **M, int L, int C);
void imprimeMatriz(double **M, int L, int C);
void Jordan(double **M, int N);

int main(){
	int num_variaveis;
	char escolha;
	double a, **Matriz, *X;
		
	while(escolha != 'F'){
		printf("Digite uma opcao:\nC - Conversao\nS - Sistema Linear\nE - Equacao Algebrica\nF - Finalizar\n");
		scanf("%c", &escolha);
		switch (escolha){
		
			case 'C': 
				printf("Digite um numero decimal:\n");
				scanf("%lf", &a);
				dec2bin(a);
				dec2oct(a);
				dec2hex(a);
				break;
				
			case 'S':
				printf("Digite a quantidade de variaveis:\n");
				scanf("%d", &num_variaveis);
				Matriz = alocaMatriz(num_variaveis, num_variaveis+1);
				X = malloc(sizeof(double)*num_variaveis);
				if(Matriz == NULL || X == NULL){ // Falta de memória
					printf("Deu Pau!!\nFalta de memoria\n");
					return 1;
				}
				leMatriz(Matriz, num_variaveis, num_variaveis+1);
				imprimeMatriz(Matriz, num_variaveis, num_variaveis+1);
				Jordan(Matriz, num_variaveis);
				printf("\n\n");
				imprimeMatriz(Matriz, num_variaveis, num_variaveis+1);
				break;
				
			case 'E':
				printf("E\n");
				break;
				
			case 'F':
				printf("Programa Encerrado\n");
				return 0;
		}
	}
}


double* dec2bin(double n){
	double parte_fra, a;
	a = n;
	int  i, c=0;
	int vetor_int[20], vetor_fra[20];
	
	/*Preenche os vetores da parte inteira e fracionaria da conversão dos bits com 0*/
	for(i=0; i<20; i++){
		vetor_fra[i] = 0;
	}
	
	for(i=0; i<20; i++){
		vetor_int[i] = 0;
	}
	
	// Parte fracionária do número
	parte_fra = n - (int)n;
	
	/*Transformando a parte fracionária do número decimal para binário*/
	int j=0;
	while(parte_fra!=0){
		parte_fra *= 2;
		c = (int)parte_fra;
		vetor_fra[j] = (int)parte_fra;
		parte_fra -=c;
		j++;
	}
	
	//Transformando a parte inteira do número decimal para binário
	for(i=0; i<19; i++){
		if(((int)n)%2 == 0){
			vetor_int[i] = 0;
			n = n/2;
		}
		else{
			vetor_int[i] = 1;
			n = n/2;
		}
	}
		
	// Printando o número binário
	printf("O binario do numero %lf e: ", a);
	for(i=19; i>=0; i--){
		if(i==0){
			printf("%d.", vetor_int[i]);
		}
		else{
			printf("%d", vetor_int[i]);
		}
	}
	
	for(i=0; i<20; i++){
		printf("%d", vetor_fra[i]);
	}
	printf("\n");	
}

double* dec2oct(double n){
	double parte_fra, a;
	a = n;
	int  i, c=0;
	int vetor_int[20], vetor_fra[20];
	
	for(i=0; i<20; i++){
		vetor_fra[i] = 0;
	}
	
	for(i=0; i<20; i++){
		vetor_int[i] = 0;
	}
	
	// Parte fracionária do número
	parte_fra = n - (int)n;
	
	//Transformando a parte fracionária do número decimal para octal
	int j=0;
	while(parte_fra!=0){
		parte_fra *= 8;
		c = (int)parte_fra;
		vetor_fra[j] = (int)parte_fra;
		parte_fra -=c;
		j++;
	}
	
	//Transformando a parte inteira do número decimal para octal
	for(i=0; i<19; i++){
		vetor_int[i] = (int)n%8;
		n = n/8;
	}
		
	// Printando o número octal
	printf("O octal   do numero %lf e: ", a);
	for(i=19; i>=0; i--){
		if(i==0){
			printf("%d.", vetor_int[i]);
		}
		else{
			printf("%d", vetor_int[i]);
		}
	}
	
	for(i=0; i<20; i++){
		printf("%d", vetor_fra[i]);
	}
	printf("\n");
}

double* dec2hex(double n){
	double parte_fra, a;
	a = n;
	int  i, c=0;
	int vetor_int[20], vetor_fra[20];
	
	for(i=0; i<20; i++){
		vetor_fra[i] = 0;
	}
	
	for(i=0; i<20; i++){
		vetor_int[i] = 0;
	}
	
	// Parte fracionária do número
	parte_fra = n - (int)n;
	
	//Transformando a parte fracionária do número decimal para hexadecimal
	int j=0;
	while(parte_fra!=0){
		parte_fra *= 16;
		c = (int)parte_fra;
		vetor_fra[j] = (int)parte_fra;
		parte_fra -=c;
		j++;
	}
	
	//Transformando a parte inteira do número decimal para hexadecimal
	for(i=0; i<19; i++){
		vetor_int[i] = (int)n%16;
		n = n/16;
	}	
		
	// Printando o número hexadecimal
	printf("O hexal   do numero %lf e: ", a);
	for(i=19; i>=0; i--){
		if(i==0){
			if(vetor_int[i]==10){
				printf("%c.", 65);
			}
			else if(vetor_int[i]==11){
				printf("%c.", 66);
			}
			else if(vetor_int[i]==12){
				printf("%c.", 67);
			}
			else if(vetor_int[i]==13){
				printf("%c.", 68);
			}
			else if(vetor_int[i]==14){
				printf("%c.", 69);
			}
			else if(vetor_int[i]==15){
				printf("%c.", 70);
			}
			else{
				printf("%d.", vetor_int[i]);
			}
		}
		else{
			if(vetor_int[i]==10){
				printf("%c", 65);
			}
			else if(vetor_int[i]==11){
				printf("%c", 66);
			}
			else if(vetor_int[i]==12){
				printf("%c", 67);
			}
			else if(vetor_int[i]==13){
				printf("%c", 68);
			}
			else if(vetor_int[i]==14){
				printf("%c", 69);
			}
			else if(vetor_int[i]==15){
				printf("%c", 70);
			}
			else{
				printf("%d", vetor_int[i]);
			}
		}
	}
	
	for(i=0; i<20; i++){
		if(vetor_fra[i]==10){
			printf("%c", 65);
		}
		else if(vetor_fra[i]==11){
			printf("%c", 66);
		}
		else if(vetor_fra[i]==12){
			printf("%c", 67);
		}
		else if(vetor_fra[i]==13){
			printf("%c", 68);
		}
		else if(vetor_fra[i]==14){
			printf("%c", 69);
		}
		else if(vetor_fra[i]==15){
			printf("%c", 70);
		}
		else{
			printf("%d", vetor_fra[i]);
		}
	}
	
	printf("\n");

}



double **alocaMatriz(int L, int C){
/* Se houver memoria disponivevl a função aloca uma matriz
bidimensional de double com L linhas e C colunas e devolve
um ponteiro para essa matriz; Caso contrário, devolve um
ponteiro nulo.*/

	double **M;
	int i, j;
	M = malloc(sizeof(M) * L);
	if (M == NULL){ // Falta de memória
		return NULL;
	}
	
	for(i = 0; i < L; i++){
		M[i] = malloc(sizeof(double) * C);
		
		if(M[i] == NULL){
			for(j = 0; j < i; j++){
				free(M[j]);
			}
			free(M);
			return NULL;
		}
		
	}
	return M;
} // Fim **AlocaMatriz

void leMatriz(double **M, int L, int C){
/* Lê valores para uma matriz de double, alocada dinâmicamente
com L linhas e C colunas. */

	int i, j;
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			printf("M[%d][%d]: ", i+1, j+1);
			scanf("%lf", &M[i][j]);
		}
	}
} // Fim LêMatriz

void imprimeMatriz(double **M, int L, int C){
/* Imprime uma matriz de double com L linhas e C colunas*/
	
	int i, j;
	for(i = 0; i < L; i++){
		for(j = 0; j < C; j++){
			printf("%10.4lf ", M[i][j]);
		}
		printf("\n");
	}
} // Fim imprimeMatriz



void Jordan(double **M, int N){
	int i, j, k, c;
	double mult_baixo, mult_cima, aux;
	int *x, aux2;
	x = (int *) malloc(sizeof(int) * N);
	
	for(i = 0; i < N; i++) {
		x[i] = i + 1;
	}
	
	for(i = 0; i< N-1; i++){
		if(M[i][i] == 0){ //Pivô sendo nulo
			c = i + 1;
			while(c < N && M[i][c] == 0){
				c++;
			}
					
			if(c < N){ // troca das colunas
				aux2 = x[i];
				x[i] = x[c];
				x[c] = aux2;
				for(j = 0 ; j < N; j++) {
					aux = M[j][i];
					M[j][i] = M[j][c];
					M[j][c] = aux;
				}
			}
		}
		
		
	}
}
