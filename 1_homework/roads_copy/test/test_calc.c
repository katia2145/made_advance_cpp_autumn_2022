#include "unity.h"
#include "ReaderCsv.h"

void setUp(void)
{
}
void tearDown(void)
{
}
void test_add( void )
{
    int result = 0;
    result = calc_add(2,2);
    TEST_ASSERT_EQUAL_INT( 4, result );
}