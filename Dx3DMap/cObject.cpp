#include "stdafx.h"
#include "cObject.h"
#include "cTextureManager.h"


cObject::cObject()
	:m_tm(NULL)
	, m_vPos(0,0,0)
	,_rotaionY(D3DX_PI/2)
	, _rotaionX(-D3DX_PI/2)
	,_rotaionZ(0.0f)
	,z(0)
{
	ZeroMemory(&s_mtl, sizeof(s_mtl));
	ZeroMemory(&s_obj, sizeof(s_obj));
}


cObject::~cObject()
{
}

void cObject::Setup()
{
	m_tm = new cTextureManager;


	FILE* fpMtl = 0;
	/*fopen_s(&fpMtl, "obj/Map.mtl", "r");*/
	fopen_s(&fpMtl, "obj/map.mtl", "r");
	char szBuf[1024];
	
	int vecCount = 0;
	while (!feof(fpMtl))
	{
		fgets(szBuf, 1024, fpMtl);
		size_t len = strlen(szBuf);
		if (len == 0)
			continue;
		if (szBuf[len - 1] == '\n') {
			szBuf[len - 1] = 0;
		}
		if (szBuf[0] == '#') continue;
		else if (szBuf[0] == 'n')
		{
			strcpy(s_mtl.name, &szBuf[7]);
		}
		else if (szBuf[0] == 'K')
		{
			if (szBuf[1] == 'a')
			{
				char* result = &szBuf[4];
				result = strtok(result, " ");
				int count = 0;
				while (result !=NULL) {
					if (count == 0) {
						s_mtl.material.Ambient.r = (atof(result));
					}
					else if (count == 1) {
						s_mtl.material.Ambient.g = (atof(result));
					}
					else if (count == 2) {
						s_mtl.material.Ambient.b = (atof(result));
						s_mtl.material.Ambient.a = 1.0f;
					}
					result = strtok(NULL, " ");
					count++;
					
				}
			}
			else if (szBuf[1] == 'd')
			{
				char* result = &szBuf[4];
				result = strtok(result, " ");
				int count = 0;
				while (result != NULL) {
					if (count == 0) {
						s_mtl.material.Diffuse.r = (atof(result));
					}
					else if (count == 1) {
						s_mtl.material.Diffuse.g = (atof(result));
					}
					else if (count == 2) {
						s_mtl.material.Diffuse.b = (atof(result));
						s_mtl.material.Diffuse.a = 1.0f;
						s_mtl.material.Emissive = D3DXCOLOR(0.0f, 0.0f, 0.0f, 1.0f);
					}
					result = strtok(NULL, " ");
					count++;

				}
			}
			else if (szBuf[1] == 's')
			{
				char* result = &szBuf[4];
				result = strtok(result, " ");
				int count = 0;
				while (result != NULL) {
					if (count == 0) {
						s_mtl.material.Specular.r = (atof(result));
					}
					else if (count == 1) {
						s_mtl.material.Specular.g = (atof(result));
					}
					else if (count == 2) {
						s_mtl.material.Specular.b = (atof(result));
						s_mtl.material.Specular.a = 1.0f;
					}
					result = strtok(NULL, " ");
					count++;
				}
			}
		}
		else if (szBuf[0] == 'd')
		{
			s_mtl.material.Power = (atof(&szBuf[8]));
		}
		else if (szBuf[0] == 'm')
		{				
			//strcpy(s_mtl.imageName, &szBuf[9]);
			s_mtl.texture=(m_tm->addTexture(&szBuf[9]));

		}
		vecCount++;
		if (vecCount % 8 == 0) {

			m_mapMtl.insert(make_pair(s_mtl.name, s_mtl));
			vecCount = 0;
		}
	}
	fclose(fpMtl);

	FILE* fpObj = 0;
	/*fopen_s(&fpMtl, "obj/Map.mtl", "r");*/
	fopen_s(&fpObj, "obj/map.obj", "r");
	char szBufObj[1024];

	//int pushCount = 0;
	while (!feof(fpObj))
	{
		fgets(szBufObj, 1024, fpObj);
		size_t len = strlen(szBufObj);
		if (len == 0)
			continue;
		if (szBufObj[len - 1] == '\n') {
			szBufObj[len - 1] = 0;
		}
		if (szBufObj[0] == '#') continue;
		else if (szBufObj[0] == 'm')
		{
			strcpy(s_obj.useMtlLib, &szBufObj[7]);
		}
		else if (szBufObj[0] == 'v')
		{
			if (szBufObj[1] == ' ')
			{
				char* result = &szBufObj[3];
				result = strtok(result, " ");
				int count = 0;
				while (result != NULL) {
					if (count == 0) {
						s_obj.vertexPos.x = (atof(result));
					}
					else if (count == 1) {
						s_obj.vertexPos.y = (atof(result));
					}
					else if (count == 2) {
						s_obj.vertexPos.z = (atof(result));
						s_obj.vecVertexPos.push_back(s_obj.vertexPos);
					}
					result = strtok(NULL, " ");
					count++;

				}
			}
			else if (szBufObj[1] == 't')
			{
				char* result = &szBufObj[4];
				result = strtok(result, " ");
				int count = 0;
				while (result != NULL) {
					if (count == 0) {
						s_obj.UVPos.x = (atof(result));
					}
					else if (count == 1) {
						s_obj.UVPos.y = (atof(result));
						s_obj.vecUVPos.push_back(s_obj.UVPos);
					}
					result = strtok(NULL, " ");
					count++;
				}
			}
			else if (szBufObj[1] == 'n')
			{
				char* result = &szBufObj[4];
				result = strtok(result, " ");
				int count = 0;
				while (result != NULL) {
					if (count == 0) {
						s_obj.VertexNormal.x = (atof(result));
					}
					else if (count == 1) {
						s_obj.VertexNormal.y = (atof(result));
					}
					else if (count == 2) {
						s_obj.VertexNormal.z = (atof(result));
						s_obj.vecVertexNormal.push_back(s_obj.VertexNormal);
					}
					result = strtok(NULL, " ");
					count++;
				}
			}
		}
		else if (szBufObj[0] == 'u')
		{
			strcpy(s_obj.useMtl, &szBufObj[7]);
		}
		
		else if (szBufObj[0] == 'g')
		{
			if (szBufObj[1] == ' ') {
				strcpy(s_obj.gName, &szBufObj[2]);
				z++;
			}
			else if(z>0){
				m_mapObj.insert(make_pair(s_obj.gName, s_obj));
				z = 0;
			}
		}
		else if (szBufObj[0] == 'f')
		{
			char* result = &szBufObj[2];
			result = strtok(result, "/ ");
			int pos, texture, nomal;
			for (int i = 0; i < 12; i++) {
				if (i%4== 0) {
					pos = (atoi(result));
					result = strtok(NULL, "/ ");
				}
				else if (i % 4 == 1) {
					texture = (atoi(result));
					result = strtok(NULL, "/ ");
				}
				else if (i % 4 == 2) {
					nomal = (atoi(result));
					result = strtok(NULL, "/ ");
					/*s_obj.vecSTPNT.push_back(ST_PNT_VERTEX(s_obj.vecVertexPos[pos-1], s_obj.vecVertexNormal[nomal-1], s_obj.vecUVPos[texture-1]));*/
				}
				else if (i % 4 == 3) {
					s_obj.vecSTPNT.push_back(ST_PNT_VERTEX(s_obj.vecVertexPos[pos - 1], s_obj.vecVertexNormal[nomal - 1], s_obj.vecUVPos[texture - 1]));
				}
				
			}
		}

	}
	fclose(fpObj);


}

void cObject::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_SPECULARENABLE, true);

	D3DXMATRIX matS;
	D3DXMatrixScaling(&matS, 0.1, 0.1, 0.1);

	D3DXMATRIX matRX;
	D3DXMatrixRotationX(&matRX, _rotaionX);

	D3DXMATRIX matRY;
	D3DXMatrixRotationY(&matRY, _rotaionY);

	D3DXMATRIX matRZ;
	D3DXMatrixRotationZ(&matRZ, _rotaionZ);

	D3DXMATRIX matT;
	D3DXMatrixTranslation(&matT, m_vPos.x, m_vPos.y, m_vPos.z);

	m_matWorld = matS*matRX*matRY*matRZ * matT;

	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);

	for (auto it = m_mapObj.begin(); it != m_mapObj.end(); it++) {

		auto it2 = m_mapMtl.find(it->second.useMtl);
		if (it2 != m_mapMtl.end()) {
			g_pD3DDevice->SetTexture(0,it2->second.texture);
			g_pD3DDevice->SetMaterial(&it2->second.material);
			g_pD3DDevice->SetFVF(ST_PNT_VERTEX::FVF);
			g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
				it->second.vecSTPNT.size() / 3,
				&it->second.vecSTPNT[0],
				sizeof(ST_PNT_VERTEX));
		}
	}
}

D3DXVECTOR3 * cObject::GetPosition()
{
	return &m_vPos;
}

