/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 256
#define MAX_NUM 128

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int offset=0,p;
  int steps,per,i,j,n,size,aux;
  char line[LINE_LENGTH];
  char * lhs, * rhs;
  char s[]="|";
  int num[MAX_NUM];

  while( fgets(line, LINE_LENGTH, input) != NULL ){
    lhs=strtok(line,s);
    rhs=strtok(NULL,s);
    sscanf(rhs,"%d",&steps);
    size=0;
    while(sscanf(lhs,"%d%n",&n,&offset)!=EOF){
      lhs+=offset;
      num[size]=n;
      size++;
    }
    p=0;
    j=0;
    while(j<size-1 && p<steps){
       if(num[j+1]<num[j]){
	  aux=num[j];
	  num[j]=num[j+1];
	  num[j+1]=aux;
	  p++;
	  j=-1;
       }
       j++;
    }
    for(i=0;i<size;i++){
      printf("%d ",num[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
