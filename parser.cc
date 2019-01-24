#include "parser.h"
#include <string>

#define DEBUG(output):
	std::cerr <<output <<std ::endl;

Parser::Parser(Scanner *scanner_) {
	lex = scanner_;
	word = lex ->next_token();
	DEBUG("Parsing: "<< * word->to_string());

	curr_env = main_env = procedure_name = nullptr;
	curr_parameter_pos = formal_parameter_pos = -1;
	parsing_formal_parameter = false;

	emmitter = new Emmitter() 
}