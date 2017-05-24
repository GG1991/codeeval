/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 1000

int cmpfunc (const void * aa, const void * bb)
{
   int  h1,h2,m1,m2,s1,s2; 
   char a[20];
   char b[20];
   strcpy(a,(char *)aa);
   strcpy(b,(char *)bb);
   
   h1 = atoi(strtok(a,": \n"));
   m1 = atoi(strtok(NULL,": \n"));
   s1 = atoi(strtok(NULL,": \n"));
   h2 = atoi(strtok(b,": \n"));
   m2 = atoi(strtok(NULL,": \n"));
   s2 = atoi(strtok(NULL,": \n"));
   if(h1>h2){
       return 1;
   }else if(h1<h2){
       return -1;
   }else if(h1==h2){
       if(m1>m2){
           return 1;
       }else if(m1<m2){
           return -1;
       }else if(m1==m2){
           if(s1>s2){
               return 1;
           }else if(s1<s2){
               return -1;
           }else if(s1==s2){
               return 0;
           }
       }
   }
}

int swap(char a[20],char b[20]){

    char c[20];
    strcpy(c,a);
    strcpy(a,b);
    strcpy(b,c);
    return 0;

}

int sort_slow(char **a,int n){

    int i,j,imax;
    char c[20];
    for(i=0;i<n-1;i++){
	strcpy(c,a[i]);
	imax=i;
	for(j=i+1;j<n;j++){
	    if(cmpfunc((void*)a[j],(void*)c)>0){
		strcpy(c,a[j]);
		imax=j;
	    }
	}
	swap(a[imax],a[i]);
    }
    return 0;
}

int main(int argc, char **argv){
 
  FILE  *input = fopen(argv[1],"r");
  char  line[LINE_LENGTH];
  char  * a[20];
  char  *data;
  int   n,i;

  while(fgets(line,LINE_LENGTH,input)!= NULL ){ 
    n=0;
    data=strtok(line," \n");
    while(data!=NULL){
	a[n] = (char*)malloc(strlen(data)*sizeof(char));
	strcpy(a[n],data);
	n++;
	data=strtok(NULL," \n");
    }

    sort_slow(a,n);
    for(i=0;i<n;i++){
       printf("%s ",a[i]);
    }
    printf("\n");
  }
  
  fclose(input);
  return 0; 
}
