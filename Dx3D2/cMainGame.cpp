#include "StdAfx.h"
#include "cMainGame.h"
#include "cCube.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cHead.h"
#include "cBody.h"
#include "cArm.h"
#include "cLeg.h"
#include "cBst.h"




cMainGame::cMainGame(void)
	: m_pGrid(NULL)
	, m_pCube(NULL)
	, m_pCamera(NULL)
{
}

cMainGame::~cMainGame(void)
{

	SAFE_DELETE(m_pHead);
	SAFE_DELETE(m_pBody);
	SAFE_DELETE(m_pLArm);
	SAFE_DELETE(m_pRArm);
	SAFE_DELETE(m_pLLeg);
	SAFE_DELETE(m_pRLeg);
	//SAFE_DELETE(m_pBst);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCube);
	SAFE_DELETE(m_pCamera);
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);


	D3DXCOLOR c(1.0f, 1.0f, 1.0f, 1.0f);
	D3DXVECTOR3 dira = { 1.0f, -1.0f, 1.0f };
	D3DXVec3Normalize(&dira, &dira);
	ZeroMemory(&_light, sizeof(_light));
	_light.Type = D3DLIGHT_DIRECTIONAL;
	_light.Ambient = c*0.4f;
	_light.Diffuse = c;
	_light.Specular = c*0.6f;
	_light.Direction = dira;

	g_pD3DDevice->SetLight(0, &_light);
	g_pD3DDevice->LightEnable(0, true);

	//g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);


	m_pCube = new cCube;
	m_pCube->Setup();

	/*for (int i = 0; i < 10; i++) {
		m_pTestCube[i] = new cCube;
		m_pTestCube[i]->Setup();
	}*/

	m_pGrid = new cGrid;
	m_pGrid->Setup();

	m_pBody = new cBody;
	m_pBody->Setup(D3DXVECTOR3(0, 3, 0));

	m_pCamera = new cCamera;
	m_pCamera->Setup(m_pBody->GetPosition());


	//크기조절용 변수들
	D3DXMATRIX matS, matR, mat;

	m_pHead = new cHead;
	D3DXMatrixScaling(&matS, 1, 1, 1);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pHead->Setup(&mat, D3DXVECTOR3(0, 2, 0));

	m_pLArm = new cArm;
	D3DXMatrixScaling(&matS, 0.5, 1.2, 0.5);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLArm->Setup(&mat, D3DXVECTOR3(-1.5, 0.7, 0), false);

	m_pRArm = new cArm;
	D3DXMatrixScaling(&matS, 0.5, 1.2, 0.5);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRArm->Setup(&mat, D3DXVECTOR3(1.5, 0.7, 0), true);

	m_pLLeg = new cLeg;
	D3DXMatrixScaling(&matS, 0.5, 1.4, 0.5);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLLeg->Setup(&mat, D3DXVECTOR3(-0.6, -1.2, 0), true);

	m_pRLeg = new cLeg;
	D3DXMatrixScaling(&matS, 0.5, 1.4, 0.5);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRLeg->Setup(&mat, D3DXVECTOR3(0.6, -1.2, 0), false);
	
	time = 1000.0f;

	//g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
	//D3DXCOLOR c = { 1.0f, 1.0f, 1.0f, 1.0f };
	////D3DXVECTOR3 dira = { 1.0f, 0.0f, 0.0f };
	//ZeroMemory(&_light, sizeof(_light));
	//_light.Type = D3DLIGHT_SPOT;
	//_light.Ambient = c*0.4f;
	//_light.Diffuse = c;
	//_light.Specular = c*0.2f;
	//_light.Range = 100.0f;
	//_light.Falloff = 1.0f;
	//_light.Attenuation0 = 0.01f;
	//_light.Attenuation1 = 0.05f;
	//_light.Attenuation2 = 0.01f;
	////_light.Position = m_pLArm->getPos();
	////_light.Direction = m_pLArm->getFlashRightPos();
	//_light.Theta = D3DXToRadian(5);
	//_light.Phi = D3DXToRadian(3);

	//g_pD3DDevice->SetLight(0, &_light);
	//g_pD3DDevice->LightEnable(0, true);

	//g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);
	//D3DXCOLOR c = { 1.0f, 1.0f, 1.0f, 1.0f };
	////D3DXVECTOR3 dira = { 1.0f, 0.0f, 0.0f };
	//ZeroMemory(&_light, sizeof(_light));
	//_light.Type = D3DLIGHT_POINT;
	//_light.Ambient = c*0.4f;
	//_light.Diffuse = c;
	//_light.Specular = c*0.6f;
	//_light.Position = D3DXVECTOR3(0.0f, 0.0f, 1.0f);
	//_light.Range = 500.0f;
	//_light.Falloff = 1.0f;
	//_light.Attenuation0 = 0.01f;
	//_light.Attenuation1 = 0.05f;
	//_light.Attenuation2 = 0.1f;
	//_light.Direction = D3DXVECTOR3(0.0f, 0.0f, 1.0f);

	//g_pD3DDevice->SetLight(0, &_light);
	//g_pD3DDevice->LightEnable(0, true);

}

void cMainGame::Update()
{
	static float timedelay = 0;
	timedelay += 0.0001f;
	time -= (0.1f+ timedelay);


	/*_light.Position = *m_pBody->GetPosition();
	_light.Direction = m_pLArm->getFlashRightPos();
	g_pD3DDevice->SetLight(0, &_light);*/
	//g_pD3DDevice->LightEnable(0, true);


	int _act = m_pBody->getAction();
	if (_act == 2) {

		float _length = D3DXVec3Length(&(*m_pBody->GetPosition() - (*m_pCube->GetPosition())));
		D3DXVECTOR3 _dir;
		D3DXVec3Normalize(&_dir, &(*m_pBody->GetPosition() - (*m_pCube->GetPosition())));
		D3DXVECTOR3 _dir2;
		D3DXVec3Normalize(&_dir2, &(*m_pBody->getDirection()));
		float _theta = acos(D3DXVec3Dot(&_dir, &_dir2));
		float _damageRadi = D3DXToRadian(45);
		if (_length < 7 && ((fabs(_theta)) < _damageRadi)) {

			m_pCube->setDamage(0.01f);
		}

	}
	
	if (m_pCube->getDestroy() == true) {
		time += 0.4f;
	}

	m_pCamera->CameraAction(m_pCube->GetPosition(), m_pCube->getDamage());

	if (m_pBody)m_pBody->Update();
	if (m_pHead) m_pHead->Update(_act);
	if (m_pLArm)m_pLArm->Update(_act);
	if (m_pRArm)m_pRArm->Update(_act);
	if (m_pLLeg)m_pLLeg->Update(_act);
	if (m_pRLeg)m_pRLeg->Update(_act);
	if (m_pCube) m_pCube->Update();
	if (m_pCamera) m_pCamera->Update();	

	/*for (int i = 0; i < 10; i++) {
		if (m_pTestCube[i])m_pTestCube[i]->Update();
	}*/
	

}

void cMainGame::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	int _dBox = m_pCube->getNumBox();
	char buf[100];
	sprintf(buf,"남은 시간: %.1f   부순 박스 : %d", time, _dBox);
	SetWindowText(g_hWnd, buf);
	
	if (time < 0.01f) {
		sprintf(buf, "부순 박스 : %d", _dBox);
		MessageBox(g_hWnd, buf,TEXT("GameOver"), MB_OK);
		PostMessage(g_hWnd, WM_DESTROY, 0, 0);
	}

	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(47, 121, 112),
		1.0f, 0);

	g_pD3DDevice->BeginScene();
	// 그림을 그린다.
	if(m_pGrid) m_pGrid->Render();
	if (m_pCube->getDestroy() == false) {
		if (m_pCube) m_pCube->Render();
	}

	/*for (int i = 0; i < 10; i++) {
		if(m_pTestCube[i])m_pTestCube[i]->Render();
	}*/

	if (m_pBody)m_pBody->Render();
	if (m_pHead)m_pHead->Render(m_pBody->getBodyPosition());
	if (m_pLLeg)m_pLLeg->Render(m_pBody->getBodyPosition());
	if (m_pRLeg)m_pRLeg->Render(m_pBody->getBodyPosition());
	if (m_pLArm)m_pLArm->Render(m_pBody->getBodyPosition());
	if (m_pRArm)m_pRArm->Render(m_pBody->getBodyPosition());

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
