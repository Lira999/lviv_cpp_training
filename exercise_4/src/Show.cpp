#include <iostream>
#include <string>
#include <vector>
#include <memory>

#include "Show.h"

Show::Show(std::vector<std::pair<std::string, std::vector<std::pair<int, std::unique_ptr<IRecord> > > > > &records,
		   const std::string &command,
		   const std::string &table_name): _records(records),
										   _command(command),
										   _table_name(table_name){}

void Show::execute() {
	if (_command == "SHOW") {
		_show();
	} else {
		std::cerr << "Unknown command." << std::endl;
	}

}

void Show::_show() {
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
