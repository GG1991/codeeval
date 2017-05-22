/* Author : Guido Giuntoli
 * 
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define FRIEND_NUM 100
#define STREET_ADR 10000
#define LINE_LENGTH FRIEND_NUM*5+6

int main(int argc, char **argv){
 
  FILE *input = fopen(argv[1],"r");
  int na,i,offset;
  int a[FRIEND_NUM];
  int up, down, dist_down, dist_up;
  char line[LINE_LENGTH];
  char *data = line;
  double sum;
  
  while( fgets(line, LINE_LENGTH, input) != NULL ){
    sum=0;dist_down=0;dist_up=0;
    sscanf(line, "%d%n", &na, &offset);
    data=line+offset;
    for(i=0;i<na;i++)
    {
      sscanf(data,"%d%n", &a[i], &offset);
      data+=offset;
      sum+=a[i];
    } 
    down=floor(sum/na);
    up=ceil(sum/na);
    for(i=0;i<na;i++)
    {
       dist_up+=abs(up-a[i]); 
       dist_down+=abs(down-a[i]);
    }
    if(dist_up < dist_down){
      printf("%d\n",dist_up);  
    }else{
      printf("%d\n",dist_down);
    }
  }  
  fclose(input);
  return 0; 
}
