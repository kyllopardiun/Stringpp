/************************************************************************
*** ***
*** Rodrigo Mansueli Nunes No. Matrícula 1166174
*** Exercício-Programa Aula 8 - Código de César
*** Curso: Técnicas de Programação Turma: C21 Professor Msc.: Alexandre Rossi Paschoal
*** Computador: Lenono 3000 N200
*** Compilador: Dev-C++ 4.9.9.2
*** Objetivo: Criar um progama que encodifica pelo código de césar,
*** com alterações no código original de césar, que não substitui espaços.
*** Data de Entrega: 3 out 2010.
*** Notas adicionais:
***   O alfabéto utilizado é o nórdico, ou seja ha as letras æøå após o z
***   Letras acentudadas não seram modificadas, uma vez que o código nada diz a respeito dessas.
*** ***
************************************************************************/

#include <stdio.h> //entradas e saídas
#include <string.h> //funções para brincar com string
#include <conio.h> //getch() AVISO: não é padrão ANSI pode dar problemas em alguns S.O.
#include <stdlib.h> //system()
#include "stringpp.h"// Facilita a manipulação de strings e
#define MAX 300
//Protótipos
void descriptar(int k,char *enc);

void encriptar(int k,char *enc);
//Fim dos protótipos


/*---------------------------------------------------------------------------------------------------------------/
                           Programa Principal
----------------------------------------------------------------------------------------------------------------*/
int main(void){
     char enc[MAX];
     int opc=0,konst=0,j;
     char frase[MAX],*pointer;
     //troca o esquema de cor
     system("color 3F");
     system("cls");
     //para unix
     // printf ("\x1b\x5b1;31;40m\x1b\x5b0;37;40m");
     //
     //interface para o usuário
     printf("----------------------------------------------------------------------\n");
     printf("-\n-\tBem vindo ao encriptador C\x82sar++ \n-\n");
     printf("----------------------------------------------------------------------\n\n\n");
     //menu de opções
     do{
            printf("-Escolha uma das op\x87åes abaixo:\n\n-1.Encriptar\n-2.Desencriptar\n-3.Sair\n\n-Sua op\x87\xC6o:\n-");
            scanf("%d",&opc);
            system("cls");
     }while((opc>3)||(opc<1));
     //como o valor já é um não precisa de comparar
     //encripta
     if(opc==1){
        //le a frase
        printf("- Escreva a frase para encriptar\n-");
        //por algum erro do compilador o programa pula essa linha e só lê um gets(enc)
        //foi simulado o que está dentro desse if em um programa separado e funcionou sem os dois gets()
        gets(enc);
        gets(enc);
        j=0;
        //le a 'chave'
        printf("\n- Escreva a constante de encripta\x87\xC6o\n-");
        scanf("%d",&konst);
        //módulo
        konst=(konst*konst)/konst;
        //passa a 'chave' para o procedimento
        encriptar(konst,enc);
        }
     //verifica se o usuário digitou 2
     //desencripta
     else{ if(opc==2){
              //le a frase
              printf("- Escreva a frase para desencriptar\n-");
              gets(frase);
              gets(frase);
              j=0;
              //le a 'chave'
              printf("\n- Escreva a constante de encripta\x87\xC6o\n-");
              scanf("%d",&konst);
              //módulo
              konst=(konst*konst)/konst;
              //passa a frase para a string de manipulação
              sprintf(enc,"%s",frase);
              //passa a 'chave' para o procedimento
              descriptar(konst,enc);
              }
          //verifica se o usuário digitou 3
          //encerra o programa
          else if(opc==3){
                   return 0;
                }
     }
     //getch() não é ANSI, e pode ser substituido por alguma outra coisa,
     //como um scanf()
     getch();
     //faz o loop que matem o programa aberto,
     //enquanto o usuário quizer
     return main();
}

/*---------------------------------------------------------------------------------------------------------------/
                           Função que decodifica
----------------------------------------------------------------------------------------------------------------*/

void descriptar(int k,char *enc){
   char *pchar,*pchar2;
   char alfa[]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
   char ALFA[]="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
   int j,i,l;
   //garante que o número não sairá da alfa[]
     k%=26;
   //troca os caracteres minusculos
     for(pchar=enc,i=0;i<strlen(enc);pchar++,i++){
         for(j=0,pchar2=alfa;j<=strlen(alfa);j++,pchar2++){
              if(*pchar2==*pchar){
                   l=j-k+26;
                   *pchar=alfa[l];
                   j=strlen(alfa)+4;
              }
         }
     }
     //troca os caracteres maiusculos
     for(pchar=enc,i=0;i<strlen(enc);pchar++,i++){
         for(j=0,pchar2=ALFA;j<=strlen(ALFA);j++,pchar2++){
              if(*pchar2==*pchar){
                   l=j-k+26;
                   *pchar=ALFA[l];
                   j=strlen(ALFA)+4;
              }
         }
     }
     //procura as strings e troca pelos sinais gráfico
     sprintf(enc,"%s",repallstr("wbrw"," ",enc));//troca espaco
     sprintf(enc,"%s",repallstr("wvrw",",",enc));//troca_virgula();
     sprintf(enc,"%s",repallstr("wptw",".",enc));//troca_ponto();
     sprintf(enc,"%s",repallstr("winw","?",enc));//troca_inter();
     sprintf(enc,"%s",repallstr("wexw","!",enc));//troca_excla();
     sprintf(enc,"%s",repallstr("wdpw",":",enc));//troca_2pontos();
     sprintf(enc,"%s",repallstr("whfw","-",enc));//troca_hifen();
     sprintf(enc,"%s",repallstr("wpvw",";",enc));//troca_pontovirgula();

     printf("-\n-\n-\n- A frase a original \x82\n-");
     printf("\n-\"%s\"\n-\n-\n-Pressione qualquer tecla para continuar",rencode(enc));
}
/*---------------------------------------------------------------------------------------------------------------/
                           Função que encodifica
----------------------------------------------------------------------------------------------------------------*/
void encriptar(int k,char *enc){
   char *pchar,*pchar2;
   char alfa[]="abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
   char ALFA[]="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";
   rencode(alfa);
   rencode(ALFA);
   int j,i;
     //garante que o número não sairá da array alfa[]
     k%=26;
     //efetua as funções semelhantes que estão mais acima para,
     //substituir caracteres por string

     sprintf(enc,"%s",ach2str(' ',"wbrw",enc));//troca espaco
     sprintf(enc,"%s",ach2str(',',"wvrw",enc));//troca_virgula();
     sprintf(enc,"%s",ach2str('.',"wptw",enc));//troca_ponto();
     sprintf(enc,"%s",ach2str('?',"winw",enc));//troca_inter();
     sprintf(enc,"%s",ach2str('!',"wexw",enc));//troca_excla();
     sprintf(enc,"%s",ach2str(':',"wdpw",enc));//troca_2pontos();
     sprintf(enc,"%s",ach2str('-',"whfw",enc));//troca_hifen();
     sprintf(enc,"%s",ach2str(';',"wpvw",enc));//troca_pontovirgula();
     //troca as letras ao usar da 'chave' de criptografia
     for(pchar=enc,i=0;i<strlen(enc);pchar++,i++){
         for(j=0,pchar2=alfa;j<=strlen(alfa);j++,pchar2++){
              //se as letras forem iguais
              if(*pchar2==*pchar){
                   //troca a letra da string por uma que está k deslocada conforme a chave
                   *pchar=alfa[j+k];
                   //termina o for para não ter processamento desnecessário
                   j=strlen(alfa)+4;
              }
         }
     }
     for(pchar=enc,i=0;i<strlen(enc);pchar++,i++){
         for(j=0,pchar2=ALFA;j<=strlen(ALFA);j++,pchar2++){
              //se as letras forem iguais
              if(*pchar2==*pchar){
                   //troca a letra da string por uma que está k deslocada conforme a chave
                   *pchar=ALFA[j+k];
                   //termina o for para não ter processamento desnecessário
                   j=strlen(ALFA)+4;
              }
         }
     }
     //imprime as saídas ao usuário.
     printf("-\n-\n-\n- A frase a encriptada \x82\n-");
     printf("\n-%s\n-\n-\n-Pressione qualquer tecla para continuar",enc);
}
