import QtQuick
import QtQuick.Layouts
import QtQuick.Controls

import gui.layout
import gui.control.text_edit

import controller 1.0

Window {
    width: 350
    height: 430

    minimumWidth: 200
    minimumHeight: 260

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
            text: CalculatorController.inputText

            onTextEdited: {
                CalculatorController.setInputText(text)
            }
        }

        UButtonGrid {
            onButtonClicked: function(symbol) {
                CalculatorController.processInput(symbol)
            }
        }
    }
}
