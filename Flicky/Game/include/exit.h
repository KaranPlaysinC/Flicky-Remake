class Exit
{
public:

	Exit();
	~Exit();

	static Exit* CreateInstance();
	static Exit* GetInstance();
	static Exit* IExit;
	
	int quadWidth;
	int quadHeight;

	int ExitX;
	int ExitY;

	void collidewithFlicky();
	void OnCollision();
	int colExit;
	void drawExit();


	int getExitX();
	int getExitY();
	int getWidth();
	int getHeight();
	int getcolFlag();

};
