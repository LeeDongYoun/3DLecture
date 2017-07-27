#include "stdafx.h"
#include "cBezier.h"



cBezier::cBezier()
{
}


cBezier::~cBezier()
{
}

void cBezier::Setup(int n)
{
	if (n == 0) 
	{
		m_vecPoint.push_back((D3DXVECTOR3(-5.0f, 0.0f, -sqrt(75))));
		m_vecPoint.push_back((D3DXVECTOR3(5.0f, 0.0f, -sqrt(75))));
		m_vecPoint.push_back((D3DXVECTOR3(10.0f, 0.0f, 0.0f)));
	}
	else if (n == 1) 
	{
		m_vecPoint.push_back((D3DXVECTOR3(10.0f, 0.0f, 0.0f)));
		m_vecPoint.push_back((D3DXVECTOR3(5.0f, 0.0f, sqrt(75))));
		m_vecPoint.push_back((D3DXVECTOR3(-5.0f, 0.0f, sqrt(75))));
	}
	else if (n == 2)
	{
		m_vecPoint.push_back((D3DXVECTOR3(-5.0f, 0.0f, sqrt(75))));
		m_vecPoint.push_back((D3DXVECTOR3(-10.0f, 0.0f, 0.0f)));
		m_vecPoint.push_back((D3DXVECTOR3(-5.0f, 0.0f, -sqrt(75))));
	}
	_bezierTime = YUKCHO / 3.0f;
}

void cBezier::UpdateBezier(vector<D3DXVECTOR3>& vecInput, float currentTime)
{

	if (vecInput.size() == 2) {
		m_vecFinal = vecInput[0] + (currentTime / (_bezierTime))*(vecInput[1] - vecInput[0]);
		m_dir = vecInput[1] - vecInput[0];
		D3DXVec3Normalize(&m_dir, &m_dir);
	}
	else
	{
		vector<D3DXVECTOR3> vec;
		for (size_t i = 0; i < vecInput.size() - 1; ++i)
		{
			vec.push_back(vecInput[i] + (currentTime / _bezierTime)*(vecInput[i + 1] - vecInput[i]));
		}
		UpdateBezier(vec, currentTime);
	}
}


void cBezier::Update(float currentTime)
{
	UpdateBezier(m_vecPoint, currentTime);
}

void cBezier::Render()
{
}
