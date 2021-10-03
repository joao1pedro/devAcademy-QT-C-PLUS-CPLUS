import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.12
import QtQuick.Controls.Material 2.12
import QtQuick.Controls.Material.impl 2.12
import Models 1.0

Dialog {
    id: addAnnotation
    height: 300
    width: 190
    signal okClicked(var nome, var descricao, var cor, var id)
    standardButtons: Dialog.Cancel | Dialog.Ok
    property string nome: ""
    property string descricao: ""
    property string cor: ""
    property string id: ""
    property string titleText: "Adicionar anotacao"

    ColumnLayout {
        anchors.fill: parent
        spacing: 8
        Text{
            Layout.fillWidth: true
            text: titleText
            horizontalAlignment: Text.AlignHCenter
        }
        TextField {
            id: textName
            text: nome
            onTextChanged: {
                nome = text
            }
            Layout.maximumWidth: parent.width
            placeholderText: "Nome"
        }

        TextField {
            id: textDescription
            text: descricao
            onTextChanged: {
                descricao = text
            }
            Layout.maximumWidth: parent.width
            placeholderText: "Descricao"
        }

        TextField {
            id: textColor
            Layout.maximumWidth: parent.width
            text: cor
            onTextChanged: {
                cor = text
            }
            placeholderText: "Cor"
        }
    }

    function clearFields(){
        nome = ""
        descricao = ""
        cor = ""
        id = ""
    }

    onAccepted: {
        okClicked(nome, descricao, cor, id)
        clearFields()
    }
    onRejected: {
        clearFields()
    }
}
