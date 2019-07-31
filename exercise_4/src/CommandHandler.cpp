#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "CommandHandler.h"

CommandHandler::CommandHandler(const std::map<std::string, std::map<int, std::shared_ptr<IRecord> > > &records,
	                           const std::string &command,
	                           const std::string &table_name): _records(records),
                                                               _command(command),
                                                               _table_name(table_name){}

void CommandHandler::execute() {
	std::cout << _command << _table_name << std::endl;
	if (_command == "SHOW") {
		_show();
	} else {
		std::cerr << "Unknown command." << std::endl;
	}

}

void CommandHandler::_show() {
	if (_table_name == "") {
		std::cout << "Pretty prints whole database to the output. Records are grouped into tables:" << std::endl;
	}
	for (const auto &table : _records) {
		if (_table_name == "" || _table_name == table.first) {
			std::cout << "Table " << table.first << ":" << std::endl;
			for (const auto &item : table.second) {
				std::cout << item.second -> getPrettyPrinted() << std::endl;
			}
			std::cout << std::endl;
		}
	}
}
