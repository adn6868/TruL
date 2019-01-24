#ifndef EMITTER_H
#define EMITTER_H

#include <iostream>
#include "register.h"
using namespace std;

typedef enum instruction_type
{
	MOVE = 802,
	ADD =  803,
	SUB =  804,
	MUL =  805,
	DIV =  806,
	NEG =  807,
	NOT =  808,
	LEA =  809,
	BRUN = 810,
	BREZ = 811,
	BRPO = 812,
	BRNE = 813,
	OUTB = 814,
    HALT = 815,
    GARBAGE = 899
};

class Emitter{
	public : 
		Emitter();
		~Emitter();

		string * get_new_label();

		// Emit mabel :
		//default
		void emit_label(const string * label) const; 	
		//for immediate mode
		void emit_move(const Register *reg, int immedidate) const;
		// register direct mdoe
		void emit_move(const Register *reg, const Register *regd) const;}
		// memory direct mode.
		void emit_move(const Register *reg, const string *var) const;
		// memery move
		void emit_move(const string *var, const Register *reg) const

		void emit_to_addr (inst_type inst, const Register *reg, int immediate) const;
		void emit_to_addr(inst_type inst, const Register *reg, const Register *src) const;
  		void emit_to_addr(inst_type inst, const Register *reg, const string *var) const;