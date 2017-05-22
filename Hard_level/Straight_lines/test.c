/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXP 120

typedef struct {
    unsigned int stat : 1;
}conect_t;



int AreInLine( int coor[MAXP], int a, int b, int c ){
    int v0[2], v1[2];
    v0[0]=coor[b*2]-coor[a*2];
    v0[1]=coor[b*2+1]-coor[a*2+1];
    v1[0]=coor[c*2]-coor[a*2];
    v1[1]=coor[c*2+1]-coor[a*2+1];
    if(v0[0]*v1[1]-v0[1]*v1[0]==0){        
        return 1;
    }else{
        return 0;
    }
}

int ItWasNotCounted(int coor[MAXP],conect_t conect[MAXP][MAXP],int num_nodes, int count,int i,int j,int k){
    
    int l,n,a,b,c,flg=0;
    int v0[2], v1[2];
    
    for(l=0;l<count;l++){
        flg=0;
        for(n=0;n<num_nodes&&flg<2;n++){
            if(conect[n][l].stat==1 && flg==0){
                a=n;
                flg=1;
                n++;
            }
            if(n<num_nodes){
                if(conect[n][l].stat==1 && flg==1){
                    b=n;
                    flg=2;
                }  
            }
        }
        
        v0[0]=coor[b*2]-coor[a*2];
        v0[1]=coor[b*2+1]-coor[a*2+1];
        v1[0]=coor[i*2]-coor[j*2];
        v1[1]=coor[i*2+1]-coor[j*2+1];
        if(v0[0]*v1[1]-v0[1]*v1[0]==0){        
            return 0;
        }
    }
    return 1;
}

int HowManyLines( int coor[MAXP], int c ){
    
    conect_t conect[MAXP][MAXP];
    int i,j,k,count=0;
    
    for(i=0;i<MAXP;i++){
        for(j=0;j<MAXP;j++){
            conect[i][j].stat=0;
        }
    }
    
    for(i=0;i<c-2;i++){
        for(j=i+1;j<c-1;j++){
            for(k=j+1;k<c;k++){
                
                if(AreInLine(coor,i,j,k)){
                    if(ItWasNotCounted(coor,conect,c,count,i,j,k)){
                        //printf("In line = %d %d, %d %d, %d %d \n",coor[i*2],coor[i*2+1],coor[j*2],coor[j*2+1],coor[k*2],coor[k*2+1]);
                        conect[i][count].stat=1;
                        conect[j][count].stat=1;
                        conect[k][count].stat=1;
                        count++; 
                    }                     
                }                
                
            }
        }            
    }
    
    return count;
}

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    int i;
    char line[LINE_LENGTH],*data;
    int coor[MAXP*2];
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        data=strtok(line,"|");
        i=0;
        while(data != NULL){
            sscanf(data,"%d %d",&coor[i],&coor[i+1]);
            //printf("%d %d \n ",coor[i],coor[i+1]);
            i+=2;
            data=strtok(NULL,"|");
        }
        printf("%d\n",HowManyLines(coor,i/2));
    }
    
    fclose(input);
    return; 
}
