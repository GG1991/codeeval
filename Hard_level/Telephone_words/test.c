/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 32

int GetCombinations(char c){
  if(c=='1' || c=='0'){
    return 1;
  }else if(c=='2'){
    return 3;
  }else if(c=='3'){
    return 3;
  }else if(c=='4'){
    return 3;
  }else if(c=='5'){
    return 3;
  }else if(c=='6'){
    return 3;
  }else if(c=='7'){
    return 4;
  }else if(c=='8'){
    return 3;
  }else if(c=='9'){
    return 4;
  }else{
    return -1; 
  }
}

char GetChar(char c, int i){
  if(c=='1' || c=='0'){
    return c;
  }else if(c=='2'){
    return 97+i;
  }else if(c=='3'){
    return 100+i;
  }else if(c=='4'){
    return 103+i;
  }else if(c=='5'){
    return 106+i;
  }else if(c=='6'){
    return 109+i;
  }else if(c=='7'){
    return 112+i;
  }else if(c=='8'){
    return 116+i;
  }else if(c=='9'){
    return 119+i;
  }else{
    return -1; 
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int ND,NW,i,k,W;
  char line[LINE_LENGTH];
  int NUM[LINE_LENGTH];
  int PER[LINE_LENGTH];

  while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
    ND=strlen(line)-1;
    NW=1;
    for( i=ND-1 ; i >=0 ; i-- ){
      NUM[i] = GetCombinations(line[i]);
      NW    *= GetCombinations(line[i]);
      PER[i]=0;
    }
    W=0;
    while(W<NW){
      for( i=(ND-2) ; 0 <= i ; i-- ){
	if((PER[i+1]!=0) && (PER[i+1]%NUM[i+1]==0)){
	  PER[i]++;
	  PER[i+1]=0;
	}
      }
      for( i=0 ; i < ND ; i++ )
// 	printf("%d", PER[i] ) ;
	printf("%c",GetChar( line[i], PER[i] )) ;
      PER[ND-1]++;
      W++;
      if(W<NW)printf(",");
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
