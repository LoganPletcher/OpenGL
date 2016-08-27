#include "StarSystem.h"

int main()
{
	Program* Sol = new StarSystem();
	if (Sol->startup() == true)
	{
		while (Sol->update() == true)
		{
			Sol->draw();
		}
		Sol->shutdown();
	}

	delete Sol;

	return 0;
}