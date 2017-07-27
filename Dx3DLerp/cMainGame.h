#pragma once


class cGrid;
class cCamera;
class cHead;
class cBody;
class cArm;
class cLeg;
class cHexagon;
class cBezier;

class cMainGame
{
private:
	
	cGrid*		m_pGrid;
	cCamera*	m_pCamera;
	//캐릭터1
	cBody* m_pBody;
	cHead* m_pHead;
	cArm* m_pLArm;
	cArm* m_pRArm;
	cLeg* m_pLLeg;
	cLeg* m_pRLeg;
	cHexagon* m_pHexagon;

	D3DLIGHT9 _light;

	vector<ST_PC_VERTEX> m_hexaPos;

	//캐릭터2
	cBody* m_pBody2;
	cHead* m_pHead2;
	cArm* m_pLArm2;
	cArm* m_pRArm2;
	cLeg* m_pLLeg2;
	cLeg* m_pRLeg2;

	cBezier* m_pBezier[3];

	float _time;
	float _bTime;
	
public:
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

