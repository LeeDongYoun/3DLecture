#include "stdafx.h"
#include "cTextureManager.h"


cTextureManager::cTextureManager()
{
}


cTextureManager::~cTextureManager()
{
}

HRESULT cTextureManager::init(void)
{
	return S_OK;
}

void cTextureManager::release(void)
{
	deleteAll();
}

LPDIRECT3DTEXTURE9 cTextureManager::addTexture(std::string strKey)
{
	mapTextureIter key = _mapTextureList.find(strKey);
	//키 값 찾으면....
	if (key != _mapTextureList.end())
	{
		 return  key->second;
	}
	//없으면  생성

	LPDIRECT3DTEXTURE9 texture = NULL;
	D3DXCreateTextureFromFile(g_pD3DDevice, strKey.c_str(),&texture);

	_mapTextureList.insert(make_pair(strKey.c_str(), texture));

	_mapTextureList.size();
	return texture;
}

LPDIRECT3DTEXTURE9 cTextureManager::findTexture(std::string strKey)
{
	mapTextureIter key = _mapTextureList.find(strKey);

	//키 값 찾으면....
	if (key != _mapTextureList.end())
	{
		return key->second;
	}

	return NULL;
}

void cTextureManager::deleteAll(void)
{
	//맵을 모두 돌면서 삭제..
	mapTextureIter iter = _mapTextureList.begin();

	for (; iter != _mapTextureList.end();)
	{
		//지울 수 있으면 반복자 증가 x
		SAFE_RELEASE(iter->second);
	}

	_mapTextureList.clear();
}
