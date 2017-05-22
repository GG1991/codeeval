/* Author : Guido Giuntoli */

#include <stdio.h>

void qsort_g(double *num, int n){
  int i,j,min;
  double aux;
  for(i=0; i<n; i++){
    min=i;
    for(j=i+1; j<n; j++){
      if(num[j]<num[min]) min = j;
    }  
    aux=num[i];
    num[i]=num[min];
    num[min]=aux;
  }
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int i,j,ofs;
  char line[1024];
  double num[1024];
  char *data;
  
  while(fgets(line,1024,input)!= NULL ){ 
    i=0;
    data=line;
    while(sscanf(data,"%lf%n",&num[i],&ofs)!=EOF){
      i++;
      data+=ofs;
    }
    qsort_g(num, i);
    for(j=0;j<i;j++){
      printf("%0.3lf ",num[j]);
    }
    printf("\n");
  }
  
  fclose(input);
  return; 
}
