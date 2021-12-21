#include "CircleList.h"

#include <gtest.h>

TEST(CircleList, can_create_circlelist)
{
  ASSERT_NO_THROW(CircleList A);
}
TEST(CircleList, can_add_monom_to_circleList)
{
    CircleList A;
    Monom m(4, 478);
    A.AddMonom(m);
    EXPECT_EQ(A.Getpolinom()," + 4.00x^4y^7z^8");
}
TEST(CircleList, can_add_monom_with_zero_koef)
{
    CircleList A;
    Monom m(4,0);
    A.AddMonom(m);
    EXPECT_EQ(A.Getpolinom(), " + 4.00");
}
TEST(CircleList, can_add_monom_with_max_koef)
{
    CircleList A;
    Monom m(4, 999);
    A.AddMonom(m);
    EXPECT_EQ(A.Getpolinom(), " + 4.00x^9y^9z^9");
}
TEST(CircleList, can_not_add__monom_with_negative_degree_to__polinom)
{
    CircleList A;
    Monom m(4, -999);
    ASSERT_ANY_THROW(A.AddMonom(m));
}
TEST(CircleList, can_sum_polinoms_with_equal_deqrees)
{
    CircleList A;
    Monom m(4, 111);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 111);
    B.AddMonom(m2);
    CircleList C;
    C = A + B;
    EXPECT_EQ(C.Getpolinom(), " + 11.00xyz");
}
TEST(CircleList, can_sum_polinoms_with_not_equal_deqrees)
{
    CircleList A;
    Monom m(4, 111);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 222);
    B.AddMonom(m2);
    CircleList C;
    C = A + B;
    EXPECT_EQ(C.Getpolinom(), " + 7.00x^2y^2z^2 + 4.00xyz");
}
TEST(CircleList, can_sub_polinoms_with_equal_deqrees)
{
    CircleList A;
    Monom m(4, 111);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 111);
    B.AddMonom(m2);
    CircleList C;
    C = B - A;
    EXPECT_EQ(C.Getpolinom(), " + 3.00xyz");
}
TEST(CircleList, can_sub_polinoms_with_not_equal_deqrees)
{
    CircleList A;
    Monom m(4, 111);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 222);
    B.AddMonom(m2);
    CircleList C;
    C = B-A;
    EXPECT_EQ(C.Getpolinom(), " + 7.00x^2y^2z^2 -4.00xyz");
}
TEST(CircleList, can_multiply_polinoms_with_not_equal_deqrees)
{
    CircleList A;
    Monom m(4, 111);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 222);
    B.AddMonom(m2);
    CircleList C;
    C = A.multiply(B,10);
    EXPECT_EQ(C.Getpolinom(), " + 28.00x^3y^3z^3");
}
TEST(CircleList, return_zero_if_degree_of_composition_polinoms_more_nine)
{
    CircleList A;
    Monom m(4, 555);
    A.AddMonom(m);
    CircleList B;
    Monom m2(7, 555);
    B.AddMonom(m2);
    CircleList C;
    C = A.multiply(B, 10);
    EXPECT_EQ(C.Getpolinom(), "0");
}
TEST(CircleList, return_zero_if_subtract_the_same_polynomial_from_the_polynomial)
{
    CircleList A;
    Monom m(4, 555);
    Monom m2(5, 666);
    A.AddMonom(m);
    A.AddMonom(m2);
    CircleList B;
    B.AddMonom(m);
    B.AddMonom(m2);
    CircleList C;
    C = A - B;
    EXPECT_EQ(C.Getpolinom(), "0");
}
TEST(CircleList, can_get_result_polinom_with_positive_koefs)
{
    CircleList A;
    Monom m(4, 555);
    Monom m2(5, 666);
    A.AddMonom(m);
    A.AddMonom(m2);
    EXPECT_EQ(A.GetResultPolinom(1, 1, 1), 9);
}
TEST(CircleList, can_get_result_polinom_with_negative_koefs)
{
    CircleList A;
    Monom m(-4, 555);
    Monom m2(-5, 666);
    A.AddMonom(m);
    A.AddMonom(m2);
    EXPECT_EQ(A.GetResultPolinom(1, 1, 1), -9);
}
TEST(CircleList, can_get_result_polinom_with_zero_koefs)
{
    CircleList A;
    Monom m(0, 555);
    Monom m2(0, 666);
    A.AddMonom(m);
    A.AddMonom(m2);
    EXPECT_EQ(A.GetResultPolinom(144, 225, 369), 0);
}

