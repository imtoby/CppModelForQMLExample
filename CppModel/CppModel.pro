TEMPLATE = app

QT += qml quick

SOURCES += main.cpp \
    ObjectModel.cpp \
    TestItem.cpp \
    ModelManager.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    ObjectModel.h \
    TestItem.h \
    Config.h \
    ModelManager.h
