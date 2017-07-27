#pragma once

class cTextureManager
{

public:
	typedef std::map<std::string, LPDIRECT3DTEXTURE9> mapTextureList;
	typedef std::map<std::string, LPDIRECT3DTEXTURE9>::iterator mapTextureIter;

private:
	//맵으로 만든 이미지 리스트
	mapTextureList _mapTextureList;

public:
	//초기화
	HRESULT init(void);

	//해제
	void release(void);

	//키값 추가하여 이미지 생성
	LPDIRECT3DTEXTURE9 addTexture(std::string strKey);
	
	//이미지 찾는다
	LPDIRECT3DTEXTURE9 findTexture(std::string strKey);
	

	void deleteAll(void);
public:
	cTextureManager();
	~cTextureManager();
};

