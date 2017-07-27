#pragma once
class cHexagon
{
private:

	vector<ST_PC_VERTEX>	m_vecVertex;
	D3DXVECTOR3 m_angles;


public:
	cHexagon();
	~cHexagon();
	
	void Setup();
	void Render();
	vector<ST_PC_VERTEX> getHexagonPos(void) {return m_vecVertex;}
};

