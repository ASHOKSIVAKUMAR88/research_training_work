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
    test.c \
    even_odd.c \
    file_text.c \
    string_descending.c \
    sum.c \
    IPC/ipc.c \
    IPC/semaphore.c \
    function.c \
    set_bits.c \
    IPC/message_queue.c \
    IPC/msg_rcv.c \
    IPC/msg_rm.c \
    IPC/sem1.c \
    IPC/sem2.c \
    IPC/shared1.c \
    IPC/shared2.c \
    IPC/shared_memory.c

DISTFILES += \
    a.out \
    README.md
