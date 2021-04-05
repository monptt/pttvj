QT       += core gui
QT       += multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z

QMAKE_CXXFLAGS += /std:c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FrameProcessing.cpp \
    cmd.cpp \
    deck.cpp \
    displaywindow.cpp \
    main.cpp \
    mainwindow.cpp \
    setting.cpp

HEADERS += \
    FrameProcessing.h \
    cmd.h \
    deck.h \
    displaywindow.h \
    mainwindow.h \
    setting.h

FORMS += \
    displaywindow.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# OpenCV settings
DEPENDPATH  += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include"
LIBS += "C:\opencv\build\x64\vc15\lib\opencv_world3413.lib"
LIBS += "C:\opencv\build\x64\vc15\lib\opencv_world3413d.lib"

