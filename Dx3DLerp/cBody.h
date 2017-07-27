#pragma once

enum action {

	idle,
	walk,
	attack,
	idleAni,
	damagetime

};
class cBody
{
private:
	vector<ST_PNT_VERTEX>	m_vecVertex;
	D3DXVECTOR3				m_vPos;
	D3DXVECTOR3				m_vDir;
	LPDIRECT3DTEXTURE9		m_pTexture;

	D3DXMATRIXA16 matRotaionX;
	D3DXMATRIXA16 matRotaionY;
	D3DXMATRIXA16 matRotaionZ;

	D3DXMATRIX m_matWorld;
	D3DXMATRIX m_pMatworld;

	float m_fSpeed;
	float m_fAngle;
	float _rotaionX;
	float _rotaionY;
	float _rotaionZ;

	action _act;
	D3DXVECTOR3 m_dDir;
	bool _attack;
	D3DMATERIAL9 m_Material;

public:
	cBody(void);
	~cBody(void);

	void Setup(D3DXVECTOR3 pos);
	void Update();
	void Render();
	D3DXVECTOR3* GetPosition();
	D3DXMATRIX* getBodyPosition();
	action getAction();
	D3DXVECTOR3* getDirection();
	void setBodyPos(D3DXVECTOR3 pos) { m_vPos = pos; }
	void setBodyDir(D3DXVECTOR3 dir);

};

