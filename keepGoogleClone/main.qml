import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import Models 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Dev.Academy")
    Material.accent: Material.LightGreen

    ListModel{
        id: carrinho
    }

    AddAnnotationPopup {
        id: addAnnotationPopup
        anchors.centerIn: parent
        onOkClicked: {

            if(id !== ""){
                arrayDeAnotacoes.updateAnnotation(id, nome, descricao, cor)
            }
            else {
                arrayDeAnotacoes.addAnnotation(nome, descricao, cor)
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
            carrinho.remove(annotationIndex)
//            total.text = carrinho.getPreco()
        }
    }

    Item {
        id: carrinhoId
        anchors{
            left: parent.left
            right: parent.right
            top: parent.top
        }
        height: parent.height/2.5

        RowLayout{
            width: parent.width
            id: productTitle
            Text{
                Layout.fillWidth: true
                text: "Carrinho"
                font.pixelSize: 15
                clip: true
            }

            Text{
                Layout.fillWidth: true
                id: total
                font.pixelSize: 15
                clip: true
                horizontalAlignment: Text.AlignRight
            }
        }
        ListaDeAnotacoes {
            width: parent.width
            anotacaoModel: carrinho
            buttonName: "Remover"
            showAddButton: false
            showQuantity: false
            clip: true
            anchors{
                topMargin: 10
                top: productTitle.bottom
                bottom: parent.bottom
            }
//            onQuantityChanged: {
//                total.text = carrinho.getPreco()
//            }
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
            top: carrinhoId.bottom
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
                text: "Adicionar anotação"
                font.pixelSize: 15
                clip: true
                onClicked: {
                    addAnnotationPopup.titleText = "Adicionar anotação"
                    addAnnotationPopup.open()
                }
            }
        }

        ListaDeAnotacoes {
            anchors{
                top: title.bottom
                bottom: parent.bottom
                margins: 10
            }
            clip: true
            width: parent.width
            anotacaoModel: arrayDeAnotacoes
            buttonName: "Colocar no carrinho"
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
                carrinho.append(annotation)
//                total.text = carrinho.getPreco()
            }
        }
    }
}
