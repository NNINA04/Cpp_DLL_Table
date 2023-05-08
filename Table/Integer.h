#pragma once

#include "pch.h"

namespace Table
{
    namespace DataTypes
    {
        class Integer;
    }
}

class TABLE_API /*Каким-то образом решает проблему с выполнением тестов*/
    Table::DataTypes::Integer :
    public Table::DataTypes::BaseDataType<std::string>,
    public DataTypes::Interfaces::ISummable<Integer>,
    public DataTypes::Interfaces::IMultiplyable<Integer>
{
    using string = std::string;
    using Base = BaseDataType<string>;
public:
    Integer(string object) : Base(object)
    {
        Validate(object);
    }

    // Inherited via BaseDataType
    void Validate(const string& object);

    // Inherited via ISummable
    Integer* Sum(const Integer& other);

    // Inherited via IMultiplyable
    Integer* Multiply(const Integer& other);
};
