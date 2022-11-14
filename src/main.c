#include <h3.h>

#ifndef NDEBUG
# pragma comment(lib, "h3-s-d.lib")
#else // !NDEBUG
# pragma comment(lib, "h3-s.lib")
#endif // !NDEBUG

int state;
state = 1;

int main(int argc, char** argv)
{
	if (state = 1) {
		H3Handle screen_cam = H3_Init((SH3InitParams) {
			.fullscreen = false,
				.height = 500,
				.width = 500,
		});
	};
	return 0;
}
