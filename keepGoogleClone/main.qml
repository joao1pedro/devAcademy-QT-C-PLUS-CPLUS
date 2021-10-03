import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import Models 1.0

Window {
    width: 860
    height: 540
    visible: true
    title: qsTr("Dev.Academy: Clone Google Keep")
    Material.accent: Material.LightBlue
    id: root

    ListModel{
        id: favoritos
    }

    AddAnnotationPopup {
        id: addAnnotationPopup
        anchors.centerIn: parent
        onOkClicked: {

            if(id !== ""){
                arrayDeAnotacoes.updateAnnotation(id, nome, descricao, cor, date_time)
            }
            else {
                arrayDeAnotacoes.addAnnotation(nome, descricao, cor, date_time)
            }

        }
    }

    AnnotationDatabaseModel {
        id: arrayDeAnotacoes
    }

    Dialog{
        id: removeAnnotationPopup
        anchors.centerIn: parent
        property var annotationIndex
        standardButtons: Dialog.Yes | Dialog.No
        Text{
            id: popupTitle
            text: "Deseja remover a anotação?"
        }
        onAccepted: {
            favoritos.remove(annotationIndex)
        }
    }

    Item {
        id: favoritosId
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: parent.height/2

        RowLayout{
            width: parent.width
            id: productTitle
            Text{
                Layout.fillWidth: true
                text: "Favoritos"
                font.pixelSize: 15
                clip: true
                horizontalAlignment: Text.AlignHCenter
            }
        }
        ListaDeAnotacoes {
            width: parent.width
            anotacaoModel: favoritos
            buttonName: "Remover"
            showAddButton: false
            clip: true
            anchors{
                topMargin: 10
                top: productTitle.bottom
                bottom: parent.bottom
            }
            onRemoveClicked: {
                removeAnnotationPopup.annotationIndex = index
                removeAnnotationPopup.open()
            }
        }
    }

    Item{
        anchors{
            left: parent.left
            right: parent.right
            bottom: parent.bottom
            top: favoritosId.bottom
        }
        RowLayout{
            width: parent.width
            clip: true
            id: title
            Text{
                id: titleText
                Layout.fillWidth: true
                text: "Lista de anotações"
                font.pixelSize: 15
                clip: true
            }

            Button{
                Layout.fillWidth: true
                font.pixelSize: 15
                clip: true
                icon.source: "qrc:/add.svg"
                onClicked: {
                    addAnnotationPopup.titleText = "Adicionar anotação"
                    addAnnotationPopup.open()
                }
            }
        }

        ListaDeAnotacoes {
            id: anotacoes
            anchors{
                top: title.bottom
                bottom: parent.bottom
                margins: 10
            }
            clip: true
            width: parent.width
            anotacaoModel: arrayDeAnotacoes
            buttonName: "Colocar no favoritos"
            onEditClicked: function(annotation, index){
                addAnnotationPopup.titleText = "Editar anotação"
                addAnnotationPopup.id = annotation.id
                addAnnotationPopup.nome = annotation.nome
                addAnnotationPopup.descricao = annotation.descricao
                addAnnotationPopup.cor = annotation.cor
                addAnnotationPopup.open()
            }
            onRemoveClicked: {
                arrayDeAnotacoes.removeAnnotation(id)
            }
            onAddClicked: {
                favoritos.append(annotation)
            }
        }
        RowLayout{
            id: usuario
            anchors{
                top: root.bottom
                bottom: parent.bottom
                margins: 10
            }
            width: parent.width
            clip: true
            Text {
                text: "Usuário:"
            }
            Text {
                text: "Email:"
            }
        }
    }
}
