/*
 * main.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: root
 */
#include <iostream>
#include <functional>
#include <type_traits>

namespace Cat{

auto Id = [](auto value){return value;};
auto Square = [](auto value){return value*value;};
auto Compose = [](auto secondFunction, auto firstFunction){return [secondFunction,firstFunction](auto value){return secondFunction(firstFunction(value));};};
auto Twice = [](auto value){return 2*value;};

auto Memoize = [](auto function){return [function](auto value){static std::map<>

}

int main(int argc, char* argv[]){
	using namespace Cat;

	int c=0;
	std::string cosa("this is my string");
	std::cout<<Id(c)<<std::endl;
	std::cout<<Id(cosa)<<std::endl;
	std::cout<<Square(.866025404)<<std::endl;
	auto twiceOfSquare = Compose(Twice, Square);
	auto squareOfTwice = Compose(Square, Twice);
	std::cout<<twiceOfSquare(5)<<std::endl;
	std::cout<<squareOfTwice(5)<<std::endl;

//	compose other functions
//	create a maybe monad
//	create other monads
//
//	abstract operations from successor to tetration
//	use that to define algorithms for calculating any real number and measure its algorithmic complexity, lenght and other properties that algorithms might have

	return 0;
}

