#include "StdAfx.h"
#include "cBst.h"
#include "cNode.h"

cBst::cBst(void)
	: m_pRoot(NULL)
{
}


cBst::~cBst(void)
{
}

void cBst::Insert(D3DXMATRIX* body)
{
	if (m_pRoot)
	{
		m_pRoot->Insert(body);
	}
	else
	{
		m_pRoot = new cNode(body);
	}
}

void cBst::Delete(D3DXMATRIX* body)
{
	if (m_pRoot)
	{
		cNode* pNode = m_pRoot->Delete(body, &m_pRoot);
		if (pNode) delete pNode;
	}
}

void cBst::Print()
{
	if (m_pRoot)
	{
		m_pRoot->Print();
	}
}
