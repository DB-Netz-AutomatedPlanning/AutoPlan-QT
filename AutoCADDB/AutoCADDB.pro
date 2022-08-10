QT       += core gui openglwidgets sql printsupport widgets svg svgwidgets concurrent
requires(qtConfig(tableview))
requires(qtConfig(fontdialog))

INCLUDEPATH += ./include

LIBS +=  -lopengl32 -lglu32 -lgdi32

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    connect2csharp.cpp \
    connecttocsharp.cpp \
    coordinates.cpp \
    gleiskantenfromunprocessedjson.cpp \
    gleisknotenfromunprocessedjson.cpp \
    hofromunprocessedjson.cpp \
    importfolder.cpp \
    kmliniefromunprocessedjson.cpp \
    kmtocoordinate.cpp \
    lagefromunprocessedjson.cpp \
    main.cpp \
    mainwindow.cpp \
    newprojectdialog.cpp \
    nopreviewdelete.cpp \
    planningtable.cpp \
    planproelements.cpp \
    previeweulynxxml.cpp \
    qgraphicsmainwindow.cpp \
    qgraphicssymbolcontainer.cpp \
    qjsonmodel.cpp \
    readeulynxsignals.cpp \
    removedata.cpp \
    signalfromunprocessedjson.cpp \
    signalsfromunprocessedjson.cpp \
    symbolcontainer.cpp \
    tracks.cpp \
    uberhohungfromunprocessedjson.cpp \
    uploadnewdata.cpp \
    exportdialog.cpp \
    xml2json.cpp

HEADERS += \
    connect2csharp.h \
    connecttocsharp.h \
    coordinates.h \
    gleiskantenfromunprocessedjson.h \
    gleisknotenfromunprocessedjson.h \
    hofromunprocessedjson.h \
    importfolder.h \
    kmliniefromunprocessedjson.h \
    kmtocoordinate.h \
    lagefromunprocessedjson.h \
    mainwindow.h \
    newprojectdialog.h \
    nopreviewdelete.h \
    planningtable.h \
    planproelements.h \
    previeweulynxxml.h \
    qgraphicsmainwindow.h \
    qgraphicssymbolcontainer.h \
    qjsonmodel.h \
    readeulynxsignals.h \
    removedata.h \
    signalfromunprocessedjson.h \
    signalsfromunprocessedjson.h \
    symbolcontainer.h \
    tracks.h \
    uberhohungfromunprocessedjson.h \
    uploadnewdata.h \
    exportdialog.h \
    xml2json.h

FORMS += \
    importfolder.ui \
    mainwindow.ui \
    newprojectdialog.ui \
    nopreviewdelete.ui \
    planningtable.ui \
    previeweulynxxml.ui \
    qgraphicsmainwindow.ui \
    qgraphicssymbolcontainer.ui \
    removedata.ui \
    symbolcontainer.ui \
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
