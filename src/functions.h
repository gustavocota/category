/*
 * functions.h
 *
 *  Created on: Apr 13, 2019
 *      Author: chur
 */

#ifndef SRC_FUNCTIONS_H_
#define SRC_FUNCTIONS_H_

#include <iostream>
#include <functional>
#include <map>
#include <unistd.h>

namespace Cat{

auto Id = [](auto value){return value;};
auto Square = [](auto value){return value*value;};
auto Compose = [](auto secondFunction, auto firstFunction){return [secondFunction,firstFunction](auto value){return secondFunction(firstFunction(value));};};
auto Twice = [](auto value){return 2*value;};

auto Memoize = [](auto function){
	return [function](auto value){
		static std::map<long,long> results;
		auto temp=0;
		if(results.find(value) != results.end()){
			std::cout<<"value found "<<value<<std::endl;
			temp = results[value];
		}
		else {
			std::cout<<"value not found "<<value<<std::endl;
			usleep(1000000);
			temp = function(value); results[value] = temp;
		}
		return temp;
	};
};

}


#endif /* SRC_FUNCTIONS_H_ */
