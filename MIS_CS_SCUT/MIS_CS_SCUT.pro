#-------------------------------------------------
#
# Project created by QtCreator 2022-04-14T20:45:15
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MIS_CS_SCUT
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    login.cpp \
    input_student.cpp \
    result_student.cpp \
    input_score.cpp \
    result_score.cpp \
    input_course.cpp \
    result_course.cpp \
    input_teacher.cpp \
    result_teacher.cpp \
    input_average.cpp \
    result_average.cpp \
    modify1_administrator.cpp \
    student_modify.cpp \
    student_insert.cpp \
    student_delete.cpp \
    course_modify.cpp \
    course_insert.cpp \
    course_delete.cpp \
    choosing_modify.cpp \
    choosing_insert.cpp \
    choosing_delete.cpp \
    modify_teacher.cpp \
    prompt_box.cpp

HEADERS += \
        mainwindow.h \
    login.h \
    input_student.h \
    result_student.h \
    input_score.h \
    result_score.h \
    input_course.h \
    result_course.h \
    input_teacher.h \
    result_teacher.h \
    input_average.h \
    result_average.h \
    modify1_administrator.h \
    student_modify.h \
    student_insert.h \
    student_delete.h \
    course_modify.h \
    course_insert.h \
    course_delete.h \
    choosing_modify.h \
    choosing_insert.h \
    choosing_delete.h \
    modify_teacher.h \
    prompt_box.h

FORMS += \
        mainwindow.ui \
    login.ui \
    input_student.ui \
    result_student.ui \
    input_score.ui \
    result_score.ui \
    input_course.ui \
    result_course.ui \
    input_teacher.ui \
    result_teacher.ui \
    input_average.ui \
    result_average.ui \
    modify1_administrator.ui \
    student_modify.ui \
    student_insert.ui \
    student_delete.ui \
    course_modify.ui \
    course_insert.ui \
    course_delete.ui \
    choosing_modify.ui \
    choosing_insert.ui \
    choosing_delete.ui \
    modify_teacher.ui \
    prompt_box.ui

RESOURCES += \
    res.qrc
