#pragma once

#include <vector>
#include <Math/vector.h>
#define strdup(s) _strdup(s)
#ifndef M_PI
#define M_PI 3.14159265f
#endif

using namespace std;

class OBJMaterial{
public:
	OBJMaterial(){
		diffuse[0] = 0.7f; diffuse[1] = 0.7f; diffuse[2] = 0.7f; diffuse[3] = 1.f;
		ambient[0] = 0.2f; ambient[1] = 0.2f; ambient[2] = 0.2f; ambient[3] = 1.f;
		specular[0] = 0.5f; specular[1] = 0.5f; specular[2] = 0.5f; specular[3] = 1.f;
		emissive[0] = 0.f; emissive[1] = 0.f; emissive[2] = 0.f; emissive[3] = 1.f;
		shininess = 100;    
	};
	~OBJMaterial(){};
	char*			name;
	float			diffuse[4];           
	float			ambient[4];
	float			specular[4];
	float			emissive[4];
	float			shininess;    
};

class OBJTriangle {
public:
	Vector3i			vindices;           
	Vector3i			nindices;           
	Vector3i			tindices;           
	int					findex;                
};

class OBJGroup{
public:
	OBJGroup(char* _name) { name = strdup(_name); numtriangles = 0;};
	char*					name;       
	int						numtriangles;   
	vector<int>				triangles;      
	int						material;       
};

class GLWidget;

class Object{
	friend GLWidget;
public:	
	Object();
	Object(const char* filePath);
	~Object();
	
	OBJGroup* findGroup(char* name);
	int findMaterial(char* name);
	void readOBJFile(const char* filePath);
	void firstPass(FILE* file);
	void secondPass(FILE* file);
	void readMTLFile(char* name);
	void writeOBJFile(char* filePath);
	void writeMTLFile(char* filePath);
	void updateFacetNormals();
	void updateVertexNormals(float angle);
		
	//virtual void updatePosition();
	int getNumOfVertices(){ return numvertices; };
	int getNumOfTriangles(){ return numtriangles; };
	
	char*						pathname;        
	char*						mtllibname;      

	int							numvertices;     
	vector<Vector3d>			vertices;        

	int						    numnormals;      
	vector<Vector3d>			normals;         

	int							numtexcoords;    
	vector<Vector2d>			texcoords;       

	int						    numfacetnorms;   
	vector<Vector3d>			facetnorms;      

	int						    numtriangles;    
	vector<OBJTriangle>			triangles;       

	int							nummaterials;    
	vector<OBJMaterial>			materials;       

	int							numgroups;       
	vector<OBJGroup>			groups;          

	//GLfloat						position[3];     
};