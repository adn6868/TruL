/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "muloptoken.h"

MulopToken::MulopToken(const &string attr)
{
  this->attribute = *attr;
  type = 4;
}

MulopToken::~MulopToken()
{}

// Return the attribute of this token
mulop_attr_type MulopToken::get_attribute()
{
	return attribute;
}

// Set the attribute of this token
void MulopToken::set_attribute(mulop_attr_type attr){
	this->attribute = attr;
}

string * MulopToken::to_string() const{
	//return "Mulop Token Attr_Number:" + attribute;
	string ans  = "TOKEN MULOP:";
  	switch (attribute) {
    case mulop_attr_type::MULOP_MUL:
      return new string(ans + "MULOP_MUL");

    case mulop_attr_type::MULOP_DIV:
      return new string(ans + "MULOP_DIV");

    case mulop_attr_type::MULOP_AND:
      return new string(ans + "MULOP_AND");

    case mulop_attr_type::MULOP_NO_ATTR:
      return new string(ans + "MULOP_NO_ATTR");
  }
}




