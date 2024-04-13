#include "baseTypes.h"

class Flicky
{
public:
    Flicky();
    ~Flicky();
    static Flicky* IFlicky;
    float_t FPosX; int FPosY;
    float_t movespeed;

    int previoustime = 0;
    int jumpDistance;
    float_t jumpSpeed;
    int jumpTime;
    int jumpHeight;
    int initPos;
    int FinPos;
    bool jumpProcess = false;

    
    
    GLuint GameOver = 0;
    GLuint FlickySprite = 0;

    int lives;
    float_t FwidthX; float_t FheightY;
    
    void init();
    void FlickyPhysics(float deltatime);

    float_t gravity = 2.0f;
    void update(float deltatime, float vy, float vx, float y, float x);
    
 
    float lerpFlicky(float a, float b, float k);  //use for jump

    static Flicky* CreateInstance();
    static Flicky* GetInstance();
    void MoveRight(bool right);
    void Jump();
    bool jumped = false;
    int Onground();
    bool checkLerp();
    
    void Descend();
    int jumpFlag;
    int onground;
    int touchDown;

    float_t getFPosX();


    int getFPosY();
    int getFwidthX();
    int getFheightY();
    void drawFlicky();

    bool h = false;
    bool v = false;
    bool hit = false;
    bool hit2 = false;
    bool hit3 = false;
    bool hit4 = false;
    bool hit5 = false;
    bool hit6 = false;
    bool hit7 = false;
    bool hit8 = false;
    bool hit9 = false;
    bool hit10 = false;
    bool hit11 = false;
    bool hit12= false;

    void loselife();
    
  
    bool collision(float X1, float Y1, float width1, float height1, float X2, float Y2, float width2, float height2, bool h, bool v)     //collision algorithm
    {
        if (X1 + width1 / 2 >= X2 - width2 / 2 && X1 - width1 / 2 <= X2 + width2 / 2 && Y1 + height1 / 2 >= Y2 - height2 / 2 && Y1 - height1 / 2 <= Y2 + height2 / 2)
        {
            return true;
        }
        else
        {

        }
        return false;
    };
    
    //Collision Detection
    //void colPlatform1();
    //void checkCol1(bool check1, bool check2, bool check3, bool check4);
    //void checkCol2(bool check1, bool check2, bool check3, bool check4);
    //void checkCol3(bool check1, bool check2, bool check3, bool check4);
    //void checkCol4(bool check1, bool check2, bool check3, bool check4);
    //void checkCol5(bool check1, bool check2, bool check3, bool check4);
    //void checkCol6(bool check1, bool check2, bool check3, bool check4);
    //void checkCol7(bool check1, bool check2, bool check3, bool check4);
    //void checkCol8(bool check1, bool check2, bool check3, bool check4);
    ////void checkCol8(bool check1, bool check2, bool check3, bool check4);
    //void checkCol9(bool check1, bool check2, bool check3, bool check4);
    //void checkCol10(bool check1, bool check2, bool check3, bool check4);
    //void checkCol11(bool check1, bool check2, bool check3, bool check4);
    //float_t colPosX, colPosY;

    ////bool CollidedX1 = false;
    //bool Collided2 = false;
    //bool Collided3 = false;
    //bool Collided4 = false;
    //bool Collided5 = false;
    //bool Collided6 = false;
    //bool Collided7 = false;
    //bool Collided8 = false;
    //bool Collided9 = false;
    //bool Collided10 = false;
    //bool Collided11 = false;
    //bool Collided12 = false;
    //

    //bool coltop1=false;
    //bool colbottom1=false;
    //bool colleft1=false;
    //bool colright1=false;

    
    
    void FlickyHit();

    void drawLosingScreen();

    bool gethit1();
    bool gethit2();
    bool gethit3();
    bool gethit4();
    bool gethit5();
    bool gethit6();
    bool gethit7();
    bool gethit8();
    bool gethit9();
    bool gethit10();
    bool gethit11();
    bool gethit12();

};
