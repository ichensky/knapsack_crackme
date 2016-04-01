#include <stdio.h>
#include <assert.h>
#include "knapsack.h"
#include "bits.h"

const size_t _n = 31,
  _m = 105;

const size_t _private_key[]={2,3,6,13,27,52};
const size_t _str[]={0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0};

void printf_arr(const size_t *arr,
		const size_t size){
  size_t i;
  for(i=0;i<size;i++){
    printf("%d",arr[i]);
  }
}

int
main(void){
  
  size_t key_size = sizeof _private_key / sizeof *_private_key;
  size_t public_key[key_size];

  generate_public_key(_private_key, public_key, key_size, _n, _m);
  printf_arr(_private_key, key_size);
  printf_arr(public_key, key_size);

  size_t str_size = sizeof _str / sizeof * _str;
  size_t* encrypted_str;
  size_t encrypted_str_size;
  encrypt_str(public_key, key_size, _str, str_size,
		   &encrypted_str, &encrypted_str_size);

  printf_arr(_str, str_size);
  printf("%zu\n\n\n", encrypted_str_size);
  printf_arr(encrypted_str, encrypted_str_size);
  
  return(0);
}

