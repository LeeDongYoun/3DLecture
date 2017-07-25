#include "stdafx.h"
#include "cBody.h"


cBody::cBody()
	:_rotaionX(0)
	, _rotaionY(0)
	, _rotaionZ(0)
	, m_vPos(0, 0, 0)
	, m_fSpeed(0.1f)
	, _act(idle)
	, _attack(false)
{
}


cBody::~cBody()
{
}

void cBody::Setup( D3DXVECTOR3 pos)
{
	m_vPos = pos;
	_act = idle;
	D3DXCreateTextureFromFile(g_pD3DDevice,
		"Iron_Man_Skin.png",
		&m_pTexture);

	//========================앞 012/023
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.3125, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.3125, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.3125, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.4375, 1)));

	//=============뒤465/476
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.625, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.625, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.625, 0.625)));

	//==================좌451/410
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.4375, 1)));

	//===================우326/367
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.3125, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.3125, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.3125, 1)));

	//======================위156/162
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.3125, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.3125, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.4375, 0.5)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.3125, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.4375, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));


	//================아래403/437
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.4375, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.4375, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.5625, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.4375, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.5625, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5625, 0.5)));


	/*for (size_t i = 0; i < m_vecVertex.size(); ++i)
	{
		if (i % 6 == 0)
			c = D3DCOLOR_XRGB(rand() % 256, rand() % 256, rand() % 256);
		D3DXVECTOR3 p = vecVertex[vecIndex[i]];
		m_vecVertex.push_back(ST_PC_VERTEX(p, c));
	}*/
	for (size_t i = 0; i < m_vecVertex.size(); i += 3) {

		D3DXVECTOR3 u = (m_vecVertex[i + 1].p) - (m_vecVertex[i].p);
		D3DXVECTOR3 v = (m_vecVertex[i + 2].p) - (m_vecVertex[i].p);

		D3DXVECTOR3 n;
		D3DXVec3Cross(&n, &u, &v);
		D3DXVec3Normalize(&n, &n);

		m_vecVertex[i].np = n;
		m_vecVertex[i + 1].np = n;
		m_vecVertex[i + 2].np = n;

	}

	ZeroMemory(&m_Material, sizeof(m_Material));
	m_Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Material.Ambient = D3DXCOLOR(1.0, 1.0f, 1.0f, 1.0f);
	m_Material.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	m_Material.Power = 5.0f;
}

void cBody::Update()
{
	static int count = 0;
	static int _timeAttack=0;

	if (count >= 130&& _act != attack) {
		_act = idleAni;
	}

	if (_act != idleAni&&_act!=attack) {
		_act = idle;
	}

	if (_act != attack) {
		count++;

		if (GetKeyState('W') & 0x8000)
		{
			m_dDir = D3DXVECTOR3(0, 0, 0.2);
			D3DXVec3TransformNormal(&m_dDir, &m_dDir, &m_matWorld);
			m_vPos = m_vPos - m_dDir;
			m_matWorld(3, 0) = m_vPos.x;
			m_matWorld(3, 1) = m_vPos.y;
			m_matWorld(3, 2) = m_vPos.z;
			_act = walk;
			count = 0;
		}

		if (GetKeyState('S') & 0x8000)
		{
			m_dDir = D3DXVECTOR3(0, 0, 0.2);
			D3DXVec3TransformNormal(&m_dDir, &m_dDir, &m_matWorld);
			m_vPos = m_vPos + m_dDir;
			m_matWorld(3, 0) = m_vPos.x;
			m_matWorld(3, 1) = m_vPos.y;
			m_matWorld(3, 2) = m_vPos.z;
			_act = walk;
			count = 0;
		}

		if (GetKeyState('A') & 0x8000)
		{
			_rotaionY -= 0.05f;
			_act = walk;
			count = 0;	
		}

		if (GetKeyState('D') & 0x8000)
		{
			_rotaionY += 0.05f;
			_act = walk;
			count = 0;
		}
	}

	if (_act == idle || _act == idleAni) {
		if (GetKeyState(VK_SPACE) & 0x8000)
		{
			_act = attack;
			_attack = true;
		}
	}
	if (_attack) {

		_timeAttack++;
		 if (_timeAttack >= 100) {
			 //_act = damagetime;
			_attack = false;
			_timeAttack = 0;
			count = 0;
			_act = idle;
		}
	}
}

void cBody::Render()
{

	g_pD3DDevice->SetMaterial(&m_Material);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);

	D3DXMATRIX matS;
	D3DXMatrixScaling(&matS, 1, 1, 0.5);

	D3DXMATRIX matRX;
	D3DXMatrixRotationY(&matRX, _rotaionY);

	D3DXMATRIX matRY;
	D3DXMatrixRotationY(&matRY, _rotaionY);

	D3DXMATRIX matRZ;
	D3DXMatrixRotationY(&matRZ, _rotaionY);

	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, m_vPos.z);
	m_pMatworld= matRX*matRY*matRZ * matT;
	m_matWorld = matS*matRX*matRY*matRZ * matT;
	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PNT_VERTEX));

}

D3DXVECTOR3* cBody::GetPosition()
{
	return &m_vPos;
}

D3DXMATRIX * cBody::getBodyPosition()
{
	return &m_pMatworld;
}

action cBody::getAction()
{
	return _act;
}

D3DXVECTOR3 * cBody::getDirection()
{
	return &m_dDir;
}
