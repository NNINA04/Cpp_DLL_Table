#pragma once

namespace Table
{
    namespace DataTypes
    {
        namespace Interfaces
        {
            template<class T>
            class ISummable;
        }
    }
}

template<class T>
class Table::DataTypes::Interfaces::ISummable
{
public:
    virtual T* Sum(const T& other) = 0;
};