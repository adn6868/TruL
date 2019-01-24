/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "idtoken.h"

IdToken::IdToken(const string& attr) : Token(token_type::TOKEN_ID), attribute(attr){}

IdToken::~IdToken()
{}

// Return the attribute of this token
keyword_attr_type IdToken::get_attribute()
{
	return attribute;
}

// Set the attribute of this token
void IdToken::set_attribute(const string& attr){
	this->attribute = *attr;
}
string IdToken::to_string() const
{
	return "ID Token attr_number: " + attribute;
}


