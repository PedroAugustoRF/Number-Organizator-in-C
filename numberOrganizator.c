#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdbool.h>
#define TAM 5

int arranjo[TAM] = {0};

bool arranjoVazio(void){ // função para verificar o conteúdo do array:
	bool arranjoVazio = false;

	for(int i = 0; i < TAM; i++){
        if(arranjo[i] != 0){
        	arranjoVazio = false;
        }
        else{
        	arranjoVazio = true;
            }
        }
        
    return arranjoVazio;
}

void imprimirMenu(void){ // função para imprimir o menu de opções:
	printf("\n(01) Listar todos os numeros contidos no array\n");
    printf("(02) Listar somente os números pares\n");
    printf("(03) Listar somente os números ímpares\n");
    printf("(04) Listar somente os números primos\n");
	printf("(05) Calcular e imprimir o somatório de todos os números\n");
    printf("(06) Calcular e imprimir a média aritmética de todos os números\n");    
	printf("(07) Imprimir a quantidade de números iguais a um dado número\n");
    printf("(08) Imprimir a primeira ocorrência de um dado número do array\n");
    printf("(09) Imprimir a última ocorrência de um dado número do array\n");
    printf("(10) Imprimir o maior número contido no array\n");
    printf("(11) Imprimir o menor número contido no array\n");
    printf("(12) Gerar novos números para o array\n");
    printf("(00) Finalizar o programa\n");
}

int escolherOpcao(void){ // função usada no case 0 e no main:
	int caso = 0;

	printf("\nQual opcao voce deseja?\n");
	scanf("%d", &caso);

	return caso;
}

void listarNumeros(void){ // função do case 1:
	bool vazio = false;
	int indice = 0, orientacao = 0;

	for(int i = 0; i < TAM; i++){
        if(arranjo[i] == 0){
            vazio = true;
        }
	}
	if(vazio){
        printf("\nO arranjo está vazio, para preenche-lo digite (12)!\n\n");
    }
    else{
        printf("Como você quer listar o arranjo?\n");
        printf("(01)Com índice\n");
        printf("(02)Sem índice\n");
        scanf("%d", &indice);

        if(indice == 1){
            printf("(01)Na vertical\n");
            printf("(02)Na horizontal\n");
            scanf("%d", &orientacao);

            if(orientacao == 1){
                for(int i = 0; i < TAM; i++){
                printf("Posição [%d]: %d \n", i, arranjo[i]);//vertical c/ índice
                }
            }
            else if(orientacao == 2){
                for(int i = 0; i < TAM; i++){
                printf("[%d]: %d. ", i, arranjo[i]);//horizontal c/ índice
                }
            }
        }
        else if(indice == 2){
            printf("(01)Na vertical\n");
            printf("(02)Na horizontal\n");
            scanf("%d", &orientacao);

            if(orientacao == 1){
                for(int i = 0; i < TAM; i++){
                printf("Número: %d \n", arranjo[i]);//vertical s/ índice
                }
            }
            else if(orientacao == 2){
                for(int i = 0; i < TAM; i++){
                printf("[%d] ", arranjo[i]);//horizontal s/ índice
                }
            }
        }
    }
}

bool isPar(int num){ //substituir logica da 2
	bool ePar = false;
	
	for(int i = 0; i < TAM; i++){
		if(num % 2 == 0){
			ePar = true;
		}	
	}
	return ePar;
}

void imprimirPares(void){ // função do case 2:
    for(int i = 0; i < TAM; i++){
        if(isPar(arranjo[i])){
            printf("\nOs valores pares dentro do arranjo em ordem são: [%d] %d\n", i, arranjo[i]);
        }
    }
}

bool isNotPar(int num){ //substituir logica da 3
	bool eImpar = false;
	for(int i = 0; i < TAM; i++){
		if(num % 2 != 0){
			eImpar = true;
		}	
	}
	return eImpar;
}

void imprimirImpares(void){ // função do case 3:
    for(int i = 0; i < TAM; i++){
        if(isNotPar(arranjo[i])){
            printf("\nOs valores ímpares dentro do arranjo em ordem são: [%d] %d\n", i, arranjo[i]);
        }
    }
}

void acharPrimos(void){ // função do case 4**:
    for(int i = 0; i < TAM; i++){
        int num = arranjo[i];
        bool ePrimo = true;

        if(num < 2){
            ePrimo = false; // se num for menor que 2 não é primo.
        }
        else{
            for(int j = 2; j <= num / 2; j++){
                if(num % j == 0){
                    ePrimo = false; // se num for divisivel por um numero entre 2 e ele mesmo / 2, não é primo.
                }
            }
        }
        if(ePrimo){
            printf("\nO número %d, que está na posição [%d] do arranjo é primo\n", num, i);
        }
    }
}

void somarValoresArranjo(void){ // função do case 5:
    int somatorio = 0;

    for(int i = 0; i < TAM; i++){
        somatorio += arranjo[i];
    }
    printf("\nA soma dos valores do arranjo é: %d\n", somatorio);

}

void calcularMediaArranjo(void){ // função do case 6:
    int somatorio = 0;
    float media = 0;

    for(int i = 0; i < TAM; i++){
        somatorio += arranjo[i];
    }
    media = (float)somatorio / TAM;

    printf("\nA média dos valores do arranjo é: %d/%d: %.2f\n", somatorio, TAM, media);

}

void contarNumerosRepetidos(void){ // função do case 7***:
    int numero = 0, contador = 0;

    printf("Qual valor você quer ver se repetiu?\n");
    scanf("%d", &numero);

    for(int i = 0; i < TAM; i++){
        if (arranjo[i] == numero){
            contador++;
        }
    }
    printf("\nNo arranjo o número %d se repete %d vezes\n", numero, contador);
}

void imprimirPrimeiraOcorrencia(void){ // função do case 8***:
    int numero = 0, primeiraPosicao = -1;

    printf("Qual numero você quer ver a primeira ocorrência?\n");
    scanf("%d", &numero);

    for(int i = 0; i < TAM; i++){
        if(arranjo[i] == numero && primeiraPosicao == -1){
            primeiraPosicao = i;
        }
    }
    if(primeiraPosicao != -1){
        printf("O número %d, aparece pela primeira vez na posição: [%d]", numero, primeiraPosicao);
    }
    else{
        printf("\nEsse valor não está dentro do arranjo\n");
    }
}

void imprimirUltimaOcorrencia(void){ // função do case 9***:
    int numero = 0, ultimaPosicao = -1;

    printf("Qual numero você quer ver a última ocorrência?\n");
    scanf("%d", &numero);

    for(int i = 0; i < TAM; i++){
        if(arranjo[i] ==  numero){
            ultimaPosicao = i;
        }
    }
    if(ultimaPosicao != -1){
        printf("O número %d, aparece pela ultima vez na posição: [%d]", numero, ultimaPosicao);
    }
    else{
        printf("\nEsse valor não está dentro do arranjo\n");
    }
}

void imprimirMaiorNumero(){ // função do case 10:
    int maiorNumero = arranjo[0];

    for(int i = 0; i < TAM; i++){
        if(arranjo[i] > maiorNumero)
            maiorNumero = arranjo[i];
    }
    printf("\nO maior número do arranjo é: %d\n", maiorNumero);
}

void imprimirMenorNumero(void){ // função do case 11:
    int menorNumero = arranjo[0];

    for(int i = 0; i < TAM; i++){
        if(menorNumero < arranjo[i]);
        	menorNumero = arranjo[i];
    }
    printf("\nO menor número do arranjo é: %d\n", menorNumero);
}

void preencherArranjo(void){ // função do case 12:
	int numUm = 0, numDois = 0;
	bool flag = false;

	do{
		printf("\nDigite um valor inteiro (Esse valor deve ser menor o que proximo!)\n");
		scanf("%d", &numUm);
		printf("\nDigite outro valor inteiro (Esse valor deve ser maior o que anterior!)\n");
		scanf("%d", &numDois);

		if(numUm >= numDois){
			printf("\nO primeiro valor não pode ser maior ou igual o segundo, digite de novo!\n\n\n");
			flag = true;
			}
		}while(false);

		srand(time(NULL));

		for(int i = 0; i < TAM; i++){
            arranjo[i] = rand()%(numDois - numUm + 1) + numUm;
		}
		printf("\nArranjo preenchido!\n");
}

int main(void){
	setlocale(LC_ALL, "Portuguese");
	int caso = 0;

	do{
        imprimirMenu();
		caso = escolherOpcao();
		if(caso > 0 && caso < 12 && arranjoVazio()){
			printf("Array vazio!\n");
		}
		else{
			switch(caso){
				case 1: listarNumeros(); break;
				case 2: imprimirPares(); break;
				case 3: imprimirImpares(); break;
				case 4: acharPrimos(); break;
				case 5: somarValoresArranjo(); break;
				case 6: calcularMediaArranjo(); break;
				case 7: contarNumerosRepetidos(); break;
				case 8: imprimirPrimeiraOcorrencia(); break;
				case 9: imprimirUltimaOcorrencia(); break;
				case 10: imprimirMaiorNumero(); break;
				case 11: imprimirMenorNumero(); break;
				case 12: preencherArranjo(); break;
				case 0: printf("Programa encerrado!\n"); break;
				default: printf("\nDigite um valor válido!\n");
			}
		}
	}while(caso != 0);
	return 0;
}
