import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.dndhelper.spells 0.1

Page {

    SilicaListView {
        id: listView
        anchors.fill: parent

        header: SearchField {
            id: searchField
            width: listView.width
            placeholderText: "Search"
            onTextChanged: {
                spells.search(searchField.text)
            }
        }

        // prevent newly added list delegates from stealing focus away from the search field
        currentIndex: -1

        model: spells
        delegate: ListItem {
            contentHeight: Theme.itemSizeSmall
            //menu: contextMenu
            Label {
                text: name
                anchors {
                    verticalCenter: parent.verticalCenter
                }
            }
            onClicked: {
                pageStack.push(Qt.resolvedUrl("SpellDetails.qml"), {"spellFullText": full_text})
            }
            Component {
                id: contextMenu
                ContextMenu {
                    MenuItem {
                        text: "Add to favorites"
                    }
                }
            }
        }
    }

    Spells {
        id: spells
    }
}
