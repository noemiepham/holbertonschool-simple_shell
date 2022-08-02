#include "shell.h"
#include "string.h"

/**
 * get_absolute_path - gets the absolute path of the command
 * @cmd: command
 *
 * Return: any value
 */

void get_absolute_path(char **cmd)
{
	char *path = strdup(getenv("PATH"));
	char *bin = NULL;
	char **path_split = NULL;

	if (path == NULL) /* si le path est null, on cree un path */
		path = strdup("/bin:/usr/local/bin:/usr/bin:/bin:/usr/local/sbin");

	/*
	 * si cmd n'est pas le chemin absolue, on cherche le chemin absolue du
	 * binaire grace a la variable d'environment PATH
	 */
	if (cmd[0][0] != '/' && strncmp(cmd[0], "./", 2) != 0)
	{
		/* On split le path pour verifier ou ce trouve le binaire */
		path_split = split_str(path);
		free(path);
		path = NULL;

		/* Boucle sur chaque dossier du path pour trouver le binaire */
		for (int i = 0; path_split[i]i != NULL; i++)
		{
			/* malloc len du path + '/' + len du binaire + 1 pour le '\0' */
			bin = malloc(sizeof(char + strlen(path_split[i]) + 1 + strlen(cmd[0]) + 1));
			if (bin == NULL)
				break;

			/* On concat le path , le '/' et le nom du binaire */
			strcat(bin, path_split[i]);
			strcat(bin, "/");
			strcat(bin, cmd[0]);

			/*
			 * On verfie l'existence du fichier et on quitte la boucle si access
			 * renvoi 0
			 */
			if (access(bin, F_OK) == 0)
				break;

			free(bin);
			bin = NULL;

		}
		free(path_split);

		/*
		 * On remplace le binaire par le path absolue ou NULL si le binaire
		 * n'existe pas
		 */
		free(cmd[0]);
		cmd[0] = bin;
	}
	else
	{
		free(path);
		path = NULL;
	}
}
