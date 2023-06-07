#ifndef Minimal_IntegerProduct_HH
#define Minimal_IntegerProduct_HH

//
// A trivial data product to test:
//   - making a dictionary
//   - creating a data product
//   - writing to a file and reading it back

namespace mu2e {
  class IntegerProduct {

  public:

    // Needed by ROOT's genreflex
    IntegerProduct();

    explicit IntegerProduct( int n);
    int value() const;

  private:
    int _n;

  };

}
#endif
