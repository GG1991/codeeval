/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024

void clean(char *b){
 int i;
 for(i=0;i<strlen(b);i++){
   if (b[i]==',' || b[i]=='-')b[i]=' '; 
 }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int list[64],n1,n2,i,j;
  int mov[64],ofs,aux;
  char line[LINE_LENGTH];
  char *a,*b;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,":");
    b=strtok(NULL,":");
    n1=0;
    while(  sscanf(a,"%d%n",&list[n1],&ofs)!=EOF ){
     a+=ofs;
     n1++; 
    }
    clean(b);
    n2=0;
    while(  sscanf(b,"%d%n",&mov[n2],&ofs)!=EOF ){
     b+=ofs;
     n2++; 
    }
    for(i=0;i<n2/2;i++){
      aux=list[mov[2*i]];
      list[mov[2*i]]=list[mov[2*i+1]];
      list[mov[2*i+1]]=aux;
    }
    for(i=0;i<n1;i++){
      printf("%d ",list[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
