import QtQuick.Controls
import QtQuick
import QtQuick.Layouts

import multilib

ApplicationWindow {
    visible: true
    id:window


    QMLCamera
    {
        width:300
        height:450
        anchors.centerIn: parent
    }


}
