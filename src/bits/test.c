#include <stdio.h>
#include <assert.h>
#include "bits.h"

const size_t _enconding_size=256;
const size_t _number=68;
const char* _str="message";

void printf_bits(size_t *bits, size_t size){
  size_t i;
  for(i=0;i<size;i++){
    printf("%d",bits[i]);
  }
}

void number_to_bin_to_number(const size_t number, const size_t max_size){
  printf("function: %s\n", __FUNCTION__);
  printf("number: %d\n", number);
  size_t *bits;
  size_t size;
  // number to bin
  number_decimal_to_bin(max_size,number,&bits,&size);
  printf("bits from number: ");
  printf_bits(bits, size);
  printf("\n");
  size_t n;
  // bin to number
  bin_to_decimal(bits, size, &n);
  printf("number from bits: %d\n", n);
  printf("\n");
}
void str_to_bin_to_str(const char *str, const size_t max_size){
  printf("function: %s\n", __FUNCTION__);
  printf("str: %s\n", str);
  size_t *bits;
  size_t size;
  size_t str_size=sizeof str / sizeof *str; 
  // str to bin
  str_to_bin(str,str_size,max_size,&bits,&size);
  printf("bits from str: ");
  printf_bits(bits, size);
  printf("\n");
  char* s;
  // bin to str
  bin_to_str(bits, size, &s);
  printf("str from bits: %s\n", s);
  printf("\n");
}

int
main(void){
  number_to_bin_to_number(_number, _enconding_size);
  str_to_bin_to_str(_str, _enconding_size);

  return(0);
}
