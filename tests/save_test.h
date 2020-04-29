#ifndef TEST_SAVE_H
#define TEST_SAVE_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fcntl.h>

extern "C++" {
#include "save.h"
#include "load.h"
}

TEST(saveTest_positive, simple) {
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/move_input.txt",INPUTDIRFILE_MV);
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

TEST(saveTest_negative, wrong_file_extension) {
    text txt = create_text();
    char *filename = (char*) malloc(sizeof(char) * 2048);
    snprintf(filename, 1024, "%s/move_input.txt",INPUTDIRFILE_MV);

    load (txt, filename);
    free(filename);

    char *newfilename = (char*) malloc(sizeof(char) * 2048);
    snprintf(newfilename, 1024, "%s/input.xlsx",INPUTDIRFILE_SP);

    EXPECT_EQ(save(txt, newfilename), 1);

    char *in = (char *)malloc(sizeof(char)*256);
    int input = open(filename, O_RDONLY);
    int in_size = read(input, in, 256);
    close(input);

    char *out = (char *)malloc(sizeof(char)*256);
    int output = open(filename, O_RDONLY);
    int out_size = read(output, out, 256);
    close(output);

    EXPECT_EQ(out_size, in_size);
    EXPECT_EQ(*(in), *(out));

    free(in);
    free(out);

}

#endif // TEST_SAVE_H
