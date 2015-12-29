//
// Created by jakub on 12/29/15.
//


#include <gtest/gtest.h>

TEST(Lambda, SimpleExample_NoParameters) {
    auto func = [](){ std::cout << "Hello World" << std::endl;};

    // [] - signals the start of lambda
    // () - argument list
    // {} = the body
    // No return type is needed. c++11 compiler can deduce it
    func();
}

TEST(Lambda, Parameters) {
    auto func = [](int x){ std::cout << "Hello World" << std::endl;};

    func(2);
}
