/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "numtoken.h"

NumToken::NumToken(const string& attr) : attribute_(attr) 
{
  Token::set_token_type(token_type_type::TOKEN_NUM);
}

NumToken::~NumToken()
{}

// Return the attribute of this token
keyword_attr_type NumToken::get_attribute()
{
	return &attribute;
}

// Set the attribute of this token
void NumToken::set_attribute(const string& attr){
	this->attribute = *attr;
}

string* NumToken::to_string(){
	return "NumToken" + attribute;
}
