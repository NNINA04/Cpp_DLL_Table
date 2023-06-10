#pragma once

#include "TableBody.h"

namespace Table
{
    template <class _Ty, size_t _Cols>
    class NamedTable;
}

struct TableNames
{
    using TNames = std::vector<const char*>;

    TNames& Rows;
    TNames& Cols;
};

template <class _Ty, size_t _Cols>
class Table::NamedTable
{
    using TableBody = TableBody<_Ty, _Cols>;
public:
};