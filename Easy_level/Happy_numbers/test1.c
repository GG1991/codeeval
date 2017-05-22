/* Author : Guido Giuntoli */

#include <stdio.h>
#include <math.h>

int IsHappy(int n){
  int nd=0,sum=0,i;
  while(n/(int)pow(10,nd)>=10){
    nd++;
  }
  if(nd==0){
    if(n==1 || n==7){
      return 1;      
    }else{
      return 0;
    }
  }else{
    for(i=nd;i>=0;i--){
      sum+=pow((n%(int)pow(10,i+1))/(int)pow(10,i),2);
    }
    return IsHappy(sum);
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int a; 
  char line[32];

  while(fgets(line,32,input)!= NULL ){ 
    sscanf(line,"%d",&a);
    printf("%d\n",IsHappy(a));      
  }  
  fclose(input);
  return; 
}
