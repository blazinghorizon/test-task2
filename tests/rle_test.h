#ifndef RLE_H
#define RLE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "rle.h"
#include "load.h"
#include "move.h"
}

TEST(rleTest_positive, _default) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/rle_input.txt", INPUTDIRFILE);

    load(txt, filename);
    free(filename);
    move(txt, 0, 2);
    EXPECT_EQ(rle_str(txt), 1);
}

TEST(rleTest_negative, _empty) {
    text txt = create_text();

    EXPECT_EQ(rle_str(txt), -1);

}

TEST(rleTest_negative, _wrong_crsr_pos) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/rle_input.txt", INPUTDIRFILE);

    load(txt, filename);
    free(filename);

    move(txt, 1, 15);
    EXPECT_EQ(rle_str(txt), 0);
}
#endif // RLE_H
