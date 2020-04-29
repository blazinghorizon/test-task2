#include <gtest/gtest.h>
#include "move_test.h"
#include "rle_test.h"
#include "save_test.h"
#include "showtrimmedfromstart_test.h"

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
