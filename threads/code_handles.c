#include "phylo.h"

void	mutex_handle(t_mtx *mutex, t_codes code)
{
	if (code == LOCK)
		pthread_mutex_lock(mutex);
	else if(code == UNLOCK)
		pthread_mutex_lock(mutex);
	else if(code == INIT)
		pthread_mutex_init(mutex, NULL);
	else if(code == DESTROY)
		pthread_mutex_destroy(mutex);
}

void	thread_handle(pthread_t *thread, void *(*fct)(void *),
		void *data, t_codes code)
{
	if (code == CREATE)
		pthread_create(thread, NULL, fct, data);
	else if (code == JOIN)
		pthread_join(*thread, NULL);
	else if (code == DETACH)
		pthread_detach(*thread);
}