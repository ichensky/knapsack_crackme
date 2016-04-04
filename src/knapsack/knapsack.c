#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



void
generate_public_key(const size_t* private_key,
		    const size_t key_size,
		    const size_t n,
		    const size_t m,
		    size_t* public_key) {
  assert(private_key!=NULL&&key_size>0);
  size_t i;
  for (i = 0; i < key_size; i++) {
    public_key[i]=(private_key[i]*n)%m; 
  }
}


void
encrypt_str(const size_t* public_key,
	    const size_t public_key_size,
	    const size_t* str,
	    const size_t str_size,
	    size_t** encrypted_str,
	    size_t * encrypted_str_size){

  size_t m = str_size%public_key_size;
  size_t size = str_size/public_key_size;
  if (m>0) {
    size++;
  }

  size_t* p=(size_t *)malloc((sizeof *encrypted_str) * size);

  size_t i=0;
  size_t sum=0;
  size_t k=0;

  if (m>0) {
    for (; i<m; i++) {
      if(str[i]!=0){
	sum+=public_key[public_key_size-m+i];
      }
    }

    p[k]=sum;
    k++;
  }
  
  size_t j=0;
  for (;i<str_size;i+=public_key_size,k++) {
    sum=0;
    j=0;
    for(;j<public_key_size;j++) {
      if(str[i+j]!=0){
	sum+=public_key[j];
      }
      p[k]=sum;
    }
  }
  *encrypted_str=(size_t *)p;
  *encrypted_str_size = size;
}


void
decrypt_str(const size_t* private_key,
	    const size_t private_key_size,
	    const size_t* str,
	    const size_t str_size,
	    const size_t n,
	    const size_t m,
	    size_t** decrypted_str,
	    size_t* decrypted_str_size){

  size_t size=str_size*private_key_size;
  size_t* p=(size_t *)malloc((sizeof *decrypted_str) * size);
  

  size_t x=(2*n)-1;

  size_t i;
  size_t j;
  size_t sum;
  size_t res;
  size_t tmp;
  for (i=0; i<str_size; i++) {
    sum=(str[i]*x)%m;
    
    res=0;
    j=private_key_size;
  for (;j--!=0;) {
      tmp=private_key[j];
      if (res+tmp<=sum) {
	res+=tmp;
	if(res==sum){
	  break;
	}
      }
      
    }

  }

  
  *decrypted_str=(size_t *)p;
  *decrypted_str_size = size;
}
