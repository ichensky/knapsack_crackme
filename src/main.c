#include <stdio.h>
#include <assert.h>

const unsigned int _n = 31,
          _m = 105;

const unsigned int _privateKey[]={2,3,6,13,27,52};
const unsigned int _message[]={0,1,1,0,0,0,1,1,0,1,0,1,1,0,1,1,1,0};

void printfArr(int* arr);

int main(void){
  
  unsigned int keySize = sizeof _privateKey / sizeof *_privateKey;
  int publicKey[keySize];
  generatePublicKey();
  
  return(0);
}
