#include "annotationbasemodel.h"
#include <QQmlEngine>
#include <QCoreApplication>
#include <QSqlError>
#include <QSqlQuery>

const static QString TABLE_NAME = "anotacao";

AnnotationBaseModel::AnnotationBaseModel(QObject *parent, Database *db): QSqlTableModel(parent, db->database()),
    m_db(db)
{
    setTable(TABLE_NAME);
    registerRoleColumns(Id, "id");
    registerRoleColumns(Name, "nome");
    registerRoleColumns(Description, "descricao");
    registerRoleColumns(Color, "cor");
    registerRoleColumns(DateTime, "date_time");
    setEditStrategy(QSqlTableModel::OnRowChange);
    select();
}

QVariant AnnotationBaseModel::data(const QModelIndex &index, int role) const
{
      if(m_roleColumns.contains(role)){
        int column = fieldIndex(m_roleColumns.value(role));
        QModelIndex item = QSqlTableModel::index(index.row(), column);
        QVariant result = QSqlTableModel::data(item);
        return result;
      }
      return QVariant();
}

QHash<int, QByteArray> AnnotationBaseModel::roleNames() const
{
    return m_roleColumns;
}

void AnnotationBaseModel::addAnnotation(QString name, QString description, QString color, QString date_time)
{
    QSqlQuery query(m_db->database());
    query.prepare("INSERT INTO anotacao "
                  " (nome, descricao, cor, date_time) VALUES (:name, :description, :color, :date_time)");
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":color", color);
    query.bindValue(":date_time", date_time);
    bool success = query.exec();
    if(success){
        qDebug() << "INSERT BEM SUCEDIDO";
    } else {
        qDebug() << "INSERT MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void AnnotationBaseModel::removeAnnotation(QString id)
{
    QSqlQuery query(m_db->database());
    query.prepare("DELETE FROM anotacao WHERE id = :id");
    query.bindValue(":id", id);
    bool success = query.exec();
    if(success){
        qDebug() << "DELETE BEM SUCEDIDO";
    } else {
        qDebug() << "DELETE MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void AnnotationBaseModel::updateAnnotation(QString id, QString name, QString description, QString color, QString date_time)
{
    QSqlQuery query(m_db->database());
    query.prepare("UPDATE anotacao SET "
                  " nome = :name, "
                  " descricao = :description,  "
                  " cor = :color,  "
                  " date_time = :date_time "
                  " WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":name", name);
    query.bindValue(":description", description);
    query.bindValue(":color", color);
    query.bindValue(":date_time", date_time);
    bool success = query.exec();
    if(success){
        qDebug() << "UPDATE BEM SUCEDIDO";
    } else {
        qDebug() << "UPDATE MAL SUCEDIDO" << query.lastError();
    }
    select();
}

void AnnotationBaseModel::registerRoleColumns(int role, QByteArray columnName)
{
    m_roleColumns.insert(role, columnName);
}

void registerTypes() {
    qmlRegisterType<AnnotationBaseModel>("Models", 1, 0, "AnnotationDatabaseModel");
}

Q_COREAPP_STARTUP_FUNCTION(registerTypes)
