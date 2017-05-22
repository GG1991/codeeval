/* Author : Guido Giuntoli */

#include <stdio.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int sum=0;
  int b; 
  do{  
      b=fgetc(input);
      if(49<=b && b<=57){ sum += (b-48);}
      if((b=='\n')|| (b==EOF)){
	printf("%d\n",sum);
	sum=0;
      }
  }while(b != EOF);
  
  fclose(input);
  return; 
}
