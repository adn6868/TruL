/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "eoftoken.h"

EofToken::EofToken()
{
  type = 7;
}

EofToken::~EofToken()
{}

EofToken::*tostring(){
	return "#7 end of File";
}