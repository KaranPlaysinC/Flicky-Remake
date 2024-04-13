#include "soil.h"
#include "baseTypes.h"
class Textures
{
public:
	Textures();
		~Textures();
	static Textures* CreateInstance();
	static Textures* GetInstance();
	static Textures* IText;

	void init();

	unsigned int FlickySprite = SOIL_load_OGL_texture("asset/Flicky.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	unsigned int ChirpSprite = SOIL_load_OGL_texture("asset/spritesheet2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);

	unsigned int LevelSprite = SOIL_load_OGL_texture("asset/spritesheet2.png", SOIL_LOAD_AUTO, SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_NTSC_SAFE_RGB | SOIL_FLAG_COMPRESS_TO_DXT);
};
