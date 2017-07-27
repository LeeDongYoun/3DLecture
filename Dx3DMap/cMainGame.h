#pragma once

class cCamera;
class cObject;


class cMainGame
{
private:
	
	cCamera*	m_pCamera;
	cObject*	m_pObject;
	D3DLIGHT9 _light;

public:
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

