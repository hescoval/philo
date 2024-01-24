#include "phylo.h"

int	not_numeric(char *str)
{
	int i = 0;

	while(str[i])
	{
		if(!ft_isdigit(str[i]))
			return true;
		i++;
	}
	return false;
}

int invalid_args(int ac, char **args)
{
	int i = 1;

	while(i < ac)
	{
		if(not_numeric(args[i]))
			return true;
		if(ft_atoi(args[i]) != ft_atol(args[i]))
			return true;
		i++;
	}
	return false;
}