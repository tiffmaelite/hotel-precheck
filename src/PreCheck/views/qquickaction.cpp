#include "qquickaction.h"

#include <QtGui/QGuiApplication>
//#include "../../src/gui/kernel/qguiapplication_p.h"
#include <QtQuick/QQuickItem>
#include <QtQuick/QQuickWindow>
#include <QQmlFile>

QQQuickAction::QQQuickAction(QObject *parent)
    : QObject(parent)
    , m_enabled(true)
{
}

QQQuickAction::~QQQuickAction()
{
    setKeyShortcut(Qt::Key_unknown);
    setMnemonicFromText(QString());
}

void QQQuickAction::setText(const QString &text)
{
    if (text == m_text)
        return;
    m_text = text;
    setMnemonicFromText(m_text);
    emit textChanged();
}

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

void QQQuickAction::setKeySequence(const QKeySequence &sequence) {
    if (sequence == m_shortcut)
        return;

    /*if (!m_shortcut.isEmpty())
        QGuiApplicationPrivate::instance()->shortcutMap.removeShortcut(0, this, m_shortcut);
    */
    m_shortcut = sequence;

    if (!m_shortcut.isEmpty()) {
        Qt::ShortcutContext context = Qt::WindowShortcut;
        //QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_shortcut, context, qShortcutContextMatcher);
    }
    emit shortcutChanged(shortcut());
}

void QQQuickAction::setKeyShortcut(const Qt::Key &shortcut)
{
    setKeySequence(QKeySequence(shortcut));
}

QString QQQuickAction::shortcut() const
{
    return m_shortcut.toString(QKeySequence::NativeText);
}

void QQQuickAction::setShortcut(const QString &arg)
{
    if(shortcut() == arg)
        return;

    setKeySequence(QKeySequence::fromString(arg));
}

void QQQuickAction::setMnemonicFromText(const QString &text)
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
        //QGuiApplicationPrivate::instance()->shortcutMap.addShortcut(this, m_mnemonic, context, qShortcutContextMatcher);
    }
}

void QQQuickAction::setIconSource(const QUrl &iconSource)
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

QString QQQuickAction::iconName() const
{
    return m_iconName;
}

void QQQuickAction::setIconName(const QString &iconName)
{
    if (iconName == m_iconName)
        return;
    m_iconName = iconName;
    m_icon = QIcon::fromTheme(m_iconName, QIcon(QQmlFile::urlToLocalFileOrQrc(m_iconSource)));
    emit iconNameChanged();
    emit iconChanged();
}

void QQQuickAction::setTooltip(const QString &arg)
{
    if (m_tooltip != arg) {
        m_tooltip = arg;
        emit tooltipChanged(arg);
    }
}

void QQQuickAction::setEnabled(bool e)
{
    if (e == m_enabled)
        return;
    m_enabled = e;
    emit enabledChanged();
}



bool QQQuickAction::event(QEvent *e)
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

void QQQuickAction::trigger()
{
    if (!m_enabled)
        return;
    emit triggered();
}
