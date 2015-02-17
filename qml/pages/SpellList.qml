import QtQuick 2.0
import Sailfish.Silica 1.0
import harbour.dndhelper.spells 0.1

Page {
    id: spellListPage
    property bool focusSearchField

    SilicaListView {
        id: listView
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: "About"
                onClicked: {
                    pageStack.push(Qt.resolvedUrl("About.qml"), {})
                }
            }
        }

        function focusSearchField() {
            listView.headerItem.focusSearchField()
        }

        header: SearchField {
            function focusSearchField() {
                searchField.forceActiveFocus()
            }

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

    Component.onCompleted: {
        if (spellListPage.focusSearchField === true) {
            listView.focusSearchField()
            spellListPage.focusSearchField = false
        }
    }

    Spells {
        id: spells
    }
}
