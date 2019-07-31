#pragma once

#include <string>
#include <vector>
#include <memory>

#include "ICommand.h"
#include "IRecord.h"

class Show : public ICommand {
	public:
	Show(std::vector<std::pair<std::string, std::vector<std::pair<int, std::unique_ptr<IRecord> > > > > &records,
	     const std::string &command,
	     const std::string &table_name);
		void execute() override;
	private:
		std::string _command;
		std::string _table_name;
		std::vector<std::pair<std::string, std::vector<std::pair<int, std::unique_ptr<IRecord> > > > > &_records;
		void _show();
};
