import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

Window {
    width: 350
    height: 430
    visible: true
    title: qsTr("Qualqulator")

    ColumnLayout {
        anchors {
            fill: parent
        }

        spacing: 0

        UTextEdit {
            id: exprField
            Layout.alignment: Qt.AlignTop
            Layout.fillWidth: true
        }

        UButtonGrid {}
    }
}
