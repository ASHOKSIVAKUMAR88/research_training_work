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
    IPC/shared_memory.c \
    IPC/posix/sem1.c \
    IPC/posix/sem2.c \
    IPC/posix/semaphore.c \
    system/limit.c \
    system/sys_info.c \
    sorting/insertion_sort.c \
    sorting/selection_sort.c \
    sorting/m_bubble_sort.c \
    sorting/bubble_sort.c \
    sorting/quick_sort.c \
    sorting/merge_sort.c \
    sorting/Assignment/bubble_sort.c \
    sorting/Assignment/insertion_sort.c \
    sorting/Assignment/m_bubble_sort.c \
    sorting/Assignment/merge_sort.c \
    sorting/Assignment/quick_sort.c \
    sorting/Assignment/selection_sort.c \
    awesome_works/divisible_not.c \
    sorting/Assignment/as/bubble_sort.c \
    sorting/Assignment/as/insertion_sort.c \
    sorting/Assignment/as/m_bubble_sort.c \
    sorting/Assignment/as/merge_sort.c \
    sorting/Assignment/as/quick_sort.c \
    sorting/Assignment/as/selection_sort.c

DISTFILES += \
    a.out \
    README.md \
    IPC/a.out \
    IPC/m \
    IPC/message_queue \
    IPC/msg_rm \
    IPC/rcv \
    IPC/sem1 \
    IPC/sem2 \
    IPC/shared2 \
    IPC/good.txt \
    IPC/posix/a.out \
    IPC/posix/sem1 \
    IPC/posix/sem2 \
    system/a.out \
    sorting/a.out \
    sorting/Assignment/a.out \
    awesome_works/a.out \
    sorting/Assignment/as/a.out
