#include <stdio.h>
void
generate_public_key(const size_t* private_key,
		    const size_t key_size,
		    const size_t n,
		    const size_t m,
		    size_t* public_key
		    );
void
encrypt_str(const size_t* public_key,
	    const size_t key_size,
	    const size_t* str,
	    const size_t str_size,
	    size_t** encrypted_str,
	    size_t* encrypted_str_size);
