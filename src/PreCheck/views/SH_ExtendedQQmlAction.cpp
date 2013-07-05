#include <QtGui/QGuiApplication>
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickWindow>
#include <QQmlFile>
#include "SH_ExtendedQQmlAction.h"
/*namespace SimplHotel
{*/
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::SH_ExtendedQQmlAction
*/
SH_ExtendedQQmlAction::SH_ExtendedQQmlAction(QObject *parent)
    : QObject(parent), m_enabled(true), kShort(Qt::Key_unknown)
{
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::~SH_ExtendedQQmlAction
*/
SH_ExtendedQQmlAction::~SH_ExtendedQQmlAction()
{
    setKeyShortcut(Qt::Key_unknown);
    setMnemonicFromText(QString());
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setText
*/
void SH_ExtendedQQmlAction::setText(const QString &text)
{
    if (text != m_text) {
        m_text = text;
        setMnemonicFromText(m_text);
        emit textChanged();
    }
}
/*!
 \details \~french
 \fn qShortcutContextMatcher
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
 \details \~french
 \fn SH_ExtendedQQmlAction::setKeySequence
*/
void SH_ExtendedQQmlAction::setKeySequence(const QKeySequence &sequence) {
    if (sequence != m_shortcut) {
        /*if (!m_shortcut.isEmpty()) {
            QGuiApplicationPrivate::instance()->shortcutMap.removeShortcut(0, this, m_shortcut);
        }*/
        m_shortcut = sequence;

        /*if (!m_shortcut.isEmpty()) {
            Qt::ShortcutContext context = Qt::WindowShortcut;
            QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_shortcut, context, qShortcutContextMatcher);
        }*/
        emit shortcutChanged(shortcut());
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setKeyShortcut
*/
void SH_ExtendedQQmlAction::setKeyShortcut(const Qt::Key &shortcut)
{
    kShort = shortcut;
    setKeySequence(QKeySequence(shortcut));
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::kShortcut
*/
Qt::Key SH_ExtendedQQmlAction::kShortcut()
{
    return kShort;
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::shortcut
*/
QString SH_ExtendedQQmlAction::shortcut() const
{
    return m_shortcut.toString(QKeySequence::NativeText);
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setShortcut
*/
void SH_ExtendedQQmlAction::setShortcut(const QString &arg)
{
    if(shortcut() != arg) {
        setKeySequence(QKeySequence::fromString(arg));
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setMnemonicFromText
*/
void SH_ExtendedQQmlAction::setMnemonicFromText(const QString &text)
{
    QKeySequence sequence = QKeySequence::mnemonic(text);
    if (m_mnemonic != sequence) {
        /*if (!m_mnemonic.isEmpty()) {
            QGuiApplicationPrivate::instance()->shortcutMap.removeShortcut(0, this, m_mnemonic);
        }*/
        m_mnemonic = sequence;

        /*if (!m_mnemonic.isEmpty()) {
            Qt::ShortcutContext context = Qt::WindowShortcut;
            QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_mnemonic, context, qShortcutContextMatcher);
        }*/
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setIconSource
*/
void SH_ExtendedQQmlAction::setIconSource(const QUrl &iconSource)
{
    if (iconSource != m_iconSource) {
        m_iconSource = iconSource;
        if (m_iconName.isEmpty() || m_icon.isNull()) {
            QString fileString = QQmlFile::urlToLocalFileOrQrc(iconSource);
            m_icon = QIcon(fileString);
            emit iconChanged();
        }
        emit iconSourceChanged();
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::iconName
*/
QString SH_ExtendedQQmlAction::iconName() const
{
    return m_iconName;
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setIconName
*/
void SH_ExtendedQQmlAction::setIconName(const QString &iconName)
{
    if (iconName != m_iconName) {
        m_iconName = iconName;
        m_icon = QIcon::fromTheme(m_iconName, QIcon(QQmlFile::urlToLocalFileOrQrc(m_iconSource)));
        emit iconNameChanged();
        emit iconChanged();
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setTooltip
*/
void SH_ExtendedQQmlAction::setTooltip(const QString &arg)
{
    if (m_tooltip != arg) {
        m_tooltip = arg;
        emit tooltipChanged(arg);
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::setEnabled
*/
void SH_ExtendedQQmlAction::setEnabled(bool e)
{
    if (e != m_enabled) {
        m_enabled = e;
        emit enabledChanged();
    }
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::event
 \param e
*/
bool SH_ExtendedQQmlAction::event(QEvent *e)
{
    if (!m_enabled) {
        e->ignore();
        return false;
    }
    if (e->type() != QEvent::Shortcut) {
        e->ignore();
        return false;
    }
    QShortcutEvent *se = static_cast<QShortcutEvent *>(e);
    Q_ASSERT_X(se->key() == m_shortcut || se->key() == m_mnemonic,
               "SH_ExtendedQQmlAction::event",
               "Received shortcut event from incorrect shortcut");
    if (se->isAmbiguous()) {
        qWarning("SH_ExtendedQQmlAction::event: Ambiguous shortcut overload: %s", se->key().toString(QKeySequence::NativeText).toLatin1().constData());
        e->ignore();
        return false;
    }
    trigger();
    e->accept();
    return true;
}
/*!
 \details \~french
 \fn SH_ExtendedQQmlAction::trigger
*/
void SH_ExtendedQQmlAction::trigger()
{
    if (!m_enabled) {
        return;
    }
    emit triggered();
}
/*}*/
