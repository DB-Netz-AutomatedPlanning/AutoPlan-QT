INCLUDEPATH += D:\Users\BKU\SayliArjunPednekar\Documents\GitHub\AutoPlan-QT\AutoCADDB\glew-2.1.0\include
INCLUDEPATH += D:\Users\BKU\SayliArjunPednekar\Documents\GitHub\AutoPlan-QT\AutoCADDB\glm\glm


QT       += core gui openglwidgets sql printsupport widgets svg svgwidgets
requires(qtConfig(tableview))
requires(qtConfig(fontdialog))

LIBS +=  -LD:\Users\BKU\SayliArjunPednekar\Documents\GitHub\AutoPlan-QT\AutoCADDB\glew-2.1.0\lib\Release\x64 -lglew32 -lopengl32 -lglu32 -lgdi32




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calcbutton.cpp \
    calculator.cpp \
    constructsvgdialog.cpp \
    dragwidget.cpp \
    dropwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    openglclass.cpp \
    planningtable.cpp \
    svgdialogview.cpp \
    test.cpp

HEADERS += \
    calcbutton.h \
    calculator.h \
    constructsvgdialog.h \
    dragwidget.h \
    dropwidget.h \
    mainwindow.h \
    openglclass.h \
    planningtable.h \
    svgdialogview.h \
    test.h

FORMS += \
    constructsvgdialog.ui \
    mainwindow.ui \
    planningtable.ui \
    test.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES +=
