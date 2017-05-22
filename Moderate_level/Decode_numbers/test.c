/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define LINE_LENGTH 32

int Comb(char *num, int nd, int i){
  /*el número viene en un char*/  
  if(nd <= 1){
    return 1;
  }else if(nd == 2){
    if( ( (num[i]-48)*10 + (num[i+1]-48) ) <= 26 ){
      return 2;
    }else{
      return 1;
    }
  }else{
    if( ((num[nd/2-1]-48)*10 + (num[nd/2]-48)) > 26){
      if(nd%2 == 0){
	return Comb(num,nd/2,0) * Comb(num,nd/2,nd/2);
      }else{
	return Comb(num,nd/2,0) * Comb(num,nd/2+1,nd/2);
      }
    }else{
	if(nd%2 == 0){
	  return Comb(num,nd/2,0) * Comb(num,nd/2,nd/2)   +  Comb(num,nd/2-1,0) * Comb(num,nd/2-1,nd/2+1);
	}else{                                                                                        
	  return Comb(num,nd/2,0) * Comb(num,nd/2+1,nd/2) +  Comb(num,nd/2-2,0) * Comb(num,nd/2,nd/2+1)  ;
	}
    }
  }
    
}


int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    if(line[strlen(line)-1]=='\n'){
      printf("%d\n",Comb(line,strlen(line)-1,0));
    }else{
      printf("%d\n",Comb(line,strlen(line),0));
    }
  }
  
  fclose(input);
  return; 
}
