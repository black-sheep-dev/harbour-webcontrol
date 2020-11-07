import QtQuick 2.0
import Sailfish.Silica 1.0

import org.nubecula.harbour.webcontrol 1.0

CoverBackground {
    Image {
        width: parent.width * 0.8
        height: width
        smooth: true
        source: "/usr/share/icons/hicolor/512x512/apps/" + Qt.application.name + ".png"
        anchors.centerIn: parent
        opacity: 0.3
    }

    CoverActionList {
        enabled: !WebControl.active

        CoverAction {
            iconSource: "image://theme/icon-cover-play"
            onTriggered: WebControl.active = true
        }
    }

    CoverActionList {
        enabled: WebControl.active

        CoverAction {
            iconSource: "image://theme/icon-cover-cancel"
            onTriggered: WebControl.active = false
        }
    }
}
