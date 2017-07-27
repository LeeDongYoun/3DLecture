#pragma once
class cHead
{
private:
	vector<ST_PNT_VERTEX>	m_vecVertex;
	D3DXVECTOR3				m_vPos;
	LPDIRECT3DTEXTURE9		m_pTexture;
	float m_fAngle;
	D3DXVECTOR3 m_angles;

	D3DXMATRIX* m_pBody;
	int _direction;
	D3DMATERIAL9 m_Material;

public:
	cHead(void);
	~cHead(void);

	void Setup(D3DXMATRIX* pmat, D3DXVECTOR3 pos);
	void Update(int direction);
	void Render(D3DXMATRIX* body);

};

