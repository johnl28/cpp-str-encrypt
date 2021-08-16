/*
	A basic cipher algorithm to encode and decode a string.
*/

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <fstream>
#include <cstring>

//using the standard namespace
using namespace std;

//encode and decode keys
const char ENCODE_KEY[] = "435iu3j4toi3434";
const char DECODE_KEY[] = "435iu3j4toi3434";


// encode function with 2 parameters. The first one is a pointer to the detination
// Second one, a pointer to the input text
void Encode(char *dest, const char *src)
{
  int i = 0;

  //iterate the text we want to encrypt, char by char
  for(int x = 0; x < strlen(src); ++x )
  {

    // verify if i is greatest than the size of the key, if yes we iterate gain the key
    if(i >= strlen(ENCODE_KEY))
    {
      i = 0;
    }
    /* each character has a number which represent himself, we take one character from our key and one from our text and we just gather the numbers of them
    */ 
    dest[x] = (int)ENCODE_KEY[i] + (int)src[x];
    ++i;
  }
}


//same as encode but we subtract them now
void Decode(char *dest, const char *src)
{
  int i = 0;
  for(int x = 0; x < strlen(src); ++x )
  {
    if(i >= strlen(DECODE_KEY))
    {
      i = 0;
    }
    dest[x] = (int)src[x]-(int)DECODE_KEY[i];
    ++i;
  }
}

int main() 
{
  const char *buff = "Hello, i'm john and this is an encrypted text.";
  char encryptedBuff[500];

  Encode(encryptedBuff, buff);
  cout << encryptedBuff << endl;

  char dencryptedBuff[500];
  Decode(dencryptedBuff, encryptedBuff);
  cout << dencryptedBuff << endl;
  return 0;
}
