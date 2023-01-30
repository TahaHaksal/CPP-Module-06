#include <stdint.h>

typedef struct s_Data
{
	int	data;
}	t_Data;

uintptr_t serialize(t_Data* ptr)
{
	return ((uintptr_t *)ptr);
}

t_Data* deserialize(uintptr_t raw)
{
	return ((t_Data *)&raw);
}

int	main(void)
{

}
