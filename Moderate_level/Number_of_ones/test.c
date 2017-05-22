/* Author : Guido Giuntoli */

#include <stdio.h>
#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];
  int i,n,cnt;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%d",&n);
    cnt=0;
    for( i=0 ; i < sizeof(int)*8 ; i++ ){
      if( (n >> i & 1 ) == 1 ) cnt++ ;
    }
    printf("%d\n",cnt) ;
  }
  
  fclose(input);
  return; 
}
