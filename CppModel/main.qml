/***************************************************************************
    Copyright (C) 2017 by ZhaoDongshuang
    Author: ZhaoDongshuang
    Email: imtoby@126.com
    Date: 2017/11/07
    File: main.qml
 ***************************************************************************/
import QtQuick 2.3
import QtQuick.Window 2.2

Window {
    id: rootWindow
    visible: true
    width: 240
    height: 360

    ListView {
        anchors.fill: parent

        model: modelMgr.objectModel()

        delegate: Text {
            width: rootWindow.width
            height: 40
            text: model.modelData.name + index
        }
    }

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log("ZDS=============")
            modelMgr.testInsert();
        }
    }
}
