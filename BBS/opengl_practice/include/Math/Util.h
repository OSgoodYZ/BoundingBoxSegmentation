//============================================================================
//
//
//  Primary Author: Doyub Kim
//		kim@graphics.snu.ac.kr
//
//  Copyright (c) Doyub Kim. 2005-2007. All rights reserved.
//	Distrubution or modification without any permission is not allowed.
//
//============================================================================





#ifndef __UTIL_H__
#define __UTIL_H__

//============================================================================
// 1. Arithmatics

const double PI		= double(3.14159265358979323846);		// ¥ð
const float SQRT2	= 1.4142135623730951f;



#define SIGN(a)		( ((a)>0) ? 1 : -1 )
#ifndef MIN2
#define MIN2(a,b)	( ((a)<(b)) ? (a) : (b) )
#endif
#ifndef MAX2
#define MAX2(a,b)	( ((a)>(b)) ? (a) : (b) )
#endif



#ifndef ABS
#define ABS(x)		( ((x)>=0.0) ? (x) :-(x) )
#endif
#define ABSMIN(a,b)	( ((a*a)<(b*b)) ? (a) : (b) )
#define ABSMAX(a,b)	( ((a*a)>(b*b)) ? (a) : (b) )
#define SQ(x)		( (x)*(x) )
#define CB(x)		( (x)*(x)*(x) )
#define SQRT(x)		( sqrt(ABS(x)) )
#define MAG(x,y,z)	( sqrt( (x)*(x) + (y)*(y) + (z)*(z) ) )
#define MAG2(x)		( sqrt( (x[0])*(x[0]) + (x[1])*(x[1]) ) )
#define MAG3(x)		( sqrt( (x[0])*(x[0]) + (x[1])*(x[1]) + (x[2])*(x[2]) ) )
#define DIST2(x1,y1,x2,y2) ( sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) ) )
#define DOT2(x,y)	( x[0]*y[0] + x[1]*y[1] )
#define DOT3(x,y)	( x[0]*y[0] + x[1]*y[1] + x[2]*y[2] )
#define AVG2(x1,x2) ( 0.5*( (x1)+(x2) ) )
#define AVG4(x1,x2,x3,x4) ( 0.25*( (x1)+(x2)+(x3)+(x4) ) )
#define AVG8(x1,x2,x3,x4,x5,x6,x7,x8) ( 0.125*( (x1)+(x2)+(x3)+(x4)+(x5)+(x6)+(x7)+(x8) ) )
#define RANDOM(x)	( ((float)(rand()%(x)))/((float)x) )
#define RANDOM_SIGN	( (rand()%2 == 1) ? 1 : -1 )
#define DTOR		0.0174532925
#define RTOD		57.324840
#define ACOS(x)		( ((x)>1.0) ? (0) : ( ((x)<-1.0) ? (PI) : (acos(x)) ) )
#define ASIN(x)  ( ((x)>1.0) ? (PI/2.0) : ( ((x)<-1.0) ? (-PI/2.0) : (asin(x)) ) )
#define DC_EPS			1.0e-4
#define SWAP(a,b)	a^=b^a^=b

inline double pow2(int p) {
	switch (p) {
		case -20: return 9.53674e-07;
		case -19: return 1.90735e-06;
		case -18: return 3.8147e-06;
		case -17: return 7.62939e-06;
		case -16: return 1.52588e-05;
		case -15: return 3.05176e-05;
		case -14: return 6.10352e-05;
		case -13: return 0.0001220703125;
		case -12: return 0.000244140625;
		case -11: return 0.00048828125;
		case -10: return 0.0009765625;
		case -9: return 0.001953125;
		case -8: return 0.00390625;
		case -7: return 0.0078125;
		case -6: return 0.015625;
		case -5: return 0.03125;
		case -4: return 0.0625;
		case -3: return 0.125;
		case -2: return 0.25;
		case -1: return 0.5;
		case 0: return 1;
		case 1: return 2;
		case 2: return 4;
		case 3: return 8;
		case 4: return 16;
		case 5: return 32;
		case 6: return 64;
		case 7: return 128;
		case 8: return 256;
		case 9: return 512;
		case 10: return 1024;
		case 11: return 2048;
		case 12: return 4096;
		case 13: return 8192;
		case 14: return 16384;
		case 15: return 32768;
		case 16: return 65536;
		case 17: return 131072;
		case 18: return 262144;
		case 19: return 524288;
		case 20: return 1048576;
		default:
			double ret = 1;
			if (abs(p) == p)
				for (int i=0; i<abs(p); i++) ret *= 2.0;
			else
				for (int i=0; i<abs(p); i++) ret *= 0.5;
			return ret;
	}
}

inline int Obin( int p ) {
	int ret = 2;
	for ( int i = 0; i < p*2; i*=2 ) {
		if ( p < ret ) return ret;
		else ret *= 2;
	}
	return ret;

}

inline int Odec( int p ) {
	int ret = 10;
	for ( int i = 0; i < p*10; i*=10 ) {
		if ( p < ret ) return ret;
		else ret *= 10;
	}
	return ret;
}
//============================================================================
// 2. Debug

#define PRINT_INT(src) printf(#src ": %d\n", src)
#define PRINT_DOUBLE(src) printf(#src ": %f\n", src)
#define PRINT_ERROR(src) printf("ERROR: %s\n", src)
#define FLAG printf("FLAG\n")
#endif // __UTIL_H__