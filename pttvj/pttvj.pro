QT       += core gui
QT       += multimedia

QT += opengl
LIBS += -lOpenGL32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++1z

QMAKE_CXXFLAGS += /std:c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    FrameProcessing.cpp \
    audioprocess.cpp \
    cmd.cpp \
    deck.cpp \
    glwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    setting.cpp

HEADERS += \
    FrameProcessing.h \
    audioprocess.h \
    cmd.h \
    deck.h \
    glwidget.h \
    mainwindow.h \
    setting.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


# OpenCV settings
DEPENDPATH  += "C:\opencv\build\include"
INCLUDEPATH += "C:\opencv\build\include"
LIBS += "C:\opencv\build\x64\vc15\lib\opencv_world3414.lib"
LIBS += "C:\opencv\build\x64\vc15\lib\opencv_world3414d.lib"

