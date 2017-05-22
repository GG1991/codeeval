/* Author : Guido Giuntoli */

#include <stdio.h>
#include <math.h>

int IsPrime(int n){
  int j,flag;
  flag=0;
  for(j=2;j<n;j++){
    if(n%j==0){
      flag=1;
      break; //no es primo
    }
  }
  if(flag==0){
    return 1;
  }else{
    return 0;
  }  
}

int main(int argc, char **argv){
  
  int j,n,flag,a,m;
  char line[32];
  FILE *input = fopen(argv[1],"r");
  
  while(fgets(line,32,input)!= NULL){
    sscanf(line,"%d",&a);
    flag=0;
    n=2;
    m=(int)pow(2,n)-1;
    while(a > m){
      if(IsPrime((int)m)){
	if(flag==1){
	  printf(", %d",m);
	}else{
	  printf("%d",m);
	  flag=1;
	}
      }
      n++;
      m=(int)pow(2,n)-1;
    }
    printf("\n"); 
  }
  return 0; 
}
