#pragma once

class cGrid;
class cCube;
class cCamera;
class cHead;
class cBody;
class cArm;
class cLeg;
class cBst;

class cMainGame
{
private:
	cGrid*		m_pGrid;
	cCube*		m_pCube;
	cCamera*	m_pCamera;
	cHead* m_pHead;
	cBody* m_pBody;
	cArm* m_pLArm;
	cArm* m_pRArm;
	cLeg* m_pLLeg;
	cLeg* m_pRLeg;
	cBst* m_pBst;

	float time;
	
public:
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

