TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    editor.cpp \
    load.cpp \
    move.cpp \
    place_first.cpp \
    pr_righter.cpp \
    rle.cpp \
    save.cpp \
    show.cpp \
    showtrimmedfromstart.cpp \
    text/add_begin.cpp \
    text/append_line.cpp \
    text/create_text.cpp \
    text/move_cursor.cpp \
    text/process_forward.cpp \
    text/remove_all.cpp \
    text/rle_line.cpp


HEADERS += \
    load.h \
    move.h \
    place_first.h \
    pr_righter.h \
    rle.h \
    save.h \
    show.h \
    showtrimmedfromstart.h \
    text/text.h \
    text/_text.h

QMAKE_CXXFLAGS += -Wall -Wextra -Werror

# gcov
QMAKE_CXXFLAGS += -fprofile-arcs -ftest-coverage
LIBS += -lgcov -lm
