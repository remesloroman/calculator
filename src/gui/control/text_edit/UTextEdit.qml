import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: root
    width: 300
    height: 80
    color: "#2f3b3e"
    border.color: "#b0b0b0"
    border.width: 1

    property alias text: tedit.text
    signal textEdited(string newText)

    ScrollView {
        id: outerScroll
        anchors.fill: parent
        anchors.margins: 10
        clip: true

        ScrollBar.vertical.policy: ScrollBar.AsNeeded
        ScrollBar.horizontal.policy: ScrollBar.AsNeeded

        TextEdit {
            id: tedit
            wrapMode: TextEdit.NoWrap
            font.pixelSize: 30
            color: "#fff"
            cursorVisible: false
            focus: true
            text: ""

            Keys.onReturnPressed: function(event) {
                event.accepted = true
            }

            Keys.onEnterPressed: function(event) {
                event.accepted = true
            }
            
            function scrollToEnd() {
                        Qt.callLater(function() {
                            outerScroll.contentItem.contentX =
                                Math.max(0, outerScroll.contentItem.contentWidth - outerScroll.width)
                        })
                    }

            onTextChanged: function(text) {
                scrollToEnd()
                root.textEdited(text)
            }
            onWidthChanged: scrollToEnd()
        }

        onWidthChanged: tedit.scrollToEnd()
    }
}
