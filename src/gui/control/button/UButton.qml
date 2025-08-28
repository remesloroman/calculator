import QtQuick
import QtQuick.Controls

Button {
    id: root
    property color baseColor: "#e0e0e0"

    font {
        pixelSize: 19
    }

    contentItem: Text {
        text: root.text
        font: root.font
        opacity: enabled ? 1.0 : 0.3
        color: root.down ? "#5f5555" : "black"
        horizontalAlignment: Text.AlignHCenter
        verticalAlignment: Text.AlignVCenter
        elide: Text.ElideRight
    }

    background: Rectangle {
        id: rect

        color: if(root.hovered) {
                   return Qt.lighter(baseColor, 1.05)
               } else if(root.pressed) {
                   return Qt.darker(baseColor, 1.1)
               } else
                   return baseColor

        border.color: "#9fa2a5"
        border.width: 1
    }
}
