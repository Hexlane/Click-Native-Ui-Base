#include "MainScript.hpp"
#include "Natives.hpp"
#include "UI/Timer.hpp"
#include "UI/UIManager.hpp"
#include "UI/option/BoolOption.hpp"
#include "UI/option/ChooseOption.hpp"
#include "UI/option/NumberOption.hpp"
#include "UI/option/RegularOption.hpp"
#include "UI/option/SubOption.hpp"
#include "UI/submenu/RegularSubmenu.hpp"
#include "UI/submenu/PlayerSubmenu.hpp"
#include "UI/option/BreakOption.hpp"
#include "submenu.hpp"
#include "Discord/handler.h"
#include "../Features.hpp"
#include "Backend/Backend.hpp"
#include "../Lists.h"
#include "../Math.h"


using namespace big::UserInterface;
namespace big
{

	void MainScript::Initialize()
	{
		if (true)
		{
			m_Initialized = true;
			g_UiManager->AddSubmenu<RegularSubmenu>("Home", Submenu::SubmenuHome, [](RegularSubmenu* sub)
				{
					sub->AddOption<SubOption>(xorstr_("Demo"), nullptr, Submenu::SubmenuDemo);

				});
			g_UiManager->AddSubmenu<RegularSubmenu>(xorstr_("Demo"), Submenu::SubmenuDemo, [&](RegularSubmenu* sub)
				{

					sub->AddOption<RegularOption>(xorstr_("Show Notification"), nullptr, []
						{
							Math::notification("Test Notification");
						});
					sub->AddOption<RegularOption>(xorstr_("Show Error"), nullptr, []
						{
							Math::notification_error("Test Error");
						});
					sub->AddOption<RegularOption>(xorstr_("Test option"), nullptr, []
						{
							LOG(INFO) << "Test";
						});
					static bool testBool1{};
					sub->AddOption<BoolOption<bool>>(xorstr_("Bool On/Off"), nullptr, &testBool1, BoolDisplay::OnOff);
					static bool testBool2{};
					sub->AddOption<BoolOption<bool>>(xorstr_("Bool Yes/No"), nullptr, &testBool2, BoolDisplay::YesNo);
					static std::int32_t int32Test{ 69 };
					sub->AddOption<NumberOption<std::int32_t>>("Int32", nullptr, &int32Test, 0, 100);
					static std::int64_t int64Test{ 420 };
					sub->AddOption<NumberOption<std::int64_t>>("Int64", nullptr, &int64Test, 0, 1000, 10);
					static float floatTest{ 6.9f };
					sub->AddOption<NumberOption<float>>("Float", nullptr, &floatTest, 0.f, 10.f, 0.1f, 1);
					static std::vector<std::uint64_t> vector{ 1, 2, 3 };
					static std::size_t vectorPos{};
					sub->AddOption<ChooseOption<const char*, std::size_t>>("Array", nullptr, &Lists::DemoList, &Lists::DemoListPos);
					sub->AddOption<ChooseOption<std::uint64_t, std::size_t>>("Vector", nullptr, &vector, &vectorPos);

				});
		}
	}
	void MainScript::Tick()
	{
		g_MainScript->Initialize();
		while (true)
		{
			g_UiManager->OnTick();
			g_Discord->Tick();
			script::get_current()->yield();
		}
	}
}
