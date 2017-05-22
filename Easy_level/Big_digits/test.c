/* Author : Guido Giuntoli */

#include <stdio.h>
#include <string.h>

#define LINE_LENGTH 1024
#define MAXN 100

int main(int argc, char **argv){
    
    FILE *input = fopen(argv[1],"r");
    char line[LINE_LENGTH],*data,*d[10];
    int n,ofs,v[MAXN],i,j,k;
    char c;
    
    d[0]="-**--*--*-*--*-*--*--**-------";
    d[1]="--*---**----*----*---***------";
    d[2]="***-----*--**--*----****------";
    d[3]="***-----*--**-----*-***-------";
    d[4]="-*---*--*-****----*----*------";
    d[5]="****-*----***-----*-***-------";
    d[6]="-**--*----***--*--*--**-------";
    d[7]="****----*---*---*----*--------";
    d[8]="-**--*--*--**--*--*--**-------";
    d[9]="-**--*--*--***----*--**-------";
    
    while( fgets(line,LINE_LENGTH,input)!= NULL ){ 
        data=line;
        n=0;
        while( sscanf(data,"%d%n",&c,&ofs)!=EOF ){
            if('0'<=c && c<='9' ){
                v[n]=c-'0';
                n++;
            }
            data+=ofs;
        }
        
        for(k=0;k<6;k++){
            for(i=0;i<n;i++){
                for(j=0;j<5;j++){
                    printf("%c\n",d[v[i]][j]); 
                }
            }
            printf("\n");
        }
        
    }
    
    fclose(input);
    return; 
}