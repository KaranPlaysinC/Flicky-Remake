#include "baseTypes.h"
class CollisionField
{
public:
	CollisionField();
	~CollisionField();
	static CollisionField* ICol;
	static CollisionField* CreateInstance();
	static CollisionField* GetInstance();
	
	void colInit();
	void drawField();
	float_t LeftColX, RightColX, LowColY, TopColY;

	bool Enabled;

};