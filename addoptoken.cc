/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
 #include "addoptoken.h"

AddopToken::AddopToken(const addop_attr_type attr) : attribute(attr) {
  Token::set_token_type(token_type_type::TOKEN_ADDOP);
}

AddopToken::AddopToken()
    : AddopToken(addop_attr_type::ADDOP_NO_ATTR) {}

AddopToken::~AddopToken() {}

addop_attr_type AddopToken::get_attribute() const {
  return attribute;
}

void AddopToken::set_attribute(const addop_attr_type attr) {
  this->attribute = attr;
}

string *AddopToken::to_string() const {
  string ans = "TOKEN_ADDOP:";
  switch (attribute) {
    case addop_attr_type::ADDOP_ADD:
      return new string(ans + "ADDOP_ADD");

    case addop_attr_type::ADDOP_SUB:
      return new string(ans + "ADDOP_SUB");

    case addop_attr_type::ADDOP_OR:
      return new string(ans + "ADDOP_OR");

    case addop_attr_type::ADDOP_NO_ATTR:
      return new string(ans + "ADDOP_NO_ATTR");
  }
}