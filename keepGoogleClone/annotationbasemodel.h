#ifndef ANNOTATIONBASEMODEL_H
#define ANNOTATIONBASEMODEL_H

#include "database.h"

#include <QObject>
#include <QSqlTableModel>

class AnnotationBaseModel: public QSqlTableModel
{
    Q_OBJECT
public:
    explicit AnnotationBaseModel(QObject *parent = nullptr, Database *db = new Database());

    enum AnnotationRoles {
        Id = Qt::DisplayRole,
        Name,
        Description,
        Color,
        DateTime
    };

    Q_INVOKABLE QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Q_INVOKABLE QHash<int, QByteArray> roleNames() const override;
    Q_INVOKABLE void addAnnotation(QString name, QString description, QString color, QString date_time);
    Q_INVOKABLE void removeAnnotation(QString id);
    Q_INVOKABLE void updateAnnotation(QString id, QString name, QString description, QString color, QString date_time);

private:
    void registerRoleColumns(int role, QByteArray columnName);
    QHash<int, QByteArray> m_roleColumns;
    Database *m_db = new Database();
};

#endif // ANNOTATIONBASEMODEL_H
