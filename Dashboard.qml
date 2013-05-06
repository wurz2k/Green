import QtQuick 2.0
import QtQuick.Window 2.0

Rectangle {
    width: 500;
    height: 400;

    Flickable {
        id: imageArea
        anchors.fill: parent
        interactive: true
        contentWidth: image.sourceSize.width
        contentHeight: image.sourceSize.height
        clip: true

        MouseArea {
            anchors.fill: parent
            onWheel: {

            }
        }

        onMovementStarted: {
            verticalBar.color = "#70000000"
            horizontalBar.color = "#70000000"
        }

        onMovementEnded: {
            verticalBar.color = "#00000000"
            horizontalBar.color = "#00000000"
        }

        Image {
            id: image
            anchors.fill: parent
            source: "image://imagethumb"
        }
    }

    // vertical scroll bar
    Rectangle {
        id: verticalBar
        width: 4
        height: imageArea.height / 8
        radius: 2
        color: "#00000000"
        y: (7 * imageArea.height / 8) * imageArea.visibleArea.yPosition * 1 / (1 - imageArea.visibleArea.heightRatio)
        anchors.right: imageArea.right
    }

    // horizontal scroll bar
    Rectangle {
        id: horizontalBar
        width: imageArea.width / 8
        height: 4
        radius: 2
        color: "#00000000"
        x: (7 * imageArea.width / 8) * imageArea.visibleArea.xPosition * 1 / (1 - imageArea.visibleArea.widthRatio)
        anchors.bottom: imageArea.bottom
    }
}
