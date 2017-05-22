/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int n,i;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%d",&n);
    if(n/1000>0){
	for(i=0;i<n/1000;i++){
	    printf("M");
	}
    }
    n=n%1000;
    if(n/100>0){
	if(n/100==4){
	    printf("CD");
	}else if(n/100==9){
	    printf("CM");
	}else if(n/100>4){
	    printf("D");
	    for(i=0;i<n/100-5;i++){
		printf("C");
	    }
	}else{
	    for(i=0;i<n/100;i++){
		printf("C");
	    }
	}
    }
    
    n=n%100;
    if(n/10>0){
	if(n/10==4){
	    printf("XL");
	}else if(n/10==9){
	    printf("XC");
	}else if(n/10>4){
	    printf("L");
	    for(i=0;i<n/10-5;i++){
		printf("X");
	    }
	}else{
	    for(i=0;i<n/10;i++){
		printf("X");
	    }
	}
    }
    n=n%10;
    if(n==4){
	printf("IV");
    }else if(n==9){
	printf("IX");
    }else if(n>4){
	printf("V");
	for(i=0;i<n-5;i++){
	    printf("I");
	}
    }else{
	for(i=0;i<n;i++){
	    printf("I");
	}
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
