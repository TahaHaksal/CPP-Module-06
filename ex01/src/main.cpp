#include <stdint.h>
#include <iostream>

typedef struct s_Data
{
	int	data;
}	t_Data;

inline uintptr_t serialize(t_Data* ptr) {return ((uintptr_t )ptr);}

inline t_Data* deserialize(uintptr_t raw) {return ((t_Data *)raw);}

int	main(void)
{
	t_Data	ex;
	std::cout << &ex << std::endl;
	std::cout << deserialize(serialize(&ex)) << std::endl;
}
