#ifndef SHOWTRIMMEDFROMSTART_TEST_H
#define SHOWTRIMMEDFROMSTART_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <fcntl.h>

extern "C++" {
#include "load.h"
#include "showtrimmedfromstart.h"
#include "text/text.h"
}

TEST(trimmed_positive, simple) {
    text txt = create_text();

    char *stdout_copy = (char*) malloc(sizeof(char)*2048);
    snprintf(stdout_copy, 2048, "%s/showtrimmed_output.txt", INPUTDIRFILE_TR);

    char *filename = (char*) malloc(sizeof(char)*2048);
    snprintf(filename, 2048, "%s/showtrimmed_input.txt", INPUTDIRFILE_TR);

    load(txt, filename);
    free(filename);

    int new_stdout = open(stdout_copy, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    ASSERT_NE(new_stdout, -1);

    int old_stdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(new_stdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(new_stdout);
    dup2(old_stdout, STDOUT_FILENO);

    char *right_output = (char*) malloc(sizeof(char)*2048);
    snprintf(right_output, 2048, "%s/showtrimmed_r_output.txt", INPUTDIRFILE_TR);

    int current_buf = open(stdout_copy, O_RDONLY);
    int original_buf = open(right_output, O_RDONLY);
    char *outBuf = (char*) malloc(sizeof(char)*128);
    char *testBuf = (char*) malloc(sizeof(char)*128);
    free(right_output);

    int test_buf_size = read(current_buf, testBuf, 16);
    int original_buf_size = read(original_buf, outBuf, 16);
    close(current_buf);
    close(original_buf);

    ASSERT_EQ(test_buf_size, original_buf_size);
    ASSERT_EQ(*(outBuf), *(testBuf));

    free(outBuf);
    free(testBuf);
    free(stdout_copy);
    remove_all(txt);
}

TEST(trimmed_negative, no_spaces) {
    text txt = create_text();

    char *stdout_copy = (char*) malloc(sizeof(char)*2048);
    snprintf(stdout_copy, 2048, "%s/showtrimmed_output_no_spaces.txt", INPUTDIRFILE_TR);

    char *filename = (char*) malloc(sizeof(char)*2048);
    snprintf(filename, 2048, "%s/showtrimmed_no_spaces.txt", INPUTDIRFILE_TR);

    load(txt, filename);

    int new_stdout = open(stdout_copy, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    ASSERT_NE(new_stdout, -1);

    int old_stdout = dup(STDOUT_FILENO);
    close(STDOUT_FILENO);
    dup2(new_stdout, STDOUT_FILENO);

    showfromstart(txt);

    fflush(stdout);
    close(new_stdout);
    dup2(old_stdout, STDOUT_FILENO);

    int current_buf = open(stdout_copy, O_RDONLY);
    int original_buf = open(filename, O_RDONLY);
    char *outBuf = (char*) malloc(sizeof(char)*128);
    char *testBuf = (char*) malloc(sizeof(char)*128);
    free(filename);

    int test_buf_size = read(current_buf, testBuf, 16);
    int original_buf_size = read(original_buf, outBuf, 16);
    close(current_buf);
    close(original_buf);

    ASSERT_EQ(test_buf_size, original_buf_size);
    ASSERT_EQ(*(outBuf), *(testBuf));

    free(outBuf);
    free(testBuf);
    free(stdout_copy);
    remove_all(txt);
}

#endif // SHOWTRIMMEDFROMSTART_TEST_H
