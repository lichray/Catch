/*
 *  catch.hpp
 *  Catch
 *
 *  Created by Phil on 22/10/2010.
 *  Copyright 2010 Two Blue Cubes Ltd
 *
 *  Distributed under the Boost Software License, Version 1.0. (See accompanying
 *  file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
 *
 */

/* TBD:
 
 Next:

 Later:
    Finish command line parser (list as xml, specify FP tolerance)
    INFO() stores messages until next result
    Revisit Approx()
    Extra reports
    Tags?
    Detect caught "Catch" exception, offer continuation based iteration instead
    Finish macros, listed here, later (just CHECK_NOFAIL now)
 */
#ifndef TWOBLUECUBES_CATCH_HPP_INCLUDED
#define TWOBLUECUBES_CATCH_HPP_INCLUDED

#include "internal/catch_registry.hpp"
#include "internal/catch_capture.hpp"
#include "internal/catch_section.hpp"

//////

#define EXPECT( expr ) INTERNAL_CATCH_TEST( expr, false, true, "EXPECT" )
#define EXPECT_NOT( expr ) INTERNAL_CATCH_TEST( expr, true, true, "EXPECT_NOT" )

#define EXPECT_THROWS( expr ) INTERNAL_CATCH_THROWS( expr, ..., false, true, "EXPECT_THROWS" )
#define EXPECT_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWS_AS( expr, exceptionType, false, true, "EXPECT_THROWS_AS" )

#define CHECK( expr ) INTERNAL_CATCH_TEST( expr, false, false, "CHECK" )
#define CHECK_NOT( expr ) INTERNAL_CATCH_TEST( expr, true, false, "CHECK_NOT" )

#define CHECK_THROWS( expr )  INTERNAL_CATCH_THROWS( expr, ..., false. false, "CHECK_THROWS" )
#define CHECK_THROWS_AS( expr, exceptionType ) INTERNAL_CATCH_THROWS_AS( expr, exceptionType, false, false, "CHECK_THROWS_AS" )
#define CHECK_NOTHROW( expr ) INTERNAL_CATCH_THROWS_AS( expr, Catch::DummyExceptionType_DontUse, true, false, "CHECK_NOTHROW" )

#define INFO( reason ) INTERNAL_CATCH_MSG( reason, Catch::ResultWas::Info, false, "INFO" )
#define WARN( reason ) INTERNAL_CATCH_MSG( reason, Catch::ResultWas::Warning, false, "WARN" )
#define FAIL( reason ) INTERNAL_CATCH_MSG( reason, Catch::ResultWas::ExplicitFailure, true, "FAIL" )

#define SECTION( name, description ) CATCH_SECTION( name, description )

#define TEST_CASE( name, description ) INTERNAL_CATCH_TESTCASE( name, description )
#define METHOD_AS_TEST_CASE( method, name, description ) CATCH_METHOD_AS_TEST_CASE( method, name, description )

#define REGISTER_REPORTER( name, reporterType ) CATCH_REGISTER_REPORTER( name, reporterType )

///////////////
// Still to be implemented
#define CHECK_NOFAIL( expr ) // !TBD - reports violation, but doesn't fail Test

using Catch::Approx;

#endif // TWOBLUECUBES_CATCH_HPP_INCLUDED