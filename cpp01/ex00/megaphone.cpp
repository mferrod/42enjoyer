#include <iostream>

void print(char *str)
{
	int i = 0;
	while (str[i])
	{
		std::cout << (char)toupper(str[i]);
		i++;
	}
}

int main(int argc, char const *argv[])
{
	(void)argc;
	if (argv[1] != NULL)
	{
		argv++;
		while (*argv)
		{
			print((char *)*argv);
			argv++;
		}
		std::cout << "\n";
	}
	else
		print((char *)"* LOUD AND UNBEARABLE FEEDBACK NOISE *\n");
	return 0;
}
