/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 32

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  double a,b;
  char line[LINE_LENGTH];

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    sscanf(line,"%lf;%lf",&a,&b);
    if(a>b){
      printf("ERROR\n");
    }
    if(a==b){
      printf("ZERO\n");
    }
    while(b-a>=100.00-0.001){     
      b=b-100.0; 
      (b-a>0+0.001)?printf("ONE HUNDRED,"):printf("ONE HUNDRED\n");
    }
    while(b-a>=50.00-0.001){
      b=b-50.0; 
      (b-a>0+0.001)?printf("FIFTY,"):printf("FIFTY\n");
    }
    while(b-a>=20.00-0.001){
      b=b-20.0; 
      (b-a>0+0.001)?printf("TWENTY,"):printf("TWENTY\n");
    }
    while(b-a>=10.00-0.001){
      b=b-10.0; 
      (b-a>0+0.001)?printf("TEN,"):printf("TEN\n");
    }
    while(b-a>=5.00-0.001){
      b=b-5.0; 
      (b-a>0+0.001)?printf("FIVE,"):printf("FIVE\n");
    }
    while(b-a>=2.00-0.001){
      b=b-2.0; 
      (b-a>0+0.001)?printf("TWO,"):printf("TWO\n");
    }
    while(b-a>=1.00-0.001){
      b=b-1.0; 
      (b-a>0+0.001)?printf("ONE,"):printf("ONE\n");
    }
    while(b-a>=0.5-0.001){
      b=b-0.5; 
      (b-a>0+0.001)?printf("HALF DOLLAR,"):printf("HALF DOLLAR\n");
    }
    while(b-a>=0.25-0.001){
      b=b-0.25; 
      (b-a>0+0.001)?printf("QUARTER,"):printf("QUARTER\n");
    }
    while(b-a>=0.1-0.001){
      b=b-0.1; 
      (b-a>0+0.001)?printf("DIME,"):printf("DIME\n");
    }
    while(b-a>=0.05-0.001){
      b=b-0.05;
      (b-a>0+0.001)?printf("NICKEL,"):printf("NICKEL\n");
    }
    while(b-a>=0.01-0.001){
      b=b-0.01; 
      (b-a>0+0.001)?printf("PENNY,"):printf("PENNY\n");
    }    
  }
  
  fclose(input);
  return; 
}
