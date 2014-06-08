/*------------------------------------------------------------------------------------------------------//
  Name: Replace char 2 stringS
  Author: Rodrigo Mansueli Nunes
  Date: 21-10-10 01:18
  Contact: kyllopardiun@gmail.com
  Description: 4 functions:
       1.ch2str -> Char to string
        Replace just the first character  found for the string.
       2.ach2str -> All 'char' to string
        Replace every char found in a string for an amount of characters.
  Note: the usage is the same just he name of funcion changes.

       3.repstr -> Replace string
        Replace the first occurrence of a substring,
       for another substring in a specified string.
       4.repallstr -> Replace all strings
        Replaces all occurrences of a substring,
       for another substring in a specified string.
       5.rencode -> Right Encode
       Replace the special characters,
       so they can be displayed in the console mode.
  References below:
------------------------------------------------------------------------------------------------------
English:
     Function: char to string
     usage: ach2srt(char to be changed,string to be placed where it's the char,main string)

  1.
  e.g  for change the first occurrence of 'a' in "lolaaa" to "he" do:

     //changes
     k=ch2str('a',"he","lolaaa");
     //show to you the result
     puts(k); // lolheaa
  2.
  e.g. for change every 'a' in: lolaaa to "he" do:

     //changes
     k=ach2str('a',"he","lolaaa");
     //show to you the result
     puts(k); // lolhehehe

======================================================================================================
           WARNING: You can use the functions below for exactly the same of the first to,
                    but it's not recomended because it is MUCH slower.
======================================================================================================
  3.
  e.g for change the first occurrence of "rolf" in "rolfrolfhehehe" to "lol" do:

    //changes
    k=repstr("rolf","lol","rolfrolfhehehe");
    //show the result
    puts(k);// lolrolfhehehe
  4.
  e.g for change every occurrence of "rolf" in "rolfrolfhehehe" to "lol" do:

    //changes
    k=repallstr("rolf","lol","rolfrolfhehehe");
    //show the result
    puts(k);// lollolhehehe
  5.
  e.g for be able to print this string in console properly: string[]="Halløj, hvordan gik det i går?";
  just do:

    printf("%s",encode(string));
  //it does return the same string so the follow it's also possible:
    encode(string);
    printf("%s",string);

------------------------------------------------------------------------------------------------------
Português
     Função: char to string

// caracter para string
-Uso: ch2srt(caracter a ser trocado,string para colocar no lugar do caracter,string que contem o caracter)

  1.
  ex. para trocar o primeiro 'a' em: "lolaaa" por "he" faça:
     //faz a troca
     k=ch2str('a',"he","lolaaa");
     //imprime lolheaa
     puts(k);

// toda ocorência daquele caracter para string
-Uso: o mesmo da função anterior apenas troque o nome da função para ach2str

  2.
  ex. para trocar todos 'a' em: "lolaaa" por "he" faça:
     //faz a troca
     k=ach2str('a',"he","lolaaa");
     //imprime lolhehehe
     puts(k);
=======================================================================================================
     AVISO: Embora seja possível fazer as operações acima com apenas essas funções abaixo,
            isto não é recomendado devido ao fato que estas, são MUITO mais lentas que as acima.
=======================================================================================================
//Primeira ocorrência de uma string para outra string
uso: repstr(string a ser substituida,string que substituirá,string que contém a primeira substring)
  3.
  ex. Para trocar o primeiro "rofl" para "lol" faça
    //faz a troca
    k=repallstr("rolf","lol","rolfrolfhehehe");
    //imprime
    puts(k);// lolroflhehehe

//Toda ocorrência de uma string para outra string
uso: repallstr(string a ser substituida,string que substituirá,string que contém a primeira substring)
  4.
  ex. Para trocar o primeiro "rolf" para "lol" faça
    //faz a troca
    k=repallstr("rolf","lol","rolfrolfhehehe");
    //imprime
    puts(k);// lollolhehehe

//Impressão correta no Console
  5.
  ex. Para corrigir a acentuação gráfica impressa por string="Olá quero mostrar acentuação" faça
    printf("%s",encode(string));

  //ou como a função retorna a mesma string pode se fazer o seguinte:
    rencode(string);
    printf("%s",string);

  //ou use a função oprintf, que está disponível nessa biblioteca
    oprintf("&s",string);

//------------------------------------------------------------------------------------------------------*/
#ifndef stdio_H_
#define stdio_H_
#include <stdio.h>
#endif /*stdio_H_*/
//this above it's to include the built-in header stdio.h

#ifndef stdlib_H_
#define stdlib_H_
#include <stdlib.h>
#endif /*stdlib_H_*/
//this above it's to include the built-in header stdlib.h

#ifndef stdarg_H_
#define stdarg_H_
#include <stdarg.h>
#endif /*stdarg_H_*/
//this above it's to include the built-in header stdarg.h

#ifndef string_H_
#define string_H_
#include <string.h>
#endif /*string_H_*/
//this above it's to include the built-in header string.h

#ifndef stringpp_H_
#define stringpp_H_
#define constEspeciais 34 //para a função 5.
char *ch2str(char k,char *string,char *pp){
   int MAX=strlen(string)+strlen(pp);
   char kstring[MAX];
   char *pchar,stringaux1[MAX],stringaux2[MAX];
   int j,i;
      if (strchr(pp,k)!=0){
             memset(stringaux1, 0, MAX);
             memset(stringaux2,0,MAX);
             pchar=1+strchr(pp,k);
             sprintf(stringaux1,"%s",pchar);
             j=strlen(pp)-strlen(stringaux1);
             strncpy(stringaux2, pp,j-=1);
             strcat(stringaux2,string);
             strcat(stringaux2,stringaux1);
             sprintf(pp,"%s",stringaux2);
      }
      return pp;
}
//------------------------------------------------------------------------------------------------------//
char *ach2str(char k,char *string,char *pp){
   int MAX=strlen(string)+strlen(pp);
   char kstring[MAX];
   char *pchar,stringaux1[MAX],stringaux2[MAX];
   int j,i;
      if (strchr(pp,k)!=0){
             memset(stringaux1, 0, MAX);
             memset(stringaux2,0,MAX);
             pchar=1+strchr(pp,k);
             sprintf(stringaux1,"%s",pchar);
             j=strlen(pp)-strlen(stringaux1);
             strncpy(stringaux2, pp,j-=1);
             strcat(stringaux2,string);
             strcat(stringaux2,stringaux1);
             sprintf(pp,"%s",stringaux2);
      }
      if (strchr(pp,k)!=0){
           ach2str(k,string,pp);
      }
      return pp;
}
//------------------------------------------------------------------------------------------------------//
char *repstr(char *pchar,char *string3,char *pp){
  int MAX=strlen(pp),j;
  char stringaux1[MAX],*pp2=pp,*paux,paux2[MAX];
  char* stringaux2 = (char*) malloc (MAX*sizeof(char));//pode substituir "*sizeof(char)" por "*2"
  while(strchr(pp2,*pchar)!=0){
     paux=strchr(pp2,*pchar);
     memset(paux2,0,MAX);
     strncpy(paux2,paux,strlen(pchar));
     if( strcmp(paux2,pchar) == 0 ) {
              memset(stringaux1, 0, MAX);
              memset(stringaux2,0,MAX);
              sprintf(stringaux1,"%s",paux+strlen(paux2));
              j=(strlen(pp)-strlen(stringaux1))-strlen(pchar);
              strncpy(stringaux2,pp,j);
              strcat(stringaux2,string3);
              strcat(stringaux2,stringaux1);
              return stringaux2;
     }
     pp2++;
  }
  return 0;
}
//------------------------------------------------------------------------------------------------------//
char *repallstr(char *pchar,char *string3,char *pp){
  char *p2,*p;
    p2=repstr(pchar,string3,pp);
    if (p2){
       p=p2;
       while(p2!=0){
             p2=repstr(pchar,string3,p);
             if (p2!=0){
                p=p2;
             }
       }
       return p;
    }
    return pp;
}
//------------------------------------------------------------------------------------------------------//
char *rencode(char *string){
     int i,j;
     char *p=string,*p2,spc[2*constEspeciais]={
     '\x94','\xC4','\x94','\xC2','\xE5','\xC5','\xE0','\xC0','\xE3','\xC3','\xE1','\xC1','\xE7','\xC7','\xE9','\xC9','\xEA',
     '\xCA','\xED','\xCD','\xEE','\xCE','\xF4','\xD4','\xF5','\xD5','\xF3','\xD3','\xFA','\xDA','\xE6','\xC6','\xF8','\xD8',
     '\x84','\x8E','\x83','\xB6','\x86','\x8F','\x85','\xB7','\xC6','\xC7','\xA0','\xB5','\x87','\x80','\x82','\x90','\x88',
     '\xD2','\xA1','\xD6','\x8C','\xD7','\x93','\xE2','\xE4','\xE5','\xA2','\xE0','\xA3','\xE9','\x91','\x92','\x9B','\x9D'};

     for(i=0;i<=strlen(string);i++,p++){
        j=0;
        for(j=0,p2=spc;j<constEspeciais+1;j++,p2++){
           if((*p)==(*p2)){
             *p=*(p2+constEspeciais);
             j=constEspeciais+2;
           }
        }
     }
     return string;
}
void oprintf(char * format, ...)
{
  int Max=strlen(format)*4;
  char a[Max],*p=a;
  memset(a,0,Max);
  va_list args;
  va_start (args, format);
  vsprintf (a,format, args);
  rencode(a);
  printf("%s",a);
  va_end (args);
}
#endif /*string_H_*/
