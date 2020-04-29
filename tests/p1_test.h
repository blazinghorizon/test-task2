#ifndef P1_TEST_H
#define P1_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "text/_text.h"
#include "place_first.h"
#include "load.h"
}

TEST(p1_positive, simple) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/move_input.txt", INPUTDIRFILE_MV);

    load(txt, filename);

    place_first(txt, "123");

    string beginning = (*(txt->lines.begin()));
    EXPECT_EQ(beginning, "123\n");
    remove_all(txt);
}


TEST(p1_negative, empty_text) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/empty.txt", INPUTDIRFILE_SP);

    load(txt, filename);

    place_first(txt, "123");

    string beginning = (*(txt->lines.begin()));
    EXPECT_EQ(beginning, "123\n");

    remove_all(txt);
}


#endif // P1_TEST_H
