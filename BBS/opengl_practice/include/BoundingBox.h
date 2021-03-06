#pragma once
#include <list>
#include "ClothSimulator.h"
//#include "layout/ParameterWindow.h"
#include "Math/performance.h"
#include<algorithm>

using namespace std;
#define VerySmall -10000
#define VeryLarge 10000

bool Y_cmp(const Vector3d &a, const Vector3d &b) {
	return a.y < b.y;
}
struct BBCompo
{
	double MaxX = VerySmall;
	double MinX = VeryLarge;
	double MaxY = VerySmall;
	double MinY = VeryLarge;
	int ControlPoint = 0;
};

class BoundingBoxS
{
public:
	double MaxX = VerySmall;
	double MinX = VeryLarge;
	double MaxY = VerySmall;
	double MinY = VeryLarge;
	int NumOfBoxes = 1;

	vector<Vector3d> OrderedYvalue;
	vector<BBCompo> Segments;

	BoundingBoxS();
	BoundingBoxS(ClothSimulator cloth);
	~BoundingBoxS();

	void MakeSegement(double NumOfBox);
	void Expand2LargeBB();
private:


};

BoundingBoxS::BoundingBoxS()
{
	MaxX = VerySmall;
	MinX = VeryLarge;
	MaxY = VerySmall;
	MinY = VeryLarge;


}
BoundingBoxS::BoundingBoxS(ClothSimulator cloth)
{
	MaxX = VerySmall;
	MinX = VeryLarge;
	MaxY = VerySmall;
	MinY = VeryLarge;
	

	//constructe max,min bounding box
	for (int i = 0; i < cloth.nV; i++)
	{
		OrderedYvalue.push_back(cloth.pos[i]);
		MaxX = (MaxX < cloth.pos[i].x) ?  (cloth.pos[i].x ) : MaxX;
		MinX = (MinX > cloth.pos[i].x) ? (cloth.pos[i].x) : MinX;
		MaxY = (MaxY < cloth.pos[i].y) ? (cloth.pos[i].y) : MaxY;
		MinY = (MinY > cloth.pos[i].y) ? (cloth.pos[i].y) : MinY;
	}
	sort(OrderedYvalue.begin(), OrderedYvalue.end(), Y_cmp); // y값을 기준으로  sorting
	
															 
	//sorting test
	//for (int i = 0; i < OrderedYvalue.size(); i++)
	//{
	//	cout << OrderedYvalue[i].y << endl;
	//}
}
void BoundingBoxS::MakeSegement(double NumOfBox)
{
	NumOfBoxes = NumOfBox;
	double interval = 0.0;
	interval = (MaxY - MinY) / NumOfBox;
	BBCompo tmp;

	int k = 0;
	for (int i = 1; i < NumOfBox+1; i++)
	{
		tmp.MaxX = VerySmall;
		tmp.MinX = VeryLarge;
		tmp.MaxY = VerySmall;
		tmp.MinY = VeryLarge;
		for (int j = k; j < OrderedYvalue.size(); j++)
		{
			tmp.MaxX = (tmp.MaxX < OrderedYvalue[j].x) ? (OrderedYvalue[j].x) : tmp.MaxX;
			tmp.MinX = (tmp.MinX > OrderedYvalue[j].x) ? (OrderedYvalue[j].x) : tmp.MinX;
			tmp.MaxY = (tmp.MaxY < OrderedYvalue[j].y) ? (OrderedYvalue[j].y) : tmp.MaxY;
			tmp.MinY = (tmp.MinY > OrderedYvalue[j].y) ? (OrderedYvalue[j].y) : tmp.MinY;

			if (OrderedYvalue[j].y > MinY + interval * i)
			{
				k = j+1;
				tmp.ControlPoint = k-1;
				cout << k << endl;
				break;
				
			}
			tmp.ControlPoint = j;
		}
		Segments.push_back(tmp);
	}


}
void BoundingBoxS::Expand2LargeBB()
{
	double interval = 0.0;
	interval = (MaxY - MinY) / NumOfBoxes;

	int k = 0;
	for (int i = 1; i < NumOfBoxes + 1; i++)
	{

		for (int j = k; j < OrderedYvalue.size(); j++)
		{
			if (OrderedYvalue[j].x >= 0)			OrderedYvalue[j].x += (MaxX - Segments[i - 1].MaxX);
			else OrderedYvalue[j].x += (MinX - Segments[i - 1].MinX);


			if (OrderedYvalue[j].y > MinY + interval * i)
			{

				k = j + 1;
				cout << k << endl;
				break;

			}

		}
	}
}
BoundingBoxS::~BoundingBoxS()
{
}