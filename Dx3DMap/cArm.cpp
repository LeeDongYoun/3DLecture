#include "stdafx.h"
#include "cArm.h"


cArm::cArm()
	:m_vPos(0, 0, 0)
	, m_fAngle(0)
	, _direction(3)
	, m_angles(0, 0, 0)
	, _down(downend)
{
}


cArm::~cArm()
{
}

void cArm::Setup(D3DXMATRIX * pmat, D3DXVECTOR3 pos, bool right)
{
	m_vPos = pos;
	_right = right;
	/*D3DXCreateTextureFromFile(g_pD3DDevice,
		"Iron_Man_Skin.png",
		&m_pTexture);*/

	//========================앞 012/023
	if (right) {
		//========================앞 012/023
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.0625, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.0625, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.0625, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125, 1)));
	}
	else if (!right) {
		//========================앞 012/023
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.125, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.0625, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.125, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.0625, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.0625, 1)));
	}
	
	if (right) {
		//=============뒤465/476
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.8125, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.875, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.8125, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.875, 0.625)));
	}
	else if (!right) {
		//=============뒤465/476
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.875, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.8125, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.625)));

	}
	if (right) {
		//==================좌451/410
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.6875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.6875, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.625, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.6875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.625, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.625, 1)));

		//===================우326/367
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.75, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.75, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.75, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.8125, 1)));
	}
	else if (!right) {

		//==================좌451/410
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.75, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.75, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0), D3DXVECTOR2(0.8125, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.75, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0), D3DXVECTOR2(0.8125, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.), D3DXVECTOR2(0.8125, 1)));

		//===================우326/367
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.6875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.6875, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.625, 0.625)));

		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.6875, 1)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.625, 0.625)));
		m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.625, 1)));

	}

	//======================위156/162
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.6875, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.6875, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.75, 0.5)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.6875, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, 1.0f), D3DXVECTOR2(0.75, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, 1.0f, -1.0f), D3DXVECTOR2(0.75, 0.625)));


	//================아래403/437
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.75, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.75, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.8125, 0.625)));

	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(-1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.75, 0.5)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, -1.0f), D3DXVECTOR2(0.8125, 0.625)));
	m_vecVertex.push_back(ST_PNT_VERTEX(D3DXVECTOR3(1.0f, -1.0f, 1.0f), D3DXVECTOR2(0.8125, 0.5)));

	if (pmat)
	{
		for (size_t i = 0; i < m_vecVertex.size(); ++i)
		{
			D3DXVec3TransformCoord(&m_vecVertex[i].p,
				&m_vecVertex[i].p,
				pmat);
		}
	}
	for (size_t i = 0; i < m_vecVertex.size(); ++i) {
		m_vecVertex[i].p.y -= 1.0f;
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

	ZeroMemory(&m_Material, sizeof(m_Material));
	m_Material.Diffuse = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Material.Ambient = D3DXCOLOR(1.0, 1.0f, 1.0f, 1.0f);
	m_Material.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
	m_Material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
	m_Material.Power = 5.0f;
}

void cArm::Update(int direction)
{
	_direction = direction;
	static int count = 0;
	//idle상태일때
	if (_direction == 3) {
		if (_right) {
			if (fabs(D3DX_PI - m_angles.x) > 0.1f) {
				m_angles.x += 0.1f;
			}
			else {
				m_angles.z = 0.7 * sin(count*0.05) + 0.7;
			}
		}
		else if (!_right) {

			if (fabs(D3DX_PI - m_angles.x) > 0.1f) {
				m_angles.x += 0.1f;
			}
			else {
				m_angles.z = 0.7 * sin(count*0.05) - 0.7;
			}
		}
		_down = start;
		m_angles.y = 0;
		m_vPos.z = 0;
	}
	//걷기상태일때
	else if (_direction == 1) {
		m_vPos.z = 0;
		if (_right) {
			if (_down == start) {
				if ((m_angles.z) < -0.13f) {
					m_angles.z += 0.1f;
				}
				else if ((m_angles.z) > 0.13f) {
					m_angles.z -= 0.1f;
				}
				else {
					_down = ing;
				}
			}
			if (_down == ing) {
				if (fabs(m_angles.x) > 0.1f) {
					m_angles.x -= 0.08f;
				}
				else {
					_down = downend;
				}
			}
			if (_down == downend) {
				m_angles.x = 0.7 * sin(count*0.05);
			}

		}
		else if (!_right) {
			if (_down == start) {
				if ((m_angles.z) < -0.13f) {
					m_angles.z += 0.1f;
				}
				else if ((m_angles.z) > 0.13f) {
					m_angles.z -= 0.1f;
				}
				else {
					_down = ing;
				}
			}
			if (_down == ing) {
				if (fabs(m_angles.x) > 0.1f) {
					m_angles.x -= 0.08f;
				}
				else {
					_down = downend;
				}
			}
			if (_down == downend) {
				m_angles.x = 0.7 * sin(count*0.05 + 15);
			}

		}
		m_angles.y = 0;
		
	}
	//공격상태일떄
	else if (_direction == 2) {
		if (_right) {
			if (_down == start) {
				if ((m_angles.z) > 0.1f) {
					m_angles.z -= 0.1f;
				}
				else {
					_down = ing;
				}
			}
			if (_down == ing) {
				if (m_angles.x > (D3DX_PI / 2)+0.1f) {
					m_angles.x -= 0.08f;
				}
				else if (m_angles.x < (D3DX_PI / 2) - 0.1f) {
					m_angles.x += 0.08f;
				}
				else {
					_down = downend;
				}
			}
			if (_down == downend) {
				static int numR = 0;
				if (numR < 10) {
					m_vPos.z -= 0.2;
				}
				else {
					m_vPos.z = 0;
					numR = 0;
				}
				numR++;
			}
		}
		else if (!_right) {
			if (_down == start) {
				if (m_angles.z < 0.1f) {
					m_angles.z += 0.1f;
				}
				else {
					_down = ing;
					m_angles.z = 0;
				}
			}
			if (_down == ing&&_down!=downend) {
				if (m_angles.x >(D3DX_PI / 2) + 0.1f) {
					m_angles.x -= 0.08f;
				}
				else if (m_angles.x < (D3DX_PI / 2) - 0.1f) {
					m_angles.x += 0.08f;
				}
				else {
					_down = downend;
				}
			}
			if (_down == downend) {
				static int numL = 0;
				if (numL < 10) {
					m_vPos.z -= 0.2;
				}
				else {
					m_vPos.z = 0;
					numL = 0;
				}
				numL++;
			}
		}
	}
	//대기애니메이션이면
	else if(_direction==0){
		_down = start;
		m_vPos.z = 0;
	}
	count++;
	_ArmBottom = m_vecVertex[35].np;

}



void cArm::Render(D3DXMATRIX* body)
{

	g_pD3DDevice->SetMaterial(&m_Material);
	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);

	D3DXMATRIX matR;
	D3DXMatrixRotationYawPitchRoll(&matR, m_angles.y, m_angles.x, m_angles.z);

	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, m_vPos.z);


	D3DXMATRIX _body = *body;
	D3DXMATRIX matWorld = matR * matT;
	matWorld = (matWorld) * (_body);

	g_pD3DDevice->SetTexture(0, m_pTexture);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);
	g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_vecVertex.size() / 3,
		&m_vecVertex[0],
		sizeof(ST_PNT_VERTEX));
}
