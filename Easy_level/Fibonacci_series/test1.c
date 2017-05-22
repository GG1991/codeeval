/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32
int Fibonacci(int n){
  if(n==0)return 0;
  if(n==1)return 1;
  return(Fibonacci(n-2)+Fibonacci(n-1));
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int n;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%d",&n);
    printf("%d\n",Fibonacci(n));
  }
  
  fclose(input);
  return; 
}
