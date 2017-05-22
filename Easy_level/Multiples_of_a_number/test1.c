/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32


int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a,b,n;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL){   
      sscanf(line,"%d,%d",&a,&b);
      n=1;
      while(a>b*n){
	n++;
      }
      printf("%d\n",b*n);
  }
  
  fclose(input);
  return; 
}
