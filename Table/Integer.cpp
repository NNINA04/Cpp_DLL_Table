#include "pch.h"
#include "Integer.h"

using Table::DataTypes::Integer;

// Inherited via BaseDataType
inline void Integer::Validate(const string& object)
{
    const char& firstCh = object[0];
    const bool& negativeOrPositive = firstCh == '-' || isdigit(firstCh);
    if (negativeOrPositive == false)
        throw std::exception("It's not an Integer or negative symbol");

    for (size_t i = 1; i < object.size(); i++)
    {
        const char& currentCh = object[i];
        if (isdigit(currentCh) == false)
            throw std::exception("It's not an Integer");
    }
}

// Inherited via ISummable
inline Integer* Integer::Sum(const Integer& other)
{
    const string& firstStrNumb = this->GetDataType();
    const string& secondStrNumb = other.GetDataType();

    const int& firstNumb = std::stoi(firstStrNumb);
    const int& secondNumb = std::stoi(secondStrNumb);

    int sum = firstNumb + secondNumb;

    const string& strSum = std::to_string(sum);

    return new Integer(strSum);
}

// Inherited via IMultiplyable
inline Integer* Integer::Multiply(const Integer& other)
{
    const string& firstStrNumb = this->GetDataType();
    const string& secondStrNumb = other.GetDataType();

    const int& firstNumb = std::stoi(firstStrNumb);
    const int& secondNumb = std::stoi(secondStrNumb);

    int mult = firstNumb * secondNumb;

    const string& strMult = std::to_string(mult);

    return new Integer(strMult);
}
