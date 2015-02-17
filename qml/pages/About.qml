import QtQuick 2.0
import Sailfish.Silica 1.0

Page {
    Column {
        anchors.fill: parent
        width: parent.width

        PageHeader {
            title: "About DnDhelper"
        }

        Item {
            width: parent.width
            height: Theme.paddingLarge
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            text: "A D&D helper for SailfishOS"
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: Theme.fontSizeSmall
            text: "Copyright \u00A9 2015 Tadeusz Sośnierz"
        }

        Item {
            width: parent.width
            height: Theme.paddingLarge
        }

        Label {
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
            font.pixelSize: Theme.fontSizeTiny
            text: "Source code and licensing info available at\n" +
                  "https://github.com/tadzik/harbour-dndhelper"
        }
    }
}
