#ifndef ANNOTATIONMODEL_H
#define ANNOTATIONMODEL_H

#include "annotation.h"

#include <QAbstractListModel>
#include <QList>

class AnnotationModel: public QAbstractListModel
{
    Q_OBJECT
public:

    enum AnnotationRoles {
        Name = Qt::DisplayRole,
        Description,
        Color,
        DateTime
    };

    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)

    AnnotationModel(QObject *parent = nullptr);
    QVariant data(const QModelIndex &index, int role) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    void setupData();
    QString title();
    Q_INVOKABLE void setTitle(QString title);

public slots:
    void addAnnotation(QString nome, QString descricao, QString cor, QString date_time);
    void removeAnnotation(int index);

signals:
    void titleChanged();

private:
    QHash<int, QByteArray> roleNames() const override;
    QList<Annotation> m_annotations;
    QString m_title;
};

#endif // ANNOTATIONMODEL_H
