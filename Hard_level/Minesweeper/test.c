/* Author : Guido Giuntoli */

#include <stdio.h>
#define MAX 100

void PrintMine(int v[MAX], int m, int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){  
            printf("%d ",v[i*n+j]);
        }
        printf("\n");
    }
}
void PrintMineCEVAL(int v[MAX], int m, int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){  
            if(v[i*n+j]==-1){
                printf("%c", '*');
            }else{
                printf("%d",v[i*n+j]);
            }   
        }
    }
    printf("\n");
}

void SUMONE(int v[MAX],int m, int n, int i, int j){
    if( i<0 || j<0 || i>=m || j>=n ){
        return;
    }
    if(v[i*n+j] != -1){
        v[i*n+j]++;                
    }else{
        return;
    }       
}

void ADJ(int v[MAX],int m, int n){
    int i, j;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){            
            if(v[i*n+j] == -1){
                SUMONE(v,m,n,i+1,j);
                SUMONE(v,m,n,i+1,j+1);
                SUMONE(v,m,n,i,j+1);
                SUMONE(v,m,n,i-1,j+1);
                SUMONE(v,m,n,i-1,j);
                SUMONE(v,m,n,i-1,j-1);
                SUMONE(v,m,n,i,j-1);
                SUMONE(v,m,n,i+1,j-1);
            }
            
        }  
    }
    
}


int main(int argc, char **argv){
    
    int i,j;
    int v[MAX];
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char a,*data;
    int m, n, ofs;
    
    while (fgets(line, 1024, file)) {
        data=line;
        sscanf(data,"%d,%d;%n",&m,&n,&ofs);
        data += ofs;
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                sscanf(data,"%c%n",&a,&ofs);
                v[i*n+j] = (a == '*') ? -1 : 0;
                data += ofs;
            }  
        }
        ADJ(v,m,n);
        PrintMineCEVAL(v,m,n);
        
    }
    
    return 0; 
}
