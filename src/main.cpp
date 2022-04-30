#include "shared_ptr.h"
#include "unique_ptr.h"
#include <gtest/gtest.h>
#include <iostream>

int main(int argc, char** argv)
{
    if (true) // make false to run unit-tests
    {
        // debug section

        // UniquePtr<int> ptr { make_unique<int>(10) };
        // std::cout << ptr.get() << "----" << *ptr.get() << std::endl;

        // UniquePtr<int> ptr1 { new int { 10 } };
        // UniquePtr<int> ptr2 { ptr1 };
        SharedPtr<std::string> ptr { new std::string { "hello" } };
        std::cout << ptr->length() << std::endl; // output: 5
    } else {
        ::testing::InitGoogleTest(&argc, argv);
        std::cout << "RUNNING TESTS ..." << std::endl;
        int ret { RUN_ALL_TESTS() };
        if (!ret)
            std::cout << "<<<SUCCESS>>>" << std::endl;
        else
            std::cout << "FAILED" << std::endl;
    }
    return 0;
}