include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

QMAKE_CFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov

DEFINES += INPUTDIRFILE=\\\"$$PWD/test_files\\\"

HEADERS += \
    cp_test.h \
    move_test.h \
    rle_test.h \
    save_test.h \
    showtrimmedfromstart_test.h \

SOURCES +=  main.cpp \
    ../app/cp.cpp \
    ../app/load.cpp \
    ../app/move.cpp \
    ../app/rle.cpp \
    ../app/save.cpp \
    ../app/showtrimmedfromstart.cpp \
    ../app/text/append_line.cpp \
    ../app/text/cp_swap.cpp \
    ../app/text/create_text.cpp \
    ../app/text/move_cursor.cpp \
    ../app/text/process_forward.cpp \
    ../app/text/remove_all.cpp \
    ../app/text/rle_line.cpp \

INCLUDEPATH += ../app
