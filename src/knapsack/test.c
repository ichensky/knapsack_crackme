#include <stdio.h>
#include <assert.h>
#include "knapsack.h"

const size_t _n = 31,
  _m = 105;

const size_t _privateKey[]={2,3,6,13,27,52};
const size_t _message[]={0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0};
void
printfArr(const char* str,
	       const size_t* arr,
	       const size_t size);

int
main(void){
  
  size_t keySize = sizeof _privateKey / sizeof *_privateKey;
  size_t publicKey[keySize];

  generatePublicKey(_privateKey, publicKey, keySize, _n, _m);
  printfArr("privateKey:", _privateKey, keySize);
  printfArr("publicKey:", publicKey, keySize);

  size_t messageSize = sizeof _message / sizeof * _message;
  size_t* encryptedMessage;
  size_t encryptedMessageSize;
  encryptMessage(publicKey, keySize, _message, messageSize,
		   &encryptedMessage, &encryptedMessageSize);

  printfArr("mesage:", _message, messageSize);
  printf("%zu\n\n\n", encryptedMessageSize);
  printfArr("encryptedMessage:", encryptedMessage, encryptedMessageSize);
  
  return(0);
}

void
printfArr(const char* str,
	  const size_t* arr,
	  const size_t size){
  printf("%s{", str);
  unsigned i;
  if (size>1) {
    for(i=0;i<size-1;i++){
      printf("%zu,",arr[i]);
    }
      printf("%zu",arr[i]);
  }
  else if (size>0){
    printf("%zu\n", arr[0]);
  }
  printf("%s", "}\n");
}
