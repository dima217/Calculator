#ifndef ACTIONS_H
#define ACTIONS_H

#include <QObject>
using namespace std;

class actions : public QObject
{
    Q_OBJECT
public:
    explicit actions(QObject *parent = nullptr);
    QString expression;
    QString acting;
    void CheckExpression();
private:
    vector<QString>operations;
    vector<double>elements;

signals:

public slots:
     void SetExpression(QString lable, int CheckOpp);
     void ruvn();
};

#endif // ACTIONS_H
