import QtQuick 2.9

Item {
    anchors.fill: parent
    Rectangle {
        anchors.fill: parent
        color: "lightblue"
    }
    Loader {
        id: main_loader
        objectName: "obj_main_loader"
        anchors.fill: parent
    }
}
