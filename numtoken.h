/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#ifndef NUMTOKEN_H
#define NUMTOKEN_H

using namespace std;

#include "token.h"
#include <string>

class NumToken : public Token
{
 public:
  NumToken();
  NumToken(const string& attr);
  ~NumToken();

  string *get_attribute();
  void set_attribute(const string& attr);

  string *to_string() const;

 private:
  string *attribute;
};

#endif
