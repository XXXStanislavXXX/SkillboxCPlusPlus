import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

ApplicationWindow {
    visible: true
    width: 800
    height: 450
    title: "Видео-проигрыватель"

    ColumnLayout {
        anchors.fill: parent
        spacing: 10

        Rectangle {
            id: screenArea
            Layout.fillWidth: true
            Layout.preferredHeight: parent.height * 0.72
            color: "#111214"
            radius: 6
            border.color: "#333"
            border.width: 1

            Text {
                anchors.centerIn: parent
                text: "Экран проигрывателя"
                color: "#ffffff"
                font.pixelSize: 20
            }
        }

        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: 110
            color: "transparent"

            ColumnLayout {
                anchors.fill: parent
                spacing: 8

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 12

                    Button {
                        id: rewindButton
                        text: "⏪️"
                        font.pixelSize: 20
                        ToolTip.visible: hovered
                        ToolTip.text: "Rewind"
                    }
                    Button {
                        id: playButton
                        text: "▶️"
                        font.pixelSize: 22
                        ToolTip.text: "Play"
                    }
                    Button {
                        id: pauseButton
                        text: "⏸️"
                        font.pixelSize: 20
                        ToolTip.text: "Pause"
                    }
                    Button {
                        id: stopButton
                        text: "⏹"
                        font.pixelSize: 18
                        ToolTip.text: "Stop"
                    }
                    Button {
                        id: forwardButton
                        text: "⏩️"
                        font.pixelSize: 20
                        ToolTip.text: "Forward"
                    }
                }

                ProgressBar {
                    Layout.fillWidth: true
                    from: 0
                    to: 100
                    value: 35
                    height: 14
                }
            }
        }
    }
}
