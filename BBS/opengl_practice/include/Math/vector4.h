//============================================================================
//
//	Vector4.h - ver 0.1.0
//
//  Primary Author: Doyub Kim
//		kim@graphics.snu.ac.kr
//	Modified by Inyong Jeon
//		jeon@graphics.snu.ac.kr
//
//  Copyright (c) Doyub Kim. 2005-2007. All rights reserved.
//	Distrubution or modification without any permission is not allowed.
//
//============================================================================

#ifndef __VECTOR4_H__
#define __VECTOR4_H__

#include <cmath>
#include <cstdlib>
#include <iostream>

//============================================================================
//	Vector4 class definition
//!		Class to store a four dimensional vector.
//!		Expected uses include point in R4, RGBA color, etc.
template <typename T> class Vector4 {
public:
	Vector4() {
		data[0] = data[1] = data[2] = data[3] = 0;
	}

	Vector4( T d0, T d1, T d2, T d3 ) {
		data[0] = d0; data[1] = d1; data[2] = d2; data[3] = d3;
	}

	//////////////////////////////////////////////////////////////////////////
	// Index operators
	inline T &operator[]( unsigned int i)      ;
	inline T  operator[]( unsigned int i) const;

	Vector4<T> operator*( const T rhs ) const {
		return Vector4<T>(data[0]*rhs, data[1]*rhs, data[2]*rhs, data[3]*rhs);	
	}

	float *getFloat() const { return (float *)this; }

private:
	T data[4];
};

template <typename T> inline T &Vector4<T>::operator[]( unsigned int i ) {
	DB_CHECK(i<4);
	return data[i];
}

template <typename T> inline T  Vector4<T>::operator[]( unsigned int i ) const {
	DB_CHECK(i<4);
	return data[i];
}

#endif // __VECTOR4_H__