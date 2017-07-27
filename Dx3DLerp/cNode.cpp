#include "StdAfx.h"
#include "cNode.h"

cNode::cNode(D3DXMATRIX* body, cNode* pChild)
	: m_nData(body)
	, m_pChild(pChild)
	
{
}

cNode::~cNode(void)
{
}

void cNode::Insert(D3DXMATRIX* body)
{
	
	if (m_pChild)
	{
		m_pChild->Insert(body);
	}
	else
	{
		m_pChild = new cNode(body);
	}
	
	
}

void cNode::Print()
{
	if (m_pChild)
	{
		m_pChild->Print();
	}

	if (m_pChild)
	{
		m_pChild->Print();
	}
}

cNode* cNode::Delete(D3DXMATRIX* body, cNode** ppThis)
{
	
	if (!m_pChild) {
		return NULL;
	}
	return m_pChild->Delete(body, &m_pChild);
	
}

cNode* cNode::GetMinNode()
{
	if (m_pChild)
	{
		return m_pChild->GetMinNode();
	}
	return this;
}
