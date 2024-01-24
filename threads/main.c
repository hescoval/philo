#include "phylo.h"

int main(int ac, char **av)
{
	t_general *info;
	char	*error;

	if (ac < 5 || ac > 6)
		return (p_error("Wrong Argument Count"));
	if(invalid_args(ac, av))
		return (p_error("Arguments not properly formatted"));
	info = ft_calloc(1, sizeof(t_general));
	if (!info)
		return (p_error("Malloc Error"));
	error = init_data(info, av, ac);
	if(error)
		return (p_error(error));
	for(int i = 0; i < info->total_p; i++)
	{
		printf("Philosopher %d\n", i);
		printf("Fork 1: %d\n", info->philos[i].f_one->f_id);
		printf("Fork 2: %d\n", info->philos[i].f_two->f_id);
		printf("Death Time: %ld\n", info->death_time);
		printf("Eat Time: %ld\n", info->eat_time);
		printf("Sleep Time: %ld\n", info->sleep_time);
		printf("Max Meals: %ld\n", info->max_meals);
		printf("\n");
	}
//	eat_setup(info);
}