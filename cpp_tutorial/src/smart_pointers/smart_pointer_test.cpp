//
// Created by jakub on 12/29/15.
//

#include "smart_pointer_test.h"

#include <gtest/gtest.h>
#include <memory>

TEST(SmartPointer, CreatingSharedPointer_UsingConstructor_ProperObjectInside){
    int expectedId = 1;

    // Constructor, allocates memory atleast twice, not recommanded.
    // see make_shared for proper way
    std::shared_ptr<MyPtrTest> p0(new MyPtrTest(expectedId));

    // Refer to members as usual pointer
    int actualId = p0->id;

    EXPECT_EQ(expectedId, actualId);
}

TEST(SmartPointer, CreatingSharedPointer_UsingMakeShared_ProperObjectInside){
    int expectedId = 1;

    // make_shared is the proper way of creating shared pointer.
    // only allocates memory once as opposed to using constructor
    std::shared_ptr<MyPtrTest> p0 = std::make_shared<MyPtrTest>(expectedId);

    // Refer to members as usual pointer
    int actualId = p0->id;

    EXPECT_EQ(expectedId, actualId);
}


TEST(SmartPointer, TwoSharedPointers_PointsAtSameObject_ProperUseCount){
    // p0 points at newly created object
    std::shared_ptr<MyPtrTest> p0 = std::make_shared<MyPtrTest>(2);
    // p1 points at the same object as p0
    std::shared_ptr<MyPtrTest> p1 = p0;

    int expectedUseCount = 2;

    int actaulUseCount = p0.use_count();

    EXPECT_EQ(expectedUseCount, actaulUseCount);
}

TEST(SmartPointer,
     TwoSharedPointers_PointerIsMoved_RemovedPointerProperUseCount){
    // p0 points at newly created object
    std::shared_ptr<MyPtrTest> p0 = std::make_shared<MyPtrTest>(2);
    // p0 moves ownership of the pointed object to p1.
    // p1 points at the same object but p0 points at nothing
    std::shared_ptr<MyPtrTest> p1 = std::move(p0);

    int expectedUseCount = 0;

    int actaulUseCount = p0.use_count();

    EXPECT_EQ(expectedUseCount, actaulUseCount);
}

TEST(SmartPointer,
     TwoSharedPointers_PointerIsMoved_MovedPointerProperUseCount){
    // p0 points at newly created object
    std::shared_ptr<MyPtrTest> p0 = std::make_shared<MyPtrTest>(2);
    // p0 moves ownership of the pointed object to p1.
    // p1 points at the same object but p0 points at nothing
    std::shared_ptr<MyPtrTest> p1 = std::move(p0);

    int expectedUseCount = 1;

    int actaulUseCount = p1.use_count();

    EXPECT_EQ(expectedUseCount, actaulUseCount);
}