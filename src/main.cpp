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

template<typename T>
std::function<T(T)> IdCore = [](T value){return value;};
//#define Id(value) IdCore<decltype(value)>(value)
template<typename T>
T Id(T value){
	return IdCore<T>(value);
}

template<typename T>
std::function<T(T)> SquareCore = [](T value){return value*value;};
//#define Square(value) SquareCore<decltype(value)>(value)
template<typename T>
T Square(T value){
	return SquareCore<T>(value);
}

template <typename A, typename B, typename C>
std::function<C(A)> Compose(std::function<C(B)> g, std::function<B(A)> f)
{
  return [=](A a) -> C { return g(f(a)); };
}
}

int main(int argc, char* argv[]){
	using namespace Cat;

	int c=0;
	std::string cosa("this is my string");
	std::cout<<Id(c)<<std::endl;
	std::cout<<Id(cosa)<<std::endl;
	std::cout<<Square(.866025404)<<std::endl;
	auto idSquare = Compose(IdCore<int>, SquareCore<int>);
	auto squareId = Compose(SquareCore<int>, IdCore<int>);
	std::cout<<idSquare(5)<<std::endl;
	std::cout<<squareId(6)<<std::endl;


	return 0;
}

