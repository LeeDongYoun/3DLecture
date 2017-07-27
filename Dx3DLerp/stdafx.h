// stdafx.h : ���� ��������� ���� ��������� �ʴ�
// ǥ�� �ý��� ���� ���� �� ������Ʈ ���� ���� ������
// ��� �ִ� ���� �����Դϴ�.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // ���� ������ �ʴ� ������ Windows ������� �����մϴ�.
// Windows ��� ����:
#include <windows.h>

// C ��Ÿ�� ��� �����Դϴ�.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>


// TODO: ���α׷��� �ʿ��� �߰� ����� ���⿡�� �����մϴ�.

#include <d3dx9.h>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <assert.h>
#include <list>
#include <time.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

using namespace std;

extern HWND g_hWnd;

#define YUKCHO	6.0f


#define SAFE_RELEASE(p) if(p) { (p)->Release(); p = NULL; }
#define SAFE_DELETE(p) if(p) { delete (p); (p) = NULL; }

#define SINGLETON(class_name)	private:\
	class_name(void);\
	~class_name(void);\
public:\
	static class_name* GetInstance() { static class_name instance; return &instance; }

#include "cDeviceManager.h"

// 1. Position ������ ��ǥ x,y,z(float)			: D3DFVF_XYZ
// 2. RHW (float)                               : D3DFVF_XYZRHW (D3DFVF_XYZ �Ǵ� D3DFVF_NORMAL�� ���� ���Ұ�)
// 3. Blending Weight Data ���� ����ġ (float)	: D3DFVF_XYZB1 ~ D3DFVF_XYZB5
// 4. Vertex Normal ������ ���� ���� x,y,z(float)	: D3DFVF_NORMAL
// 5. Vertex Point Size ������ �� ũ�� (float)	: D3DFVF_PSIZE
// 6. Diffuse Color (DWORD)						: D3DFVF_DIFFUSE
// 7. Specular Color (DWORD)                    : D3DFVF_SPECULAR
// 8. Texture Coordinate Set 1 (float)          : D3DFVF_TEX0 - D3DFVF_TEX8

struct ST_PC_VERTEX
{
	D3DXVECTOR3 p;
	D3DCOLOR	c;

	ST_PC_VERTEX() : p(0, 0, 0), c(D3DCOLOR_XRGB(0, 0, 0)) {}
	ST_PC_VERTEX(D3DXVECTOR3 _p, D3DCOLOR _c) : p(_p), c(_c) {}

	enum { FVF = D3DFVF_XYZ | D3DFVF_DIFFUSE };
};

struct ST_PT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR2	t;

	ST_PT_VERTEX() : p(0, 0, 0), t(0, 0) {}
	ST_PT_VERTEX(D3DXVECTOR3 _p, D3DXVECTOR2 _t) : p(_p), t(_t) {}

	enum { FVF = D3DFVF_XYZ | D3DFVF_TEX1 };
};

struct ST_PNT_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 np;
	D3DXVECTOR2	t;

	ST_PNT_VERTEX() : p(0, 0, 0), np(0, 0, 0), t(0, 0) {}
	ST_PNT_VERTEX(D3DXVECTOR3 _p, D3DXVECTOR2 _t) : p(_p), t(_t), np(0,0,0) {}
	ST_PNT_VERTEX(D3DXVECTOR3 _p, D3DXVECTOR2 _t, D3DXVECTOR3 _np) : p(_p), t(_t), np(_np) {}

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_TEX1};
};


struct ST_PN_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 np;
	

	ST_PN_VERTEX() : p(0, 0, 0), np(0, 0, 0) {}
	ST_PN_VERTEX(D3DXVECTOR3 _p) : p(_p), np(0, 0, 0) {}
	ST_PN_VERTEX(D3DXVECTOR3 _p, D3DXVECTOR3 _np) : p(_p), np(_np) {}

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL };
};

struct ST_PNC_VERTEX
{
	D3DXVECTOR3 p;
	D3DXVECTOR3 np;
	D3DCOLOR	c;

	ST_PNC_VERTEX() : p(0, 0, 0), np(0, 0, 0), c(D3DCOLOR_XRGB(0, 0,0)) {}
	ST_PNC_VERTEX(D3DXVECTOR3 _p, D3DCOLOR _c) : p(_p), c(c), np(0, 0, 0) {}
	ST_PNC_VERTEX(D3DXVECTOR3 _p, D3DCOLOR _c, D3DXVECTOR3 _np) : p(_p), c(_c), np(_np) {}

	enum { FVF = D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE};
};


#define SYNTHESIZE(varType, varName, funName)\
protected: varType varName;\
public: inline varType Get##funName(void) const { return varName; }\
public: inline void Set##funName(varType var){ varName = var; }

#define SYNTHESIZE_PASS_BY_REF(varType, varName, funName)\
protected: varType varName;\
public: inline varType& Get##funName(void) { return varName; }\
public: inline void Set##funName(const varType& var){ varName = var; }
