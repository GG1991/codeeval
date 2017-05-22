/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 6000


int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int L[64],L1[64],n,i,ofs2;
  char line[LINE_LENGTH];
  char *a,*a1[64],*a2[64],*b;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,";");
    b=strtok(NULL,";");
    n=0;
    a1[n]=strtok(a," ");
    while( sscanf(b,"%d%n",&L[n],&ofs2)!=EOF ){  
      b+=ofs2;
      L1[n]=L[n];
      n++;      
      a1[n]=strtok(NULL," ");
    }
    qsort(L1, n, sizeof(int), cmpfunc);
    for(i=0;i<n+1;i++){
      if(L1[i]!=i+1){
	L[n]=i+1;
	break; 
      }
    }
    n++;
    for(i=0;i<n;i++){
      a2[L[i]-1]=a1[i];
    }
    for(i=0;i<n;i++){
      printf("%s ",a2[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return 0; 
}
