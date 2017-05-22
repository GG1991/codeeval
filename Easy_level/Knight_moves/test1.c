/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>
#include <math.h>

#define LINE_LENGTH 256

int belongs(int l, int n){
  if( l>(int)'h' || l<(int)'a' || n>8 || n<=0 ){
    return 1;
  }
  return 0;
}
int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];
  int a=(int)'a',n,l,i;
  int l0=(int)'g';
  int n0=2;
  int lm[8] = { -2, -2, -1, -1, +1, +1, +2, +2 };  
  int nm[8] = { -1, +1, -2, +2, -2, +2, -1, +1 };
  
  while( fgets(line, LINE_LENGTH, input) != NULL ){
    sscanf(line,"%c%d",&l0,&n0);    
    for(i=0;i<8;i++){
      l=l0+lm[i];
      n=n0+nm[i];
      if(!belongs(l,n)) printf("%c%d ",l,n);
    }
    printf("\n");
  }  
  fclose(input);
  return 0; 
}
