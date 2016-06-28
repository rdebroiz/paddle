#pragma once

#include <QObject>

class PAbstractParameterPrivate;
class PAbstractParameter : public QObject
{

public:
    enum ParameterType
    {
        P_PARAMETER_UNDEFINED,
        P_PARAMETER_INT,
        P_PARAMETER_DOUBLE,
        P_PARAMETER_BOOL,
        P_PARAMETER_STRING
    };
    Q_ENUM(ParameterType)

    Q_OBJECT

public:
    PAbstractParameter(QString const& id, QObject* parent = NULL);
    virtual ~PAbstractParameter();

    QString id() const;

    QString description() const;
    void setDescription(QString const& description);

    QString caption() const;
    void setCaption(QString const& caption);

    bool match(PAbstractParameter const* other) const;

signals:
    void captionChanged(QString caption);
    void descriptionChanged(QString description);

public:
    virtual ParameterType type() const = 0;

public slots:
    virtual void trigger() = 0;

private:
    const QScopedPointer<PAbstractParameterPrivate> d;
};

