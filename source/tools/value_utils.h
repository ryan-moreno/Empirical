/**
 *  @note This file is part of Empirical, https://github.com/devosoft/Empirical
 *  @copyright Copyright (C) Michigan State University, MIT Software license; see doc/LICENSE.md
 *  @date 2019
 *
 *  @file value_utils.h
 *  @brief Simple functions to manipulate values.
 *  @note Status: ALPHA
 */

#ifndef EMP_VALUE_UTILS_H
#define EMP_VALUE_UTILS_H

#include <string>

namespace emp {

  template <typename T>
  inline double ToDouble(const T & in) { return (double) in; }

  template <>
  inline double ToDouble<std::string>(const std::string & in) {
    return std::stod(in);
  }
}

#endif
