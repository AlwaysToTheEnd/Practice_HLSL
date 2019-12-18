#include "AmbientLight.h"

AmbientLight::AmbientLight(HINSTANCE hInstance)
	: D3DApp(hInstance)
{
}

bool AmbientLight::Initialize()
{
	if (D3DApp::Initialize())
	{
		return true;
	}

	return false;
}

void AmbientLight::Update()
{
}

void AmbientLight::Draw()
{
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE, PSTR, int)
{
#if defined(_DEBUG)
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	try
	{
		AmbientLight theApp(hInstance);
		if (!theApp.Initialize())
			return 0;

		return theApp.Run();
	}
	catch (std::exception e)
	{
		std::string stringMessage(e.what());
		std::wstring exceptionMessage(stringMessage.begin(), stringMessage.end());
		MessageBox(nullptr, exceptionMessage.c_str(), L"HR Failed", MB_OK);
		return 0;
	}
	catch (DxException e)
	{
		MessageBox(nullptr, e.ToString().c_str(), L"HR Failed", MB_OK);
		return 0;
	}
}