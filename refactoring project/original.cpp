/******************************************************************************
Brief Description: Exercise to rework code to satisfy SOLID
******************************************************************************/
#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

using namespace std;

enum SHAPE_TYPE
{
	RECTANGLE,
	SQUARE,
	TRIANGLE,
	CIRCLE
};

enum PRINT_STYLE
{
	STYLE_A,
	STYLE_B,
	STYLE_C
};

struct ShapeData
{
	float width;
	float height;
	SHAPE_TYPE type;
	PRINT_STYLE style;
};

int main(void)
{
	// Declare 4 shapes in an array
	ShapeData myShapes[4];

	// Initialize 1st shape
	myShapes[0].type = RECTANGLE;
	myShapes[0].width = 10.f;
	myShapes[0].height = 5.0f;
	myShapes[0].style = STYLE_A;

	// Initialize 2nd shape
	myShapes[1].type = SQUARE;
	myShapes[1].width = 7.f;
	myShapes[1].height = 7.0f;
	myShapes[1].style = STYLE_B;

	// Initialize 3rd shape
	myShapes[2].type = TRIANGLE;
	myShapes[2].width = 10.f;
	myShapes[2].height = 5.0f;
	myShapes[2].style = STYLE_C;

	// Initialize 4th shape
	myShapes[3].type = CIRCLE;
	myShapes[3].width = 4.0f;
	myShapes[3].height = 4.0f;
	myShapes[3].style = STYLE_A;

	// Loop for all shapes
	for (int i = 0; i < 4; ++i)
	{
		// Get the area (Formula based on the shape type)
		float areaResult = 0.0f;
		switch (myShapes[i].type)
		{
		case RECTANGLE:
			areaResult = myShapes[i].width * myShapes[i].height;
			break;

		case SQUARE:
			areaResult = myShapes[i].width * myShapes[i].width;
			break;

		case TRIANGLE:
			areaResult = 0.5f * myShapes[i].width * myShapes[i].height;
			break;

		case CIRCLE:
			areaResult = (float)M_PI * myShapes[i].width * myShapes[i].width;
			break;
		default:
			break;
		}

		// Print based on the style set
		switch (myShapes[i].style)
		{
		case STYLE_A:
			cout << "A: The area is " << areaResult << endl;
			break;

		case STYLE_B:
			cout << "B: The given shape has an area of " << areaResult << endl;
			break;

		case STYLE_C:
			cout << "C: Answer: " << areaResult << endl;
			break;
		default:
			break;
		}
	}

	// Extra pause to review the printout
	// Note: There might be more shapes and styles to add in the future, is this a good solution?
	system("pause");
}

/*
A: The area is 50
B: The given shape has an area of 49
C: Answer: 25
A: the area is 50.2655
*/
