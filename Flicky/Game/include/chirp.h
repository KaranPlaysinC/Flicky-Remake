class chirpNotManager { // should just be chirp
public:
	void Update(uint32_t milliseconds) {}
	void Draw() {}

	int X;
	int Y;
	bool colFlag;
	bool colExit;
	bool h;
};
#define NUM_CHIRPS 13

class chirp // this is really chirpManager
{

public:
	
	chirp();
	~chirp() {};
	static chirp* Ichirp;
	static chirp *CreateInstance();
	static chirp* GetInstance();

	int quadW;
	int quadH;
	
	int FcolX;
	int FcolY;
	int FHeight;
	int FWidth;

	int EX;  
	int EY; 
	int EW;  
	int EH;  

	void initialize();
	int SpawnLoc(int initX, int initY);
	bool colwithFlicky();
	bool colwithPlatforms();
	bool colwithTiger(bool colTiger);

	chirpNotManager chirps[NUM_CHIRPS];

	int chirpX;
	int chirpY;

	int chirpX2;
	int chirpY2;

	int chirpX3;
	int chirpY3;

	int chirpX4;
	int chirpY4;

	int chirpX5;
	int chirpY5;

	int chirpX6;
	int chirpY6;

	int chirpX7;
	int chirpY7;

	int chirpX8;
	int chirpY8;

	int chirpX9;
	int chirpY9;

	int chirpX10;
	int chirpY10;

	int chirpX11;
	int chirpY11;

	int chirpX12;
	int chirpY12;

	int chirpX13;
	int chirpY13;


	int chirpSpeed;
	float lerpchirp(float a, float b, float k)
	{
		return a + (b - a) * k;
	}
	
	void lerpWithFlicky();

	void CollideWithFlicky();
	
	void lerptoExit();

	void collidewithExit();
	
	int exitFlag=0;

	int WinFlag = 0; //if all chirps exitset this to 1 and change to win screen!


	int colFlag1; //with flicky
	int colFlag2;
	int colFlag3;
	int colFlag4;
	int colFlag5;
	int colFlag6;
	int colFlag7;
	int colFlag8;
	int colFlag9;
	int colFlag10;
	int colFlag11;
	int colFlag12;
	int colFlag13;

	int colExit1;
	int colExit2;
	int colExit3;
	int colExit4;
	int colExit5;
	int colExit6;
	int colExit7;
	int colExit8;
	int colExit9;
	int colExit10;
	int colExit11;
	int colExit12;
	int colExit13;

	int cwidth;
	int cheight;
	GLuint ChirpSprite = 0;
	
	int getchirpspeed() { return chirpSpeed; }
	int getchirpX() { return chirpX; }
	int getchirpY() { return chirpY; }
	int getQuadWidth(){ return quadW; }
	int getQuadHeight(){ return quadH; }

	void drawChirps();
	void drawChirp();
	void drawChirp2();
	void drawChirp3();
	void drawChirp4();
	void drawChirp5();
	void drawChirp6();
	void drawChirp7();
	void drawChirp8();
	void drawChirp9();
	void drawChirp10();
	void drawChirp11();
	void drawChirp12();
	void drawChirp13();

	int getcolFlag1();
	int getcolFlag2();
	int getcolFlag3();
	int getcolFlag4();
	int getcolFlag5();
		int getcolFlag6();
		int getcolFlag7();
		int getcolFlag8();
		int getcolFlag9();
		int getcolFlag10();
		int getcolFlag11();
		int getcolFlag12();


		void WinCondition();
		void dropChirps();

		bool h1=false;
		bool h2 = false;
		bool h3 = false;
		bool h4 = false;
		bool h5 = false;
		bool h6 = false;
		bool h7 = false;
		bool h8 = false;
		bool h9 = false;
		bool h10 = false;
		bool h11 = false;
		bool h12 = false;

		void drawWinScreen();

};