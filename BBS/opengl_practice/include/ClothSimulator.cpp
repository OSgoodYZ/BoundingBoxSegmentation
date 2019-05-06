#include "ClothSimulator.h"

ClothSimulator::ClothSimulator(){
	clothMesh = NULL;
	nV = nE = nT = nB = 0;
}

ClothSimulator::ClothSimulator(TriangularMesh* clmesh):clothMesh(clmesh){
	initWithClothMesh(clmesh);
}

ClothSimulator::~ClothSimulator(){

}

