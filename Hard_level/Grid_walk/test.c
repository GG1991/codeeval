/* Author : Guido Giuntoli */

#include <stdio.h>
#include <math.h>
#define MAX 600
#define MN  19

typedef struct {
  unsigned int stat : 1;
}map_t;

map_t map[MAX][MAX];
int counter;
//FILE *fp;

int SOD( int n ){
    if( (n / 10) < 1 ) return n;
    return n/(int)pow(10,(int)log10(n)) + SOD( n%(int)pow(10,(int)log10(n)) );  
}

void GW( int i, int j ){
  
  if( map[i+MAX/2][j+MAX/2].stat==0 && ( SOD(fabs(i)) + SOD(fabs(j)) ) <= MN ){
    map[i+MAX/2][j+MAX/2].stat=1;
    counter++;
//    fprintf(fp,"%d %d %d\n",i,j,SOD(fabs(i)) + SOD(fabs(j)));
    GW( i+1, j );
    GW( i-1, j );
    GW( i, j+1 );
    GW( i, j-1 );
  }
  return;   
    
}

int main(int argc, char **argv){
  
  int i,j;
  counter=0;
//  fp=fopen("out.dat","w");
  for(i=0;i<MAX;i++){
    for(j=0;j<MAX;j++){
      map[i][j].stat=0;    
    }  
  }
  GW( 0, 0 );
  printf("%d",counter);
//  fclose(fp);
  return 0; 
}
