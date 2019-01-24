/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#ifndef IDTOKEN_H
#define IDTOKEN_H

using namespace std;

#include "token.h"
#include <string>

class IdToken : public Token
{
 public:
  IdToken(const string& attr ="");
  ~IdToken() override;

  string get_attribute();
  void set_attribute(const string& attr);
  string to_string() const;

 private:
  const string attribute;
};

#endif
