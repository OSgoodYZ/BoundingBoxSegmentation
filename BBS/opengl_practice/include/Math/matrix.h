//==============================================================================
//
//	Matrix.h - ver 07.11.11b
//
//  Primary Author: Doyub Kim
//		kim@graphics.snu.ac.kr
//	Modified by Inyong Jeon
//		jeon@graphics.snu.ac.kr
//
//  Copyright (c) Doyub Kim. 2005-2007. All rights reserved.
//	Distrubution or modification without any permission is not allowed.
//
//==============================================================================
#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <assert.h>
#include "matrix3.h"
#include "matrix4.h"
#include "matrixN.h"
#include "matrixS.h"


typedef Matrix3<float>		Matrix3f;
typedef Matrix3<double>		Matrix3d;

typedef Matrix4<float>		Matrix4f;
typedef Matrix4<double>		Matrix4d;

typedef MatrixN<float>		MatrixNf;
typedef MatrixN<double>		MatrixNd;

typedef MatrixS<float>		MatrixSf;
typedef MatrixS<double>		MatrixSd;


#endif // __MATRIX_H__
