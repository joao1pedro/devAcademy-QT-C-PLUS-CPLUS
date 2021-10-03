#include "annotationmodel.h"

#include <QQmlEngine>
#include <QCoreApplication>

AnnotationModel::AnnotationModel(QObject *parent): QAbstractListModel(parent)
{
    setupData();
}

QVariant AnnotationModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    switch (role) {
    case Name:
        return m_annotations[index.row()].nome();
    case Description:
        return m_annotations[index.row()].descricao();
    case Color:
        return m_annotations[index.row()].cor();
    case DateTime:
        return m_annotations[index.row()].date_time();
    default:
        return QVariant();
    }
}

int AnnotationModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_annotations.count();
}

void AnnotationModel::setupData()
{
    beginResetModel();
    m_annotations.append(Annotation("Comprar Arroz", "Ir no mercantil comprar arroz", "red", "Tue 2013-09-17 10:56:06"));
    m_annotations.append(Annotation("Abastecer o reservatorio", "Encher os reservatorios de agua", "green", "Tue 2021-09-17 11:56:08"));
    endResetModel();
}

QString AnnotationModel::title()
{
    return m_title;
}

void AnnotationModel::setTitle(QString title)
{
    if(title == m_title){
        return;
    }

    m_title = title;
    emit titleChanged();
}

void AnnotationModel::addAnnotation(QString nome, QString descricao, QString cor, QString data_time)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    m_annotations.append(Annotation(nome, descricao, cor, data_time));
    endInsertRows();
}

void AnnotationModel::removeAnnotation(int index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_annotations.removeAt(index);
    endRemoveRows();
}

QHash<int, QByteArray> AnnotationModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Name] = "name";
    roles[Description] = "description";
    roles[Color] = "color";
    roles[DateTime] = "date_time";
    return roles;
}

void registerType() {
    qmlRegisterType<AnnotationModel>("Models", 1, 0, "AnnotationModel");
}

Q_COREAPP_STARTUP_FUNCTION(registerType)
