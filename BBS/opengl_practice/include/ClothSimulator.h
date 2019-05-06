#pragma once


#include <list>
#include "TriangularMesh.h"
//#include "layout/ParameterWindow.h"
#include "Math/performance.h"

//class GLWidget;

class ClothSimulator{
public:
	ClothSimulator();
	ClothSimulator(TriangularMesh* clmesh);
	~ClothSimulator();

	void initWithClothMesh(TriangularMesh* clmesh);
	void reset();


	friend GLWidget;
	
//private:
	// Original Mesh
	TriangularMesh*				clothMesh;

	vector<TriangularMesh*>		colliders;

	// Geometry
	unsigned int				nV;
	unsigned int				nE;
	unsigned int				nT;
	unsigned int				nB;

	vector<Vector3i>			triangles;		//vertex의 index를 저장			
	vector<Vector2i>			edges;			
	vector<Vector3i>			trianglesEdges;
	vector<int>					bendingElementIdx;			
	
	vector<Vector2d>			restPos;	
	vector<Vector3i>			restTri;	
	vector<double>				restLengths;				
	vector<double>				restTriangleAreas;

	vector<Vector3d>			vertexNormals;
	vector<Vector3d>			facetNormals;

	// Physical Datas
	vector<double>				mass;	
	vector<Vector3d>			pos;	
	vector<Vector3d>			prev_pos;		
	vector<Vector3d>			vel;	
	vector<Vector3d>			prev_vel;
	vector<Vector3d>			force;	


	int temp_nnz;




	list<int>					fixedConstraintVertices;
	

	void updateFacetNormals();
	void updateVertexNormals();
};
