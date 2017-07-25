#include "stdafx.h"
#include "cHead.h"


cHead::cHead()
	:m_vPos(0,0,0)
	, m_fAngle(0)
	, m_angles(0,0,0)
	, _direction(0)
{
}


cHead::~cHead()
{
}

void cHead::Setup(D3DXMATRIX * pmat, D3DXVECTOR3 pos)
{
	m_vPos = pos;

	D3DXCreateTextureFromFile(g_pD3DDevice,
		"Iron_Man_Skin.png",
		&m_pTexture);

	/*vector<ST_PT_VERTEX> m_vecVertex;
	vector<DWORD>		vecIndex;
	0vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125,0.5)));
	1vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.25)));
	2vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));
	3vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 0.5)));
	4vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0.5)));
	5vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.375, 0.25)));
	6vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0.25)));
	7vecVertexHead.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 0.5)));*/

	//========================앞 012/023
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 0.5)));

	//=============뒤465/476
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.375, 0.25)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.5, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.5, 0.25)));

	//==================좌451/410
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.375, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 0.5)));

	//===================우326/367
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.125, 0.25)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0, 0.5)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.125, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.125, 0.5))); 

	//======================위156/162
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.125, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));


	//================아래403/437
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.25, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.375, 0.25)));

	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.25, 0)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.375, 0.25)));
	m_vecVertex.push_back(ST_PT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.375, 0))); 

	if (pmat)
	{
		for (size_t i = 0; i < m_vecVertex.size(); ++i)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p,
				&m_vecVertex[i].p,
				pmat);
		}
	}
}

void cHead::Update(int direction)
{
	_direction = direction;
	static int count = 0;
	if (_direction == 1) {
		m_angles.y = 0.4 * sin(count*0.05);
		//m_angles.x = 0.2 * cos(count * 0.1);
		//m_angles.x = 0;

		m_angles.z = 0;
	}
	else if (_direction == 0|| _direction == 2|| _direction == 3) {
		m_angles.x = 0;
		m_angles.y = 0;
		m_angles.z = 0;

	}
	count++;
}

void cHead::Render(D3DXMATRIX* body)
{
	D3DXMATRIX matR;
	D3DXMatrixRotationYawPitchRoll(&matR, m_angles.y, m_angles.x, m_angles.z);
	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, m_vPos.z);

	D3DXMATRIX _body = *body;
	D3DXMATRIX matWorld = matR * matT;
	matWorld = (matWorld) * (_body);
	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PT_VERTEX));
}

