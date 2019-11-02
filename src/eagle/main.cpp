#include <iostream>
#include <cassert>
#include <vector>
#include <cstring>


/* 
 * Run test or IO stream by default.
 * Make this variable 'false' to run tests.
 * */
const bool useByDefault_IO = false;
/* 
 * Enable this to run silent.
 * Program will not pause in the end.
 * */
const bool runInSilentMod = false;

int main(int argc, char* argv[]) 
{
	std::string fileName = "";
	
	std::ios_base::sync_with_stdio(false);
	
	if (argc == 1) 
	{
		if (useByDefault_IO)
                {

		}
		else
		{
                        std::cout << "Programm void." << std::endl;
		}
	}
	else 
	{
                if (strcmp(argv[1], "--test") == 0)
                {

                }
		else
		{
			if (strcmp(argv[1], "--file") == 0) 
			{
                                if (argc == 3)
                                {
                                    fileName = argv[2];
                                }

			}
                        else if (strcmp(argv[1], "--io") == 0)
                        {

                        }
			else
			{
                                std::cout << "No programm input specified." << std::endl;
				return 0;
			}


		}
	}
	if (!runInSilentMod)
	{
                std::cout << "Programm finished." << std::endl;
	}
	return 0;
}
