#ifndef PARSER_H
#define PARSER_H

#include <isotream>
#include <string>
#include <vector>

#include "token.h"
#include "keywordtoken.h"
#include "punctoken.h"
#include "reloptoken.h"
#include "addoptoken.h"
#include "muloptoken.h"
#include "idtoken.h"
#include "numtoken.h"
#include "eoftoken.h"
#include "scanner.h"

using namespace std;

class Parser{
public:
	explicit Parser(Scanner *scanner_);
	~Parser

	bool parsing();
	bool end_of_file() const;
private:
	Scanner * lex;
	Token * word;
	sring * curr_env;
	string * main_env;
	string *procedure_name;
	int curr_parameter_pos;
	int formal_parameter_pos;
	bool parsing_formal_parameter
	Symbol_Table stab;

	void next();


}