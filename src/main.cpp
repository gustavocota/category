/*
 * main.cpp
 *
 *  Created on: Apr 3, 2019
 *      Author: root
 */
#include <iostream>
#include <functional>

namespace Cat{

template <typename T>
T Id(T value){
	return value;
}

template <typename Input, typename Middle, typename Output>
std::function<Output(Middle)> Compose(std::function<Output(Middle)> first,std::function<Middle(Input)> second){
	return [first, second](Input value)->Output{
		return first(second(value));
	};
}

}

int main(int argc, char* argv[]){
	using namespace Cat;

	int c=0;
	std::string cosa("this is my string");
	std::cout<<Id(c)<<std::endl;
	std::cout<<Id(cosa)<<std::endl;

	auto square = [](int value)->int{return value*value;};

	std::function<int(int)> x(Compose(square,Id));
	std::cout<<<<std::endl;

	return 0;
}

