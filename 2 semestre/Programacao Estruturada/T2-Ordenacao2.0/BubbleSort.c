#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define range 10000+1
#define tamA 5000
#define tamB 10000
#define tamC 20000
#define tamD 30000


void ler(int vetor[],int fim);
void ordenar(int vetor[],int fim);
void imprimir(int vetor[],int fim);

FILE *inputA;
FILE *inputB;
FILE *inputC;
FILE *inputD;
FILE *outputA;
FILE *outputB;
FILE *outputC;
FILE *outputD;
FILE *output_tempo;

int main()
{
  inputA=fopen("A.txt","r");
  inputB=fopen("B.txt","r");
  inputC=fopen("C.txt","r");
  inputD=fopen("D.txt","r");
  output_tempo=fopen("Relatorio_Bubble_Sort.txt","w");
  if(inputA==NULL)
  {
    printf("Erro na abertura do A\n");
    return 0;
  }
  if(inputB==NULL)
  {
    printf("Erro na abertura do B\n");
    return 0;
  }
  if(inputC==NULL)
  {
    printf("Erro na abertura do C\n");
    return 0;
  }
  if(inputD==NULL)
  {
    printf("Erro na abertura do D\n");
    return 0;
  }
  int vetorA[tamA],vetorB[tamB],vetorC[tamC],vetorD[tamD];
  clock_t tempoInicial, tempoFinal;
  double tempoGasto[4];
  int contador=0;

  tempoInicial = clock(); //recebe o tempoInicial do relogio
  ler(vetorA,tamA); //faz a leitura no arquivo, e salva o vetorA
  ordenar(vetorA,tamA);
  imprimir(vetorA,tamA);
  tempoFinal = clock();//recebe o tempo final do relogio
  tempoGasto[contador] = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC; //divide clocks/segundo
  fprintf(output_tempo," VetorA: %.3f\n",tempoGasto[contador]);
  contador++;

  tempoInicial = clock(); //recebe o tempoInicial do relogio
  ler(vetorB,tamB); //faz a leitura no arquivo, e salva o vetorA
  ordenar(vetorB,tamB);
  imprimir(vetorB,tamB);
  tempoFinal = clock();//recebe o tempo final do relogio
  tempoGasto[contador] = (double) (tempoFinal-tempoInicial)/CLOCKS_PER_SEC; //divide clocks/segundo
  fprintf(output_tempo," vetorB: %.3f\n",tempoGasto[contador]);
  contador++;

  tempoInicial = clock(); //recebe o tempoInicial do relogio
  ler(vetorC,tamC); //faz a leitura no arquivo, e salva o vetorA
  ordenar(vetorC,tamC);
  imprimir(vetorC,tamC);
  tempoFinal = clock();//recebe o tempo final do relogio
  tempoGasto[contador] = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC; //divide clocks/segundo
  fprintf(output_tempo," vetorC: %.3f\n",tempoGasto[contador]   );
  contador++;

  tempoInicial = clock(); //recebe o tempoInicial do relogio
  ler(vetorD,tamD); //faz a leitura no arquivo, e salva o vetorA
  ordenar(vetorD,tamD);
  imprimir(vetorD,tamD);
  tempoFinal = clock();//recebe o tempo final do relogio
  tempoGasto[contador] = (double)(tempoFinal-tempoInicial)/CLOCKS_PER_SEC; //divide clocks/segundo
  fprintf(output_tempo," vetorD: %.3f\n",tempoGasto[contador]);
  fclose(output_tempo);
  return 0;
}
void ler(int vetor[],int fim)
{
	int i;
  if(fim==tamA)
  {
  for(i=0;i<fim;i++)//preecher o vetor
  {
     fscanf(inputA,"%d",&vetor[i]);
   }
  fclose(inputA);
  }
  if(fim==tamB)
  {
  for(i=0;i<fim;i++)//preecher o vetor
     fscanf(inputB,"%d",&vetor[i]);
  fclose(inputB);
  }
  if(fim==tamC)
  {
  for(i=0;i<fim;i++)//preecher o vetor
     fscanf(inputC,"%d",&vetor[i]);
  fclose(inputC);
  }
  if(fim==tamD)
  {
  for(i=0;i<fim;i++)//preecher o vetor
     fscanf(inputD,"%d",&vetor[i]);
  fclose(inputD);
  }
}
void ordenar(int vetor[],int final) //BUBBLE SORT
{
  int i,fim=final,count,aux;
  do
  {
    count=0;
    for(i=0;i<fim-1;i++)
    {
      if(vetor[i]<vetor[i+1])
        {
        aux= vetor[i];
        vetor[i]=vetor[i+1];
        vetor[i+1]=aux;
        count=1;
        }
      }
    fim--;
  }
  while(count!=0);
}
void imprimir(int vetor[],int fim)
{
  int i;
  if(fim==tamA)
  {
  outputA=fopen("A_Ordenado_Bubble_Sort.txt","w");
  for(i=0;i<tamA;i++) //preecher o vetor A
    fprintf(outputA,"%d\n", vetor[i]);
  fclose(outputA);
  }
  if(fim==tamB)
  {
  outputB=fopen("B_Ordenado_Bubble_Sort.txt","w");
  for(i=0;i<tamB;i++) //preecher o vetor A
    fprintf(outputB,"%d\n", vetor[i]);
  fclose(outputB);
  }
  if(fim==tamC)
  {
  outputC=fopen("C_Ordenado_Bubble_Sort.txt","w");
  for(i=0;i<tamC;i++) //preecher o vetor A
    fprintf(outputC,"%d\n", vetor[i]);
  fclose(outputC);
  }
  if(fim==tamD)
  {
  outputD=fopen("D_Ordenado_Bubble_Sort.txt","w");
  for(i=0;i<tamD;i++) //preecher o vetor A
    fprintf(outputD,"%d\n", vetor[i]);
  fclose(outputD);
  }
}
