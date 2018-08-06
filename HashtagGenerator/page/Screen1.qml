import QtQuick 2.0

Item {
    Item {
        id: lable
        width: parent.width; height: parent.height * 1 / 4
        Text {
            id: lable_name1
            text: "#Hashtag"
            anchors.top: parent.top
            anchors.topMargin: parent.height / 4
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 40
            font.bold: true
        }
        Text {
            id: lable_name2
            anchors.top: lable_name1.bottom
            anchors.topMargin: 10
            text: "Generator!"
            anchors.right: lable_name1.right
            font.pixelSize: 20
        }
    }

    Item {
        id: input
        width: parent.width; height: parent.height * 1 / 2
        anchors.top: lable.bottom
        Text {
            id: lable_input
            text: qsTr("   Your key word:")
        }
        Rectangle {
            id: input_border
            width: parent.width * 3 / 4; height: parent.height * 2 / 3
            anchors.top: lable_input.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            border.width: 1
            clip: true
            Text {
                id: input_mask
                anchors.centerIn: input_text
                text: qsTr("Push your key word here...")
                visible: input_text.text == "" && input_text.focus == false
            }
            TextInput {
                id: input_text
                anchors.fill: parent
                cursorVisible: focus
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                wrapMode: TextInput.WordWrap
            }
        }
        Rectangle {
            id: button_Ok
            width: parent.width * 1 / 3; height: parent.height * 1 / 6
            anchors.top: input_border.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            color: "lightgray"
            border.width: 1
            Text {
                text: qsTr("Generate & copy")
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: {
                    UIBridge.sentString(input_text.text)
                    text_hashtag_result.selectAll()
                    text_hashtag_result.copy()
                }
                onPressed: button_Ok.color = "gray"
                onReleased: button_Ok.color = "lightgray"
                onCanceled: button_Ok.color = "lightgray"
            }
        }
        Rectangle {
            id: button_clear
            height: parent.height * 1 / 6
            anchors.top: button_Ok.top
            anchors.left: button_Ok.right
            anchors.leftMargin: 10
            anchors.right: input_border.right
            color: "lightgray"
            border.width: 1
            Text {
                text: qsTr("Clear")
                anchors.centerIn: parent
            }
            MouseArea {
                anchors.fill: parent
                onClicked: input_text.text = ""
                onPressed: button_clear.color = "gray"
                onReleased: button_clear.color = "lightgray"
                onCanceled: button_clear.color = "lightgray"
            }
        }
    }
    Item {
        id: result
        width: parent.width; height: parent.height * 1 / 4
        anchors.top: input.bottom
        Text {
            id: lable_result
            text: qsTr("   Result:")
        }
        Rectangle {
            width: parent.width * 3 / 4; height: parent.height * 2 / 3
            anchors.top: lable_result.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            color: "transparent"
            border.width: 1
            clip: true
            TextEdit {
                id: text_hashtag_result
                objectName: "obj_text_hashtag_result"
                anchors.fill: parent
                horizontalAlignment: TextInput.AlignHCenter
                verticalAlignment: TextInput.AlignVCenter
                selectByMouse: true
                wrapMode: TextInput.WordWrap
                text: "result here!"
            }
        }
    }
}
