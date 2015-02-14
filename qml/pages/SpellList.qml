import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.dndhelper.spells 0.1

Page {
    id: spellList

    SilicaListView {
        id: listView
        anchors.fill: parent

        header: SearchField {
            id: searchField
            width: listView.width
            placeholderText: "Search"
            onTextChanged: {
                console.log("Text is now " + searchField.text)
                spells.search(searchField.text)
            }
        }

        // prevent newly added list delegates from stealing focus away from the search field
        //currentIndex: -1

        model: spells
        delegate: Item {
            height: Theme.itemSizeSmall
            width: parent.width
            Label { text: name }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("SpellDetails.qml"), {"spellFullText": full_text})
                }
            }
        }
    }

    Spells {
        id: spells
    }
}
