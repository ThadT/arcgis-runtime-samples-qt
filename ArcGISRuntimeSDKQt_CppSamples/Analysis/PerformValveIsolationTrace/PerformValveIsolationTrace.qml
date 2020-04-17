// [WriteFile Name=PerformValveIsolationTrace, Category=Analysis]
// [Legal]
// Copyright 2020 Esri.

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
// [Legal]

import QtQuick 2.6
import QtQuick.Controls 2.2
import Esri.Samples 1.0
import QtQuick.Layouts 1.11

Item {

    // add a mapView component
    MapView {
        id: view
        anchors.fill: parent
    }


    ColumnLayout {
        anchors {
            left: parent.left
            top: parent.top
        }
        Rectangle {
            id: backgroundRect
            color: "#FBFBFB"
            height: childrenRect.height
            width: row.width * 1.5
            RowLayout {
                id: row
                anchors.horizontalCenter: parent.horizontalCenter
                ComboBox {
                    id: comboBox
                    enabled: sampleModel.uiEnabled
                    Layout.fillWidth: true
                    width: 200

                    model:sampleModel.categoriesList
                    onCurrentIndexChanged: {
                        sampleModel.selectedIndex = currentIndex;
                    }
                }
                Button {
                    text: "trace"
                    onClicked: {
                        sampleModel.performTrace();
                    }
                    enabled: sampleModel.uiEnabled
                }
            }
            RowLayout {
                id: checkBoxRow
                anchors.top: row.bottom
                CheckBox {
                    text: "Include isolated features"
                    enabled: sampleModel.uiEnabled
                    onCheckedChanged: {
                        sampleModel.isolateFeatures = checked;
                    }
                }
            }
        }
    }

    BusyIndicator {
        id: busyIndicator
        anchors.centerIn: parent
        running: !sampleModel.uiEnabled
    }

    // Declare the C++ instance which creates the scene etc. and supply the view
    PerformValveIsolationTraceSample {
        id: sampleModel
        mapView: view
    }
}
