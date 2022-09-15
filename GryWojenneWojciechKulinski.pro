QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Counter.cpp \
    Game.cpp \
    Gui.cpp \
    Icon_Menu.cpp \
    Icon_Spawn.cpp \
    Unit.cpp \
    Unit_Archer.cpp \
    Unit_Guard.cpp \
    Unit_Knight.cpp \
    Weapon.cpp \
    Weapon_Arrow.cpp \
    Weapon_Sword.cpp \
    main.cpp

HEADERS += \
    Counter.h \
    Game.h \
    Gui.h \
    Icon_Menu.h \
    Icon_Spawn.h \
    Unit.h \
    Unit_Archer.h \
    Unit_Guard.h \
    Unit_Knight.h \
    Weapon.h \
    Weapon_Arrow.h \
    Weapon_Sword.h

FORMS +=

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Zasoby.qrc
