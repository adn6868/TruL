/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "token.h"

Token::Token(const token_type type_ ) : type(type_) {}

Token::~Token() {}

void Token::set_token_type (token_type_type type_)
{
  this->type = type_;
}

token_type_type Token::get_token_type() const
{
  return type;
}
