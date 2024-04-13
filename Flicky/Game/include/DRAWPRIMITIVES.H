class drawPrimitives
{
public:
	static drawPrimitives* CreateInstance();
	static drawPrimitives* Primitive;
	static drawPrimitives* GetInstance() { return Primitive; };
	~drawPrimitives() {};

	void platform();
	void drawFlicky();
	void TigerSpawn();




};
