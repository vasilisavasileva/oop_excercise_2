#ifndef BITSTRING_H
#define BITSTRING_H
#include <inttypes.h>
#include <iostream>
class Bitstring {
private:
	uint64_t b1;
	uint32_t b2;
public:
	Bitstring();
	Bitstring(uint64_t b1, uint32_t b2);
	friend Bitstring operator& (Bitstring& a, Bitstring& b);
	friend Bitstring operator| (Bitstring& a, Bitstring& b);
	friend Bitstring operator^ (Bitstring& a, Bitstring& b);
	friend Bitstring operator~ (Bitstring& a);
	friend Bitstring operator<< (Bitstring& l, int m);
	friend Bitstring operator>> (Bitstring& l, int m);
	int counter();
	friend bool operator< (Bitstring& a, Bitstring& b);
	friend bool operator> (Bitstring& a, Bitstring& b);
	friend bool operator== (Bitstring& a, Bitstring& b);
	bool compare(Bitstring bs2);
	bool includes(Bitstring bs2);
	void print();
	friend std::ostream& operator<<(std::ostream& out, Bitstring& Bs);
};
Bitstring operator "" _bs(const char* str);
#endif
