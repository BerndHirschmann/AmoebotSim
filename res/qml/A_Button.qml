import QtQuick 2.0
import QtQuick.Controls 1.1
import QtQuick.Controls.Styles 1.1

Button {
    style: ButtonStyle {
        background: Rectangle {
            implicitWidth: 80
            implicitHeight: 25
            border.width: 1
            border.color: "#888"
            radius: 4
            color: control.pressed ? "#888" : "#eee"
            opacity: 0.75
        }
    }
}