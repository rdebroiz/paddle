#pragma once

#include <QObject>
#include "PBoolParameter.h"

class PBoolGroupPrivate;
class PBoolGroup : public QObject
{
    Q_OBJECT

public:
    PBoolGroup(QObject *parent = NULL);
    virtual ~PBoolGroup();

    void addParameter(PBoolParameter *param);
    void removeParameter(PBoolParameter *param);
    
    QList<PBoolParameter *> parameters() const;
    PBoolParameter* trueParameter() const;

protected slots:
    void _toggleParameters(bool value);

private:
    Q_DECLARE_PRIVATE(PBoolGroup)
    QScopedPointer<PBoolGroupPrivate> const d_ptr;
};
