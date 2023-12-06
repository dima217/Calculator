#include "actions.h"
#include <QDebug>

actions::actions(QObject *parent) : QObject(parent) {}

void actions::SetExpression(QString label, int CheckOpp)
{
    if (CheckOpp > 1) {}
    else {
  expression += label;
  qDebug() << "label is: " << expression;

    }
}

void actions::ruvn()
{

}

