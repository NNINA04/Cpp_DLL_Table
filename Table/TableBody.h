#pragma once

#include <array>
#include <vector>

namespace Table
{
    template <class _Ty, size_t _Cols>
    class TableBody;
}

template <class _Ty, size_t _Cols>
class Table::TableBody : public std::vector<std::array<_Ty, _Cols>>
{
    using Field = std::array<_Ty, _Cols>;
    using Base = std::vector<Field>;
    using Base::vector; // Realizes all base constructors
public:
    template<size_t _prevSize>
    TableBody(const TableBody<_Ty, _prevSize>& other) : Base(ResizeRow<_Cols>(other)) {}

    inline constexpr size_t Rows() const
    {
        return Base::size();
    }

    inline constexpr size_t Cols() const
    {
        return _Cols;
    }

    template<size_t _newSize, size_t _prevSize>
    static TableBody<_Ty, _newSize> ResizeRow(const TableBody<_Ty, _prevSize>& table) // Почему ROW, а не COLS?
    {
        const size_t rows = table.Rows();
        const size_t smollestSize = _newSize > _prevSize ? _prevSize : _newSize;

        TableBody<_Ty, _newSize> newTable(rows);

        for (size_t row = 0; row < rows; row++)
        {
            for (size_t i = 0; i < smollestSize; i++)
                newTable[row][i] = table[row][i];
        }
        return newTable;
    }
};
