/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#ifndef TOKENEOF_H
#define TOKENEOF_H

using namespace std;

#include "token.h"

// The EofToken has no attributes.

class EofToken : public Token
{
 public:
  EofToken ();
  ~EofToken ();

  string *to_string() const;

};

#endif

  
