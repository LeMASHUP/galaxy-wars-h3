#include <h3.h>

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
	while (h3, scene);
	return 0;
}
