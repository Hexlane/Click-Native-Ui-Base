#pragma once 
#include"../src/common.hpp"
#include "natives.hpp"

namespace big::Math
{
	void notification(const std::string& text)
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::THEFEED_SET_BACKGROUND_COLOR_FOR_NEXT_POST(184);
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text.c_str()));
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
	}
	void notification_error(const std::string& text)
	{
		HUD::BEGIN_TEXT_COMMAND_THEFEED_POST("STRING");
		HUD::THEFEED_SET_BACKGROUND_COLOR_FOR_NEXT_POST(6);
		HUD::ADD_TEXT_COMPONENT_SUBSTRING_PLAYER_NAME(const_cast<char*>(text.c_str()));
		HUD::END_TEXT_COMMAND_THEFEED_POST_TICKER(false, false);
	}
}
