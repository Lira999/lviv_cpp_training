#pragma once

#include <string>

class IRecord {
	public:
		virtual int getId() const = 0;
		virtual std::string getFormatted() const = 0;
		virtual ~IRecord() = default;
	protected:
		int _id;
};
