/* Author : Guido Giuntoli
 */

#include <stdio.h>
#include <math.h>

#define MAX_ELEM 10

int IsPalindrome(int a,int n){
  if(n==1||n==0){
    return 1 ;
  }
  if(a/(int)pow(10,n-1)!=a%10){
    return 0;
  }
  return IsPalindrome(a/(int)pow(10,n-1)-a%10,n-2); 
}

int main(int argc, char **argv){
    
    
    FILE *file = fopen(argv[1], "r");
    char line[1024];
    char *data;
    int r_i[MAX_ELEM], i, a1, a2, n, np, c, n_r, n_c;
    while ( fgets(line, 1024, file) != NULL ) {
        i=0;
        data=line;
        c = 0;
        sscanf(data,"%d %d", &a1, &a2);
        //armamos todos los posibles r_i
        n_r = a2 - a1 + 1;
        while( n_r > 0 ){
            //n_r es la cantidad de elementos de r_i, al inicio hay una sola combinación n_c=1
            n_c = a2 - a1 + 1 - n_r + 1;
            while( n_c > 0 ){
                for(i=0;i<n_r;i++){
                    r_i[i]=a1+i+n_c-1;
                }
                //con r_i contamos la cantidad de palindromos dentro (cada uno tiene longitud n)
                np = 0;
                n = n_r-1;
                while( n >= 0 ){
                    if( IsPalindrome(r_i[n],(int)log10(r_i[n])+1)) np++;
                    n--;
                }
                // si esa cantidad es par entonces este r_i es "interesting"
                if( np%2 == 0 ) c++;
                n_c--;
            }
            n_r--;
        }
        printf( "%d\n" , c );
    }
    
    
    return 0; 
}
