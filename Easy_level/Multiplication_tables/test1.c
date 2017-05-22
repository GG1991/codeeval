/* Author : Guido Giuntoli */

#include <stdio.h>

int main(int argc, char **argv){
  int i,j,a;
  printf("   1   2   3   4   5   6   7   8   9  10  11  12\n");
  for(i=2;i<=12;i++){
      printf("%4i",i);
    for(j=2;j<=12;j++){
      printf("%4i",i*j);
    }
    printf("\n");
  }
  return; 
}
