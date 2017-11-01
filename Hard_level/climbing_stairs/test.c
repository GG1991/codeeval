#include <stdio.h>
#include <gmp.h>

mpz_t a;
mpz_t comb;

int r;

mpz_t * climb(mpz_t * n)
{
  if(mpz_cmp_ui(*n, 4) < 0 ){
    return n;
  }
  mpz_t b;mpz_init(b);
  mpz_t c;mpz_init(c);
  mpz_t d;mpz_init(d);
  mpz_t e;mpz_init(e);
  mpz_t f;mpz_init(f);
  mpz_t g;mpz_init(g);
  mpz_t h;mpz_init(h);
   
  r = mpz_cdiv_q_ui (b, *n, 2);
  mpz_sub (c, *n, b);
  mpz_sub_ui (d, b, 1);
  mpz_sub_ui (e, c, 1);
  
  mpz_t b_c; mpz_init_set( b_c, *climb(&b) );
  mpz_t c_c; mpz_init_set( c_c, *climb(&c) );
  mpz_t d_c; mpz_init_set( d_c, *climb(&d) );
  mpz_t e_c; mpz_init_set( e_c, *climb(&e) );
  mpz_mul (f, b_c, c_c);
  mpz_mul (g, d_c, e_c);
//  mpz_mul (f, *climb(&b), *climb(&c));
//  mpz_mul (g, *climb(&d), *climb(&e));
  mpz_add (comb, f, g);
//  gmp_printf("%Zd %Zd %Zd %Zd %Zd %d\n", b, c, d, e, f, r );

//  return climb( (n % 2) ? (n/2+1):(n/2) ) * climb( n/2 )  \
//    + climb( (n % 2) ? ((n/2+1)-1):((n/2)-1) ) * climb( n/2 - 1 );
//  return climb( (n % 2) ? (n/2+1):(n/2) ) * climb( n/2 )  \
//    + climb( (n % 2) ? ((n/2+1)-1):((n/2)-1) ) * climb( n/2 - 1 );
  return &comb;
}

int main(int argc,char **argv)
{
  FILE *fm=fopen(argv[1],"r");
  char buf[64];

  mpz_init(comb);

  while(fgets(buf,64,fm)!=NULL){
    mpz_init_set_str (a, buf, 10);
//climb(&a);
    gmp_printf("%Zd\n", *climb(&a));
  }
  return 0;
}
