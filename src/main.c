#include <h3.h>
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include <stdlib.h>

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int width;
int height;
int mousex;
int mousey;
float angle;

int main(int argc, char** argv)
{
	width = 1280;
	height = 720;
	angle = 25;
	

	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = false,
		.height = height,
		.width = width,
		.windowTitle = "Galaxy Wars Hydrogen Engine 3"
	});


	H3Handle scene = H3_Scene_Create(h3, true);
	H3Handle player = H3_Object_Create(scene, "player", NULL);

	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_SetRenderOrder(player, 1);
	H3_SetView2(h3, 0, 0, width, height);
	H3_Object_Translate(player, 0, 0);
	


	while (H3_DoFrame(h3, scene)) {
		H3_Input_GetMousePos(h3, &mousex, &mousey);
		H3_Object_Rotate(player, angle);


	}
	return 0;
}
