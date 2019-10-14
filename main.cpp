
#include <iostream>
#include<locale>
#include "Bitstring.h"


int main() {

	setlocale(LC_ALL, "rus");

	uint64_t a;
	uint32_t b;
	int m, n;
	bool l;
	std::cout << "Введите значения строки 1\n";
	std::cin >> a >> b;
	Bitstring BS1 = Bitstring(a, b);
	std::cout << "Введите значения строки 2\n";
	std::cin >> a >> b;
	Bitstring BS2 = Bitstring(a, b);
	std::cout << "Введите количество битов для сдвига\n";
	std::cin >> n;
	Bitstring BS3;
	std::cout << "Первая строка\n";
	std::cout<<BS1<<std::endl;
	std::cout << "Вторая строка\n";
	std::cout<<BS2<<std::endl;
	std::cout << "and\n";
	BS3 = BS1 & BS2;
	std::cout<<BS3<<std::endl;
	std::cout << "or\n";
	BS3 = BS1 | BS2;
	std::cout<<BS3<<std::endl;
	std::cout << "xor\n";
	BS3 = BS1 ^ BS2;
	std::cout<<BS3<<std::endl;
	std::cout << "not\n";
	BS3 = ~BS1;
	std::cout<<BS3<<std::endl;
	std::cout << "BS1 shiftleft\n";
	BS1 = BS1 << n;
	std::cout<<BS1<<std::endl;
	std::cout << "BS2 shiftleft\n";
	BS2 = BS2 << n;
	std::cout<<BS2<<std::endl;
	std::cout << "BS1 shiftRight\n";
	BS1 = BS1 >> n;
	std::cout<<BS1<<std::endl;
	std::cout << "BS2 shiftRight\n";
	BS2 = BS2 >> n;
	std::cout<<BS2<<std::endl;
	std::cout << "count units BS1\n";
	m = BS1.counter();
	std::cout << m << std::endl;
	std::cout << "count units BS2\n";
	m = BS2.counter();
	std::cout << m << std::endl;
	std::cout << "comparing units\n";
	l = BS1.compare(BS2);
	std::cout << l << std::endl;
	std::cout << "includes BS1 BS2\n";
	l = BS1.includes(BS2);
	std::cout << l << std::endl;
	//--------------123456789-123456789-123456789-123
	Bitstring BS4 = 10000000000000000000000000000000_bs;
	std::cout<<BS4<<std::endl;
	return 0;
}