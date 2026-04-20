import QtQuick

Window {
    id: root
    width: 800
    height: 400
    visible: true
    title: qsTr("Circle Movement")

    // Left square
    Rectangle {
        id: leftRectangle
        x: 50
        y: 150
        width: 100
        height: 100
        color: "#4CAF50"
        border.color: "#2E7D32"
        border.width: 2
        radius: 5

        Text {
            anchors.centerIn: parent
            text: "move"
            font.pixelSize: 18
            font.bold: true
            color: "white"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // Find square center
                var rightCenterX = rightRectangle.x + rightRectangle.width / 2

                // Check if the ball has reached or passed the center of the right square
                if (ball.x + ball.width / 2 >= rightCenterX) {
                    // Return to initial position
                    ball.state = "InitialState"
                } else {
                    // Generate a random move between 20 and 60 pixels
                    var randomMove = Math.floor(Math.random() * (60 - 20 + 1)) + 20

                    // New position after the move
                    var newX = ball.x + randomMove

                    // Calculate the maximum allowed X position to not exceed the center of the right square
                    var maxX = rightCenterX - ball.width / 2

                    // Ensure the new position does not exceed the maximum allowed position
                    if (newX > maxX) {
                        ball.x = maxX
                    } else {
                        ball.x = newX
                    }

                    // If the ball has reached or passed the center of the right square, set it to the other state
                    ball.state = "OtherState"
                }
            }
        }
    }

    // Right square
    Rectangle {
        id: rightRectangle
        x: 650
        y: 150
        width: 100
        height: 100
        color: "#FF5722"
        border.color: "#D84315"
        border.width: 2
        radius: 5

        Text {
            anchors.centerIn: parent
            text: "return"
            font.pixelSize: 18
            font.bold: true
            color: "white"
        }

        MouseArea {
            anchors.fill: parent
            onClicked: {
                // Return to initial position
                ball.state = "InitialState"
            }
        }
    }

    // Circle (ball)
    Rectangle {
        id: ball
        x: leftRectangle.x + leftRectangle.width / 2 - width / 2
        y: leftRectangle.y + leftRectangle.height / 2 - height / 2
        width: 40
        height: 40
        radius: 20
        color: "#2196F3"
        border.color: "#1976D2"
        border.width: 2

        // State machine for ball movement
        state: "InitialState"

        states: [
            State {
                name: "InitialState"
                PropertyChanges {
                    target: ball
                    x: leftRectangle.x + leftRectangle.width / 2 - ball.width / 2
                    y: leftRectangle.y + leftRectangle.height / 2 - ball.height / 2
                }
            },
            State {
                name: "OtherState"
                PropertyChanges {
                    target: ball
                    x: ball.x
                }
            }
        ]

        // Transitions for smooth movement
        transitions: [
            Transition {
                from: "OtherState"
                to: "InitialState"

                NumberAnimation {
                    properties: "x,y"
                    duration: 1000
                    easing.type: Easing.OutBounce
                }
            }
        ]
    }
}

