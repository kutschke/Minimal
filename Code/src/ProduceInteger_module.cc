//
//  An example of a trivial producer
//
//  Original author Rob Kutschke
//

#include "Minimal/DataProducts/src/IntegerProduct.hh"

#include "art/Framework/Core/EDProducer.h"
#include "art/Framework/Principal/Event.h"

namespace mu2e {

  class ProduceInteger : public art::EDProducer {

  public:
    explicit ProduceInteger(fhicl::ParameterSet const& pset) :
      art::EDProducer{pset}
    {
      produces<IntegerProduct>();
    }

    void produce( art::Event& event) override;

  private:

  };

  void ProduceInteger::produce( art::Event& event){

    auto product = std::make_unique<IntegerProduct>(event.id().event()*2);
    event.put( std::move(product) );

  }

} // end namespace mu2e

DEFINE_ART_MODULE(mu2e::ProduceInteger);
