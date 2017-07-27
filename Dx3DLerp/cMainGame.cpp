#include "StdAfx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cHead.h"
#include "cBody.h"
#include "cArm.h"
#include "cLeg.h"
#include "cHexagon.h"
#include "cBezier.h"

cMainGame::cMainGame(void)
	: m_pGrid(NULL)
	, m_pCamera(NULL)
	, m_pHexagon(NULL)
	, m_pHead(NULL)
	, m_pBody(NULL)
	, m_pLArm(NULL)
	, m_pRArm(NULL)
	, m_pLLeg(NULL)
	, m_pRLeg(NULL)
	, m_pHead2(NULL)
	, m_pBody2(NULL)
	, m_pLArm2(NULL)
	, m_pRArm2(NULL)
	, m_pLLeg2(NULL)
	, m_pRLeg2(NULL)
	
	
{	
	for (int i = 0; i < 3; ++i) {
		m_pBezier[i] = NULL;
	}
}
cMainGame::~cMainGame(void)
{

	SAFE_DELETE(m_pHead);
	SAFE_DELETE(m_pBody);
	SAFE_DELETE(m_pLArm);
	SAFE_DELETE(m_pRArm);
	SAFE_DELETE(m_pLLeg);
	SAFE_DELETE(m_pRLeg);
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCamera);

	SAFE_DELETE(m_pHexagon);

	SAFE_DELETE(m_pHead2);
	SAFE_DELETE(m_pBody2);
	SAFE_DELETE(m_pLArm2);
	SAFE_DELETE(m_pRArm2);
	SAFE_DELETE(m_pLLeg2);
	SAFE_DELETE(m_pRLeg2);

	for (int i = 0; i < 3; ++i) 
	{
		SAFE_DELETE(m_pBezier[i]);
	}

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


	m_pGrid = new cGrid;
	m_pGrid->Setup();
	
	m_pHexagon = new cHexagon;
	m_pHexagon->Setup();
	

	//캐릭터1
	m_pBody = new cBody;
	m_pBody->Setup(D3DXVECTOR3(-5, 1, -sqrt(75)));

	m_pCamera = new cCamera;
	m_pCamera->Setup(m_pBody->GetPosition());


	//크기조절용 변수들
	D3DXMATRIX matS, matR, mat;

	m_pHead = new cHead;
	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pHead->Setup(&mat, D3DXVECTOR3(0, 1.0f, 0));

	m_pLArm = new cArm;
	D3DXMatrixScaling(&matS, 0.25f, 0.6f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLArm->Setup(&mat, D3DXVECTOR3(-0.75f, 0.5f, 0.0f), false);

	m_pRArm = new cArm;
	D3DXMatrixScaling(&matS, 0.25f, 0.6f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRArm->Setup(&mat, D3DXVECTOR3(0.75f, 0.5f, 0.0f), true);

	m_pLLeg = new cLeg;
	D3DXMatrixScaling(&matS, 0.25f, 0.7f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLLeg->Setup(&mat, D3DXVECTOR3(-0.25f, -0.2f, 0.0f), true);

	m_pRLeg = new cLeg;
	D3DXMatrixScaling(&matS, 0.25f, 0.7f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRLeg->Setup(&mat, D3DXVECTOR3(0.25f, -0.2f, 0.0f), false);



	//캐릭터2
	m_pBody2 = new cBody;
	m_pBody2->Setup(D3DXVECTOR3(-5, 1, -sqrt(75)));

	m_pHead2 = new cHead;
	D3DXMatrixScaling(&matS, 0.5f, 0.5f, 0.5f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pHead2->Setup(&mat, D3DXVECTOR3(0, 1.0f, 0));

	m_pLArm2= new cArm;
	D3DXMatrixScaling(&matS, 0.25f, 0.6f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLArm2->Setup(&mat, D3DXVECTOR3(-0.75f, 0.5f, 0.0f), false);

	m_pRArm2 = new cArm;
	D3DXMatrixScaling(&matS, 0.25f, 0.6f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRArm2->Setup(&mat, D3DXVECTOR3(0.75f, 0.5f, 0.0f), true);

	m_pLLeg2 = new cLeg;
	D3DXMatrixScaling(&matS, 0.25f, 0.7f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pLLeg2->Setup(&mat, D3DXVECTOR3(-0.25f, -0.2f, 0.0f), true);

	m_pRLeg2 = new cLeg;
	D3DXMatrixScaling(&matS, 0.25f, 0.7f, 0.25f);
	D3DXMatrixRotationZ(&matR, 0);
	mat = matS * matR;
	m_pRLeg2->Setup(&mat, D3DXVECTOR3(0.25f, -0.2f, 0.0f), false);

	for (int i = 0; i < 3; ++i) {
		m_pBezier[i]  = new cBezier;
		m_pBezier[i]->Setup(i);
	}
	


	m_hexaPos = m_pHexagon->getHexagonPos();

	
	 _time =0.0f;
	 _bTime = 0.0f;
}

void cMainGame::Update()
{
	int _act = m_pBody->getAction();
	int _act2 = m_pBody2->getAction();
	//==========================================
	if (m_pBody)m_pBody->Update();
	if (m_pHead) m_pHead->Update(_act);
	if (m_pLArm)m_pLArm->Update(_act);
	if (m_pRArm)m_pRArm->Update(_act);
	if (m_pLLeg)m_pLLeg->Update(_act);
	if (m_pRLeg)m_pRLeg->Update(_act);
	if (m_pCamera) m_pCamera->Update();	

	//======================================
	if (m_pBody2)m_pBody2->Update();
	if (m_pHead2) m_pHead2->Update(_act2);
	if (m_pLArm2)m_pLArm2->Update(_act2);
	if (m_pRArm2)m_pRArm2->Update(_act2);
	if (m_pLLeg2)m_pLLeg2->Update(_act2);
	if (m_pRLeg2)m_pRLeg2->Update(_act2);



	_time += 1.0f / 60.0f;
	float hexagonLine = YUKCHO / 6.0f;

	static int count = 0;
	if (_time > hexagonLine) { _time = 0.0f; count++; if (count == 6)count = 0; }
	if (count==0)
	{
		m_pBody->setBodyPos(m_hexaPos[0].p + (_time / (hexagonLine))*(m_hexaPos[1].p - m_hexaPos[0].p));
		m_pBody->setBodyDir(m_hexaPos[1].p - m_hexaPos[0].p);
	}
	else if (count == 1)
	{
		m_pBody->setBodyPos(m_hexaPos[2].p + (_time / (hexagonLine ))*(m_hexaPos[3].p - m_hexaPos[2].p));
		m_pBody->setBodyDir(m_hexaPos[3].p - m_hexaPos[2].p);
	}
	else if (count == 2)
	{
		m_pBody->setBodyPos(m_hexaPos[4].p + (_time / (hexagonLine))*(m_hexaPos[5].p - m_hexaPos[4].p));
		m_pBody->setBodyDir(m_hexaPos[5].p - m_hexaPos[4].p);
	}
	else if (count == 3)
	{
		m_pBody->setBodyPos(m_hexaPos[6].p + (_time / (hexagonLine))*(m_hexaPos[7].p - m_hexaPos[6].p));
		m_pBody->setBodyDir(m_hexaPos[7].p - m_hexaPos[6].p);
	}
	else if (count == 4)
	{
		m_pBody->setBodyPos(m_hexaPos[8].p + (_time / (hexagonLine))*(m_hexaPos[9].p - m_hexaPos[8].p));
		m_pBody->setBodyDir(m_hexaPos[9].p - m_hexaPos[8].p);
	}
	else if (count == 5)
	{
		m_pBody->setBodyPos(m_hexaPos[10].p + (_time / (hexagonLine))*(m_hexaPos[11].p - m_hexaPos[10].p));
		m_pBody->setBodyDir(m_hexaPos[11].p - m_hexaPos[10].p);
	}


	_bTime += 1.0f / 60.0f;
	float bezierLine = YUKCHO / 3.0f;
	static int bcount = 0;
	if (_bTime > bezierLine) { _bTime = 0.0f; bcount++; if (bcount == 3) bcount = 0; }

	m_pBezier[bcount]->Update(_bTime);
	m_pBody2->setBodyPos(m_pBezier[bcount]->getVecFinal());
	m_pBody2->setBodyDir((m_pBezier[bcount]->getVecDir()*-1));
	//m_pBezier->Update(_bTime);
	
	/*for (int i = 0; i < 3; ++i) {
		m_pBody2->setBodyPos(m_pBezier[i]->getVecFinal());
		m_pBody2->setBodyDir((m_pBezier[i]->getVecDir()*-1));
	}*/


	/*m_pBody2->setBodyPos(m_pBezier->getVecFinal());
	m_pBody2->setBodyDir((m_pBezier->getVecDir()*-1));*/
	
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

	if (m_pBody)m_pBody->Render();
	if (m_pHead)m_pHead->Render(m_pBody->getBodyPosition());
	if (m_pLLeg)m_pLLeg->Render(m_pBody->getBodyPosition());
	if (m_pRLeg)m_pRLeg->Render(m_pBody->getBodyPosition());
	if (m_pLArm)m_pLArm->Render(m_pBody->getBodyPosition());
	if (m_pRArm)m_pRArm->Render(m_pBody->getBodyPosition());

	if (m_pBody2)m_pBody2->Render();
	if (m_pHead2)m_pHead2->Render(m_pBody2->getBodyPosition());
	if (m_pLLeg2)m_pLLeg2->Render(m_pBody2->getBodyPosition());
	if (m_pRLeg2)m_pRLeg2->Render(m_pBody2->getBodyPosition());
	if (m_pLArm2)m_pLArm2->Render(m_pBody2->getBodyPosition());
	if (m_pRArm2)m_pRArm2->Render(m_pBody2->getBodyPosition());

	
	if (m_pHexagon)m_pHexagon->Render();
	
		
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
