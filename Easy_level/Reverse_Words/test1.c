/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256
#define MAX_WORDS 1000

char *clean(char *str){
  int i;
  for(i=0;i<strlen(str);i++){
    if(str[i]=='\n')str[i]='\0';
  }
  return str;
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];
  char *h,*b,*words[MAX_WORDS];
  int i,k;
  char s[]=" ";
  
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    h=strtok(line,s);
    k=-1;
    while(h!=NULL){
      k++;
      words[k]=h;
      h=strtok(NULL,s);
    }
    for(i=0;i<k+1;i++){
      printf("%s ",clean(words[k-i]));
    }
    printf("\n");
  }
  fclose(input);
  return; 
}
