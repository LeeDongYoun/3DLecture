#pragma once
class cLeg
{
private:
	vector<ST_PT_VERTEX>	m_vecVertex;
	D3DXVECTOR3				m_vPos;
	LPDIRECT3DTEXTURE9		m_pTexture;
	float m_fAngle;
	D3DXVECTOR3 m_angles;

	bool _right;
	int _direction;

public:
	cLeg(void);
	~cLeg(void);

	void Setup(D3DXMATRIX* pmat, D3DXVECTOR3 pos,bool left);
	void Update(int direction);
	void Render(D3DXMATRIX* body);

};

