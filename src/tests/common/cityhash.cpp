// Copyright 2021 yuzu Emulator Project
// Licensed under GPLv2 or any later version
// Refer to the license.txt file included.

#include <catch2/catch.hpp>

#include "common/cityhash.h"

constexpr char msg[] = "The blue frogs are singing under the crimson sky.\n"
                       "It is time to run, Robert.";

using namespace Common;

TEST_CASE("CityHash", "[common]") {
    // These test results were built against a known good version.
    REQUIRE(CityHash64(msg, sizeof(msg)) == 0x92d5c2e9cbfbbc01);
    REQUIRE(CityHash64WithSeed(msg, sizeof(msg), 0xdead) == 0xbfbe93f21a2820dd);
    REQUIRE(CityHash64WithSeeds(msg, sizeof(msg), 0xbeef, 0xcafe) == 0xb343317955fc8a06);
    REQUIRE(CityHash128(msg, sizeof(msg)) == uint128{0x98e60d0423747eaa, 0xd8694c5b6fcaede9});
    REQUIRE(CityHash128WithSeed(msg, sizeof(msg), {0xdead, 0xbeef}) ==
            uint128{0xf0307dba81199ebe, 0xd77764e0c4a9eb74});
}
