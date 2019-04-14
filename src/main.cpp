/*
 * main.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: root
 */
#include "functions.h"
#include "tests.h"

int main(int argc, char* argv[]){

	Test::TestId();
	Test::TestSquare();
	Test::TestCompose();
	Test::TestMemoize();

//	compose other functions
//	create a maybe monad
//	create other monads
//
//	abstract operations from successor to tetration
//	use that to define algorithms for calculating any real number and measure its algorithmic complexity, lenght and other properties that algorithms might have

	return 0;
}

