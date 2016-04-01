#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



void
generate_public_key(const size_t* private_key,
		  size_t* public_key,
		  const size_t key_size,
		  const size_t n,
		  const size_t m) {
  assert(private_key!=NULL&&key_size>0);
  size_t i;
  for (i = 0; i < key_size; i++) {
    public_key[i]=(private_key[i]*n)%m; 
  }
}

void
encrypt_str(const size_t* public_key,
	       const size_t key_size,
	       const size_t* str,
	       const size_t str_size,
	       size_t** encrypted_str,
	       size_t * encrypted_str_size){

  *encrypted_str=(size_t *)malloc(sizeof(size_t) * str_size);
  size_t i;
  for (i = 0; i < str_size; i++) {
    (*encrypted_str)[i]=str[i];
  }

  *encrypted_str_size = str_size;
}
