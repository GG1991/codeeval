/* Author : Guido Giuntoli
 * 
 * TRICK: find the median
 * 
 * STATUS: FINISHED 12/03/2016
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FRIEND_NUM 100
#define STREET_ADR 10000
#define LINE_LENGTH FRIEND_NUM*5+6

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int na,i,offset;
  int a[FRIEND_NUM];
  int h, dist;
  char line[LINE_LENGTH];
  char *data = line;
  double sum;
  
  while( fgets(line, LINE_LENGTH, input) != NULL ){
    sum=0; dist=0;
    sscanf(line, "%d%n", &na, &offset);
    data=line+offset;
    for(i=0;i<na;i++)
    {
      sscanf(data,"%d%n", &a[i], &offset);
      data+=offset;
    } 
    qsort(a, na, sizeof(int), cmpfunc);
    i=floor(na/2);
    h=a[i];
    for(i=0;i<na;i++)
    {
      dist+=abs(a[i]-h);   
    }
    printf("%d\n",dist);
  }  

  fclose(input);
  return 0; 
}
