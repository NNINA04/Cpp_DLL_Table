#include "Table/pch.h"
#include "CppUnitTest.h"
#include "Table/Integer.h"
#include "Table/TableBody.h"
#include "Table/BaseDataType.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

using Table::DataTypes::Integer;
using Table::DataTypes::BaseDataType;
using Table::TableBody;
using std::exception;
using std::vector;
using std::array;

namespace UnitTests
{
    TEST_CLASS(TableBodyTests)
    {
        const TableBody<BaseDataType<std::string>*, 4> _body
        {
            {new Integer("1000"), new Integer("1000"), new Integer("1000"), new Integer("1000")},
            {new Integer("100"),  new Integer("500"),  new Integer("750"),  new Integer("100")},
            {new Integer("10"),   new Integer("6"),    new Integer("6"),    new Integer("2")}
        };
    public:
        TEST_METHOD(Rows_WithoutParameters_DoesNotThrow)
        {
            size_t expectedCountOfRows = _body.size();
            Assert::AreEqual(expectedCountOfRows, _body.Rows());
        }

        TEST_METHOD(Cols_WithoutParameters_DoesNotThrow)
        {
            size_t expectedCountOfCols = _body[0].size();
            Assert::AreEqual(expectedCountOfCols, _body.Cols());
        }

        TEST_METHOD(ResizingConstructor_WithCorrectParameters_DoesNotThrow)
        {
            const TableBody<int, 3> table
            {
                {1,2,3},
                {2,3,1},
            };

            const TableBody<int, 2> reducedTable = table;
            CheckResizing(reducedTable, { {1,2}, {2,3} });

            const TableBody<int, 4> increasedTable = table;
            CheckResizing(increasedTable, { {1,2,3,0}, {2,3,1,0} });
        }

        template <class _Ty, size_t _Cols>
        void CheckResizing(const TableBody<_Ty, _Cols>& table,
                           vector<array<_Ty, _Cols>> arr)
        {
            if (table.Rows() != arr.size())
                throw exception();

            for (size_t i = 0; i < table.Rows(); i++)
            {
                for (size_t j = 0; j < _Cols; j++)
                    Assert::AreEqual(table[i][j], arr[i][j]);
            }
        }
    };
}