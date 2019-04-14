/*
 * tests.h
 *
 *  Created on: Apr 13, 2019
 *      Author: chur
 */

#ifndef SRC_TESTS_H_
#define SRC_TESTS_H_

#include "functions.h"

namespace Test{
void TestId(){
	int c=0;
	std::string cosa("this is my string");
	std::cout<<Cat::Id(c)<<std::endl;
	std::cout<<Cat::Id(cosa)<<std::endl;
}
void TestSquare(){
	std::cout<<Cat::Square(.866025404)<<std::endl;
}
void TestCompose(){
	auto twiceOfSquare = Cat::Compose(Cat::Twice, Cat::Square);
	auto squareOfTwice = Cat::Compose(Cat::Square, Cat::Twice);
	std::cout<<twiceOfSquare(5)<<std::endl;
	std::cout<<squareOfTwice(5)<<std::endl;
}
void TestMemoize(){
	auto sqr = Cat::Memoize(Cat::Square);
	std::cout<<sqr(100000)<<std::endl;
	std::cout<<sqr(200000)<<std::endl;
	std::cout<<sqr(300000)<<std::endl;
	std::cout<<sqr(100000)<<std::endl;
	std::cout<<sqr(300000)<<std::endl;
	std::cout<<sqr(150000)<<std::endl;
	std::cout<<sqr(300000)<<std::endl;
}
}

#endif /* SRC_TESTS_H_ */
