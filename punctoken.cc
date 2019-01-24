/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "puntoken.h"

PuncToken::PuncToken(const punc_attr_type attr) : attribute(attr) 
{
  Token::set_token_type(token_type_type::TOKEN_PUNC);
}

PuncToken::~PuncToken()
{}

// Return the attribute of this token
punc_attr_type PuncToken::get_attribute()
{
	return attribute;
}

// Set the attribute of this token
void PuncToken::set_attribute(punc_attr_type attr){
	this->attribute = attr;
}

string* PuncToken::to_string()
{
	string ans = "TOKEN_PUNC:";
	switch (attribute) {
    	case punc_attr_type::PUNC_SEMI:
      	  return new string(ans + "PUNC_SEMI");
	    case punc_attr_type::PUNC_COLON:
	      return new string(ans + "PUNC_COLON");

	    case punc_attr_type::PUNC_COMMA:
	      return new string(ans + "PUNC_COMMA");

	    case punc_attr_type::PUNC_ASSIGN:
	      return new string(ans + "PUNC_ASSIGN");

	    case punc_attr_type::PUNC_OPEN:
	      return new string(ans + "PUNC_OPEN");

	    case punc_attr_type::PUNC_CLOSE:
	      return new string(ans + "PUNC_CLOSE");

	    case punc_attr_type::PUNC_NO_ATTR:
	      return new string(ans + "PUNC_NO_ATTR");
	  }
}





