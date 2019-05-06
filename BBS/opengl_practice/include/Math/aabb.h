#pragma once

#include <vector>
#include <list>
#include "vector.h"

class AABB {
public:
	Vector3d min;
	Vector3d max;
public:
	AABB() { min.set(0.0); max.set(0.0); }
	AABB(Vector3d p1, Vector3d p2);
	AABB(Vector3d p1, Vector3d p2, Vector3d p3);

	// setter
	AABB&	set(const AABB& ab);
	AABB&	set(Vector3d p1);
	AABB&	set(Vector3d p1, Vector3d p2);
	AABB&	set(Vector3d p1, Vector3d p2, Vector3d p3);

	// getter
	inline double lengthX() const { return abs(max[0]-min[0]); }
	inline double lengthY() const { return abs(max[1]-min[1]); }
	inline double lengthZ() const { return abs(max[2]-min[2]); }
	inline double minX() const { return min[0]; }
	inline double minY() const { return min[1]; }
	inline double minZ() const { return min[2]; }
	inline double maxX() const { return max[0]; }
	inline double maxY() const { return max[1]; }
	inline double maxZ() const { return max[2]; }

	// expand
	inline void expandX(double x) { min[0] -= x; max[0] += x;}
	inline void expandY(double y) { min[1] -= y; max[1] += y;}
	inline void expandZ(double z) { min[2] -= z; max[2] += z;}
	inline void expand(double t) { for(int i=0; i<3; i++) { min[i] -= t; max[i] += t;} }

	AABB&	operator=(const AABB& ab);
	AABB&	add(const AABB& ab);
	void	clear() { min.set(0.0); max.set(0.0); }

	// friend 
	friend int intersect(const AABB& ab1, const AABB& ab2);

};