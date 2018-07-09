import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

Rectangle {
    Text {
        text: slider.value
    }

    Slider {
        id:slider
        stepSize: 1
        from: 0
        to: 100
        onValueChanged: {
            //dont know
        }
    }

    GridView
    {
        anchors.topMargin: 80
        anchors.fill: parent
        anchors.leftMargin: 40
        model: manager.model
        delegate: Text {
            text: sample.percentage
        }
    }
}
