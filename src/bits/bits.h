#include <stdio.h>

/*
 * Function: popcount 
 * --------------------
 *
 *  returns: count of bits in number 
 */
size_t
popcount(const size_t number);

/*
 * Function: decimal_to_bin 
 * --------------------
 *
 *  max_size: max possible size of number; for ex. ascii=255
 *  number: number that would be converted to arr of bits
 *  bits: array of bits 
 */
void
decimal_to_bin(const size_t max_size,
	       const size_t number,
	       size_t* bits);

/*
 * Function: number_decimal_to_bin 
 * --------------------
 *
 *  max_size: max possible size of number; for ex. ascii=255
 *  number: number that would converted to arr of bits
 *  bits: array of bits
 *  bits_size: size of bits array 
 */
void
number_decimal_to_bin(const size_t max_size,
		      const size_t number,
		      size_t** bits,
		      size_t* bits_size); 

/*
 * Function: str_to_bin 
 * --------------------
 *
 *  str: string that would be converted to arr of bits
 *  str_size: size of srt array
 *  max_size: max possible size of number; for ex. ascii=256
 *  bits: array of bits
 *  bits_size: size of bits array 
 */
void
str_to_bin(const char* str,
	   const size_t str_size,
	   const size_t max_size,
	   size_t** bits,
	   size_t* bits_size); 

/*
 * Function: bin_to_decimal 
 * --------------------
 *
 *  bits: array of bits
 *  bits_size: size of bits array 
 *  number: number that would converted to arr of bits
 */
void
bin_to_decimal(const size_t* bits,
	       const size_t bits_size,
	       size_t* number);

/*
 * Function: bin_to_str 
 * --------------------
 *
 *  bits: array of bits
 *  bits_size: size of bits array 
 *  number: number that would converted to arr of bits
 */
void
bin_to_str(const size_t* bits,
	   const size_t bits_size,
	   char** str);
