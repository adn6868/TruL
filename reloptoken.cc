/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "reloptoken.h"

RelopToken::RelopToken(const relop_attr_type attr): attribute(attr) 
{
  Token::set_token_type(token_type_type::TOKEN_RELOP);
}

RelopToken::~RelopToken()
{}

// Return the attribute of this token
relop_attr_type RelopToken::get_attribute()
{
	return attribute;
}

// Set the attribute of this token
void RelopToken::set_attribute(relop_attr_type attr){
	this->attribute = attr;
}
string* RelopToken::to_string(){
	return "RelopToken Attr_Number:" + attribute;
}

string *RelopToken::to_string() const {
  const string ans = "Relop token: ";
  switch (attribute) {
    case relop_attr_type::RELOP_EQ:
      return new string(ans + "RELOP_EQ");

    case relop_attr_type::RELOP_NE:
      return new string(ans + "RELOP_NE");

    case relop_attr_type::RELOP_GT:
      return new string(ans + "RELOP_GT");

    case relop_attr_type::RELOP_GE:
      return new string(ans + "RELOP_GE");

    case relop_attr_type::RELOP_LT:
      return new string(ans + "RELOP_LT");

    case relop_attr_type::RELOP_LE:
      return new string(ans + "RELOP_LE");

    case relop_attr_type::RELOP_NO_ATTR:
      return new string(ans + "RELOP_NO_ATTR");
  }
}