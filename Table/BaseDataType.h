#pragma once

#include "IValidator.h"

namespace Table
{
    namespace DataTypes
    {
        template<class T>
        class BaseDataType;
    }
}

template<class T>
class Table::DataTypes::BaseDataType : public DataTypes::Interfaces::IValidator<T>
{
    T _value;
protected:
    BaseDataType(T& value) : _value(value) {}
public:
    inline const T& GetDataType() const
    {
        return _value;
    };

    void SetDataType(const T& newDataType)
    {
        Validate(newDataType);
        _value = newDataType;
    }

    // Inherited via IValidator
    virtual void Validate(const T& value) = 0;
};
