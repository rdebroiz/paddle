#include "PAbstractParameter.h"
#include "PAbstractParameter_p.h"


PAbstractParameterPrivate::PAbstractParameterPrivate(PAbstractParameter *q, QString const& q_id)
    : q_ptr(q), id(q_id)
{
    description = id;
    caption = id;
}

PAbstractParameter::PAbstractParameter(const QString & id, QObject *parent)
    : QObject(parent), d_ptr(new PAbstractParameterPrivate(this, id))
{    
}

PAbstractParameter::PAbstractParameter(PAbstractParameterPrivate &d, const QString & id, QObject *parent)
    : QObject(parent), d_ptr(&d)
{
    Q_UNUSED(id)
}

PAbstractParameter::~PAbstractParameter()
{
}

QString PAbstractParameter::id() const
{
    Q_D(const PAbstractParameter);

    return d->id;
}


void PAbstractParameter::setDescription(const QString & description)
{
    Q_D(PAbstractParameter);

    if(d->description != description)
    {
        d->description = description;
        emit descriptionChanged(d->description);
    }
}

QString PAbstractParameter::description() const
{
    Q_D(const PAbstractParameter);

    return d->description;
}

void PAbstractParameter::setCaption(const QString & caption)
{
    Q_D(PAbstractParameter);

    if(d->caption != caption)
    {
        d->caption = caption;
        emit captionChanged(d->caption);
    }
}

QString PAbstractParameter::caption() const
{
    Q_D(const PAbstractParameter);

    return d->caption;
}

bool PAbstractParameter::match(const PAbstractParameter *other) const
{
    Q_D(const PAbstractParameter);

    // Maybe we should just check for id equallity?
    if(other != NULL)
        return (this->type() == other->type() && d->id == other->id());
    else
        return false;
}
