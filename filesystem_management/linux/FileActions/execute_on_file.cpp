#include "execute_on_file.h"
#include <cstdlib>
int execute_on_file(std::string command_type,std::string source,std::string destination,std::string args[]){
	std::string command=command_type+" ";
	if(args!=nullptr)command+="-";
	while(args!=nullptr){
		command+=*args++;
	}
	if(args!=nullptr)command+=" ";
	command+=source + " " + destination;
	return system(command.c_str());
}
