TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += \
    $$PWD/data_structure \
    $$PWD/data_type \
    $$PWD/management

SOURCES += \
    ./data_structure/avl_tree.cpp \
    ./data_type/car.cpp \
    ./data_structure/doubly_linklist.cpp \
    main.cpp \
    ./data_type/user.cpp \
    ./management/registration.cpp \
    data_type/customer.cpp \
    management/managing_cars.cpp

HEADERS += \
    ./data_structure/avl_tree.h \
    ./data_type/car.h \
    ./data_structure/doubly_linklist.h \
    ./data_type/user.h \
    ./management/registration.h \
    data_type/customer.h \
    management/managing_cars.h
