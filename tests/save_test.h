#ifndef TEST_SAVE_H
#define TEST_SAVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "save.h"
#include "load.h"
}

TEST(saveTest_positive, _default) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/move_input.txt", INPUTDIRFILE);

    load(txt, filename);
    EXPECT_EQ(save(txt, filename), 1);
    free(filename);

}

//TEST(saveTest_negative, _empty_text) {
//}

#endif // TEST_SAVE_H
