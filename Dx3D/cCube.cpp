#include "StdAfx.h"
#include "cCube.h"

cCube::cCube(void)
	: m_vDir(0, 0, 1)
	, m_vPos(0, 0, 0)
	, m_fSpeed(0.1f)
	, m_fAngle(0.0f)
	, _damage(0)
{
	_destroy = false;
	boxDestroyCount = 0;
	_count = false;
}


cCube::~cCube(void)
{
}

void cCube::Setup()
{
	D3DXCreateTextureFromFile(g_pD3DDevice,
		"box.png",
		&m_pTexture[0]);
	D3DXCreateTextureFromFile(g_pD3DDevice,
		"boxD1.png",
		&m_pTexture[1]);
	D3DXCreateTextureFromFile(g_pD3DDevice,
		"boxD2.png",
		&m_pTexture[2]);
	D3DXCreateTextureFromFile(g_pD3DDevice,
		"boxD3.png",
		&m_pTexture[3]);

	srand(time(NULL));
	m_vPos.x = (rand() % 30) - 15;
	m_vPos.y = 30.0f;
	m_vPos.z = (rand() % 30) - 15;

	//========================앞 012/023
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.5, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.5, 1)));

	//=============뒤465/476
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));

	//==================좌451/410
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));

	//===================우326/367
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 1)));

	//======================위156/162
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 1)));


	//================아래403/437
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.5, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.75, 1)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.75, 1)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.75, 0)));
	
}

void cCube::Update()
{
	static float timedelay = 0;
	timedelay += 0.3f;
	m_vPos.y -= (0.1f + timedelay);

	if (m_vPos.y < 1.2f) {

		m_vPos.y = 1.0f;
		timedelay = 0;
	}
	
	if (_damage >= 3) {
		static int count = 0;
		count++;
		if (count<300&&count >= 150) {

			if (_destroy == false) {
				boxDestroyCount++;
				_destroy = true;
			}
		}
		else if (count >= 300) {
			count = 0;
			_damage = 0;
			srand(time(NULL));
			m_vPos.x = (rand() % 30) - 15;
			m_vPos.y = 30.0f;
			m_vPos.z = (rand() % 30) - 15;
			_destroy = false;
		}
	}

	
}

void cCube::Render()
{


	D3DXMATRIX matR;
	D3DXMatrixRotationY(&matR, m_fAngle);

	D3DXMATRIX matS;
	D3DXMatrixScaling(&matS, 2.5, 2.5, 2.5);
	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, m_vPos.z);

	D3DXMATRIX matWorld = matS*matR * matT;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	if (_damage == 0) {
		g_pD3DDevice->SetTexture(0, m_pTexture[0]);
	}
	else if (_damage<2&&_damage > 0) {
		g_pD3DDevice->SetTexture(0, m_pTexture[1]);
	}
	else if (_damage<3 && _damage >= 2) {
		g_pD3DDevice->SetTexture(0, m_pTexture[2]);
	}
	
	else if (_damage >= 3) {
		g_pD3DDevice->SetTexture(0, m_pTexture[3]);
	}
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEX));

	
}

D3DXVECTOR3 * cCube::GetPosition()
{
	return &m_vPos;
}

void cCube::setDamage(float n)
{
	_damage += n;
}
