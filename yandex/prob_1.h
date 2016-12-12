#include <stdio.h>

/***********************************************************************\ 
	Author: Abdallah Mahran
    Desc: Problem 1 - Yandex application
	Date: 12/04/2016
	Ref: https://yandex.com/jobs/vacancies/global/devmaps_cpp
***********************************************************************/

/*
  Problems in the provided code founded in the following methods:
  1- isValid:  should check the validity of the feature points ptr.
  2- read: we need to free the ptr "points" before allocating new memory
  3- draw: need to check the validity of the feature before calling the corresponding draw function
  Note: refactor code will be between the REFACTOR macro
*/


#define ARRAY_SIZE(x) (sizeof((x)) / sizeof((x)[0]))
#define ON 1
#define OFF 0
#define REFACTOR ON // Enable disable refactor


class Feature
{
public:
    enum FeatureType {eUnknown, eCircle, eTriangle, eSquare};
#if REFACTOR == ON
	Feature(FeatureType _type, double * pointsArr) : type(_type), points(pointsArr) 
	{ 
		// or we can perform a deep copy to the pointsArr pointer
	}
	Feature(FILE* file)
	{ 
		type = eUnknown;
		points = 0;
		read(file);
	}
#endif 
    Feature() : type(eUnknown), points(0) { }
 
    ~Feature()
    {
        if (points)
            delete points;
    }

#if REFACTOR == ON
	    bool isValidPoints()
		{
			if(!points)
				return false;
			int size = ARRAY_SIZE(points);
			return (size == 3 && type == eCircle ) || 
				(size == 6  && type == eTriangle ) ||
				(size == 8 && type == eSquare );
		}
#endif 

    bool isValid() 
    {
        return type != eUnknown
#if REFACTOR == ON 
			&& isValidPoints();
#endif 
			;
    }
	//
    bool read(FILE* file)
    {        
        if (fread(&type, sizeof(FeatureType), 1, file) != sizeof(FeatureType))
            return false;
        short n = 0;

        switch (type)
        {
			case eCircle: n = 3; break;
			case eTriangle: n = 6; break;
			case eSquare: n = 8; break;
			default: type = eUnknown; return false;
        }
#if REFACTOR == ON
		// check if points read before
		// if so, free the allocated memory before allocate new points
		if(points)
			delete points;
		// chech if type is unkown 
		if(type == eUnknown)
			return false;
#endif

        points = new double[n];
        if (!points) // check if allocating memory is succeeded
            return false;
        return fread(&points, sizeof(double), n, file) == n*sizeof(double);
    }
	//
    void draw()
    {
#if REFACTOR == ON
		if(!isValid())
			return;
#endif
		switch (type)
		{
		case eCircle: drawCircle(points[0], points[1], points[2]); break;
		case eTriangle: drawPolygon(points, 6); break;
		case eSquare: drawPolygon(points, 8); break;
		}
    }
 
protected:
    void drawCircle(double centerX, double centerY, double radius);
    void drawPolygon(double* points, int size);
 
    double* points;
    FeatureType type;        
};
 
extern int main()
{
    Feature feature;
    FILE* file = fopen("features.dat", "r");
    feature.read(file);
    if (!feature.isValid())
        return 1;
    return 0;
}
