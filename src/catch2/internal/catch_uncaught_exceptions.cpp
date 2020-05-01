/*
 *  Created by Josh on 1/2/2018.
 *  Copyright 2018 Two Blue Cubes Ltd. All rights reserved.
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 */

#include <catch2/internal/catch_compiler_capabilities.hpp>
#include <catch2/internal/catch_uncaught_exceptions.hpp>
#include <exception>

namespace Catch {
    bool uncaught_exceptions() {
#if defined(CATCH_CONFIG_CPP17_UNCAUGHT_EXCEPTIONS) || (defined(__cpp_lib_uncaught_exceptions) && !defined(CATCH_CONFIG_NO_CPP17_UNCAUGHT_EXCEPTIONS))
        return std::uncaught_exceptions() > 0;
#else
        return std::uncaught_exception();
#endif
  }
} // end namespace Catch
