/* Author : Guido Giuntoli */

#include <stdio.h>
#define MAX 2000
#define MAXN 30

enum directions { RIGHT, UP, LEFT, DOWN };

typedef struct {
    unsigned int stat : 1;
}map_t;

map_t map[MAXN][MAXN];
int v[MAXN][MAXN];

void PrintSpiral( int m, int n, int i, int j, int dir ){
      
    /*se supone que el i,j es un lugar correcto esto se cumple en el último*/
    if(map[i][j].stat == 1) return;
    
    printf("%d ",v[i][j]);
    map[i][j].stat=1;
    
    if( dir == RIGHT ){
        if( j+1 == n ){
            dir = UP;
            i++;
        }else if( map[i][j+1].stat == 1 ){
            dir = UP;
            i++;
        }else{
            j++;
        }
    }else if( dir == UP ){
        if( i+1 == m ){
            dir = LEFT;
            j--;
        }else if( map[i+1][j].stat == 1 ){
            dir = LEFT; 
            j--;
        }else{
            i++;
        }
    }else if( dir == LEFT ){
        if( j-1 == -1 ){
            dir = DOWN;
            i--;
        }else if( map[i][j-1].stat == 1 ){
            dir = DOWN;
            i--;
        }else{
            j--;
        }
    }else if( dir == DOWN ){
        if( i-1 == -1 ){
            dir = RIGHT;
            j++;
        }else if( map[i-1][j].stat == 1 ){
            dir = RIGHT;
            j++;
        }else{
            i--;
        }
    }
    
    
    PrintSpiral(m,n,i,j,dir);   
    
    return;
}

void clean(char *data){
    int i;
    for(i=0;i<MAX;i++){
        if(data[i]==';')data[i]=' '; 
    }
    return ;
}

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r"); 
    
    char line[MAX];
    char *data;
    int i,j,n,m,ofs;
    
    while(fgets(line,MAX,input)!= NULL ){ 
        data=line;
        clean(data);
        if(sscanf(data,"%d %d %n",&m,&n,&ofs)!=EOF){
            data+=ofs;
            for(i=0;i<m;i++){
                for(j=0;j<n;j++){
                    sscanf(data,"%d%n",&v[i][j],&ofs);
                    map[i][j].stat = 0;
                    data += ofs;
                }
            }
        }
        
        PrintSpiral( m, n, 0, 0, RIGHT);
        printf("\n");
    }
    fclose(input);
    return 0; 
}
