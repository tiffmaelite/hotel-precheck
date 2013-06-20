#ifndef QQQuickAction_H
#define QQQuickAction_H

#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtGui/QKeySequence>
#include <QtCore/qpointer.h>

/*!
 \brief

 \class QQQuickAction qquickaction.h "views/qquickaction.h"
*/
class SH_ExtendedQQmlAction : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString text READ text WRITE setText NOTIFY textChanged)
    Q_PROPERTY(QUrl iconSource READ iconSource WRITE setIconSource NOTIFY iconSourceChanged)
    Q_PROPERTY(QString iconName READ iconName WRITE setIconName NOTIFY iconNameChanged)
    Q_PROPERTY(QVariant __icon READ iconVariant NOTIFY iconChanged)
    Q_PROPERTY(QString tooltip READ tooltip WRITE setTooltip NOTIFY tooltipChanged)
    Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled NOTIFY enabledChanged)

#ifndef QT_NO_SHORTCUT
    Q_PROPERTY(QString shortcut READ shortcut WRITE setShortcut NOTIFY shortcutChanged)
    Q_PROPERTY(Qt::Key keyShortcut WRITE setKeyShortcut NOTIFY keyShortcutChanged)
#endif

public:
    /*!
     \brief

     \fn QQQuickAction
     \param parent
    */
    explicit SH_ExtendedQQmlAction(QObject *parent = 0);
    /*!
     \brief

     \fn ~QQQuickAction
    */
    ~SH_ExtendedQQmlAction();

    /*!
     \brief

     \fn text
     \return QString
    */
    QString text() const { return m_text; }
    /*!
     \brief

     \fn setText
     \param text
    */
    void setText(const QString &text);

    /*!
     \brief

     \fn shortcut
     \return QString
    */
    QString shortcut() const;
    /*!
     \brief

     \fn setShortcut
     \param shortcut
    */
    void setShortcut(const QString &shortcut);

    /*!
     \brief

     \fn keyShortcut
     \return QKeySequence
    */
    QKeySequence keyShortcut() const { return m_shortcut; }
    /*!
     \brief

     \fn setKeyShortcut
     \param shortcut
    */
    void setKeyShortcut(const Qt::Key &shortcut);

    /*!
     \brief

     \fn setMnemonicFromText
     \param mnemonic
    */
    void setMnemonicFromText(const QString &mnemonic);

    /*!
     \brief

     \fn iconName
     \return QString
    */
    QString iconName() const;
    /*!
     \brief

     \fn setIconName
     \param iconName
    */
    void setIconName(const QString &iconName);

    /*!
     \brief

     \fn iconSource
     \return QUrl
    */
    QUrl iconSource() const { return m_iconSource; }
    /*!
     \brief

     \fn setIconSource
     \param iconSource
    */
    void setIconSource(const QUrl &iconSource);

    /*!
     \brief

     \fn tooltip
     \return QString
    */
    QString tooltip() const { return m_tooltip; }
    /*!
     \brief

     \fn setTooltip
     \param tooltip
    */
    void setTooltip(const QString &tooltip);

    /*!
     \brief

     \fn isEnabled
     \return bool
    */
    bool isEnabled() const { return m_enabled; }
    /*!
     \brief

     \fn setEnabled
     \param e
    */
    void setEnabled(bool e);

    /*!
     \brief

     \fn icon
     \return QIcon
    */
    QIcon icon() const { return m_icon; }
    /*!
     \brief

     \fn iconVariant
     \return QVariant
    */
    QVariant iconVariant() const { return QVariant(m_icon); }
    /*!
     \brief

     \fn setIcon
     \param icon
    */
    void setIcon(QIcon icon) { m_icon = icon; emit iconChanged(); }

    /*!
     \brief

     \fn event
     \param e
     \return bool
    */
    bool event(QEvent *e);


public Q_SLOTS:
    /*!
     \brief

     \fn trigger
    */
    void trigger();

Q_SIGNALS:
    /*!
     \brief

     \fn triggered
    */
    void triggered();
    /*!
     \brief

     \fn toggled
     \param checked
    */
    void toggled(bool checked);

    /*!
     \brief

     \fn textChanged
    */
    void textChanged();
    /*!
     \brief

     \fn shortcutChanged
     \param shortcut
    */
    void shortcutChanged(QString shortcut);
    /*!
     \brief

     \fn keyShortcutChanged
     \param keyShortcut
    */
    void keyShortcutChanged(Qt::Key keyShortcut);

    /*!
     \brief

     \fn iconChanged
    */
    void iconChanged();
    /*!
     \brief

     \fn iconNameChanged
    */
    void iconNameChanged();
    /*!
     \brief

     \fn iconSourceChanged
    */
    void iconSourceChanged();
    /*!
     \brief

     \fn tooltipChanged
     \param arg
    */
    void tooltipChanged(QString arg);
    /*!
     \brief

     \fn enabledChanged
    */
    void enabledChanged();

protected:
    /*!
     \brief

     \fn setKeySequence
     \param sequence
    */
    void setKeySequence(const QKeySequence &sequence);

private:
    QString m_text; /*!< TODO */
    QUrl m_iconSource; /*!< TODO */
    QString m_iconName; /*!< TODO */
    QIcon m_icon; /*!< TODO */
    bool m_enabled; /*!< TODO */
    QKeySequence m_shortcut; /*!< TODO */
    QKeySequence m_mnemonic; /*!< TODO */
    QString m_tooltip; /*!< TODO */
};

#endif // QQQuickAction_H
