import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

Rectangle {
    id: display
    width: 300
    height: 80
    color: "#2f3b3e"
    border.color: "#b0b0b0"
    border.width: 1

    property alias text: tedit.text

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

            function scrollToEnd() {
                        Qt.callLater(function() {
                            outerScroll.contentItem.contentX =
                                Math.max(0, outerScroll.contentItem.contentWidth - outerScroll.width)
                        })
                    }

            onTextChanged: scrollToEnd()
            onWidthChanged: scrollToEnd()
        }

        onWidthChanged: tedit.scrollToEnd()
    }
}
