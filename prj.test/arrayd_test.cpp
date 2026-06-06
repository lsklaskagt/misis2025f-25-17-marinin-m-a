#include "../prj.labs/arrayd/arrayd.hpp" 

#include <stdexcept>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../prj.thirdparty/doctest.h" 

TEST_CASE("[arrayd] - ctor default") {
    ArrayD arr;
    CHECK(arr.size() == 0);
}

TEST_CASE("[arrayd] - ctor size") {
    ArrayD arr(5);
    CHECK(arr.size() == 5);
    for (std::ptrdiff_t i = 0; i < arr.size(); ++i) {
        CHECK(arr[i] == doctest::Approx(0.0f));
    }
}

TEST_CASE("[arrayd] - ctor size invalid") {
    CHECK_THROWS_AS(ArrayD(0), std::invalid_argument);
    CHECK_THROWS_AS(ArrayD(-5), std::invalid_argument);
}

TEST_CASE("[arrayd] - ctor copy") {
    ArrayD original(3);
    original[0] = 1.1f;
    original[1] = 2.2f;
    original[2] = 3.3f;

    ArrayD copy(original);
    CHECK(copy.size() == original.size());
    CHECK(copy[0] == doctest::Approx(1.1f));
    CHECK(copy[2] == doctest::Approx(3.3f));
}

TEST_CASE("[arrayd] - op=") {
    ArrayD arr1(2);
    arr1[0] = 5.5f;
    
    ArrayD arr2(3);
    arr2 = arr1;
    CHECK(arr2.size() == 2);
    CHECK(arr2[0] == doctest::Approx(5.5f));
}

TEST_CASE("[arrayd] - resize expand") {
    ArrayD arr(2);
    arr[0] = 1.0f;
    arr.resize(4);
    CHECK(arr.size() == 4);
    CHECK(arr[0] == doctest::Approx(1.0f));
    CHECK(arr[2] == doctest::Approx(0.0f)); 
}

TEST_CASE("[arrayd] - resize shrink") {
    ArrayD arr(4);
    arr[0] = 1.0f;
    arr[1] = 2.0f;
    arr.resize(2);
    CHECK(arr.size() == 2);
    CHECK(arr[0] == doctest::Approx(1.0f));
    CHECK_THROWS_AS(arr[2], std::invalid_argument); 
}

TEST_CASE("[arrayd] - op[] invalid index") {
    ArrayD arr(3);
    CHECK_THROWS_AS(arr[-1], std::invalid_argument);
    CHECK_THROWS_AS(arr[3], std::invalid_argument);
}

TEST_CASE("[arrayd] - insert middle") {
    ArrayD arr(3);
    arr[0] = 1.0f; arr[1] = 2.0f; arr[2] = 3.0f;
    
    arr.insert(1, 99.0f); 
    CHECK(arr.size() == 4);
    CHECK(arr[0] == doctest::Approx(1.0f));
    CHECK(arr[1] == doctest::Approx(99.0f));
    CHECK(arr[2] == doctest::Approx(2.0f));
    CHECK(arr[3] == doctest::Approx(3.0f));
}

TEST_CASE("[arrayd] - insert end") {
    ArrayD arr(2);
    arr[0] = 1.0f; arr[1] = 2.0f;
    
    arr.insert(2, 50.0f); 
    CHECK(arr.size() == 3);
    CHECK(arr[2] == doctest::Approx(50.0f));
}

TEST_CASE("[arrayd] - remove middle") {
    ArrayD arr(3);
    arr[0] = 10.0f; arr[1] = 20.0f; arr[2] = 30.0f;
    
    arr.remove(1); 
    CHECK(arr.size() == 2);
    CHECK(arr[0] == doctest::Approx(10.0f));
    CHECK(arr[1] == doctest::Approx(30.0f));
}

TEST_CASE("[arrayd] - remove end") {
    ArrayD arr(3);
    arr[0] = 10.0f; arr[1] = 20.0f; arr[2] = 30.0f;
    
    arr.remove(2); 
    CHECK(arr.size() == 2);
    CHECK(arr[1] == doctest::Approx(20.0f));
}
