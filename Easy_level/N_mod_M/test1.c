/* Author : Guido Giuntoli */

#include <stdio.h>

// void clean;

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int n,m; 
  char line[32];
  while(fgets(line,32,input) != NULL){  
    sscanf(line,"%d,%d",&n,&m);
    if(m!=0)printf("%d\n", n - m*(n/m));
  }
  fclose(input);
  return; 
}
