#include "Core.h"



int main(int argc, char *argv[])						//argc = 2, argv = [0]".exe" [1]"admin/user"
{
	int result = checkArguments(argc, argv);
	if (result == 1 || result == 2)
	{
		systemH(result);		
	}
	return 0;
}