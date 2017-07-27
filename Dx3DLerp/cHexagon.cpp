#include "stdafx.h"
#include "cHexagon.h"


cHexagon::cHexagon()
	:m_angles(0,0,0)
{
}


cHexagon::~cHexagon()
{
}

void cHexagon::Setup()
{
	D3DCOLOR c = D3DCOLOR_XRGB(255, 0, 0);

	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-5.0f, 0.0f, -sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(5.0f, 0.0f, -sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(5.0f, 0.0f, -sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(10.0f, 0.0f, 0.0f), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(10.0f, 0.0f, 0.0f), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(5.0f, 0.0f, sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(5.0f, 0.0f, sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-5.0f, 0.0f, sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-5.0f, 0.0f, sqrt(75)), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-10.0f, 0.0f, 0.0f), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-10.0f, 0.0f, 0.0f), c));
	m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-5.0f, 0.0f, -sqrt(75)), c));

}

void cHexagon::Render()
{
	
	D3DXMATRIX matR;
	D3DXMatrixRotationYawPitchRoll(&matR, m_angles.y, m_angles.x, m_angles.z);

	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&matWorld);
	matWorld = matWorld*matR;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
}
