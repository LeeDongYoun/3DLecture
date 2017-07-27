#include "StdAfx.h"
#include "cPyramid.h"


cPyramid::cPyramid(void)
{
}

cPyramid::~cPyramid(void)
{
}

void cPyramid::Setup(D3DXMATRIX* pmat, int color)
{
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 0, 0, 0)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1,-1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1,-1)));

	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 0, 0, 0)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1, 1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1,-1)));

	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 0, 0, 0)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1, 1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1, 1)));

	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 0, 0, 0)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1,-1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1, 1)));

	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1, 1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1,-1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1,-1)));

	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3(-1,-1, 1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1,-1)));
	m_vecVertex.push_back(ST_PN_VERTEX(D3DXVECTOR3( 1,-1, 1)));

	if(pmat)
	{
		for (size_t i = 0; i < m_vecVertex.size(); ++i)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p,
				&m_vecVertex[i].p,
				pmat);
		}
	}

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

	if (color == 1) {
		ZeroMemory(&m_Material, sizeof(m_Material));
		m_Material.Diffuse = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_Material.Ambient = D3DXCOLOR(1.0, 0.0f, 0.0f, 1.0f);
		m_Material.Specular = D3DXCOLOR(1.0f, 0.0f, 0.0f, 1.0f);
		m_Material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
		m_Material.Power = 5.0f;
	}
	else if (color == 2) {
		ZeroMemory(&m_Material, sizeof(m_Material));
		m_Material.Diffuse = D3DXCOLOR(0.0f, 1.0, 0.0f, 1.0f);
		m_Material.Ambient = D3DXCOLOR(0.0f, 1.0, 0.0f, 1.0f);
		m_Material.Specular = D3DXCOLOR(0.0f, 1.0, 0.0f, 1.0f);
		m_Material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
		m_Material.Power = 5.0f;
	}
	else if (color == 3) {
		ZeroMemory(&m_Material, sizeof(m_Material));
		m_Material.Diffuse = D3DXCOLOR(0.0f, 0.0f, 1.0, 1.0f);
		m_Material.Ambient = D3DXCOLOR(0.0f, 0.0f, 1.0, 1.0f);
		m_Material.Specular = D3DXCOLOR(0.0f, 0.0f, 1.0, 1.0f);
		m_Material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
		m_Material.Power = 5.0f;
	}
}

void cPyramid::Render()
{
	g_pD3DDevice->SetMaterial(&m_Material);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);

	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PN_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PN_VERTEX));
}
