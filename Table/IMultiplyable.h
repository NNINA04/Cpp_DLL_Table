#pragma once

namespace Table
{
    namespace DataTypes
    {
        namespace Interfaces
        {
            template<class T>
            class IMultiplyable;
        }
    }
}

template<class T>
class Table::DataTypes::Interfaces::IMultiplyable
{
public:
    virtual T* Multiply(const T& other) = 0;
};