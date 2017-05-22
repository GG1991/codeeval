/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32


int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a,b,c,n;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL){   
      sscanf(line,"%d,%d,%d",&a,&b,&c);
      n=1;
      if((a&(1<<(b-1)))>>(b-1)==(a&(1<<(c-1)))>>(c-1) ){
	printf("true\n");
      }else{
      printf("false\n");
      }
  }
  
  fclose(input);
  return; 
}
