#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#define autor "Jose Alexandre Fatec Ads "

struct Cliente {
    char nome[256];
    char cpf [11];
};

struct Conta{
    int numeroconta;
    struct Cliente;
    double saldo;
    int operacao;

};

struct Transacao {
    int operacao;
    double valor;
    double saldo;
};
int validarCPF(char *cpf)
{
  char dv[2];
int i = 0, tamanho = 0;

for(i = 0; cpf[i]!='\0'; i++){
  tamanho++;
}

if(tamanho != 11){
  printf("\nTamanho do CPF inválido.\n");
  return 'F';
}else {
  for (i = 0; i < strlen(cpf); i++){
    if (cpf[i]< '0' || cpf[i] > '9'){
      printf("\nCaracter Inválido.\n");
      return 'F';
    }
  }
}
}
char *msgSaudacao(int hora) {

    char *saud[] = {"Bom dia!", "Boa tarde!", "Boa noite!"};

    if (hora >= 12 && hora <18)
    {
        return saud[1];
    }
    else if(hora >= 0 && hora < 12)
    {
        return saud[0];
    }
    else {
        return saud[2];
    }
}

 main(){
    char cpf [12];
    double saldo;
    char nome[256];
    int linha = 0;
    double valorinicial;
    struct Transacao vettransacao[50];
    char nome1 [20];
    int hora;


      printf ( "Digite seu nome\n" );
      scanf ( "%s", nome1 );
      system("@cls||clear");
      printf ( "Ola %s,\n", nome1 );
      time_t data;
      time(&data);

      struct tm *horaData = localtime(&data);
      printf("\n%s | %i/%i/%i - %02i:%02i:%02i |", msgSaudacao(horaData->tm_hour), horaData->tm_mday, horaData->tm_mon + 1, horaData-> tm_year + 1900, horaData->tm_hour, horaData->tm_min, horaData->tm_sec);


    printf("\nPor favor,insira os dados solicitados para abertura da conta\n");
    printf("\nDigite seu CPF, somente numeros:\n");
    __fpurge(stdin); // esse comando limpa o buffer de teclado no linux se for compilar no windows desabilite esse e use o comando   fflush(stdin);
    //fflush(stdin);
    fgets(cpf , sizeof(cpf),stdin);
    validarCPF(cpf);
    printf("Digite seu Nome Completo:\n");
    __fpurge(stdin);
    //fflush(stdin);
    fgets(nome,sizeof(nome) ,stdin);
    printf("Qual seu deposito inicial:\n");
    scanf("%lf", &valorinicial);
    saldo = valorinicial;
    system("@cls||clear");

    printf("Conta registrada com sucesso\n");
    printf("\nCliente: %s \nSaldo inicial: %.2lf\n",nome, saldo);

    int operacao;

    double valor;


    while (operacao != 4){

    printf("\nInforme a operacao desejada:\n 1 - Saque\n 2 - Deposito\n 3 - Mostrar Saldo\n 4 - Sair:\n");
    scanf("%d", &operacao);

    switch( operacao )
    {
    case 1:
    system("@cls||clear");
    printf("Operacao Saque\n");
    printf("Informe o Valor:\n");
    scanf(" %lf", &valor);
        if(saldo >= valor){
    printf("\n Operacao aceita\n", valor);
    saldo = saldo - valor;
    vettransacao[linha].operacao = operacao;
    vettransacao[linha].valor = valor;
    vettransacao[linha].saldo = saldo;
    linha++;
    printf("Saldo atual: %.2lf\n", saldo);
    }
        else{
    printf("Operacao Invalida\n");
    }

        break;
    case 2:
    system("@cls||clear");
    printf("Operacao Deposito\n");
    printf("Informe o Valor:\n");
    scanf(" %lf", &valor);
        if(valor >0){
    printf("\nOperacao aceita\n", valor);
    saldo = saldo + valor;
    vettransacao[linha].operacao = operacao;
    vettransacao[linha].valor = valor;
    vettransacao[linha].saldo = saldo;
    linha++;
    printf("Saldo atual: %.2lf\n", saldo);
        }
        else{
    printf("Operacao Invalida\n");
        break;

    case 3:
    system("@cls||clear");
    printf("Operacao Mostrar saldo\n");
    printf("Saldo atual: %.2lf\n", saldo);
        break;

    case 4:
    system("@cls||clear");
    printf("\n\n\nObrigado , volte sempre: %s\n",autor);;
        break;

    }


    }
}

}
