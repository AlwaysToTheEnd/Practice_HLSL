#pragma once
#include "../Common/d3dApp.h"

class AmbientLight :public D3DApp
{
public:
	AmbientLight(HINSTANCE hInstance);
	AmbientLight(const AmbientLight& rhs) = delete;
	AmbientLight& operator=(const AmbientLight& rhs) = delete;
	virtual ~AmbientLight() =default;

	virtual bool Initialize() override;

private:
	virtual void Update() override;
	virtual void Draw() override;

private:

};