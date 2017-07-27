#pragma once

class cTextureManager
{

public:
	typedef std::map<std::string, LPDIRECT3DTEXTURE9> mapTextureList;
	typedef std::map<std::string, LPDIRECT3DTEXTURE9>::iterator mapTextureIter;

private:
	//������ ���� �̹��� ����Ʈ
	mapTextureList _mapTextureList;

public:
	//�ʱ�ȭ
	HRESULT init(void);

	//����
	void release(void);

	//Ű�� �߰��Ͽ� �̹��� ����
	LPDIRECT3DTEXTURE9 addTexture(std::string strKey);
	
	//�̹��� ã�´�
	LPDIRECT3DTEXTURE9 findTexture(std::string strKey);
	

	void deleteAll(void);
public:
	cTextureManager();
	~cTextureManager();
};

