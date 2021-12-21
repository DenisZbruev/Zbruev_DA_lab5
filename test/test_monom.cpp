#include "Monom.h"

#include <gtest.h>

TEST(Monom, can_create_monom_with_with_positive_koef_and_sv)
{
    ASSERT_NO_THROW(Monom A(4,4));
}
TEST(Monom, can_create_monom_with_zero_koef)
{
    ASSERT_NO_THROW(Monom A(0, 4));
}
TEST(Monom, can_create_monom_with_negative_sv)
{
    ASSERT_NO_THROW(Monom A(4,-4));
}
TEST(Monom, can_create_monom_from_string)
{
    ASSERT_NO_THROW(Monom A("4x^4y^7x^6", 10));

}
TEST(Monom, can_get_monom_with_positive_sv)
{
    Monom A(4, 147);
    EXPECT_EQ("4.00xy^4z^7", A.GetMonom(10));
}
TEST(Monom, can_get_koef)
{
    Monom A(4, 147);
    EXPECT_EQ(A.Getkoef(), 4);
}
TEST(Monom, can_get_pvx)
{
    Monom A(4, 147);
    EXPECT_EQ(A.pvx(10), 1);
}
TEST(Monom, can_get_pvy)
{
    Monom A(4, 147);
    EXPECT_EQ(A.pvy(10), 4);
}
TEST(Monom, can_get_pvz)
{
    Monom A(4, 147);
    EXPECT_EQ(A.pvz(10), 7);
}
TEST(Monom, can_copy_monom)
{
    Monom A(4, 147);
    Monom B=A;
    EXPECT_EQ("4.00xy^4z^7", B.GetMonom(10));
}
TEST(Monom, can_multiply_monom)
{
    Monom A(4, 144);
    Monom B(4, 144);
    Monom C;
    C = A.multiply(B, 10);
    EXPECT_EQ("16.00x^2y^8z^8", C.GetMonom(10));
}
TEST(Monom, can_not_get_monom_with_negative_sv)
{
    Monom A(4, -144);
    ASSERT_ANY_THROW(A.GetMonom(10));
}
TEST(Monom, can_not_have_negative_degree_of_x)
{
    Monom A(4, -144);
    ASSERT_ANY_THROW(A.pvx(10));
}
TEST(Monom, can_not_have_negative_degree_of_y)
{
    Monom A(4, -144);
    ASSERT_ANY_THROW(A.pvy(10));
}
TEST(Monom, can_not_have_negative_degree_of_z)
{
    Monom A(4, -144);
    ASSERT_ANY_THROW(A.pvz(10));
}
TEST(Monom, can_have_result_)
{
    Monom a(7, 100);
    EXPECT_EQ(49, a.result(7, 0, 0));
}
TEST(Monom, can_have_result_with_zero_x_y_z)
{
    Monom a(7, 147);
    EXPECT_EQ(0, a.result(0, 0, 0));
}
TEST(Monom, can_have_result_with_not_zero_x_y_z)
{
    Monom c("xyz");
    EXPECT_EQ(1, c.result(1, 1, 1));
}
TEST(Monom, can_have_result_with_zero_koef)
{
    Monom c(0,179);
    EXPECT_EQ(0, c.result(1, 4, 0));
}
TEST(Monom, can_have_result_with_negative_koef)
{
    Monom c(-10, 139);
    EXPECT_EQ(-640, c.result(1, 4, 1));
}