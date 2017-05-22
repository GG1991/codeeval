/* Author : Guido Giuntoli */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LENGTH 1024

int cmpfunc (const void * a, const void * b)
{
   return -( *(int*)a - *(int*)b );
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char c, *data;
  char line[LINE_LENGTH];
  int letter[26];
  int i, ofs, n, max;
  
  while(fgets(line,LINE_LENGTH,input) != NULL ){
    for(i=26;i>0;i--) letter[i-1]=0;
    data=line;
    while(sscanf(data,"%c%n",&c,&ofs) != EOF){
      if( 97 <= c && c <= 122 ){
	letter[c-97]++;
      }
      if( 65 <= c && c <= 90 ){
	letter[c-65]++;
      }
      data+=ofs;
    }
    
    qsort(letter, 26, sizeof(int), cmpfunc);
    max=0;
    for(i=26;i>0;i--){
     max += i*letter[26-i]; 
    }
    printf("%d\n",max);
  }
  fclose(input);
  return; 
}
