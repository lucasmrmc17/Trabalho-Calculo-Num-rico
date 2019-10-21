#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double* dec2bin(double n);
double* dec2oct(double n);
double* dec2hex(double n);

int main(){
	char e;
	double a;
		
	while(e != 'F'){
		printf("Digite uma opcao:\nC - Conversao\nS - Sistema Linear\nE - Equacao Algebrica\nF - Finalizar\n");
		scanf("%c", &e);
		switch (e){
		
			case 'C': 
				printf("Digite um numero decimal:\n");
				scanf("%lf", &a);
				dec2bin(a);
				dec2oct(a);
				dec2hex(a);
				break;
			case 'S':
				printf("S\n");
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
	
	for(i=0; i<20; i++){
		vetor_fra[i] = 0;
	}
	
	for(i=0; i<20; i++){
		vetor_int[i] = 0;
	}
	
	// Parte fracionária do número
	parte_fra = n - (int)n;
	
	//Transformando a parte fracionária do número decimal para binário
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
