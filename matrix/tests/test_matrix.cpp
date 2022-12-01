#include <gtest/gtest.h>

extern "C++"
{
#include "../matrix_lib/Matrix.h"
#include "../matrix_lib/Custom_vector.h"
}

#include "test_invalid_argument.h"
#include "test_inicialization.h"
#include "test_get_row.h"
#include "test_get_column.h"
#include "test_get_diagonal.h"
#include "test_plus.h"
#include "test_minus.h"
#include "test_multiply.h"

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}