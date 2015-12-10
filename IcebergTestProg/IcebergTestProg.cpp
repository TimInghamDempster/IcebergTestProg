// IcebergTestProg.cpp : Defines the entry point for the console application.
//
#include <stdio.h>
#include <thread>

int main(int argc, char* argv[])
{
	FILE* newFile = fopen("testFile.txt",  "a");

	for(int i = 0; i < 10; i++)
	{
		if(newFile != NULL)
		{
			break;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));		
	}

	if(newFile != NULL)
	{
		char* env = getenv("SGE_TASK_ID");

		if(env != NULL)
		{
			int numChars = fprintf(newFile, "%s %s", env, "\n");
		}
		else
		{
			int numChars = fprintf(newFile, "%s", "Failed to get array variable \n");
		}

		fclose(newFile);
	}

	return 0;
}

