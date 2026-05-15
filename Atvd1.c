/* Daniel Martins Ciriaco Nicoli RA:25254073-2
    ESOFT 3S NB

1. Faca um programa que implemente a sequencia de Fibonacci de forma recursiva 
sem otimização. O programa deve receber um valor `n`, calcular o termo
correspondente, e exibir tambem a quantidade total de chamadas recursivas
realizadas para evidenciar a ineficiencia do metodo.

2. Refaça o problema anterior usando memoizacao com alocacao dinamica.
O programa deve preservar a solucao recursiva, armazenar resultados ja calculados
e comparar a quantidade de chamadas da versao otimizada com a versao ingênua para 
o mesmo `n`.

3. Faca um programa que resolva o problema das Torres de Hanoi de forma recursiva. 
O programa deve receber a quantidade de discos, listar os movimentos executados 
e informar o numero total de movimentos gerados pela solucao.
*/

#include <stdio.h>

long long chamadas=0;
long long Fibonacci (int n){
    chamadas ++;

    if (n==0)
    return 0;
    if(n==1)
    return 1;

    return Fibonacci(n-1)+ Fibonacci(n-2);
}
int main(){
    int n;
    long long resultado;

    printf("Digite um valor de n:");
    scanf("%d",&n);

    if (n<0){
        printf("N tem que ser maior que 0 seu animal\n");
        return 1;
    }
   resultado =Fibonacci(n);

   printf("Resultado do fibonacci de %d = %lld\n",n,resultado);
   printf("Numero de chamadas= %lld",chamadas);

   return 0;
}

/*
#include <stdio.h>
#include <stdlib.h>


long long chamadasMemo = 0;

long long FibonacciMemo(int n, long long memo[]) {
    chamadasMemo++;

    if (memo[n] != -1) {
        return memo[n];
    }

    if (n == 0) {
        memo[n] = 0;
    } else if (n == 1) {
        memo[n] = 1;
    } else {
        memo[n] = FibonacciMemo(n - 1, memo) + FibonacciMemo(n - 2, memo);
    }

    return memo[n];
}

int main() {
    int n;
    long long resultado;
    long long *memo;

    printf("Digite um valor de n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Erro: n deve ser maior ou igual a 0.\n");
        return 1;
    }

    memo = malloc((n + 1) * sizeof(long long));

    if (memo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    for (int i = 0; i <= n; i++) {
        memo[i] = -1;
    }

    resultado = FibonacciMemo(n, memo);

    printf("Resultado do Fibonacci de %d = %lld\n", n, resultado);
    printf("Numero de chamadas com memoizacao = %lld\n", chamadasMemo);

    free(memo);

    return 0;
}
    */
  /*
     #include <stdio.h>

long long movimentos = 0;

void hanoi(int discos, char origem, char destino, char auxiliar) {
    if (discos == 1) {
        movimentos++;
        printf("Mover disco 1 de %c para %c\n", origem, destino);
        return;
    }

    hanoi(discos - 1, origem, auxiliar, destino);

    movimentos++;
    printf("Mover disco %d de %c para %c\n", discos, origem, destino);

    hanoi(discos - 1, auxiliar, destino, origem);
}

int main() {
    int discos;

    printf("Digite a quantidade de discos: ");
    scanf("%d", &discos);

    if (discos <= 0) {
        printf("Erro: a quantidade de discos deve ser maior que 0.\n");
        return 1;
    }

    printf("\nMovimentos das Torres de Hanoi:\n\n");

    hanoi(discos, 'A', 'C', 'B');

    printf("\nTotal de movimentos: %lld\n", movimentos);

    return 0;
}
   */