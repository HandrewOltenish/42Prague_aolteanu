#include <unistd.h>
#include <stdio.h>

// try while (*str == *to_find && *str != 0)
{
	remember = remember + (*str - *to_find)
}

char    *ft_strstr(char *str, char *to_find)
{
    int    i;
    int    j;
    int    remember;

    i = 0;
    j = 0;
    remember = 0;
    if (!str || !to_find)
        return (NULL);
    while (*str)
    {
        if (*str == *to_find)
        {
            remember = *str - *to_find;
            while (*str == *to_find && *str != 0)
            {
              remember = remember + (*str - *to_find);
              to_find++;
              str++;
            }
            if (*to_find == 0 && remember == 0 && *str == 0)
            {
              return ((str - 1) - (to_find -1));
            }
            else if (*to_find == 0)
              (*to_find + 0);
            str++;
        }
        str++;
    }
    return (0);
}

int    main(void)
{
    char    *str = "samusamusamurai";
    char    *to_find = "samurai";
    char    *s = ft_strstr(str, to_find);

    printf("String: %s\nTo Find: %s\nAddress if found: %p", str, to_find, s);
    return (0);
}