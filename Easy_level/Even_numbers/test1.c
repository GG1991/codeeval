/* Author : Guido Giuntoli */

#include <stdio.h>

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a;
  char line[32];
  
  while(fgets(line,32,input)!= NULL ){ 
    sscanf(line,"%d",&a);
    if(a%2==0){
      printf("1\n");
    }else{
      printf("0\n");
    }       
  }    
  fclose(input);
  return; 
}
