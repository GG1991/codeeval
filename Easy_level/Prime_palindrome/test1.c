/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <math.h>

#define MAX_PRIME 1000

int IsPalindrome(int a,int n){
  if(n==1||n==0){
    return 1 ;
  }
  if(a/(int)pow(10,n-1)!=a%10){
    return 0;
  }
  return IsPalindrome(a/(int)pow(10,n-1)-a%10,n-2); 
}

int main(int argc, char **argv){
 
  int i=2,j,n,flag=0,max=0,count;
  while(i<MAX_PRIME){
     flag=0;
     for(j=2;j<i;j++){
        if(i%j==0){
	  flag=1;
	  break; //no es primo
	}
     }
     if(flag==0){
       n=0;
       while(i/(int)pow(10,n)>0)n++;
       if(IsPalindrome(i,n)&&i>max)max=i; 
     }
     i++;
  }
  printf("%d\n",max);
  return 0; 
}
