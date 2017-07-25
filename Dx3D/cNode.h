#pragma once


class cNode
{

public:
	cNode(D3DXMATRIX* body=NULL,cNode* pChild = NULL);
	~cNode(void);

	D3DXMATRIX*		m_nData;
	cNode*	m_pChild;

	void Insert(D3DXMATRIX* body);
	cNode* Delete(D3DXMATRIX* body,cNode** ppThis);
	void Print();
	cNode* GetMinNode();
};

