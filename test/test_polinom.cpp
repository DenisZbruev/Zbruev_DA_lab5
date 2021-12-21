#include "Polinom.h"

#include <gtest.h>

TEST(Polinom, can_create_polinom_with_positive_maxst)
{
    ASSERT_NO_THROW(Polinom A("", 10));
}
TEST(Polinom, can_copy_polinom)
{
    Polinom A("12x^4y^4z^6", 10);
    Polinom B;
    B = A;
    EXPECT_EQ(" + 12.00x^4y^4z^6",B.Getpolinom());
}
TEST(Polinom, can_sum_polinoms_with_equal_deqrees)
{
    Polinom A("78xy^6z^5");
    Polinom B("72xy^6z^5");
    Polinom C;
    C = A + B;
    EXPECT_EQ(C.Getpolinom(), " + 150.00xy^6z^5");
}
TEST(Polinom, can_sum_polinoms_with_not_equal_deqrees)
{
    Polinom A("78xy^6z^5");
    Polinom B("72x^7yz^4");
    Polinom C;
    C = A + B;
    EXPECT_EQ(C.Getpolinom(), " + 72.00x^7yz^4 + 78.00xy^6z^5");
}
TEST(Polinom, can_sub_polinoms_with_equal_deqrees)
{
    Polinom A("78xy^6z^5");
    Polinom B("72xy^6z^5");
    Polinom C;
    C = B - A;
    EXPECT_EQ(C.Getpolinom(), " -6.00xy^6z^5");
}
TEST(Polinom, can_sub_polinoms_with_not_equal_deqrees)
{
    Polinom A("78xy^6z^5");
    Polinom B("72x^7yz^4");
    Polinom C;
    C = B - A;
    EXPECT_EQ(C.Getpolinom(), " + 72.00x^7yz^4 -78.00xy^6z^5");
}
TEST(Polinom, can_multiply_monoms__with_not_equal__deqrees)
{
    Polinom A("10xyz");
    Polinom B("20x^2y^2z^2");
    Polinom C;
    C = A * B;
    EXPECT_EQ(C.Getpolinom(), " + 200.00x^3y^3z^3");
}
TEST(Polinom, return_zero_if_degree_of_composition_polinoms_more_nine)
{
    Polinom A("10x^5y^4z^6");
    Polinom B("20x^4y^6z^4");
    Polinom C;
    C = A*B;
    EXPECT_EQ(C.Getpolinom(), "0");
}
TEST(Polinom, return_zero_if_subtract_the_same_polynomial_from_the_polynomial)
{
    Polinom A("17x^8y^6z^4");
    Polinom B("17x^8y^6z^4");
    Polinom C;
    C = A - B;
    EXPECT_EQ(C.Getpolinom(), "0");
}
TEST(Polinom, can_not_add_elements_with_zero_koef)
{ 
    Polinom A("17x^8y^6z^4+0x^4z^6y^8");
    EXPECT_EQ(A.Getpolinom(), " + 17.00x^8y^6z^4");
}
TEST(Polinom, can_create_a_polynom_with_elements_in_different_order)
{
    Polinom A("17z^8x^6y^4+4z^4y^6x^8");
    EXPECT_EQ(A.Getpolinom(), " + 4.00x^8y^6z^4 + 17.00x^6y^4z^8");
}
TEST(Polinom, can_multiply_polinoms__)
{
    Polinom A("x+y");
    Polinom B("x^5-x^4y+x^3y^2-x^2y^3+xy^4-y^5");
    Polinom C = A * B;
    EXPECT_EQ(" + 1.00x^6 -1.00y^6", C.Getpolinom());
}
TEST(Polinom, can_multiply_numbers_)
{
    Polinom A("5");
    Polinom B("4");
    Polinom C = A * B;
    EXPECT_EQ(" + 20.00", C.Getpolinom());
}
TEST(Polinom, can_multiply_number_and_polinom_)
{
    Polinom A("5");
    Polinom B("x+4");
    Polinom C = A * B;
    EXPECT_EQ(" + 5.00x + 20.00", C.Getpolinom());
}
TEST(Polinom, can_multiply_polinom_plus_number_and_polinom_plus_number)
{
    Polinom A("x+2");
    Polinom B("x+2");
    Polinom C = A * B;
    EXPECT_EQ(" + 1.00x^2 + 4.00x + 4.00", C.Getpolinom());
}
TEST(Polinom, can_get_result_polinom_with_positive_koefs)
{
    Polinom A("x^2+2xy+y^2");
    EXPECT_EQ(A.GetResult(1, 1, 1), 4);
}
TEST(Polinom, can_get_result_polinom_with_negative_koefs)
{
    Polinom A("-x^2-2xy-y^2");
    EXPECT_EQ(A.GetResult(1, 1, 1),-4);
}
TEST(Polinom, can_get_result_polinom_with_zero_degrees)
{
    Polinom A("4");
    EXPECT_EQ(A.GetResult(1, 1, 1), 4);
}
TEST(Polinom, _polynomials_equal)
{
    Polinom A("x^5-x^4y+x^3y^2-x^2y^3+xy^4-y^5");
    Polinom B("x^5-x^4y+x^3y^2-x^2y^3+xy^4-y^5");
    EXPECT_EQ(1, A == B);
}
TEST(Polinom, _polynomials_not_equal)
{
    Polinom A("x^5-x^4y+x^3y^2-x^2y^3+xy^4-y^5");
    Polinom B("x^5-x^4y+x^3y^2-x^2y^3+xy^4");
    EXPECT_EQ(1, A != B);
}