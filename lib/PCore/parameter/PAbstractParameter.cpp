#include "PAbstractParameter.h"

class PAbstractParameterPrivate
{
public:
    QString id;
    QString description;
    QString caption;
};

PAbstractParameter::PAbstractParameter(const QString & id, QObject *parent)
    : QObject(parent), d(new PAbstractParameterPrivate)
{
    d->id = id;
    d->caption = id;
    d->description = id;
}

PAbstractParameter::~PAbstractParameter()
{

}

QString PAbstractParameter::id() const
{
    return d->id;
}


void PAbstractParameter::setDescription(const QString & description)
{
    if(d->description != description)
    {
        d->description = description;
        emit descriptionChanged(d->description);
    }
}

QString PAbstractParameter::description() const
{    
    return d->description;
}

void PAbstractParameter::setCaption(const QString & caption)
{
    if(d->caption != caption)
    {
        d->caption = caption;
        emit captionChanged(d->caption);
    }
}

QString PAbstractParameter::caption() const
{
    return d->caption;
}

bool PAbstractParameter::match(const PAbstractParameter *other) const
{
    return (this->type() == other->type() && d->id == other->id());
}
