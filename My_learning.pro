TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    union.c \
    union_bit_field.c \
    endian.c \
    typecast.c \
    structure.c \
    thread.c \
    custom_malloc.c \
    test.c
