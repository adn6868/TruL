/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */

#ifndef TOKEN_H
#define TOKEN_H

using namespace std;

#include <string>


typedef enum token_type { TOKEN_KEYWORD =  0,
			  TOKEN_PUNC    =  1,
			  TOKEN_RELOP   =  2,
			  TOKEN_ADDOP   =  3,
			  TOKEN_MULOP   =  4,
			  TOKEN_ID      =  5,
			  TOKEN_NUM     =  6,
			  TOKEN_EOF     =  7,
			  TOKEN_NO_TYPE = 99 } token_type_type;

class Token
{

 public:
  Token(token_type type_ = token_type::TOKEN_NO_TYPE);
  virtual ~Token();
  virtual string to_string() const {
    return "";
  }
  void set_token_type (token_type_type type);
  token_type_type get_token_type() const;

 private:
  token_type_type type;
};

#endif
