#pragma once
class cCamera
{
private:
	D3DXVECTOR3*	m_pvTarget;
	float			m_fAngleX;
	float			m_fAngleY;
	POINT			m_ptPrevMouse;
	bool			m_isLButtonDown;
	D3DXVECTOR3		m_vEye;
	float			m_fDistance;
	bool			m_bAction;
	D3DXVECTOR3 vTarget;

public:
	cCamera(void);
	~cCamera(void);

	void Setup(D3DXVECTOR3* pvTarget = NULL);
	void Update();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void CameraAction(D3DXVECTOR3* cubepos,float damage);
};

