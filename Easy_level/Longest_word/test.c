/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int max;
  char line[LINE_LENGTH];
  char *w, *aux;
  char s[]=" \n";

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    w=strtok(line,s);
    max=strlen(w);
    aux=w;
    while(w!=NULL){
      if(max<strlen(w)){
	max=strlen(w);
	aux=w;
      }
      w=strtok(NULL,s);
    }
    printf("%s\n",aux);
  }  
  fclose(input);
  return; 
}
