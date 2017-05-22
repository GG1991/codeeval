/*Author:Guido Giuntoli*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX 26

int clean(char *buffer){
    int i, c, dic[26];
    for(i=0;i<26;i++){
        dic[i]=0;
    }
    for(i=0;i<strlen(buffer);i++){
        dic[(int)buffer[i]-97]=1;
    }
    c=0;
    for(i=0;i<26;i++){
        if(dic[i]==1){
            buffer[c]=i+97;
            c++;
        }
    }
    buffer[c]='\0';
    return c;
    
}

void CalcNext( int v[MAX], int c, int n ){
    
    int i;
    v[0]++;
    for( i=0; i<n-1; i++ ){
        if( v[i]%c==0 && v[i]!=0 ){
            v[i]=0;
            v[i+1]++;
        }
    }    
    
}

int main(int argc, const char * argv[]) {
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *buf;
    int n, c, i, j;
    int v[MAX];
    while(fgets(line, 1024, file)) {
        buf=strtok(line,",");
        sscanf(buf,"%d", &n);
        buf=strtok(NULL,"\n");
        c=clean(buf);
        for( i=0; i<MAX; i++) v[i]=0;
        
        //print the first combination whithout ","
        for( i=n-1; i>=0; i--){
            printf("%c",buf[v[i]]); 
        }        
        
        for( j=1; j<(int)pow(c,n); j++){
            printf(",");
            CalcNext( v, c, n );
            for( i=n-1; i>=0; i--){
                printf("%c",buf[v[i]]); 
            }
        }
        printf("\n");
    }
    return 0;
} 