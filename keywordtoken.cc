/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "keywordtoken.h"

KeyWordToken::KeyWordToken( keyword_attr_type attr ) 
	: Token(token_type::TOKEN_KEYWORD), attribute(attr) {}

KeyWordToken::~KeyWordToken() {}

// Set the attribute of this token
void KeyWordToken::set_attribute(keyword_attr_type attr){
	this->attribute = attr;
}
// Return the attribute of this token
keyword_attr_type KeyWordToken::get_attribute()
{
	return attribute;
}

string KeyWordToken::to_string() const {
	string ans = "Key Word Token";
	switch (attribute){
		case keyword_attr::KW_PROGRAM: 	{return ans + "KW_PROGRAM"}
		case keyword_attr::KW_PROCEDURE:{return ans + "KW_PROCEDURE"}
		case keyword_attr::KW_INT:		{return ans + "KW_INT"}
		case keyword_attr::KW_BOOL: 	{return ans + "KW_BOOL"}
		case keyword_attr::KW_BEGIN: 	{return ans + "KW_BEGIN"}
		case keyword_attr::KW_IF: 		{return ans + "KW_IF"}
		case keyword_attr::KW_THEN: 	{return ans + "KW_THEN"}
		case keyword_attr::KW_ELSE: 	{return ans + "KW_ELSE"}
		case keyword_attr::KW_WHILE: 	{return ans + "KW_WHILE"}
		case keyword_attr::KW_PRINT: 	{return ans + "KW_PRINT"}
		case keyword_attr::KW_NOT: 		{return ans + "KW_NOT"}
		case keyword_attr::KW_NO_ATTR: 	{return ans + "KW_NO_ATTR"}
	}
}

