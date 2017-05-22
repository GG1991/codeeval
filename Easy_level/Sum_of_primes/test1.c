/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#define N_PRIMES 1000

int main(int argc, char **argv){
 
  int i=2,j,sum=0,flag,count;
  while(count<N_PRIMES){
     flag=0;
     for(j=2;j<i;j++){
        if(i%j==0){
	  flag=1;
	  break; //no es primo
	}
     }
     if(flag==0){
       sum+=i; 
       count++;
     }    
     i++;
  }
  printf("%d\n",sum);
  return 0; 
}
