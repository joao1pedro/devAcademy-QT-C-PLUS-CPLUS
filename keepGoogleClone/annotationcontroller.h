#ifndef ANNOTATIONCONTROLLER_H
#define ANNOTATIONCONTROLLER_H

#include <QJSValue>
#include <QObject>

#include "annotationmodel.h"

class AnnotationController: public QObject
{
    Q_OBJECT
public:
    explicit AnnotationController(QObject *parent = nullptr);
    void setAnnotationModel(AnnotationModel *model);

signals:

public slots:
    void newAnnotation(QJSValue value);

private:
    AnnotationModel *m_model;
};

#endif // ANNOTATIONCONTROLLER_H
