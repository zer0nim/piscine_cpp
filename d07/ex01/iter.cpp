#include <iostream>

template <typename T, typename L>
void	iter(T *arr, L const len, void (&func)(T const &)) {
	for (L i = 0; i < len; ++i)
		func(arr[i]);
}
