#pragma once

class cNode;

class cBst

{
private:
	cNode* m_pRoot;

public:
	cBst(void);
	~cBst(void);

	void Insert(D3DXMATRIX* body);
	void Delete(D3DXMATRIX* body);
	void Print();
};

