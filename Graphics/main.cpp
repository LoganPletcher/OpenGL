#include "StarSystem.h"

int main()
{
	StarSystem Sol = StarSystem();

	Sol.startup();
	while (Sol.update(3.111) == true)
		Sol.draw();
	Sol.shutdown();

	return 0;
}