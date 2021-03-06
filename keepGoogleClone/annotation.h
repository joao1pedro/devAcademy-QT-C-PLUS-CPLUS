#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <QObject>

class Annotation
{
public:
    explicit Annotation(QString nome, QString descricao, QString cor, QString date_time);

    QString nome() const;
    QString descricao() const;
    QString cor() const;
    QString date_time() const;

signals:

private:
    QString m_nome;
    QString m_descricao;
    QString m_cor;
    QString m_date_time;
};

#endif // ANNOTATION_H
