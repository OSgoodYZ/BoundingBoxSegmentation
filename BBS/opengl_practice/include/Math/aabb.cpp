
#include "stdafx.h"
#include "aabb.h"

AABB::AABB(Vector3d p1, Vector3d p2){
	set(p1, p2);
}

AABB::AABB(Vector3d p1, Vector3d p2, Vector3d p3){
	set(p1, p2, p3);
}

AABB& AABB::set(const AABB& ab){
	min = ab.min;
	max = ab.max;
	return *this;
}

AABB& AABB::set(Vector3d p1){
	min = p1;
	max = p1;
	return *this;
}
AABB& AABB::set(Vector3d p1, Vector3d p2){
	for(int i=0; i<3; ++i) {
		min[i] = MIN(p1[i],p2[i]);
		max[i] = MAX(p1[i],p2[i]);
	}
	return *this;
}
AABB& AABB::set(Vector3d p1, Vector3d p2, Vector3d p3){
	for(int i=0; i<3; ++i) {
		min[i] = MIN3(p1[i],p2[i],p3[i]);
		max[i] = MAX3(p1[i],p2[i],p3[i]);
	}
	return *this;
}

AABB& AABB::operator=(const AABB& ab){
	return set(ab);
}

AABB& AABB::add(const AABB& ab){
	for(int i=0; i<3; ++i) {
		if(min[i] > ab.min[i]) min[i] = ab.min[i];
		if(max[i] < ab.max[i]) max[i] = ab.max[i];
	}
	return *this;
}

int intersect(const AABB& ab1, const AABB& ab2) {
	if(ab1.min[0] > ab2.max[0] ) return 0;
	if(ab2.min[0] > ab1.max[0] ) return 0;

	if(ab1.min[1] > ab2.max[1] ) return 0;
	if(ab2.min[1] > ab1.max[1] ) return 0;

	if(ab1.min[2] > ab2.max[2] ) return 0;
	if(ab2.min[2] > ab1.max[2] ) return 0;

	return 1;
}


