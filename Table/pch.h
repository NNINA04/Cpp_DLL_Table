#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include<string>
#include<exception>
#include<vector>
#include<array>

#include "BaseDataType.h"
#include "IMultiplyable.h"
#include "ISummable.h"
#include "IValidator.h"

#ifdef TABLE_EXPORTS
#define TABLE_API __declspec(dllexport)
#else
#define TABLE_API __declspec(dllimport)
#endif

#endif //PCH_H
