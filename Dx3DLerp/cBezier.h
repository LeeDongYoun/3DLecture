#pragma once

class cBezier
{

private:
	D3DXVECTOR3 m_angles;
	vector<D3DXVECTOR3> m_vecPoint;
	D3DXVECTOR3 m_vecFinal;
	D3DXVECTOR3 m_dir;

	float _bezierTime;

	void UpdateBezier(vector<D3DXVECTOR3>& vecInput, float currentTime);
public:
	cBezier();
	~cBezier();

	void Setup(int num);
	void Update(float currentTime);
	void Render();
	D3DXVECTOR3 getVecFinal(void) {return m_vecFinal;}
	D3DXVECTOR3 getVecDir(void) { return m_dir; }
};

