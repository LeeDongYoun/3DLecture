#include "StdAfx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cObject.h"

cMainGame::cMainGame(void)
	:m_pCamera(NULL)
	, m_pObject(NULL)
	
{
}

cMainGame::~cMainGame(void)
{
	
}

void cMainGame::Setup()
{
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
	m_pObject = new cObject;
	m_pObject->Setup();
	
	m_pCamera = new cCamera;
	m_pCamera->Setup(m_pObject->GetPosition());


	D3DXCOLOR c(1.0f, 1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 dira = { 1.0f, -1.0f, 1.0f };
	D3DXVec3Normalize(&dira, &dira);
	ZeroMemory(&_light, sizeof(_light));
	_light.Type = D3DLIGHT_DIRECTIONAL;
	_light.Ambient = c*0.6f;
	_light.Diffuse = c;
	_light.Specular = c*0.6f;
	_light.Direction = dira;

	g_pD3DDevice->SetLight(0, &_light);
	g_pD3DDevice->LightEnable(0, true);
	
}

void cMainGame::Update()
{
	if (m_pCamera) m_pCamera->Update();

}

void cMainGame::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);


	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	g_pD3DDevice->BeginScene();
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	m_pObject->Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);
}


void cMainGame::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	if (m_pCamera)
	{
		m_pCamera->MsgProc(hWnd, message, wParam, lParam);
	}
}
