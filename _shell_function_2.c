/**
 * _printev : print environ 
 * 
 */
void _printev(void)
{
    int i = 0;
    while (environ[i] != NULL)
    {
        printf("%s\n", environ[i]);
        i++;
    }
}