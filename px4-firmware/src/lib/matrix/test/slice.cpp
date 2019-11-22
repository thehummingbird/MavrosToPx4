#include "test_macros.hpp"
#include <matrix/math.hpp>

using namespace matrix;

template class matrix::Slice<float, 2, 3, 4, 5>; // so that we get full coverage results


int main()
{
    float data[9] = {0, 2, 3,
                     4, 5, 6,
                     7, 8, 10
                    };
    SquareMatrix<float, 3> A(data);

    // Test row slicing
    Matrix<float, 2, 3> B_rowslice(A.slice<2, 3>(1, 0));
    float data_check_rowslice[6] = {
        4, 5, 6,
        7, 8, 10
    };
    Matrix<float, 2, 3> B_check_rowslice(data_check_rowslice);
    TEST(isEqual(B_rowslice, B_check_rowslice));

    // Test column slicing
    Matrix<float, 3, 2> B_colslice(A.slice<3, 2>(0, 1));
    float data_check_colslice[6] = {
        2, 3,
        5, 6,
        8, 10
    };
    Matrix<float, 3, 2> B_check_colslice(data_check_colslice);
    TEST(isEqual(B_colslice, B_check_colslice));

    // Test slicing both
    Matrix<float, 2, 2> B_bothslice(A.slice<2, 2>(1, 1));
    float data_check_bothslice[4] = {
        5, 6,
        8, 10
    };
    Matrix<float, 2, 2> B_check_bothslice(data_check_bothslice);
    TEST(isEqual(B_bothslice, B_check_bothslice));

    //Test block writing
    float data_2[4] = {
        11, 12,
        13, 14
    };

    Matrix<float, 2, 2> C(data_2);
    A.slice<2, 2>(1, 1) = C;

    float data_2_check[9] = {
        0, 2, 3,
        4, 11, 12,
        7, 13, 14
    };
    Matrix<float, 3, 3> D(data_2_check);
    TEST(isEqual(A, D));

    //Test writing to slices
    Matrix<float, 3, 1> E;
    E(0,0) = -1;
    E(1,0) = 1;
    E(2,0) = 3;

    Matrix<float, 2, 1> F;
    F(0,0) = 9;
    F(1,0) = 11;

    E.slice<2,1>(0,0) = F;

    float data_3_check[3] = {9, 11, 3};
    Matrix<float, 3, 1> G (data_3_check);
    TEST(isEqual(E, G));
    TEST(isEqual(E, Matrix<float,3,1>(E.slice<3,1>(0,0))));

    Matrix<float, 2, 1> H = E.slice<2,1>(0,0);
    TEST(isEqual(H,F));

    float data_4_check[5] = {3, 11, 9, 0, 0};
    {   // assigning row slices to each other
        const Matrix<float, 3, 1> J (data_3_check);
        Matrix<float, 5, 1> K;
        K.row(2) = J.row(0);
        K.row(1) = J.row(1);
        K.row(0) = J.row(2);

        Matrix<float, 5, 1> K_check(data_4_check);
        TEST(isEqual(K, K_check));
    }
    {   // assigning col slices to each other
        const Matrix<float, 1, 3> J (data_3_check);
        Matrix<float, 1, 5> K;
        K.col(2) = J.col(0);
        K.col(1) = J.col(1);
        K.col(0) = J.col(2);

        Matrix<float, 1, 5> K_check(data_4_check);
        TEST(isEqual(K, K_check));
    }

    // check that slice of a slice works for reading
    const Matrix<float, 3, 3> cm33(data);
    Matrix<float, 2, 1> topRight = cm33.slice<2,3>(0,0).slice<2,1>(0,2);
    float top_right_check[2] = {3,6};
    TEST(isEqual(topRight, Matrix<float, 2, 1>(top_right_check)));

    // check that slice of a slice works for writing
    Matrix<float, 3, 3> m33(data);
    m33.slice<2,3>(0,0).slice<2,1>(0,2) = Matrix<float, 2, 1>();
    const float data_check[9] = {0, 2, 0,
                                 4, 5, 0,
                                 7, 8, 10
                                };
    TEST(isEqual(m33, Matrix<float, 3, 3>(data_check)));

    // longerThan
    Vector3f v5;
    v5(0) = 3;
    v5(1) = 4;
    v5(2) = 9;
    TEST(v5.xy().longerThan(4.99f));
    TEST(!v5.xy().longerThan(5.f));
    TEST(isEqualF(5.f, v5.xy().norm()));

    return 0;
}

/* vim: set et fenc=utf-8 ff=unix sts=0 sw=4 ts=4 : */
