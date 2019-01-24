/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */

#ifndef BUFFER_H
#define BUFFER_H

#include <stdlib.h>

#include <fstream>
#include <iostream>
#include <list>
#include <ctype.h>

// The Truman Language using all alphabet in ASCII,
// and digits from 0 - 9 and the following character
#define EOF_MARKER '$'

#define COMMENT_MARKER '#'
#define SPACE ' '
#define TAB '\t'
#define NEW_LINE '\n'

const char kNonAlphanum[] =
{';', ':', '(', ')', ',', '=', '>', '<', '+', '-', '*', '/',
 kCommentMarker, kSpace, kTab, kNewLine};

using namespace std;

class Buffer
{
 public:
  Buffer(char *filename);
  virtual ~Buffer();
  //~Buffer();

  // removes and return the next char from the buffer
  //.ignore: blocks of whitespaces and commend line
  char next_char();

  // bring a character to the buffer. 
  //@para: c last character, returned by next_char()
  void unread_char (char c);
  
  
 private: 
 //protected:
  static const int MAX_BUFFER_SIZE = 1024;
  ifstream source_file;

  //print error if bad thing happend
  void buffer_fatal_error() const;

  //inline functions for whitespace
  inline bool is_whitespace (const char c)
  {
    return (c == SPACE || c == TAB || c == NEW_LINE);
  }
  
  //inline fuctions for valid input
  inline bool isValid(char c);
};

#endif
