/*  #include "shell.h"

int _stat(int ac, char **av)
{
    unsigned int i;
	struct stat st;

	if (ac < 2)
	{
		printf("Usage: %s path_to_file ...\n", av[0]);
		return (1);
	}
	i = 1;
	while (av[i])
	{
		printf("%s:", av[i]);
		if (stat(av[i], &st) == 0)
		{
				printf("FOUND\n");
		}
		else
		{
			printf(" NOT FOUND\n");
		}
		i++;
    }
}
int main(void)
{
   
 return 0;
}  */