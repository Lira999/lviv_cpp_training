#pragma once

#include <string>

class IRecord {
public:
	int _id;

    virtual int getId() const = 0;
    virtual std::string getFormatted() const = 0;
    virtual ~IRecord() = default;
};
