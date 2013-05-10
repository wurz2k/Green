import QtQuick 2.0

Rectangle {
    width: 500
    height: 370

//    Rectangle {
//        id: addressBar
//        anchors.top: parent.top
//        border { color: "lightblue"; width: 1 }
//        height: 20;

//        Text {
//            anchors.fill: parent
//            text: "directory: " + imageDirectory.directory
//        }
//    }


    GridView {
        anchors.fill: parent
        clip: true
        model: imageDirectory.imageFiles
        delegate: nameDelegate
        cellWidth: imageDirectory.thumbSize.width
        cellHeight: imageDirectory.thumbSize.height
    }


    Component {
        id: nameDelegate
        Image {
          clip: true
          cache: true
          source: "image://imagethumb/" + imageDirectory.directory + "/" + model.modelData.fileName;
        }



//            Text {
//                anchors.fill: parent
//                text: model.modelData.fileName
//            }
    }
}
