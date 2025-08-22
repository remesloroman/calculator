import QtQuick

QtObject {
    property var buttons: [
            { text: "C", type: "func" },
            { text: "(", type: "func" },
            { text: ")", type: "func" },
            { text: "/", type: "operator" },

            { text: "7", type: "number" },
            { text: "8", type: "number" },
            { text: "9", type: "number" },
            { text: "*", type: "operator" },

            { text: "4", type: "number" },
            { text: "5", type: "number" },
            { text: "6", type: "number" },
            { text: "-", type: "operator" },

            { text: "1", type: "number" },
            { text: "2", type: "number" },
            { text: "3", type: "number" },
            { text: "+", type: "operator" },

            { text: "0", type: "number" },
            { text: ".", type: "number" },
            { text: "=", type: "operator" }
        ]
}
