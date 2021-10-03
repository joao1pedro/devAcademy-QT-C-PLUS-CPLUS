#include "annotation.h"

Annotation::Annotation(QString nome, QString descricao, QString cor, QString date_time):
    m_nome(nome),
    m_descricao(descricao),
    m_cor(cor),
    m_date_time(date_time)
{

}

QString Annotation::nome() const
{
    return m_nome;
}

QString Annotation::descricao() const
{
    return m_descricao;
}

QString Annotation::cor() const
{
    return m_cor;
}

QString Annotation::date_time() const
{
    return m_date_time;
}
