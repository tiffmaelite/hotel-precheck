#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickWindow>
#include <QQmlFile>
#include "SH_ExtendedQQmlAction.h"
/*#include "../../src/gui/kernel/qguiapplication_p.h"*/

/*!
 \details

 \fn SH_QQQuickAction::QQQuickAction

*/
SH_ExtendedQQmlAction::SH_ExtendedQQmlAction(QObject *parent)
    : QObject(parent)
    , m_enabled(true)
{
}

/*!
 \details

 \fn SH_QQQuickAction::~QQQuickAction
*/
SH_ExtendedQQmlAction::~SH_ExtendedQQmlAction()
{
    setKeyShortcut(Qt::Key_unknown);
    setMnemonicFromText(QString());
}

/*!
 \details

 \fn SH_QQQuickAction::setText
*/
void SH_ExtendedQQmlAction::setText(const QString &text)
{
    if (text == m_text)
        return;
    m_text = text;
    setMnemonicFromText(m_text);
    emit textChanged();
}

/*!
 \details

 \fn SH_qShortcutContextMatcher
*/
bool qShortcutContextMatcher(QObject *o, Qt::ShortcutContext context)
{
    switch (context) {
    case Qt::ApplicationShortcut:
        return true;
    case Qt::WindowShortcut: {
        QObject *w = o;
        while (w && !w->isWindowType()) {
            w = w->parent();
            if (QQuickItem * item = qobject_cast<QQuickItem*>(w))
                w = item->window();
        }
        if (w && w == QGuiApplication::focusWindow())
            return true;
    }
    case Qt::WidgetShortcut:
    case Qt::WidgetWithChildrenShortcut:
        break;
    }

    return false;
}

/*!
 \details

 \fn SH_QQQuickAction::setKeySequence
*/
void SH_ExtendedQQmlAction::setKeySequence(const QKeySequence &sequence) {
    if (sequence == m_shortcut)
        return;

    /*if (!m_shortcut.isEmpty())
        QGuiApplicationPrivate::instance()->shortcutMap.removeShortcut(0, this, m_shortcut);
    */
    m_shortcut = sequence;

    if (!m_shortcut.isEmpty()) {
        Qt::ShortcutContext context = Qt::WindowShortcut;
        /*QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_shortcut, context, qShortcutContextMatcher);*/
    }
    emit shortcutChanged(shortcut());
}

/*!
 \details

 \fn SH_QQQuickAction::setKeyShortcut
*/
void SH_ExtendedQQmlAction::setKeyShortcut(const Qt::Key &shortcut)
{
    setKeySequence(QKeySequence(shortcut));
}

/*!
 \details

 \fn SH_QQQuickAction::shortcut
*/
QString SH_ExtendedQQmlAction::shortcut() const
{
    return m_shortcut.toString(QKeySequence::NativeText);
}

/*!
 \details

 \fn SH_QQQuickAction::setShortcut
*/
void SH_ExtendedQQmlAction::setShortcut(const QString &arg)
{
    if(shortcut() == arg)
        return;

    setKeySequence(QKeySequence::fromString(arg));
}

/*!
 \details

 \fn SH_QQQuickAction::setMnemonicFromText
*/
void SH_ExtendedQQmlAction::setMnemonicFromText(const QString &text)
{
    QKeySequence sequence = QKeySequence::mnemonic(text);
    if (m_mnemonic == sequence)
        return;

    /*if (!m_mnemonic.isEmpty())
        QGuiApplicationPrivate::instance()->shortcutMap.removeShortcut(0, this, m_mnemonic);
    */
    m_mnemonic = sequence;

    if (!m_mnemonic.isEmpty()) {
        Qt::ShortcutContext context = Qt::WindowShortcut;
        /*QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_mnemonic, context, qShortcutContextMatcher);*/
    }
}

/*!
 \details

 \fn SH_QQQuickAction::setIconSource
*/
void SH_ExtendedQQmlAction::setIconSource(const QUrl &iconSource)
{
    if (iconSource == m_iconSource)
        return;

    m_iconSource = iconSource;
    if (m_iconName.isEmpty() || m_icon.isNull()) {
        QString fileString = QQmlFile::urlToLocalFileOrQrc(iconSource);
        m_icon = QIcon(fileString);

        emit iconChanged();
    }
    emit iconSourceChanged();
}

/*!
 \details

 \fn SH_QQQuickAction::iconName
*/
QString SH_ExtendedQQmlAction::iconName() const
{
    return m_iconName;
}

/*!
 \details

 \fn SH_QQQuickAction::setIconName
*/
void SH_ExtendedQQmlAction::setIconName(const QString &iconName)
{
    if (iconName == m_iconName)
        return;
    m_iconName = iconName;
    m_icon = QIcon::fromTheme(m_iconName, QIcon(QQmlFile::urlToLocalFileOrQrc(m_iconSource)));
    emit iconNameChanged();
    emit iconChanged();
}

/*!
 \details

 \fn SH_QQQuickAction::setTooltip
*/
void SH_ExtendedQQmlAction::setTooltip(const QString &arg)
{
    if (m_tooltip != arg) {
        m_tooltip = arg;
        emit tooltipChanged(arg);
    }
}

/*!
 \details

 \fn SH_QQQuickAction::setEnabled
*/
void SH_ExtendedQQmlAction::setEnabled(bool e)
{
    if (e == m_enabled)
        return;
    m_enabled = e;
    emit enabledChanged();
}



/*!
 \details

 \fn SH_QQQuickAction::event
 \param e
*/
bool SH_ExtendedQQmlAction::event(QEvent *e)
{
    if (!m_enabled)
        return false;

    if (e->type() != QEvent::Shortcut)
        return false;

    QShortcutEvent *se = static_cast<QShortcutEvent *>(e);

    Q_ASSERT_X(se->key() == m_shortcut || se->key() == m_mnemonic,
               "QQQuickAction::event",
               "Received shortcut event from incorrect shortcut");
    if (se->isAmbiguous()) {
        qWarning("QQQuickAction::event: Ambiguous shortcut overload: %s", se->key().toString(QKeySequence::NativeText).toLatin1().constData());
        return false;
    }

    trigger();

    return true;
}

/*!
 \details

 \fn SH_QQQuickAction::trigger
*/
void SH_ExtendedQQmlAction::trigger()
{
    if (!m_enabled)
        return;
    emit triggered();
}
