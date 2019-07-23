#pragma once

#include <iostream>
#include <string>
#include <map>
#include <memory>

#include "ICommand.h"
#include "IRecord.h"

class CommandHandler : public ICommand {
	public:
		CommandHandler(const std::map<std::string, std::map<int, std::shared_ptr<IRecord> > > &records,
				       const std::string &command,
				       const std::string &table_name);
		void execute() override;
	private:
		std::string _command;
		std::string _table_name;
		std::map<std::string, std::map<int, std::shared_ptr<IRecord> > > _records;
		void _show();
};
