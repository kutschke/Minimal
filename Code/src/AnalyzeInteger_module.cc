//
//  Read an integer from the event and print it out.
//  Also test using a function from a library ( ping ).
//

#include "Minimal/DataProducts/src/IntegerProduct.hh"
#include "Minimal/Code/src/ping.hh"

#include "art/Framework/Core/EDAnalyzer.h"
#include "art/Framework/Principal/Event.h"
#include "canvas/Utilities/InputTag.h"

#include <iostream>

namespace mu2e {

  class AnalyzeInteger : public art::EDAnalyzer {

  public:
    explicit AnalyzeInteger(fhicl::ParameterSet const& pset);

    void analyze(const art::Event& event) override;

  private:

  };

  AnalyzeInteger::AnalyzeInteger(fhicl::ParameterSet const& pset)
    : art::EDAnalyzer(pset){
    std::cout << "Hello, world.  In c'tor." << std::endl;
    ping();
  }

  void AnalyzeInteger::analyze(const art::Event& event){
    auto product = event.getValidHandle<IntegerProduct>("makeAnInteger");
    std::cout << "Hello, world.  From analyze: "
              << event.id()
              << "   The integer is: "
              << product->value()
              << std::endl;
  }

} // end namespace mu2e

DEFINE_ART_MODULE(mu2e::AnalyzeInteger);
