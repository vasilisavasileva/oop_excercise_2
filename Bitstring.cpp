#include "Bitstring.h"
#include <iostream>
#include <inttypes.h>
#include<cstring>

Bitstring::Bitstring() {
  this->b1 = 0;
  this->b2 = 0;
}

Bitstring::Bitstring(uint64_t b1, uint32_t b2) {
  this->b1 = b1;
  this->b2 = b2;
}

Bitstring operator&(const Bitstring& a, const Bitstring& b) {
  Bitstring bs3{ (a.b1)&(b.b1),(a.b2)&(b.b2) };
  return bs3;
}

Bitstring operator|(const Bitstring& a, const Bitstring& b) {
  Bitstring bs3 = Bitstring( (a.b1) | (b.b1),(a.b2) | (b.b2) );
  return bs3;
}

Bitstring operator^ (const Bitstring& a, const Bitstring& b) {
  Bitstring bs3{ (a.b1) ^ (b.b1),(a.b2) ^ (b.b2) };
  return bs3;
}

Bitstring operator~ (const Bitstring& a) {
  Bitstring bs3{ ~(a.b1),~(a.b2) };
  return bs3;
}

Bitstring operator<<(const Bitstring& l, int m) {
  uint32_t a, t2 = l.b2;
  uint64_t t1 = l.b1;
  a = 1;
  a <<= 31;
  for (int i = 0; i < m; i++) {
 if (((t2)&a) > 0) {                                                                                                                                                         t1 <<= 1;                                                                                                                                                                 t2 <<= 1;
      t1 = t1 + 1;
    }
    else {                                                                                                                                                                      t1 <<= 1;                                                                                                                                                                 t2 <<= 1;
    }                                                                                                                                                                       }
  return Bitstring(t1,t2);
}

Bitstring operator>>(const Bitstring& l, int m) {
  uint64_t a, t1 = l.b1;
  uint32_t b, t2 = l.b2;                                                                                                                                                    b = 1;                                                                                                                                                                    b <<= 31;                                                                                                                                                                 a = 1;
  for (int i = 0; i < m; i++) {
    if (((t1)&a) > 0) {        
 t1 >>= 1;
      t2 >>= 1;
      t2 = t2 + b;
    }
    else {
      t1 >>= 1;
      t2 >>= 1;                                                                                                                                                               }
  }
  return Bitstring(t1,t2);
}

int Bitstring::counter() const{
  uint64_t a = 1;                                                                                                                                                           uint32_t b = 1;                                                                                                                                                           uint64_t l;                                                                                                                                                               uint32_t l1;                                                                                                                                                              int count = 0;
                                                                                                                                                                            for (int i = 0; i < 63; i++) {
    l = (this->b1)&a;
 if (l != 0) {
      ++count;                                                                                                                                                                }
    a <<= 1;
  }
  for (int i = 0; i < 32; i++) {
    l1 = (this->b2)&b;                                                                                                                                                        if (l1 != 0) {
      ++count;
    }
    b <<= 1;
  }
  return count;
}


bool Bitstring::compare(const Bitstring& bs2) const {                                                                                                                       int a = this->counter();
  int b = bs2.counter();                                                                                                                                                    if (a == b)                                                                                                                                                                 return true; 
  return false;

}

bool Bitstring::includes(const Bitstring& bs2) const {
  if (((this->b1)&(bs2.b1)) == bs2.b1)
    if (((this->b2)&(bs2.b2)) == bs2.b2)                                                                                                                                        return true;
  return false;

}


                                                                                                                                                                          

bool operator< (const Bitstring& a, const Bitstring& b) {                                                                                                                   if ((a.b1) < (b.b1))                                                                                                                                                        return true;                                                                                                                                                            else if ((a.b1) > (b.b1))                                                                                                                                                   return false;         
}


bool operator> (const Bitstring& a, const Bitstring& b) {                                                                                                                   if ((a.b1) > (b.b1))                                                                                                                                                        return true;                                                                                                                                                            else if ((a.b1) < (b.b1))                                                                                                                                                   return false;                                                                                                                                                           if ((a.b1) == (b.b1))
    if ((a.b2) > (b.b2))                                                                                                                                                        return true;                                                                                                                                                            else                                                                                                                                                                        return false;
}
     
bool operator== (const Bitstring& a, const Bitstring& b) {                                                                                                                  return (((a.b1) == (b.b1)) && ((a.b2) == (b.b2)));
}


std::ostream& operator<<(std::ostream& out, const Bitstring& Bs){
  uint64_t a = 1;
  a <<= 63;
  uint32_t b = 1;                                                                                                                                                           b <<= 31;                                                                                                                                                                 for (int i = 0; i < 64; i++) {                                                                                                                                              out << ((a & Bs.b1) > 0);                                                                                                                                                 a >>= 1;                                                                                                                                                                }
  for (int i = 0; i < 32; i++) {                                                                                                                                              out << ((b & Bs.b2) > 0);                                                                                                                                                 b >> 1;                                                                                                                                                                }
  return out;
}         

std::istream& operator>>(std::istream& in, Bitstring& Bs){
  in>>Bs.b1>>Bs.b2;
  return in;
}



Bitstring operator "" _bs(const char* str) {
  int size = strlen(str);
  if(size > 96) exit(1);
  uint64_t a = 0;
  uint32_t b = 0;
  int i = size-1;
  for(i; i>=size-32 && i >=0;i--){
    b += (str[i] - '0') << (size-1-i);
  }
  for(i; i>=0;i--){
    a += (str[i] - '0')<<(size-33- i);
  }
  Bitstring result = Bitstring(a, b);
  return result;            
}