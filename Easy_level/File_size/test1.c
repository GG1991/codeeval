/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];
  int sum=0;
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sum+=strlen(line)+1;
  }
  fclose(input);
  printf("%d\n",sum-1);
  return 0; 
}
