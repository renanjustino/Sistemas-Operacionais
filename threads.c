
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void DesenhaLinha(int n){
    int i;
    for(i=0;i<n;i++){
        printf("-");
    }
    printf("\n");
}

void printaEstado (char thread[20]){
    printf("THREAD no estado %s \n", thread);
}

int main() {
    int repete=0;
    int n;
    int i;
    int tipo;
    MENU:
    printf("\n");
    printf("--- MENU de THREADS, digite um dos numeros  ---\n");
    printf("--- Digite 1 para comportamento com MUTEX   ---\n");
    printf("--- Digite 2 para comportamento sem MUTEX   ---\n");
    printf("--- Digite 3 para DESENHO de SINGLE-THREADS ---\n");
    printf("--- Digite 4 para DESENHO de MULTITHREADS   ---\n");
    printf("--- Digite 5 para simular ESTADOS de THREAD ---\n");
    printf("\n");
    scanf("%d", &tipo);
    while(tipo !=1 && tipo !=2 && tipo !=3 && tipo !=4 && tipo !=5){
        printf("--- INVALIDO! ---\n");
    printf("--- Digite 1 para comportamento com MUTEX   ---\n");
    printf("--- Digite 2 para comportamento sem MUTEX   ---\n");
    printf("--- Digite 3 para DESENHO de SINGLE-THREADS ---\n");
    printf("--- Digite 4 para DESENHO de MULTITHREADS   ---\n");
    printf("--- Digite 5 para simular ESTADOS de THREAD ---\n");
        scanf("%d", &tipo);
        printf("\n");
    }
    if(tipo == 1){
    printf("--- Digite quantas threads quer criar: ");
    scanf("%d", &n);
    int *v = (int *)malloc(n*sizeof(int));
        printf("Threads Sem Concorrência \n");
    for (i=1;i<=n;i++){
        v[i] = i;
        printf("Thread acessa a variável %d \n", v[i]);
    }
    printf("Fim do programa! \n");
    printf("\n");
    }
    else if (tipo==2){
    printf("--- Digite quantas threads quer criar: ");
    scanf("%d", &n);
    int *v = (int *)malloc(n*sizeof(int));
        if (n==2){
            v[0] = 1;
            v[1] = 1;
               for (i = 0; i < n; i++)
  {
    printf("Thread acessa a variável %d \n", v[i]);

  }
        }
        if (n==3){
            v[0] = 2;
            v[1] = 2;
            v[2] = 3;
               for (i = 0; i < n; i++)
  {
    printf("Thread acessa a variável %d \n", v[i]);

  }
    printf("Fim do programa! \n");
        printf("\n");
        }
        else if(n>3){
            srand(time(NULL));
            printf("Threads Concorrendo \n");
 for (i = 0; i < n; i++)
  {
    v[i] = rand()%(((n+1)-1)) + 1;

  }

   for (i = 0; i < n; i++)
  {
    printf("Thread acessa a variável %d \n", v[i]);

  }
    }
        printf("Fim do programa! \n");
        printf("\n");
    }
    else if (tipo==3){
           DesenhaLinha(25);
    printf("|code|  |data|  |files| |\n");
    printf("|registers|   |stack|   |\n");
    DesenhaLinha(25);
    printf("|   DESENHO DA THREAD   |\n");
    printf("|          (            |\n");
    printf("|           |           |\n");
    printf("|            )          |\n");
    printf("|          (            |\n");
    printf("|           |           |\n");
    printf("|            )          |\n");
    printf("|     SINGLE-THREAD     |\n");
    DesenhaLinha(25);
    printf("Fim do programa! \n");
    printf("\n");
    }
    else if (tipo==4){
           DesenhaLinha(38);
    printf("|   code  | |data     | |files|     |\n");
    printf("|registers| |registers| |registers| |\n");
    printf("|  stack  | |  stack  | |  stack  | |\n");
    DesenhaLinha(38);
    printf("|   (     |     (      |       (    |\n");
    printf("|    |    |      |     |        |   |\n");
    printf("|     )   |       )    |         )  |\n");
    printf("|   (     |     (      |       (    |\n");
    printf("|    |    |      |     |        |   |\n");
    printf("|     )   |       )    |         )  |\n");
    printf("|            MULTITHREADS           |\n");
    DesenhaLinha(38);
    printf("Fim do programa! \n");
    printf("\n");
    }
    else if (tipo==5){
        int cria=0;
    int op=0;
    int altera=0;
    char thread[20];
    printf("THREADS \n");
    printf("Digite 1 para criar a thread: ");
    scanf("%d", &cria);
    while(cria!=1){
    printf("Opcao invalida! \n");
    printf("\n");
    printf("Digite 1 para criar a thread: ");
    scanf("%d", &cria);
    }
    printf("\n");
    if(cria==1){
        strcpy(thread,"nova");
        printaEstado(thread);
    }
    printf("\n");
    do {
    ini:
    printf("Deseja alterar o estado? 1 para sim, 2 para nao \n");
    scanf("%d", &altera);
    printf("\n");
    if(altera==1 && (strcmp(thread, "nova")==0)){
    strcpy(thread, "executando");
    printaEstado(thread);
    goto ini;
    }
    if(altera==1 && (strcmp(thread, "executando")==0)){
    executando:
    printf("Deseja bloquear ou finalizar? \n");
    printf("1 para bloquear \n");
    printf("2 para finalizar \n");
    scanf("%d", &op);
    printf("\n");
    if(op==1){
    strcpy(thread, "bloqueado");
    printaEstado(thread);
    goto ini;
    }
    if(op==2){
    strcpy(thread, "morta");
    goto fim;
    }
    }
    if(altera==1 && (strcmp(thread, "bloqueado")==0)){
    strcpy(thread, "executando");
    printaEstado(thread);
    goto executando;
    }
    if(altera==1 && (strcmp(thread, "morta")==0)){
    printf("A thread já está morta!\n");
    printaEstado(thread);
    }
    } while (altera==1);
    fim:
    printf("\n");
    printaEstado(thread);
    printf("Fim do programa! \n");
    printf("\n");
    }
    printf("Deseja outra simulacao? \n");
    printf("1 para sim, 2 para nao \n");
    scanf("%d", &repete);
    if (repete == 1)
    goto MENU;
    else
    printf("FIM, OBRIGADO POR USAR O PROGRAMA!");
    return 0;
}
