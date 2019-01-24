/* Implementation of a scanner for Truman Programming Language
 * Class: CS 420
 * @author: Anh Nguyen
 * @version: Mar 01, 2018
 */
#include "buffer.h"
#include <ctype.h>
#include <iostream>

using namespace std;

bool isValid(const char c){
  return islower(c) || isdigit(c);
}

void fill_buffer(iostream *const stream, list<char> * buffer, const int  MAX_BUFFER_SIZE){
  for (int i = 0; i < MAX_BUFFER_SIZE && !is_empty_stream(stream); i++){
    buffer->push_back(stream->get());
  }
}


Buffer::Buffer (const char * const stream) : stream(stream), fin(false){
  removed_space_and_commend();
}

Buffer::Buffer(const char *const filename) : fin(false){
  source_file.open(filename);
  if (source_file.faile()){
    cerr<<"Cannot open the file"<< endl;
    buffer_fatal_error;
  }
  stream = &source_file;
  removed_space_and_commend;
}

Buffer::~Buffer()
{
	source_file.close();
}

// not complete:
bool Buffer::removed_space_and_commend(){
  char head = next();
  bool complete = false;

  while (has_whitespace(head) || head == COMMENT_MARKER){
    complete = true;
    while (has_whitespace(head)){
      head = next();
    }
    if (head == COMMENT_MARKER){
      skip
    }
  }
}

///////////////////////
char Buffer::next_char() {
  if (buf.empty()){
    fill_buffer( stream, &buf, MAX_BUFFER_SIZE);
  }

  if (buf.empty()){
    fin = true;
    return EOF_MARKER;
  }

  char head = buf.font();
  buf.pop_front();
  return head;
  //return buffer->NextChar();
}

void Buffer::unreadChar(const char c) {
  if (c != EOF_MARKER) {
    fin = false;
    buf.push_front(c);
  }
}

bool is_empty_stream(istream *const stream) {
  return stream->peek() == EOF;
}

void Buffer::buffer_fatal_error() const
{
  cerr << "Exiting on BUFFER FATAL ERROR" << endl;
  exit (-1);
}
bool Buffer::isValid(const char c){
  return islower(c) || isdigit(c);
}