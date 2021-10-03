#ifndef ANNOTATION_H
#define ANNOTATION_H

#include <QObject>

class Annotation
{
public:
    explicit Annotation(QString nome, QString descricao, QString cor);

    QString nome() const;
    QString descricao() const;
    QString cor() const;

signals:

private:
    QString m_nome;
    QString m_descricao;
    QString m_cor;
};

#endif // ANNOTATION_H
