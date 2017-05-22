/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int h,sum_h,sum_b;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%x",&h);
    printf("%d\n",h);
  }
  
  fclose(input);
  return; 
}
