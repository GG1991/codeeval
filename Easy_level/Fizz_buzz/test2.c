/* Author : Guido Giuntoli
 * 
 * STATUS: FINISHED 12/03/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int X,Y,N,i,offset;
  char line[LINE_LENGTH];
  char *data = line;

  while( fgets(line, LINE_LENGTH, input) != NULL ){
    sscanf(line, "%d %d %d", &X, &Y, &N);
    for(i=1;i<=N;i++)
    {
      if(i%X==0 && i%Y==0){
	printf("FB ");
      }else if(i%X==0){
	printf("F ");
      }else if(i%Y==0){
	printf("B ");
      }else{
	printf("%d ",i);
      }
    }
    printf("\n");
  }  

  fclose(input);
  return 0; 
}
