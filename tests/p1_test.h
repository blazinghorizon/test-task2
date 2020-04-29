#ifndef P1_TEST_H
#define P1_TEST_H

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

extern "C++" {
#include "text/text.h"
#include "place_first.h"
#include "load.h"
}

TEST(p1Positive, _default) {
    text txt = create_text();

    char *filename = (char*) malloc(sizeof(char*) * 1024);
    snprintf(filename, 1024, "%s/p1_input.txt", INPUTDIRFILE);

    load(txt, filename);

    string input_str = "123";
    place_first(txt, input_str);

}

#endif // P1_TEST_H
