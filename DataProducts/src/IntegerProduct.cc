#include "Minimal/DataProducts/src/IntegerProduct.hh"

namespace mu2e {
  IntegerProduct::IntegerProduct():_n(-1){}
  IntegerProduct::IntegerProduct( int n):_n(n){}
  int IntegerProduct::value() const { return _n;}
}
