#pragma once
class cPyramid
{
private:
	vector<ST_PC_VERTEX>	m_vecVertex;

public:
	cPyramid(void);
	~cPyramid(void);
	
	void Setup(D3DXMATRIX* pmat, D3DCOLOR c);
	void Render();
};

