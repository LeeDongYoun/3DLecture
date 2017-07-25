#pragma once
class cPyramid
{
private:
	vector<ST_PN_VERTEX>	m_vecVertex;
	D3DMATERIAL9 m_Material;

public:
	cPyramid(void);
	~cPyramid(void);
	
	void Setup(D3DXMATRIX* pmat,int color);
	void Render();
};

