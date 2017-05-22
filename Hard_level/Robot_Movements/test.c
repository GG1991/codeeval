/* Author : Guido Giuntoli */

#include <stdio.h>

typedef struct {
  unsigned int stat : 1;
}map_t;

void PrintMap(map_t map[4][4]){
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      printf("%d ",map[i][j].stat);    
    }
    printf("\n");
  }
  printf("\n");
}

void CopyMap(map_t map[4][4],map_t map1[4][4]){
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      map1[i][j].stat=map[i][j].stat;    
    }
  }
}

int RobotMov(map_t map[4][4], int i, int j){
  
  if(i==3 && j==3){
    map[i][j].stat=1;
//     PrintMap(map);
    return 1;
  }else if(i<0 || i>3|| j<0|| j>3){
    return 0;
  }else{
    if(map[i][j].stat==1){
      return 0;
    }else{
      map_t map1[4][4];
      map_t map2[4][4];
      map_t map3[4][4];
      map_t map4[4][4];
      map[i][j].stat=1;
      CopyMap(map,map1);
      CopyMap(map,map2);
      CopyMap(map,map3);
      CopyMap(map,map4);
      return ( RobotMov(map1, i, j+1) + RobotMov(map2, i-1, j) + RobotMov(map3, i, j-1) + RobotMov(map4, i+1, j) ); 
    }
  }
  
}

int main(int argc, char **argv){
  
  map_t map[4][4];
  int i,j;
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      map[i][j].stat=0;    
    }  
  }
  printf("%d",RobotMov(map,0,0));

  return 0; 
}
