#include <stdio.h>
void
generatePublicKey(const size_t* privateKey,
		  size_t* publicKey,
		  const size_t keySize,
		  const size_t n,
		  const size_t m);
void
encryptMessage(const size_t* publicKey,
	       const size_t keySize,
	       const size_t* message,
	       const size_t messageSize,
	       size_t** encryptedMessage,
	       size_t* encryptedMessageSize);
