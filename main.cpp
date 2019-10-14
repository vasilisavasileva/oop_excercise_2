#include <iostream>
#include<locale>
#include "Bitstring.h"


int main() {

  setlocale(LC_ALL, "rus");
  int m, n;
  bool l;
  std::cout << "Введите значения строки 1\n";
  Bitstring BS1;
  std::cin >> BS1;
  std::cout << "Введите значения строки 2\n";
  Bitstring BS2;
  std::cin >> BS2;
  std::cout << "Введите количество битов для сдвига\n";
  std::cin >> n;
  std::cout << "Первая строка\n";
  std::cout << BS1 <<std::endl;
  std::cout << "Вторая строка\n";
  std::cout << BS2 <<std::endl;
  std::cout << "and\n";
  std::cout << (BS1 & BS2) <<std::endl;
  std::cout << "or\n";
  std::cout << (BS1 | BS2) <<std::endl;
  std::cout << "xor\n";
  std::cout << (BS1 ^ BS2) <<std::endl;
  std::cout << "not\n";
  std::cout <<  ~BS1 <<std::endl;
  std::cout << "BS1 shiftleft\n";
  std::cout << (BS1 << n) <<std::endl;
  std::cout << "BS2 shiftleft\n";
  std::cout << (BS2 << n) <<std::endl;
  std::cout << "BS1 shiftRight\n";
  std::cout << (BS1 >> n) <<std::endl;
  std::cout << "BS2 shiftRight\n";
  std::cout << (BS2 >> n) <<std::endl;
  std::cout << "count units BS1\n";
  std::cout << (BS1.counter()) <<std::endl;
  std::cout << "count units BS2\n";       
  std::cout << (BS2.counter()) <<std::endl;
  std::cout << "comparing units\n";
  std::cout<< (BS1.compare(BS2)) <<std::endl;
  std::cout << "includes BS1 BS2\n";
  std::cout << (BS1.includes(BS2)) <<std::endl;
  //--------------123456789-123456789-123456789-123
  Bitstring BS4 = 10000000000000000000000000000000_bs;
  std::cout<<BS4<<std::endl;
  return 0;
}