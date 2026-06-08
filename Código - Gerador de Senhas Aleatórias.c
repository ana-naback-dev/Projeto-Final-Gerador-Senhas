/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

/******************************************************************************
  Projeto Final - Laboratório de Programação
  Tema: Gerador de Senhas Aleatórias

  Objetivo Geral:
  Gerar senhas aleatórias utilizando strings e funções.

  Problematização:
  Muitas pessoas utilizam senhas fracas, curtas ou fáceis de adivinhar.

  Resolução:
  O programa gera senhas aleatórias com letras maiúsculas, minúsculas,
  números e símbolos, aumentando a segurança da senha.

  Funcionalidades:
  - Escolher tamanho da senha
  - Escolher tipos de caracteres
  - Gerar senha aleatória
  - Verificar força da senha
  - Salvar senha em arquivo texto

  Autores: Ana Thereza Naback e Rafael
******************************************************************************/

/* Bibliotecas utilizadas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define TAM_MAX 100

/* void MontaCaracteres(char caracteres[], int mai, int min, int num, int simb)

  Entradas:
    caracteres: Vetor que armazenará os caracteres permitidos
    mai: Define uso de letras maiúsculas
    min: Define uso de letras minúsculas
    num: Define uso de números
    simb: Define uso de símbolos

  Saída:
    Vetor caracteres preenchido
*/
void MontaCaracteres(char caracteres[], int mai, int min, int num, int simb) {

  strcpy(caracteres, "");

  if(mai == 1) {
    strcat(caracteres, "ABCDEFGHIJKLMNOPQRSTUVWXYZ");
  }

  if(min == 1) {
    strcat(caracteres, "abcdefghijklmnopqrstuvwxyz");
  }

  if(num == 1) {
    strcat(caracteres, "0123456789");
  }

  if(simb == 1) {
    strcat(caracteres, "!@#$%&*?");
  }
}

/* int LerOpcaoBinaria(char mensagem[])

  Entrada:
    mensagem: Texto que será mostrado para o usuário

  Saídas:
    0: Não
    1: Sim
*/
int LerOpcaoBinaria(char mensagem[]) {

  int opcao;
  int leitura;

  do {
    printf("%s", mensagem);
    leitura = scanf("%d", &opcao);

    if(leitura != 1) {
      while(getchar() != '\n');
      opcao = -1;
    }

    if(opcao != 0 && opcao != 1) {
      printf("Opcao invalida. Digite apenas 1 para SIM ou 0 para NAO.\n");
    }

  } while(opcao != 0 && opcao != 1);

  return opcao;
}

/* int LerTamanhoSenha()

  Entrada:
    Nenhuma

  Saída:
    Retorna o tamanho válido da senha
*/
int LerTamanhoSenha() {

  int tamanho;
  int leitura;

  do {
    printf("Digite quantos caracteres a senha deve ter: ");
    leitura = scanf("%d", &tamanho);

    if(leitura != 1) {
      while(getchar() != '\n');
      tamanho = 0;
    }

    if(tamanho < 8 || tamanho >= TAM_MAX) {
      printf("Tamanho invalido. Digite um valor entre 8 e 99.\n");
    }

  } while(tamanho < 8 || tamanho >= TAM_MAX);

  return tamanho;
}

/* void EmbaralhaSenha(char senha[], int tamanho)

  Entradas:
    senha: Senha gerada
    tamanho: Quantidade de caracteres da senha

  Saída:
    Senha embaralhada
*/
void EmbaralhaSenha(char senha[], int tamanho) {

  int i;

  for(i = tamanho - 1; i > 0; i--) {

    int j;
    char temp;

    j = rand() % (i + 1);

    temp = senha[i];
    senha[i] = senha[j];
    senha[j] = temp;
  }
}

/* void GeraSenha(char senha[], int tamanho, char caracteres[],
                  int usarMai, int usarMin, int usarNum, int usarSimb)

  Entradas:
    senha: Vetor que armazenará a senha
    tamanho: Quantidade de caracteres da senha
    caracteres: Vetor contendo os caracteres permitidos
    usarMai: Define uso de letras maiúsculas
    usarMin: Define uso de letras minúsculas
    usarNum: Define uso de números
    usarSimb: Define uso de símbolos

  Saída:
    Senha aleatória gerada
*/
void GeraSenha(char senha[], int tamanho, char caracteres[],
               int usarMai, int usarMin, int usarNum, int usarSimb) {

  int i = 0;
  int tamCaracteres;

  char mai[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char min[] = "abcdefghijklmnopqrstuvwxyz";
  char num[] = "0123456789";
  char simb[] = "!@#$%&*?";

  tamCaracteres = strlen(caracteres);

  if(usarMai == 1 && i < tamanho) {
    senha[i] = mai[rand() % strlen(mai)];
    i++;
  }

  if(usarMin == 1 && i < tamanho) {
    senha[i] = min[rand() % strlen(min)];
    i++;
  }

  if(usarNum == 1 && i < tamanho) {
    senha[i] = num[rand() % strlen(num)];
    i++;
  }

  if(usarSimb == 1 && i < tamanho) {
    senha[i] = simb[rand() % strlen(simb)];
    i++;
  }

  for(; i < tamanho; i++) {

    int posicao;

    posicao = rand() % tamCaracteres;

    senha[i] = caracteres[posicao];
  }

  senha[tamanho] = '\0';

  EmbaralhaSenha(senha, tamanho);
}

/* int VerificaSenhaForte(char senha[])

  Entrada:
    senha: Senha gerada

  Saídas:
    0: Senha fraca
    1: Senha forte
*/
int VerificaSenhaForte(char senha[]) {

  int i;

  int maiuscula = 0;
  int minuscula = 0;
  int numero = 0;
  int simbolo = 0;

  if(strlen(senha) < 8) {
    return 0;
  }

  for(i = 0; senha[i] != '\0'; i++) {

    if(isupper((unsigned char) senha[i])) {
      maiuscula = 1;
    }

    else if(islower((unsigned char) senha[i])) {
      minuscula = 1;
    }

    else if(isdigit((unsigned char) senha[i])) {
      numero = 1;
    }

    else {
      simbolo = 1;
    }
  }

  if(maiuscula && minuscula && numero && simbolo) {
    return 1;
  }

  return 0;
}

/* void SalvaArquivo(char senha[])

  Entrada:
    senha: Senha gerada

  Saída:
    Arquivo texto contendo a senha
*/
void SalvaArquivo(char senha[]) {

  FILE *arquivo;

  arquivo = fopen("senhas.txt", "a");

  if(arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  fprintf(arquivo, "Senha Gerada: %s\n", senha);

  fclose(arquivo);

  printf("Senha salva no arquivo com sucesso.\n");
}

/* Função Principal */
int main() {

  int tamanho;

  int usarMai;
  int usarMin;
  int usarNum;
  int usarSimb;

  int salvar;

  char caracteres[TAM_MAX];
  char senha[TAM_MAX];

  srand(time(NULL));

  printf("====================================\n");
  printf("   GERADOR DE SENHAS ALEATORIAS\n");
  printf("====================================\n");

  tamanho = LerTamanhoSenha();

  printf("\nDigite 1 para SIM ou 0 para NAO.\n");

  do {
    usarMai = LerOpcaoBinaria("Usar letras maiusculas? ");
    usarMin = LerOpcaoBinaria("Usar letras minusculas? ");
    usarNum = LerOpcaoBinaria("Usar numeros? ");
    usarSimb = LerOpcaoBinaria("Usar simbolos? ");

    if(usarMai == 0 && usarMin == 0 &&
       usarNum == 0 && usarSimb == 0) {

      printf("\nEscolha pelo menos um tipo de caractere.\n");
    }

  } while(usarMai == 0 && usarMin == 0 &&
          usarNum == 0 && usarSimb == 0);

  MontaCaracteres(caracteres, usarMai, usarMin, usarNum, usarSimb);

  GeraSenha(senha, tamanho, caracteres,
            usarMai, usarMin, usarNum, usarSimb);

  printf("\nSenha gerada automaticamente: %s\n", senha);

  if(VerificaSenhaForte(senha) == 1) {
    printf("Senha FORTE.\n");
  } else {
    printf("Senha FRACA.\n");
    printf("Para ser forte, a senha precisa ter letras maiusculas, minusculas, numeros e simbolos.\n");
  }

  printf("\nDeseja salvar a senha em arquivo?\n");
  salvar = LerOpcaoBinaria("1 - SIM / 0 - NAO: ");

  if(salvar == 1) {
    SalvaArquivo(senha);
  } else {
    printf("Senha nao salva.\n");
  }

  printf("\nPrograma Finalizado.\n");

  return 0;
}