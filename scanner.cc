/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "scanner.h"

Scanner::Scanner (char *filename) : buf(new Buffer(filename)) {}

Scanner::~Scanner ()
{
  delete buf;
}

void Scanner::scanner_fatal_error(const string& message)
{
  cerr << "Exiting on Scanner Fatal Error: " << message << endl;
  exit (-1);
}

bool in_set(const char character, const vector<char>& a_set ){
  for (const char c : a_set){
    if (character == c){
      return true;
    }
  }
}

Token *Scanner::next_token()
{
  Token *lexeme = NULL;
  char c;
  int state = 0;
  string attr;

  while (state != 999){
    c = buf->next_char();

    switch(state){
      case 0:
        if (is_alpha(c) && !inset(c, {'a','b','e','i','l','n','o','p','t','w'})){
          state = 1;
          att.push_back(c);
        }else if (c == 'a'){
          state = 2;
          attr.push_back(c);
        }else if (c == 'b'){
          state = 3;
          attr.push_back(c);
        }else if (c == 'e'){
          state = 4;
          attr.push_back(c);
        }else if (c == 'i'){
          state = 5;
          attr.push_back(c);
        }else if (c == 'l'){
          state = 6;
          attr.push_back(c);
        }else if (c == 'n'){
          state = 7;
          attr.push_back(c);
        }else if (c == 'o'){
          state = 8;
          attr.push_back(c);
        }else if (c == 'p'){
          state = 9;
          attr.push_back(c);
        }else if (c == 't'){
          state = 10;
          attr.push_back(c);
        }else if (c == 'w'){
          state = 11;
          attr.push_back(c);
        }else if (c == ';'){
          state = 12;
        }else if (c == ':'){
          state = 13;
        }else if (c == ","){
          state = 14;
        }else if (c == "("){
          state = 15;
        }else if (c == ")"){
          state = 16;
        }else if (c == "="){
          state = 17;
        }else if (c == "<"){
          state = 18;
        }else if (c == ">"){
          state = 19;
        }else if (c == "+"){
          state = 20;
        }else if (c == "-"){
          state = 21;
        }else if (c == "*"){
          state = 22;
        }else if (c == "/"){
          state = 23;
        }else if (is_digit(c)){
          state = 24;
        }else if (c == EOF_MARKER){
          state = 25;
        }else {
          scanner_fatal_error(string("illegal character: ")+c );
        }
        break;
    // For all the state, please check scannerState.txt
        
      case 1: //IDENTIFIER:
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else{
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 2: //A
        if (c == 'n'){
          state = 40;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 40: //AN
        if (c == 'd'){
          state = 41;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break

      case 41: //AND
        if (is_alphanum(c)){
          state = 1;
          attr.push_back(c);
        }else{
          state = 999;
          token = new MulopToken(mulop_attr_type::MULOP_AND);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 3: //B
        if (c == 'e'){
          state = 42;
          attr.push_back(c);
        }else if (c =='o'){
          state = 43;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 42: //BE
        if (c == 'g'){
          state = 44;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 43: //BEG
        if (c == 'i'){
          state = 44;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 44: //BEGI
        if (c == 'n'){
          state = 45;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 45: //BEGIN
        if (is_alphanum(c)){
          state = 1;
          attr.push_back(c);
        }else{
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_BEGIN);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 46: //BO
        if (c == 'o'){
          state = 47;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break

      case 47: //BOO
        if (c == 'o'){
          state = 48;
          attr.push_back(c);
        }else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        }else {
          state = 999;
          token = new idtoken(attr);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 48: //BOOL
        if (is_alphanum(c)){
          state = 1;
          attr.push_back(c);
        }else{
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_BOOL);
          if (!is_space(c)){
            buf->unread_char(c);
          }
        }
        break;

      case 4: //E
        if (c == 'l') {
          state = 49;
          attr.push_back(c);
        } else if (c == 'n') {
          state = 52;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 49: //EL
        if (c == 's') {
          state = 50;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 50: //ELS
        if (c == 'e') {
          state = 51;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 51: //ELSE
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_ELSE);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 52: //EN
        if (c == 'd') {
          state = 53;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 53: // END
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_END);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 5: //I
        if (c == 'f') {
          state = 54;
          attr.push_back(c);
        } else if (c == 'n') {
          state = 55;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 54: //IF
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_IF);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 55: //IN
        if (c == 't') {
          state = 56;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 56: //INT
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_INT);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 6: //L
        if (c == 'o') {
          state = 57;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 57: //LO
        if (c == 'o') {
          state = 58;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 58: //LOO
        if (c == 'p') {
          state = 59;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 59: //LOOP
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_LOOP);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 7: //N
        if (c == 'o') {
          state = 60;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 60: //NO
        if (c == 't') {
          state = 61;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 61: //NOT
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_NOT);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 8: //O
        if (c == 'r') {
          state = 62;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 62: //OR
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new AddopToken(addop_attr_type::ADDOP_OR);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 9: //P
        if (c == 'r') {
          state = 63;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 63: //PR
        if (c == 'i') {
          state = 64;
          attr.push_back(c);
        } else if (c == 'o') {
          state = 65;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 64: //PRI
        if (c == 'n') {
          state = 66;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 66: //PRIN
        if (c == 't') {
          state = 67;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 67: //PRINT
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_PRINT);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 65: //PRO
        if (c == 'c') {
          state = 68;
          attr.push_back(c);
        } else if (c == 'g') {
          state = 74;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 68: //PROC
        if (c == 'e') {
          state = 69;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 69: //PROCE
        if (c == 'd') {
          state = 70;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 70: //PROCED
        if (c == 'u') {
          state = 71;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 71: //PROCEDU
        if (c == 'r') {
          state = 72;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 72: //PROCEDUR
        if (c == 'e') {
          state = 73;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 73: // PROCEDURE
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_PROCEDURE);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 74: // PROG
        if (c == 'r') {
          state = 75;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 75://PROGR
        if (c == 'a') {
          state = 76;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 76: //PROGRA
        if (c == 'm') {
          state = 77;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 77: //PROGRAM
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_PROGRAM);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 10: //T
        if (c == 'h') {
          state = 78;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 78: //TH
        if (c == 'e') {
          state = 79;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 79: //THE
        if (c == 'n') {
          state = 80;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 80: //THEN
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_THEN);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 11: //W
        if (c == 'h') {
          state = 81;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 81: //WH
        if (c == 'i') {
          state = 82;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 82: //WHI
        if (c == 'l') {
          state = 83;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 83:// WHIL
        if (c == 'e') {
          state = 84;
          attr.push_back(c);
        } else if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new IdToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 84://WHILE
        if (is_alphanum(c)) {
          state = 1;
          attr.push_back(c);
        } else {
          state = 999;
          token = new KeywordToken(keyword_attr_type::KW_WHILE);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 12: // ; 
        state = 999;
        token = new PuncToken(punc_attr_type::PUNC_SEMI);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 13: //:
        if (c == '=') {
          state = 33;
        } else {
          state = 999;
          token = new PuncToken(punc_attr_type::PUNC_COLON);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 33: //:=
        state = 999;
        token = new PuncToken(punc_attr_type::PUNC_ASSIGN);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 14: //,
        state = 999;
        token = new PuncToken(punc_attr_type::PUNC_COMMA);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 15: //{
        state = 999;
        token = new PuncToken(punc_attr_type::PUNC_OPEN);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 16: //}
        state = 999;
        token = new PuncToken(punc_attr_type::PUNC_CLOSE);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 17: //=
        state = 999;
        token = new RelopToken(relop_attr_type::RELOP_EQ);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 18: //<
        if (c == '=') {
          state = 34;
        } else if (c == '>') {
          state = 35;
        } else {
          state = 999;
          token = new RelopToken(relop_attr_type::RELOP_LT);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 34: <=
        state = 999;
        token = new RelopToken(relop_attr_type::RELOP_LE);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 35: //<> (NE)
        state = 999;
        token = new RelopToken(relop_attr_type::RELOP_NE);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 19://>
        if (c == '=') {
          state = 36;
        } else {
          state = 999;
          token = new RelopToken(relop_attr_type::RELOP_GT);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case 36: //>=
        state = 999;
        token = new RelopToken(relop_attr_type::RELOP_GE);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 20: //+
        state = 999;
        token = new AddopToken(addop_attr_type::ADDOP_ADD);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 21: //-
        state = 999;
        token = new AddopToken(addop_attr_type::ADDOP_SUB);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 22: //*
        state = 999;
        token = new MulopToken(mulop_attr_type::MULOP_MUL);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 32: // /
        state = 999;
        token = new MulopToken(mulop_attr_type::MULOP_DIV);
        if (!is_space(c)) {
          buffer_->unread_char(c);
        }
        break;

      case 24: //number
        if (is_digit(c)) {
          state = NUMBER;
          attr.push_back(c);
        } else {
          state = 999;
          token = new NumToken(attr);
          if (!is_space(c)) {
            buffer_->unread_char(c);
          }
        }
        break;

      case END_OF_FILE:
        state = 999;
        token = new EofToken();
        break;

      default:
        break;
    }
  }
  return token;
}





