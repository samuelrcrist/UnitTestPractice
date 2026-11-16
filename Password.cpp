#include "Password.h"
#include <string>
#include <cctype>

/*
  The function receives a string counts how many times the same character 
  occurs at the beginning of the string, before any other characters (or the
  end of the string). The function is case-sensitive so 'Z' is different than
  'z' and any ASCII characters are allowed.
*/
int Password::count_leading_characters(std::string phrase){
  int repetition = 1;
  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

/*
  receives a string and returns whether it has both at least one upper-case
  letter and at least one lower-case letter
*/
bool Password::has_mixed_case(std::string pass){
  int c_up = 0;
  int c_low = 0;

  if(pass.empty()) {return false;}

  for(std::size_t i = 0; i < pass.length(); i++) {
    unsigned char character = static_cast<unsigned char>(pass[i]);
    if(std::isupper(character)) {
      c_up++;
    }else if(std::islower(character)) {
      c_low++;
    }
  }

  if(c_low > 0 && c_up > 0) {
    return true;
  } else{
    return false;
  }
}
