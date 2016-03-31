#include <assert.h>
#include <stdio.h>
#include <stdlib.h>



void
generatePublicKey(const size_t* privateKey,
		  size_t* publicKey,
		  const size_t keySize,
		  const size_t n,
		  const size_t m) {
  assert(privateKey!=NULL&&keySize>0);
  size_t i;
  for (i = 0; i < keySize; i++) {
    publicKey[i]=(privateKey[i]*n)%m; 
  }
}

void
encryptMessage(const size_t* publicKey,
	       const size_t keySize,
	       const size_t* message,
	       const size_t messageSize,
	       size_t** encryptedMessage,
	       size_t * encryptedMessageSize){

  *encryptedMessage=(size_t *)malloc(sizeof(size_t) * messageSize);
  size_t i;
  for (i = 0; i < messageSize; i++) {
    (*encryptedMessage)[i]=message[i];
  }

  *encryptedMessageSize = messageSize;
}
