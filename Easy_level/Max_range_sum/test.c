/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*data;
    int n,ofs,i,k,c,max,aux;
    int v[MAXN];
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        
        data=strtok(line,";");       
        sscanf(data,"%d",&n);
        data=strtok(NULL,";");
        c=0;
        while( sscanf(data,"%d %n",&v[c],&ofs)!=EOF ){
            data+=ofs;
            c++;
        }
        
        for(i=0;i<c-n+1;i++){
            aux=0;
            for(k=0;k<n;k++){
                aux+=v[i+k];
            }
            if(i==0)max=aux;
            if(max<aux)max=aux;
        }
        if(max>0){
            printf("%d\n",max);
        }else{
            printf("0\n");
        }
        
    }
    
    fclose(input);
    return; 
}