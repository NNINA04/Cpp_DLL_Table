#ifndef PCH_H
#define PCH_H

#include "framework.h"

#include<exception>
#include<vector>
#include<array>

#ifdef TABLE_EXPORTS
#define TABLE_API __declspec(dllexport)
#else
#define TABLE_API __declspec(dllimport)
#endif

#endif //PCH_H
