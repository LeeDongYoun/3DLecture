#pragma once
enum down {
	start,
	ing,
	downend

};
class cArm
{
private:
	vector<ST_PN_VERTEX>	m_vecVertex;
	D3DXVECTOR3				m_vPos;
	LPDIRECT3DTEXTURE9		m_pTexture;
	float m_fAngle;
	D3DXVECTOR3 m_angles;
	
	bool _right;
	int _direction;
	float _x;
	down _down;
	D3DMATERIAL9 m_Material;

public:
	cArm(void);
	~cArm(void);

	void Setup(D3DXMATRIX* pmat, D3DXVECTOR3 pos,bool right);
	void Update(int direction);
	void Render(D3DXMATRIX* body);


	void setDirection(int direction) { _direction = direction; }

};

