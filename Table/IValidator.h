#pragma once

namespace Table
{
	namespace DataTypes
	{
		namespace Interfaces
		{
			template<class T>
			class IValidator;
		}
	}
}

template<class T>
class Table::DataTypes::Interfaces::IValidator
{
public:
    virtual void Validate(const T& value) = 0;
};