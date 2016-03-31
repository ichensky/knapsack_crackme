#include <stdio.h>
#include <assert.h>
#include "bits.h"

const size_t _enconding_size=250;
const size_t _number=65;
const char* _str="message";

int
main(void){
  size_t *bits;
  size_t size;
  number_decimal_to_bin(_enconding_size,_number,&bits,&size);
  
  size_t i;
  for(i=0;i<size;i++){
    printf("%d",bits[i]);
  }
  printf("\n\n");
  size_t str_size=sizeof _str / sizeof *_str;
  message_to_bin(_str,str_size,_enconding_size,&bits,&size);

  for(i=0;i<size;i++){
    printf("%d",bits[i]);
  }
  
  printf("\n");
  
  return(0);
}
