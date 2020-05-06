#ifndef RLE_TEST_H
#define RLE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "load.h"
#include "move.h"
}

extern "C" {
#include "rle_needed.h"
}

TEST(rleTest_positive, simple) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/rle_input.txt", INPUTDIRFILE_RL);

    load(txt, filename);
    free(filename);
    move(txt, 0, 2);
    int res = rle_needed(txt);
    EXPECT_EQ(res, 1);

    remove_all(txt);
}

TEST(rleTest_negative, empty) {
    text txt = create_text();
    
    int res = rle_needed(txt);
    EXPECT_EQ(res, -1);

    remove_all(txt);
}

TEST(rleTest_negative, wrong_crsr_pos) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/rle_input.txt", INPUTDIRFILE_RL);

    load(txt, filename);
    free(filename);

    move(txt, 1, 15);
    int res = rle_needed(txt);
    EXPECT_EQ(res), 0);

    remove_all(txt);
}
#endif // RLE_TEST_H
