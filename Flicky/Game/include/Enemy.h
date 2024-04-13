class enemy
{
public:

	enemy();
	~enemy();

	static enemy* Ienemy;
	static enemy* GetInstance();
	static enemy* CreateInstance();


	int EnX1;
	int EnX2;
	int EnX3;
	int EnX4;
	int EnX5;
	int EnX6;
	int EnX7;
	int EnX8;
	int EnX9;
	int EnX10;
	int EnX11;
	int EnX12;

	int EnY1;
	int EnY2;
	int EnY3;
	int EnY4;
	int EnY5;
	int EnY6;
	int EnY7;
	int EnY8;
	int EnY9;
	int EnY10;
	int EnY11;
	int EnY12;

	int	qheight;
	int qwidth;

	GLuint DarkFlicky=0;

	int hitflicky = 0;

	int colChirp();
	int colFlicky();

	void FlickyHit();

	bool collision(float X1, float Y1, float width1, float height1, float X2, float Y2, float width2, float height2,bool h, bool v)     //collision algorithm
	{
		if (X1 + width1/2 >= X2 - width2/2 && X1 - width1/2 <= X2 + width2/2 && Y1 + height1/2 >= Y2 - height2/2 && Y1 - height1/2 <= Y2 + height2/2)
		{
			return true;
		}

			return false;
	};
	void initialize();

	void drawEnemy1();
	void drawEnemy2();
	void drawEnemy3();
	void drawEnemy4();
	void drawEnemy5();
	void drawEnemy6();
	void drawEnemy7();
	void drawEnemy8();
	void drawEnemy9();
	void drawEnemy10();

	void init();

	int getEnX1();
	int getEnY1();

	int getqwidth();
	int getqheight();

	int getEnX2();
	int getEnY2();

	int getEnX3();
	int getEnY3();

	int getEnX4();
	int getEnY4();

	int getEnX5();
	int getEnY5();

	int getEnX6();
	int getEnY6();

	int getEnX7();
	int getEnY7();

	int getEnX8();
	int getEnY8();

	int getEnX9();
	int getEnY9();

	int getEnX10();
	int getEnY10();

	int getEnX11();
	int getEnY11();

	int getEnX12();
	int getEnY12();

	
	void moveUp(int y, bool top);

	void update(DWORD milliseconds);

	void LocCheck(int x , int y);

	bool right1 = false;
	bool right2 = false;
	bool right3 = false;
	bool right4 = false;
	bool right5 = false;
	bool right6 = false;
	bool right7 = false;
	bool right8 = false;
	bool right9 = false;
	bool right10 = false;


	int speed1;
	int speed2;
	int speed3;
	int speed4;
	int speed5;
	int speed6;
	int speed7;
	int speed8;
	int speed9;
	int speed10;

	void moveRight1();
	void moveRight2();
	void moveRight3();
	void moveRight4();
	void moveRight5();
	void moveRight6();
	void moveRight7();
	void moveRight8();
	void moveRight9();
	void moveRight10();

};