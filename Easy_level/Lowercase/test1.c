/* Author : Guido Giuntoli */
#include <stdio.h>
int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int h;
  h=fgetc(input);
  while(h != EOF ){ 
    if(65<=h && h<=90) h+=32;
    printf("%c",h);
    h=fgetc(input);
  }
  printf("\n");
  fclose(input);
  return; 
}
