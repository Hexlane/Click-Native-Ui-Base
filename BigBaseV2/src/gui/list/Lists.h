
#pragma once
#include "UI/UIManager.hpp"

namespace big::Lists
{
	inline const char* HeaderTypesFrontend[]
	{
		"Static",
	};
	inline UserInterface::HeaderType HeaderTypesBackend[]
	{
		UserInterface::HeaderType::Static,
	};
	inline std::size_t HeaderTypesPosition = 1;
	inline const char* DemoList[10]
	{
		"One",
		"Two",
		"Three",
		"Four",
		"Five",
		"Six",
		"Seven",
		"Eight",
		"Nine",
		"Ten"
	};
	inline std::size_t DemoListPos = 0;
}
