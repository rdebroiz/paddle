#include "PParameterPool.h"
#include "PParameterPool_p.h"

PParameterPoolPrivate:: PParameterPoolPrivate(PParameterPool *q)
    : q_ptr(q)
{
}

void PParameterPoolPrivate::connect(PStringParameter *param)
{
    Q_Q(PParameterPool);

    QObject::connect(param, &PStringParameter::valueChanged,
                     q, &PParameterPool::_dispatchString, Qt::UniqueConnection);
    QObject::connect(param, &PStringParameter::destroyed,
                     q, &PParameterPool::_removeSender, Qt::UniqueConnection);
}

void PParameterPoolPrivate::disconnect(PStringParameter *param)
{
    Q_Q(PParameterPool);

    param->disconnect(q);

}

void PParameterPoolPrivate::connect(PBoolParameter *param)
{
    Q_Q(PParameterPool);

    QObject::connect(param, &PBoolParameter::valueChanged,
                     q, &PParameterPool::_dispatchBool, Qt::UniqueConnection);
    QObject::connect(param, &PStringParameter::destroyed,
                     q, &PParameterPool::_removeSender, Qt::UniqueConnection);
}

void PParameterPoolPrivate::disconnect(PBoolParameter *param)
{
    Q_Q(PParameterPool);

    param->disconnect(q);

}

void PParameterPoolPrivate::connect(PIntParameter *param)
{
    Q_Q(PParameterPool);

    QObject::connect(param, &PIntParameter::valueChanged,
                     q, &PParameterPool::_dispatchInt, Qt::UniqueConnection);
    QObject::connect(param, &PStringParameter::destroyed,
                     q, &PParameterPool::_removeSender, Qt::UniqueConnection);
}

void PParameterPoolPrivate::disconnect(PIntParameter *param)
{
    Q_Q(PParameterPool);

    param->disconnect(q);

}

void PParameterPoolPrivate::connect(PDoubleParameter *param)
{
    Q_Q(PParameterPool);

    QObject::connect(param, &PDoubleParameter::valueChanged,
                     q, &PParameterPool::_dispatchDouble, Qt::UniqueConnection);
    QObject::connect(param, &PStringParameter::destroyed,
                     q, &PParameterPool::_removeSender, Qt::UniqueConnection);
}

void PParameterPoolPrivate::disconnect(PDoubleParameter *param)
{
    Q_Q(PParameterPool);

    param->disconnect(q);

}




PParameterPool::PParameterPool(QObject *parent)
    : QObject(parent), d_ptr(new PParameterPoolPrivate(this))
{
}

PParameterPool::PParameterPool(PParameterPoolPrivate &d, QObject *parent)
    : QObject(parent), d_ptr(&d)
{
}


PParameterPool::~PParameterPool()
{
}

void PParameterPool::append(PStringParameter *parameter)
{
    Q_D(PParameterPool);
    QString id = parameter->id();

    if(!d->stringHash.contains(id, parameter))
    {
        d->stringHash.insert(id, parameter);
        d->connect(parameter);
    }
}

void PParameterPool::remove(PStringParameter *parameter)
{
    Q_D(PParameterPool);

    d->disconnect(parameter);
    d->stringHash.remove(parameter->id(), parameter);
}

void PParameterPool::append(PBoolParameter *parameter)
{
    Q_D(PParameterPool);
    QString id = parameter->id();

    if(!d->boolHash.contains(id, parameter))
    {
        d->boolHash.insert(id, parameter);
        d->connect(parameter);
    }
}

void PParameterPool::remove(PBoolParameter *parameter)
{
    Q_D(PParameterPool);

    d->disconnect(parameter);
    d->boolHash.remove(parameter->id(), parameter);
}

void PParameterPool::append(PIntParameter *parameter)
{
    Q_D(PParameterPool);
    QString id = parameter->id();

    if(!d->intHash.contains(id, parameter))
    {
        d->intHash.insert(id, parameter);
        d->connect(parameter);
    }
}

void PParameterPool::remove(PIntParameter *parameter)
{
    Q_D(PParameterPool);

    d->disconnect(parameter);
    d->intHash.remove(parameter->id(), parameter);
}

void PParameterPool::append(PDoubleParameter *parameter)
{
    Q_D(PParameterPool);
    QString id = parameter->id();

    if(!d->doubleHash.contains(id, parameter))
    {
        d->doubleHash.insert(id, parameter);
        d->connect(parameter);
    }
}

void PParameterPool::remove(PDoubleParameter *parameter)
{
    Q_D(PParameterPool);

    d->disconnect(parameter);
    d->doubleHash.remove(parameter->id(), parameter);
}

void PParameterPool::append(PAbstractParameter *parameter)
{
    // static cast is enough here
    switch(parameter->type())
    {
    case PAbstractParameter::P_PARAMETER_STRING:
        this->append(static_cast<PStringParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_BOOL:
        this->append(static_cast<PBoolParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_INT:
        this->append(static_cast<PIntParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_DOUBLE:
        this->append(static_cast<PDoubleParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_UNDEFINED:
        break;
    default:
        break;
    }
}

void PParameterPool::remove(PAbstractParameter *parameter)
{
    // static cast is enough here
    switch(parameter->type())
    {
    case PAbstractParameter::P_PARAMETER_STRING:
        this->remove(static_cast<PStringParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_BOOL:
        this->remove(static_cast<PBoolParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_INT:
        this->remove(static_cast<PIntParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_DOUBLE:
        this->remove(static_cast<PDoubleParameter *>(parameter));
        break;
    case PAbstractParameter::P_PARAMETER_UNDEFINED:
        break;
    default:
        break;
    }
}

void PParameterPool::_dispatchString(QString const& value)
{
    Q_D(PParameterPool);

    if(PStringParameter *sender = qobject_cast<PStringParameter *>(this->sender()))
    {
        for(PStringParameter *param : d->stringHash.values(sender->id()))
        {
            if(param != sender)
            {
                d->disconnect(param);
                param->setValue(value);
                d->connect(param);
            }

        }
    }
}

void PParameterPool::_dispatchBool(bool value)
{
    Q_D(PParameterPool);

    if(PBoolParameter *sender = qobject_cast<PBoolParameter *>(this->sender()))
    {
        for(PBoolParameter *param : d->boolHash.values(sender->id()))
        {
            if(param != sender)
            {
                d->disconnect(param);
                param->setValue(value);
                d->connect(param);
            }

        }
    }
}

void PParameterPool::_dispatchInt(int value)
{
    Q_D(PParameterPool);

    if(PIntParameter *sender = qobject_cast<PIntParameter *>(this->sender()))
    {
        for(PIntParameter *param : d->intHash.values(sender->id()))
        {
            if(param != sender)
            {
                d->disconnect(param);
                param->setValue(value);
                d->connect(param);
            }
        }
    }
}

void PParameterPool::_dispatchDouble(double value)
{
    Q_D(PParameterPool);

    if(PDoubleParameter *sender = qobject_cast<PDoubleParameter *>(this->sender()))
    {
        for(PDoubleParameter *param : d->doubleHash.values(sender->id()))
        {
            if(param != sender)
            {
                d->disconnect(param);
                param->setValue(value);
                d->connect(param);
            }

        }
    }
}

void PParameterPool::_removeSender(QObject *sender)
{
    if(PAbstractParameter *param = qobject_cast<PAbstractParameter *>(sender))
        this->remove(param);
}
