#include "PStringParameter.h"
#include "PAbstractParameter_p.h"

class PStringParameterPrivate: public PAbstractParameterPrivate
{
public:
    QString value;

    PStringParameterPrivate(PStringParameter *q, QString const& q_id)
        : PAbstractParameterPrivate(q, q_id)
    {
    }
};

PStringParameter::PStringParameter(QString const& id,  QObject *parent)
    : PAbstractParameter(*new PStringParameterPrivate(this, id), id, parent)
{

}

PStringParameter::~PStringParameter()
{

}

QString PStringParameter::value() const
{
    Q_D(const PStringParameter);

    return d->value;
}

void PStringParameter::setValue(const QString & value)
{
    Q_D(PStringParameter);

    if(value != d->value)
    {
        d->value = value;
        emit valueChanged(d->value);
    }
}

void PStringParameter::trigger()
{
    Q_D(PStringParameter);

    emit valueChanged(d->value);
}
