import QtQuick 2.0
import Sailfish.Silica 1.0

import org.nubecula.harbour.webcontrol 1.0

Page {
    id: page

    allowedOrientations: Orientation.All

    SilicaFlickable {
        anchors.fill: parent

        contentHeight: column.height

        Column {
            id: column

            width: page.width
            spacing: Theme.paddingSmall

            PageHeader {
                title: qsTr("Settings")
            }

            TextField {
                id: hostField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Listen address")
                placeholderText: qsTr("Enter listen address e.g. 0.0.0.0)")

                text: WebControl.host

                inputMethodHints: Qt.ImhUrlCharactersOnly
                validator: RegExpValidator {
                    regExp: /^(?:(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)\.){3}(?:25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)$/
                }

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: portField.focus = true
            }

            TextField {
                id: portField

                x: Theme.horizontalPageMargin
                width: parent.width / 2

                label: qsTr("Port")

                text: WebControl.port

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 1; top: 65535;}

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: minThreadsField.focus = true
            }

            TextField {
                id: minThreadsField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Minimum threads")

                text: WebControl.minThreads

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 1; top: 255;}

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: maxThreadsField.focus = true
            }

            TextField {
                id: maxThreadsField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Maximum threads")

                text: WebControl.maxThreads

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: minThreadsField.text; top: 255;}

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: readTimeoutField.focus = true
            }

            TextField {
                id: readTimeoutField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Read timeout (msec)")

                text: WebControl.readTimeout

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 0 }

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: cleanupIntervalField.focus = true
            }

            TextField {
                id: cleanupIntervalField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Cleanup interval (msec)")

                text: WebControl.cleanupInterval

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 0 }

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: maxRequestSizeField.focus = true
            }

            TextField {
                id: maxRequestSizeField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Maximum request size (bytes)")

                text: WebControl.maxRequestSize

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 0 }

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: maxMultiPartSizeField.focus = true
            }

            TextField {
                id: maxMultiPartSizeField

                x: Theme.horizontalPageMargin
                width: parent.width - 2*x

                label: qsTr("Maximum multi part size (bytes)")

                text: WebControl.maxMultiPartSize

                inputMethodHints: Qt.ImhDigitsOnly
                validator: IntValidator { bottom: 0 }

                EnterKey.iconSource: "image://theme/icon-m-enter-next"
                EnterKey.onClicked: focus = false
            }
        }
    }

    onStatusChanged: {
        if (status == PageStatus.Deactivating) {
            if (hostField.acceptableInput) WebControl.host = hostField.text;
            if (portField.acceptableInput) WebControl.port = portField.text;
            if (minThreadsField.acceptableInput) WebControl.minThreads = minThreadsField.text;
            if (maxThreadsField.acceptableInput) WebControl.maxThreads = maxThreadsField.text;
            if (readTimeoutField.acceptableInput) WebControl.readTimeout = readTimeoutField.text;
            if (cleanupIntervalField.acceptableInput) WebControl.cleanupInterval = cleanupIntervalField.text;
            if (maxRequestSizeField.acceptableInput) WebControl.maxRequestSize = maxRequestSizeField.text;
            if (maxMultiPartSizeField.acceptableInput) WebControl.maxMultiPartSize = maxMultiPartSizeField.text;
        }
    }
}


