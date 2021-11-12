QT       += core gui openglwidgets sql printsupport widgets svg svgwidgets
requires(qtConfig(tableview))
requires(qtConfig(fontdialog))

LIBS +=  -lopengl32 -lglu32 -lgdi32




greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    calcbutton.cpp \
    calculator.cpp \
    connect2csharp.cpp \
    connecttocsharp.cpp \
    constructsvgdialog.cpp \
    coordinates.cpp \
    dragwidget.cpp \
    dropwidget.cpp \
    iconslist.cpp \
    importfolder.cpp \
    kmtocoordinate.cpp \
    main.cpp \
    mainwindow.cpp \
    myopenglwidget.cpp \
    newprojectdialog.cpp \
    nopreviewdelete.cpp \
    openglclass.cpp \
    planningtable.cpp \
    previeweulynxxml.cpp \
    qgraphicsmainwindow.cpp \
    removedata.cpp \
    svgdialogview.cpp \
    symbolcontainer.cpp \
    symbolinformation.cpp \
    symboloptions.cpp \
    test.cpp \
    tracks.cpp \
    uploadnewdata.cpp \
    exportdialog.cpp

HEADERS += \
    calcbutton.h \
    calculator.h \
    connect2csharp.h \
    connecttocsharp.h \
    constructsvgdialog.h \
    coordinates.h \
    dragwidget.h \
    dropwidget.h \
    iconslist.h \
    importfolder.h \
    kmtocoordinate.h \
    mainwindow.h \
    myopenglwidget.h \
    newprojectdialog.h \
    nopreviewdelete.h \
    openglclass.h \
    planningtable.h \
    previeweulynxxml.h \
    qgraphicsmainwindow.h \
    removedata.h \
    svgdialogview.h \
    symbolcontainer.h \
    symbolinformation.h \
    symboloptions.h \
    test.h \
    tracks.h \
    uploadnewdata.h \
    exportdialog.h

FORMS += \
    constructsvgdialog.ui \
    iconslist.ui \
    importfolder.ui \
    mainwindow.ui \
    newprojectdialog.ui \
    nopreviewdelete.ui \
    planningtable.ui \
    previeweulynxxml.ui \
    qgraphicsmainwindow.ui \
    removedata.ui \
    symbolcontainer.ui \
    symbolinformation.ui \
    symboloptions.ui \
    test.ui \
    uploadnewdata.ui \
    exportdialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    assets/Plan/import.png \
    assets/view/hand.png
