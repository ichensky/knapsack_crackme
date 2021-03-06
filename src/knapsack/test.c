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
  for(i=0;i<size-1;i++){
    printf("%d,",arr[i]);
  }
  if(i<size){
    printf("%d",arr[i]);
  }
}
void printf_bits(const size_t *bits,
		const size_t size){
  size_t i;
  for(i=0;i<size;i++){
    printf("%d",bits[i]);
  }
}

int
main(void){
  const size_t key_size = sizeof _private_key / sizeof *_private_key;
  size_t public_key[key_size];
  printf("private key: ");
  printf_arr(_private_key, key_size);
  printf("\n");

  // generate public key
  generate_public_key(_private_key, key_size, _n, _m, public_key);
  printf("public key: ");
  printf_arr(public_key, key_size);
  printf("\n");

  size_t str_size = sizeof _str / sizeof * _str;
  size_t* encrypted_str;
  size_t encrypted_str_size;
  encrypt_str(public_key, key_size, _str, str_size,
		   &encrypted_str, &encrypted_str_size);

  //char* s;
  //// bin to str
  //bin_to_str(_str, str_size, &s);
  //printf("str from bits: %s\n", s);
  //printf("\n");  

  printf("\n");
  printf("encrypted str: ");
  printf_arr(encrypted_str, encrypted_str_size);
  printf("\n");

  size_t* decrypted_str;
  size_t decrypted_str_size;
  decrypt_str(_private_key, key_size,
	      encrypted_str, encrypted_str_size,
	      _n,_m,
	      &decrypted_str,&decrypted_str_size);
  printf("\n");
  printf("decrypted str: ");
  printf_arr(decrypted_str, decrypted_str_size);
  printf("\n");
  return(0);
}

