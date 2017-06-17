//  This file is part of Empirical, https://github.com/devosoft/Empirical
//  Copyright (C) Michigan State University, 2017.
//  Released under the MIT Software license; see doc/LICENSE
//
//
//  Handle reflection on organisms to setup reasonable defaults in the World template class.

#ifndef EMP_EVO_WORLD_REFLECT_H
#define EMP_EVO_WORLD_REFLECT_H

#include <functional>
#include <type_traits>

#include "../base/assert.h"

namespace emp {

  namespace {

    // Setup Fitness reflection.
    // 1. If an organism has a "GetFitness()" member function, use it!
    // 2. If an organim can be cast to double, use it!
    // 3. Start with a fitness function that throws an assert indicating function must be set.

    template <typename WORLD, typename ORG>
    void SetDefaultFitFun_impl(WORLD & world, bool_decoy<decltype(ORG::GetFitness)>) {
      world.SetFitFun( [](ORG & org){ return (double) org.GetFitness(); } );
    }

    template <typename WORLD, typename ORG>
    void SetDefaultFitFun_impl(WORLD & world, int_decoy<decltype( (double)(*(ORG*)nullptr) )>) {
      world.SetFitFun( [](ORG & org){ return (double) org; } );
    }

    template <typename WORLD, typename ORG>
    void SetDefaultFitFun_impl(WORLD & world, ... ) {
      world.SetFitFun( [](ORG & org){
        emp_assert(false, "No default fitness function available");
        return 0.0;
      } );
    }

  }

  template <typename WORLD, typename ORG>
  void SetDefaultFitFun(WORLD & world) { SetDefaultFitFun_impl<WORLD, ORG>(world, true); }

  // Setup Mutation function
  // 1. DoMutations(random)
  // 2. Empty, with assert.


  // Setup Print function
  // 1. Proper operator<<
  // 2. Print()
  // 3. Assert?  Or trivial default?

}

#endif
