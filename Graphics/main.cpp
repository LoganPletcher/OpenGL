#define GLM_FORCE_PURE
#include "OPENGL_STAR_SYSTEM.h"

int main()
{
	OpenGL_Star_System Sol = OpenGL_Star_System();

	Sol.Start();
	while (Sol.Update() == true)
		Sol.Draw();
	Sol.Quit();
	return 0;
}