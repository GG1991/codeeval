/* Author : Guido Giuntoli */

#include <stdio.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[32];
  int sum=0;
  int b; 
  while(fgets(line,32,input) != NULL){  
      sscanf(line,"%d",&b);
      sum+=b;
  }
  printf("%d\n",sum);
  fclose(input);
  return; 
}
