# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = DnDhelper

CONFIG += sailfishapp

QT += sql

SOURCES += src/DnDhelper.cpp \
    src/Spells.cpp

OTHER_FILES += qml/DnDhelper.qml \
    qml/cover/CoverPage.qml \
    rpm/DnDhelper.changes.in \
    rpm/DnDhelper.spec \
    rpm/DnDhelper.yaml \
    translations/*.ts \
    DnDhelper.desktop \
    qml/dnd35.db \
    qml/pages/SpellDetails.qml \
    qml/pages/SpellList.qml \
    qml/pages/About.qml

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n
TRANSLATIONS += translations/DnDhelper-de.ts

HEADERS += \
    src/Spells.h

