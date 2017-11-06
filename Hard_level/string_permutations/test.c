#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compar(const void *a, const void *b){

  if( *(char*)a > *(char*)b ){
    return 1;
  }
  else if( *(char*)a < *(char*)b ){
    return -1;
  }
  else{
    return 0;
  }

}

int main(int argc,char **argv)
{

  FILE *fm = fopen(argv[1],"r");
  char buf[64], buf_o[64];
  int  n;

  while( fgets( buf, 64, fm ) != NULL ){

    n = strlen(buf)-1;

    qsort(buf, n, sizeof(char), &compar);
    printf("%s",buf);

  }

  return 0;
}

