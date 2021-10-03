import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12

ListView {
    id: root
    property alias anotacaoModel: root.model
    property string buttonName: ""
    property bool showAddButton: true
    signal addClicked(var annotation, var index)
    signal removeClicked(var id, var index)
    signal editClicked(var annotation, var index)
    spacing: 3
    delegate: Item {
        height: 50
        width: root.width
        Rectangle {
            id: rect
            anchors.fill: parent
            color: model.cor
            radius: 4
            layer.enabled: root.elevation > 0

            RowLayout{
                anchors.fill: parent
                clip: true
                spacing: 3
                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    Layout.preferredWidth: 40
                    font.pixelSize: 14
                    Layout.leftMargin: 5
                    text: model.nome
                    wrapMode: Text.WordWrap
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    Layout.alignment: Qt.AlignHCenter
                    Layout.preferredWidth: 40
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.pixelSize: 14
                    text: model.descricao
                    verticalAlignment: Text.AlignVCenter
                }

                Text {
                    Layout.preferredWidth: 40
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.pixelSize: 14
                    text: model.cor
                    horizontalAlignment: Text.AlignRight
                    Layout.rightMargin: 20
                    verticalAlignment: Text.AlignVCenter
                }
                Text {
                    Layout.preferredWidth: 40
                    Layout.fillWidth: true
                    Layout.fillHeight: true
                    font.pixelSize: 14
                    text: model.date_time
                    horizontalAlignment: Text.AlignRight
                    Layout.rightMargin: 20
                    verticalAlignment: Text.AlignVCenter
                }

                Button{
                    id: addButton
                    Layout.alignment: Qt.AlignHCenter
                    visible: showAddButton
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5
//                    text: "Favoritar"
                    icon.source: "qrc:/favorito.svg"
                    onClicked: {
                        addClicked({id: model.id, nome: model.nome, descricao: model.descricao, cor: model.cor}, index)
                    }
                }
                Button{
                    Layout.alignment: Qt.AlignHCenter
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5
                    visible: showAddButton
//                    text: "Editar"
                    icon.source: "qrc:/update_note.svg"
                    onClicked: {
                        editClicked({id: model.id, nome: model.nome, descricao: model.descricao, cor: model.cor}, index)
                    }
                }

                Button{
                    Layout.alignment: Qt.AlignHCenter
                    Layout.minimumWidth: 25
                    Layout.fillHeight: true
                    Layout.rightMargin: 5
//                    text: "Remove"
                    icon.source: "qrc:/trash.svg"
                    onClicked: {
                        removeClicked(model.id, index)
                    }
                }
            }

        }
    }
}
