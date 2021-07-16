QT       += core gui openglwidgets sql printsupport
requires(qtConfig(tableview))
requires(qtConfig(fontdialog))
LIBS +=   -lopengl32 -lglu32 -lgdi32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calcbutton.cpp \
    calculator.cpp \
    main.cpp \
    mainwindow.cpp \
    openglclass.cpp \
    test.cpp

HEADERS += \
    calcbutton.h \
    calculator.h \
    mainwindow.h \
    openglclass.h \
    test.h

FORMS += \
    mainwindow.ui \
    test.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
