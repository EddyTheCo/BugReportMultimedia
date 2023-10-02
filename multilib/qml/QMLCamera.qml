import QtQuick 2.0
import QtMultimedia
import QtQuick.Controls
import multilib

Item
{
    id:root

    VideoOutput {
        id: videoOutput
        anchors.fill: root
    }
    Camera {
        id: camera
        active: false
        onErrorOccurred: (error,errorString)=> {
                             console.log(errorString)
                             console.log(error)
                         }

    }
    Permision_h
    {
        id:p_handler
        onGotPermission:
        {
            camera.start();
        }
    }

    CaptureSession {
        id: capturesession
        camera: camera
        videoOutput: videoOutput
    }
    Button
    {
        id:startcamera
        anchors.centerIn: parent
        text:(camera.active)?qsTr("stop"):qsTr("start")
        onClicked:
        {
            (camera.active)?camera.stop():p_handler.getPermission();
        }
        width:100
        height:50
    }

}


