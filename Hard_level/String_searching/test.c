/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 4048
int flg;
int i,j;

int IsInString(char *a, char *b){

  if( b[j]=='\0' )return 1;
  
  if( a[i]=='\0' ){
    return (flg==0) ? 0 : 1 ;
  }
  
  if( a[i]==' ' && flg==1){
    flg=0;
    if(b[j]!=' ')return 0;
  }
  
  if( b[j+1]!='\0' ){
    if( b[j]==92 && b[j+1]=='*' && a[i]=='*' ){
      i=i+1;
      j=j+2;
      return IsInString( a , b );
    }
  }
  if( b[j]=='*' ){ 
    flg=1;
    j=j+1;
    if( IsInString( a , b ) == 1 ){
      return 1;
    }else{
      flg=0;
      j=0;
      i=i+1;
      return IsInString( a , b ); 
    }      
  }else if(a[i]==b[j] ){
    i=i+1;
    j=j+1;
    return IsInString( a , b );
  }else if( a[i] != b[j] ){
    if(flg==0)j=0;
    i=i+1;
    return IsInString( a , b );
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char *a,*b;
  char line[LINE_LENGTH];
  
  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    a=strtok(line,",");
    b=strtok(NULL,",\n");
    flg=0;
    i=0;
    j=0;
    if(IsInString( a, b )==1){
      printf("true\n");
    }else{
      printf("false\n");
    }
  }
  
  fclose(input);
  return; 
}
