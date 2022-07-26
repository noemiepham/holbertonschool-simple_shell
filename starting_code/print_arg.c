#include <stdio.h>
#include "starting_code.h"
/**
 * main - program print argument
 * @ac: count number av
 * @av: argument value
 * Return: 0 si succes
 */
int main(int __attribute__((__unused__)) ac, char **av)
{
	int i = 0;

	while (av[i])
	{
		printf("%s\n", av[i]);
		i++;
	}
return (0);
}
