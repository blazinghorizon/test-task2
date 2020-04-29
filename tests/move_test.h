#ifndef MOVE_TEST_H
#define MOVE_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "text/text.h"
#include "move.h"
#include "load.h"
#include "text/_text.h"
}

TEST(moveTest_positive, _empty) {
    text txt = create_text();

    EXPECT_EQ(move(txt, 0, 0), -1);
    remove_all(txt);

}

TEST(moveTest_positive, _default) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/move_input.txt", INPUTDIRFILE);

    load(txt, filename);
    free(filename);

    EXPECT_EQ(move(txt, 1, 2), 1);

    list<string>::iterator current = txt->lines.begin();
    int lineNumber = 0;
    int pos = txt->cursor->pos;

    while (current++ != txt->cursor->line)
        lineNumber++;

    EXPECT_EQ(pos, 2);
    EXPECT_EQ(lineNumber, 1);
    remove_all(txt);
}

TEST(moveTest_negative, _out_of_range) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/move_input.txt", INPUTDIRFILE);

    load(txt, filename);
    free(filename);

    EXPECT_EQ(move(txt, -10, -10), 0);
    remove_all(txt);
}

TEST(moveTest_negative, _invalid) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/move_input.txt", INPUTDIRFILE);

    load(txt, filename);
    free(filename);

    EXPECT_EQ(move(txt, '?', '-'), 0);
    remove_all(txt);
}

#endif // MOVE_TEST_H
