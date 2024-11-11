﻿#include "gtest.h"
#include "stack_queue.h"

TEST(TVector, can_create_vector_with_positive_length)
{
    ASSERT_NO_THROW(TVector<int> v(5));
}

TEST(TVector, throws_when_create_vector_with_negative_length)
{
    ASSERT_ANY_THROW(TVector<int> v(-5));
}

TEST(TVector, can_create_vector_from_arr)
{
    int* a = new int[3] {4, 6, 2};
    TVector<int> v(a, 3);
    int flag = 0;
    for (size_t i = 0; i < 3; i++)
        if (v[i] != a[i])
            flag = 1;
    delete[] a;
    EXPECT_EQ(0, flag);
}

TEST(TVector, can_create_copied_vector)
{
    TVector<int> v(10);
    ASSERT_NO_THROW(TVector<int> v1(v));
}

TEST(TVector, copied_vector_is_equal_to_source_one)
{
    TVector<int> v(10);
    v[0] = 1;
    TVector<int> vcpy(v);

    EXPECT_EQ(v, vcpy);
}

TEST(TVector, copied_vector_has_its_own_memory)
{
    TVector<int> v(10);
    TVector<int> vcpy(v);

    EXPECT_NE(&v, &vcpy);
}

TEST(TVector, can_get_size)
{
    TVector<int> v(4);
    EXPECT_EQ(4, v.size());
}

TEST(TVector, can_get_capacity)
{
    TVector<int> v(4);
    EXPECT_EQ(10, v.getCapacity());
}

TEST(TVector, can_set_and_get_element)
{
    TVector<int> v(4);
    v[0] = 4;

    EXPECT_EQ(4, v[0]);
}

TEST(TVector, can_assign_vector_to_itself)
{
    TVector<int> v(10);
    v[0] = 1;
    TVector<int> vcpy(v);

    v = v;

    EXPECT_EQ(v, vcpy);
}

TEST(TVector, can_assign_vectors_of_equal_size)
{
    TVector<int> v1(10);
    TVector<int> v2(10);
    v2[0] = 3;

    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_assign_vectors_of_different_size)
{
    TVector<int> v1(10);
    TVector<int> v2(5);
    v2[4] = 5;

    v1 = v2;

    EXPECT_EQ(v1, v2);
}

TEST(TVector, compare_equal_vectors_return_true)
{
    int* a1 = new int[3] {4, 10, 14};
    TVector<int> v1(a1, 3);
    delete[] a1;
    int* a2 = new int[3] {4, 10, 14};
    TVector<int> v2(a2, 3);
    delete[] a2;
    EXPECT_TRUE(v1 == v2);
}

TEST(TVector, compare_vector_with_itself_return_true)
{
    TVector<int> v(10);
    v[4] = 8;

    EXPECT_TRUE(v == v);
}

TEST(TVector, vectors_with_different_size_are_not_equal)
{
    TVector<int> v1(10);
    TVector<int> v2(5);

    EXPECT_FALSE(v1 == v2);
}

TEST(TVector, can_check_for_full)
{
    TVector<int> v;
    EXPECT_FALSE(v.isFull());
}

TEST(TVector, can_check_for_empty)
{
    TVector<int> v;
    EXPECT_TRUE(v.isEmpty());
}

TEST(TVector, can_push_back_elem)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[4] {8, 10, 12, 14};
    TVector<int> v2(a_check, 4);
    delete[] a_check;
    v1.push_back(14);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_back_elem_with_resize)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[9] {8, 10, 12, 3, 4, 5, 6, 7, 8};
    TVector<int> v2(a_check, 9);
    delete[] a_check;
    for (size_t i = 3; i < 9; i++)
        v1.push_back(i);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_front_elem)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[4] {14, 8, 10, 12};
    TVector<int> v2(a_check, 4);
    delete[] a_check;
    v1.push_front(14);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_push_front_elem_with_resize)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[9] {3, 4, 5, 6, 7, 8, 8, 10, 12, };
    TVector<int> v2(a_check, 9);
    delete[] a_check;
    for (size_t i = 8; i > 2; i--)
        v1.push_front(i);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_pop_back_element)
{
    int*  = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[2] {8, 10};
    TVector<int> v2(a_check, 2);
    delete[] a_check;
    v1.pop_back();
    EXPECT_EQ(v1, v2);
}

TEST(TVector, throws_when_pop_back_elem_from_empty_vector)
{
    TVector<int> v;
    ASSERT_ANY_THROW(v.pop_back());
}

TEST(TVector, can_pop_front_elem)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[2] {10, 12};
    TVector<int> v2(a_check, 2);
    delete[] a_check;
    v1.pop_front();
    EXPECT_EQ(v1, v2);
}

TEST(TVector, throws_when_pop_front_elem_from_empty_vector)
{
    TVector<int> v;
    ASSERT_ANY_THROW(v.pop_front());
}

TEST(TVector, can_insert_elem)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[4] {8, 10, 14, 12};
    TVector<int> v2(a_check, 4);
    delete[] a_check;
    v1.insert(14, 2);
    EXPECT_EQ(v1, v2);
}
TEST(TVector, can_insert_elem_with_resize)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[9] {8, 3, 4, 5, 6, 7, 8, 10, 12};
    TVector<int> v2(a_check, 9);
    delete[] a_check;
    for (std::size_t i = 8; i > 2; i--)
        v1.insert(i, 1);
    EXPECT_EQ(v1, v2);
}

TEST(TVector, can_erase_elem)
{
    int* a = new int[3] {8, 10, 12};
    TVector<int> v1(a, 3);
    delete[] a;
    int* a_check = new int[2] {8, 12};
    TVector<int> v2(a_check, 2);
    delete[] a_check;
    v1.erase(1);
    EXPECT_EQ(v1, v2);
}

TEST(Vector, cant_erase_element_empty_Vector)
{
    Vector<int> v;
    ASSERT_ANY_THROW(v.erase(1));
}