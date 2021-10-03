#include "annotationcontroller.h"
#include "qdebug.h"

AnnotationController::AnnotationController(QObject *parent): QObject(parent)
{

}

void AnnotationController::newAnnotation(QJSValue value)
{
    QVariantMap params = value.toVariant().toMap();
    QString name = params.value("name").toString();
    QString description = params.value("description").toString();
    QString color = params.value("color").toString();
    m_model->addAnnotation(name, description, color);
}

void AnnotationController::setAnnotationModel(AnnotationModel *model)
{
    m_model = model;
}
