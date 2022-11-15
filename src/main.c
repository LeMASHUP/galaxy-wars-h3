#include <h3.h>
#include "components\spritecomponent.h"

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int width;
int height;

int main(int argc, char** argv)
{
	width = 500;
	height = 700;

	H3Handle h3 = H3_Init((SH3InitParams) {
		.fullscreen = false,
			.height = height,
			.width = width,
			.windowTitle = "Galaxy Wars H3 Engine"
	});
	H3Handle scene = H3_Scene_Create(h3, false);
	H3Handle player = H3_Object_Create(scene, "player", NULL);

	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("assets/Player.png", 0x22));
	H3_Object_SetRenderOrder(player, 1);
	H3_SetView2(h3, 0, 0, width, height);


	while (H3_DoFrame(h3, scene)) {


	}
	return 0;
}
