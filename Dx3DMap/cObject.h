#pragma once

class cTextureManager;
struct mtl {

	char	name[100];
	D3DMATERIAL9 material;
	LPDIRECT3DTEXTURE9 texture;
	//char imageName[100];

};

struct obj {
	
	char useMtlLib[100];
	D3DXVECTOR3 vertexPos;
	vector<D3DXVECTOR3> vecVertexPos;
	D3DXVECTOR2 UVPos;
	vector<D3DXVECTOR2> vecUVPos;
	D3DXVECTOR3 VertexNormal;
	vector<D3DXVECTOR3> vecVertexNormal;
	char gName[100];
	char useMtl[100];
	vector<ST_PNT_VERTEX> vecSTPNT;

};

class cObject
{
private:

	mtl s_mtl;
	obj s_obj;
	map<string,mtl> m_mapMtl;
	map<string,obj> m_mapObj;

	cTextureManager* m_tm;
	D3DXMATRIX m_matWorld;
	float _rotaionX;
	float _rotaionY;
	float _rotaionZ;
	D3DXVECTOR3 m_vPos;
	int z;

public:
	cObject();
	~cObject();

	void Setup();
	void Render();
	D3DXVECTOR3* GetPosition();
};

