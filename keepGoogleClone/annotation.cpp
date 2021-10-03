#include "annotation.h"

Annotation::Annotation(QString nome, QString descricao, QString cor):
    m_nome(nome),
    m_descricao(descricao),
    m_cor(cor)
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
