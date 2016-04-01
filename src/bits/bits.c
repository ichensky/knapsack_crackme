#include <stdio.h>
#include <stdlib.h>
#include "bits.h"

size_t
popcount(const size_t number){
  /* TODO: optimize alg, read: 
   * https://en.wikipedia.org/wiki/Hamming_weight 
   */
  size_t n=number-1;
  size_t j=1;
  size_t i=1;
  while(n>>=1){
    i++;
    if(!!(n&1)==1){
      j=i;;
    }
  }
  return j;
}

void
decimal_to_bin(const size_t max_size,
	       const size_t number,
	       size_t* bits){
  size_t mask=max_size;
  size_t i=0;
  while(mask>>=1){
    bits[i]=!!(mask&number);
    i++;
  }
}

void
number_decimal_to_bin(const size_t max_size,
		      const size_t number,
		      size_t** bits,
		      size_t* bits_size){
  size_t mask=max_size;
  *bits_size=popcount(mask);
  size_t size=(sizeof *bits)*(*bits_size);
  size_t* s=malloc(size);
  decimal_to_bin(mask,number,s);
  *bits=(size_t *)s;
}
void str_to_bin(const char* str,
		    const size_t str_size,
		    const size_t max_size,
		    size_t** bits,
		    size_t* bits_size){
  size_t mask=max_size;
  size_t number_bits_size=popcount(mask);
  *bits_size=number_bits_size*str_size;
  size_t size=(sizeof *bits)*(*bits_size);
  size_t* s=malloc(size);
  size_t i,j;
  for (i = 0; i < str_size; i++) {
    decimal_to_bin(mask, (size_t)str[i], (size_t*)s+i*number_bits_size); 
  }
 
  *bits=(size_t *)s;
}


void
bin_to_decimal(const size_t* bits,
	       const size_t bits_size,
	       size_t* number){

  size_t n=0;
  size_t i;
  size_t j;
  size_t tmp;
  
  for (i=0; i < bits_size ; i++) {
    j = bits_size-i-1;
    tmp=bits[i];
    if (tmp==1) {
      tmp<<=j;
      n|=tmp;
    }
  }

  *number=n;
}

