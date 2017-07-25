#include "StdAfx.h"
#include "cCamera.h"

cCamera::cCamera(void)
	: m_pvTarget(NULL)
	, m_fAngleX(D3DX_PI/4)
	, m_fAngleY(D3DX_PI)
	, m_isLButtonDown(false)
	, m_fDistance(40)
	, m_vEye(0, 0, -m_fDistance)
	, m_bAction(false)
{
}

cCamera::~cCamera(void)
{
}

void cCamera::Setup(D3DXVECTOR3* pvTarget /*= NULL*/)
{
	m_ptPrevMouse.x = 0;
	m_ptPrevMouse.y = 0;

	m_pvTarget = pvTarget;

	RECT rc;
	GetClientRect(g_hWnd, &rc);

	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
		&m_vEye,
		&D3DXVECTOR3(0, 0, 0), 
		&D3DXVECTOR3(0, 1, 0));
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

	D3DXMATRIX matProj;
	D3DXMatrixPerspectiveFovLH(&matProj,
		D3DX_PI / 4.0f, 
		rc.right / (float)rc.bottom, 
		1.0f,
		1000.0f);
	g_pD3DDevice->SetTransform(D3DTS_PROJECTION, &matProj);
}

void cCamera::Update()
{
	D3DXMATRIX matRX;
	D3DXMatrixRotationX(&matRX, m_fAngleX);
	D3DXMATRIX matRY;
	D3DXMatrixRotationY(&matRY, m_fAngleY);
	D3DXMATRIX matR = matRX * matRY;

	m_vEye = D3DXVECTOR3(0, 0, -m_fDistance);
	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);
	
	 vTarget = D3DXVECTOR3(0, 0, 0);
	if (m_pvTarget)
	{
		vTarget = *m_pvTarget;
	}
	
	m_vEye = m_vEye + vTarget;

	if (m_bAction) {
		static int count1 = 0;
		if (count1%5==0) {
			m_vEye.y += 3;
		}
		else if (count1%10==0) {
			m_vEye.y -= 3;
			count1 = 0;
		}
		count1++;
	}
	
	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
		&m_vEye,
		&vTarget, 
		&D3DXVECTOR3(0, 1, 0));
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
}

void cCamera::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
			m_isLButtonDown = true;
			m_ptPrevMouse.x = LOWORD(lParam);
			m_ptPrevMouse.y = HIWORD(lParam);
		}
		break;
	case WM_LBUTTONUP:
		{
			m_isLButtonDown = false;
		}
		break;
	case WM_MOUSEMOVE:
		{
			if(m_isLButtonDown)
			{
				POINT ptCurrMouse;
				ptCurrMouse.x = LOWORD(lParam);
				ptCurrMouse.y = HIWORD(lParam);

				float fDeltaX = (ptCurrMouse.x - m_ptPrevMouse.x) / 50.f;
				float fDeltaY = (ptCurrMouse.y - m_ptPrevMouse.y) / 50.f;

				m_fAngleY += fDeltaX;
				m_fAngleX += fDeltaY;

				if(m_fAngleX < -D3DX_PI / 2.0f + 0.0001f)
					m_fAngleX = -D3DX_PI / 2.0f + 0.0001f;
				
				if(m_fAngleX >  D3DX_PI / 2.0f - 0.0001f)
					m_fAngleX =  D3DX_PI / 2.0f - 0.0001f;

				m_ptPrevMouse = ptCurrMouse;
			}
		}
		break;
	case WM_MOUSEWHEEL:
		{
			int nWheel = GET_WHEEL_DELTA_WPARAM(wParam);
			m_fDistance -= (nWheel / 120.f);
		}
		break;
	}
}

void cCamera::CameraAction(D3DXVECTOR3* cubepos, float damage)
{
	D3DXVECTOR3 pos = *cubepos;
	float _damage = damage;
	static int count = 0;

	if (pos.y < 1.2f) {
		if (m_bAction == false) {
			m_bAction = true;
		}
	}
	else if (pos.y < 29) {
		count = 0;
	}
	if (count >= 25) {
		m_bAction = false;
	}
	count++;
	
}

