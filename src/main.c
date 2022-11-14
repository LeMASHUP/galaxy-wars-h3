#include <h3.h>
#include "components\spritecomponent.h"

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG


int main(int argc, char** argv)
{

		H3Handle h3 = H3_Init((SH3InitParams) {
			.fullscreen = false,
			.height = 500,
			.width = 500,
			.windowTitle = "Galaxy Wars H3 Engine"
		});
	H3Handle scene = H3_Scene_Create(h3, false);
	H3Handle player = H3_Object_Create(scene,"player", NULL);

	H3_Object_AddComponent(player, SPRITECOMPONENT_CREATE("Player.png", 0x22));

	while (h3, scene);
	return 0;
}
