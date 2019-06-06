#include <iostream>
#include <time.h>

struct Data {
	std::string s1;
	int n;
	std::string s2;
};

std::string	randAlphaNum(int len) {
    std::string	alphanum =
        "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

	std::string	res = "";

	for (int i = 0; i < len; i++) {
		res.append(std::string(1, alphanum[rand() % alphanum.length()]));
	}

    return res;
}

void	*serialize(void) {
	Data *data = new Data();

	data->s1 = randAlphaNum(8);
	data->n = rand();
	data->s2 = randAlphaNum(8);

	return data;
}

Data * deserialize(void * raw) {
	return reinterpret_cast<Data *>(raw);
}

int main(void)
{
	srand(time(0));

	void	*dataV = serialize();
	Data *	data = deserialize(dataV);

	std::cout << "s1: " << data->s1 << std::endl;
	std::cout << "n: " << data->n << std::endl;
	std::cout << "s2: " << data->s2 << std::endl;

	delete data;

	return 0;
}
