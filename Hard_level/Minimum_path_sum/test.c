/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>
#define MAX  5
#define MAXL 10000

int m[MAX][MAX];
int n;
int min_sum;


typedef struct {
    unsigned int stat : 1;
}map_t;

void PrintMap(map_t map[MAX][MAX]){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            printf("%d ",map[i][j].stat);    
        }
        printf("\n");
    }
    printf("\n");
}

void CopyMap(map_t map[MAX][MAX],map_t map1[MAX][MAX]){
    int i,j;
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            map1[i][j].stat=map[i][j].stat;    
        }
    }
}

void MPS( map_t map[MAX][MAX], int i, int j, int sum ){
    
    if(i==n-1 && j==n-1){
        map[i][j].stat=1;
        sum += m[i][j];
        if( sum < min_sum ) min_sum=sum ;
//        PrintMap(map);
        return ;
    }else if( i>=n || j>=n ){
        return ; 
    }else{
        map_t map1[MAX][MAX];
        map_t map2[MAX][MAX];
        map[i][j].stat=1;
        sum += m[i][j];
        CopyMap(map,map1);
        CopyMap(map,map2);
        MPS(map1, i, j+1, sum);
        MPS(map2, i+1, j, sum); 
    }
    
}

int main(int argc, char **argv){
    
    
    int i, j, ofs, sum;
    char *data;
    char line[1024];
    
    map_t map[MAX][MAX];
    FILE *file = fopen(argv[1], "r");
    
    while (fgets(line, 1024, file)) {
        sscanf(line,"%d",&n);
        for(i=0;i<n;i++){
            fgets(line, 1024, file);
            data = strtok(line,",\n\0");
            for(j=0;j<n;j++){
                map[i][j].stat=0;
                sscanf(data,"%d", &m[i][j]);    
                data = strtok(NULL,",\n\0");
            }
        }
        min_sum = MAXL ;
        sum = 0;
        map[0][0].stat=1;
        MPS( map, 0, 0, sum );
        printf( "%d\n", min_sum );   
    }
    
    
    
    return 0; 
}
