import QtQuick 2.0
import Sailfish.Silica 1.0

import org.nubecula.harbour.webcontrol 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaFlickable {
        anchors.fill: parent

        PullDownMenu {
            MenuItem {
                text: qsTr("About")
                onClicked: pageStack.push(Qt.resolvedUrl("AboutPage.qml"))
            }
            MenuItem {
                text: qsTr("Settings")
                onClicked: pageStack.push(Qt.resolvedUrl("SettingsPage.qml"))
            }
        }

        contentHeight: column.height

        Column {
            id: column

            width: page.width
            spacing: Theme.paddingMedium

            PageHeader {
                title: qsTr("Web Control")
            }

            TextSwitch {
                id: activateSwitch

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                text: qsTr("Web Server")
                description: qsTr("Start and stop the web server");

                //checked: WebControl.active
                Component.onCompleted: checked = WebControl.active
                onCheckedChanged: WebControl.active = checked
            }

            Separator {
                x: Theme.horizontalPageMargin
                width: parent.width - 2*x
                color: Theme.highlightBackgroundColor

                opacity: WebControl.active ? 1.0 : 0.0

                Behavior on opacity { FadeAnimation {} }
            }

            Label {
                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                color: Theme.highlightColor
                wrapMode: Text.WordWrap
                text: qsTr("Navigate to the below address in your browser to access the web frontend.")

                opacity: WebControl.active ? 1.0 : 0.0

                Behavior on opacity { FadeAnimation {} }
            }

            LinkedLabel {
                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                linkColor: Theme.secondaryHighlightColor
                text: WebControl.webUrl

                opacity: WebControl.active ? 1.0 : 0.0

                Behavior on opacity { FadeAnimation {} }
            }
        }
    }

    onVisibleChanged: activateSwitch.checked = WebControl.active
}

