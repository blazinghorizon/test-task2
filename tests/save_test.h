#ifndef TEST_SAVE_H
#define TEST_SAVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fcntl.h>

extern "C++" {
#include "save.h"
#include "load.h"
}

TEST(saveTest_positive, _default) {
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/move_input.txt",INPUTDIRFILE);
    load (txt, filename);

    int output = open(filename, O_RDONLY);
    char *outBuf = (char *)malloc(sizeof(char)*512);
    int c1 = read(output, outBuf, 256);
    close(output);

    EXPECT_EQ(save(txt, filename), 1);

    int input = open(filename, O_RDONLY);
    char *inpBuf = (char *)malloc(sizeof(char)*512);
    int c2 = read(input, inpBuf, 256);
    close(input);

    EXPECT_EQ(c1, c2);
    EXPECT_EQ(*(outBuf), *(inpBuf));

    remove_all(txt);
    free(filename);

}

TEST(saveTest_negative, _secured_file) {
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/move_input.txt",INPUTDIRFILE);
    load (txt, filename);

    char *locked_file = (char*) malloc(sizeof(char) * 2048);
    snprintf(locked_file, 1024, "%s/locked.txt",INPUTDIRFILE);

    EXPECT_EQ(save(txt, locked_file), -1);

    remove_all(txt);
    free(filename);
    free(locked_file);
}

#endif // TEST_SAVE_H
