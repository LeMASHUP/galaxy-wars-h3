#include <h3.h>
#include "components\spritecomponent.h"
#include "components\cameracomponent.h"
#include <stdlib.h>
#include<math.h>

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
float playerx;
float playery;
float dx;
float dy;
float px;
float py;

int main(int argc, char** argv)
{
	width = 1280;
	height = 720;

	char bullet_name[15];
	int index_bullet = 0;
	
	

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
	H3_Object_Translate(player, width/2, height/2);
	H3_Object_EnablePhysics(player, H3_BOX_COLLIDER(CDT_Dynamic, 50, 50, 0x22, false));
	



	while (H3_DoFrame(h3, scene)) {
		dy = mousey - playery;
		dx = mousex - playerx;
		H3_Transform_GetPosition(H3_Object_GetTransform(player), &playerx, &playery);
		H3_Input_GetMousePos(h3, &mousex, &mousey);
		angle = atan2(dy, dx) * 180 / 3.141593 + 90;
		H3_Object_SetRotation(player, angle);


		if (H3_Input_IsMouseBtnDown(MB_Right)) {
			H3_Object_AddVelocity(player, dx / 45, dy / 45);
		}
		else {
			H3_Object_GetVelocity(player, &px, &py);
			H3_Object_SetVelocity(player, px*0.985,py*0.985);
		};

		if (H3_Input_IsMouseBtnPressed(MB_Left)) {
			//cr�ation de la flamme
			snprintf(bullet_name, 15, "%d", index_bullet++);
			H3Handle bullet = H3_Object_Create(scene, bullet_name, NULL);
			H3_Object_EnablePhysics(bullet, H3_BOX_COLLIDER(CDT_Dynamic, 25, 10, 0x22, false));
			H3_Object_Translate(bullet, playerx, playery + 30);
			H3_Object_SetVelocity(bullet, dx/20,dy/20);
			H3_Object_SetRenderOrder(bullet, 1);
			H3_Object_AddComponent(bullet, SPRITECOMPONENT_CREATE("../bin/assets/flamme.png", A_Center));
		}
			




	}
	return 0;
}
