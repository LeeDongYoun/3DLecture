#pragma once
class cCube
{
private:
	vector<ST_PN_VERTEX>	m_vecVertex;
	D3DXVECTOR3				m_vDir;
	D3DXVECTOR3				m_vPos;
	LPDIRECT3DTEXTURE9		m_pTexture[4];

	
	float  m_fSpeed;
	float  m_fAngle;
	float _rotaionX;
	float _rotaionY;
	float _rotaionZ;

	float _damage;
	bool _destroy;
	int boxDestroyCount;
	bool _count;
	D3DMATERIAL9 m_Material;


public:
	cCube(void);
	~cCube(void);

	void Setup();
	void Update();
	void Render();

	D3DXVECTOR3* GetPosition();
	void setDamage(float n);
	float getDamage(void) { return _damage; }
	
	bool getDestroy(void) { return _destroy; }
	int getNumBox(void) { return boxDestroyCount; }
};

