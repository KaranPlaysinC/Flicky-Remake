#include"baseTypes.h"
class platform
{
public:


	static platform* IPlat1;
	static platform* CreateInstance();
	static platform* GetInstance();

	void initPlat();
	void drawPlat();
	float_t getX1();

	
private:
	platform();
	~platform() {};
	
	float_t X1, Y1, X2, Y2;
	float_t Pwidth, PHeight;

};