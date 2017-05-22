/* Author : Guido Giuntoli */

#include <stdio.h>
#include <math.h>

#define LENGTH 2048

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int n, i, j, flg, m, c;
  char line[LENGTH];
  int num[16];
  char *data;
  
  i=0;c=0;flg=0;
  do{
    n = fgetc(input);
    if(47<n && n<58){
      num[i]=n-48;
      i++;
      flg=1;
    }else if(flg==1){
      m=0;
      for(j=i-1;j>=0;j--){
	m+=num[i-1-j]*(int)pow(10,j);
      }
      if(m<=c && m>0){
	printf("%c\n",line[c-m]);
      }else{
	printf("\n");
      }
      flg=0; 
      i=0;
      c=0;
    }else if(n!=' ' && n!='-'){
      line[c]=n;
      c++;
    }
  }while( n!= EOF );
  
  fclose(input);
  return; 
}
