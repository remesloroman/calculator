import QtQuick
import QtQuick.Layouts

import gui.control.button

GridLayout {
    Layout.fillWidth: true
    Layout.fillHeight: true
    rows: 4
    columns: 4
    columnSpacing: 0
    rowSpacing: 0


    ButtonModel {
        id: data
    }

    Repeater {
        model: data.buttons
        UButton {
            baseColor: if(index < 3)
                           return "#c6c6c6"
                       else if(index % 4 == 3 || modelData.text == "=")
                           return Qt.lighter("#f5913c", 1.25)
                       else
                           return "#e0e0e0"

            Layout.fillWidth: true
            Layout.fillHeight: true
            text: modelData.text
            Layout.columnSpan: (text === "0") ? 2 : 1

            onClicked: {

            }
        }
    }
}
