#ifndef QQQuickAction_H
#define QQQuickAction_H
#include <QtCore/QObject>
#include <QtCore/QUrl>
#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtGui/QKeySequence>
#include <QtCore/qpointer.h>
/*namespace SimplHotel
{*/
/*!
\brief \~french
 \class SH_QQQuickAction qquickaction.h "views/qquickaction.h"
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
	\brief \~french
	\fn QQQuickAction
	\param parent
	*/
	explicit SH_ExtendedQQmlAction(QObject *parent = 0);
	
/*!
	\brief \~french
	\fn ~QQQuickAction
	*/
	~SH_ExtendedQQmlAction();
	
/*!
	\brief \~french
	\fn text
	\return QString
	*/
	QString text() const { return m_text; }
	
/*!
	\brief \~french
	\fn setText
	\param text
	*/
	void setText(const QString &text);
	
/*!
	\brief \~french
	\fn shortcut
	\return QString
	*/
	QString shortcut() const;
	
/*!
	\brief \~french
	\fn setShortcut
	\param shortcut
	*/
	void setShortcut(const QString &shortcut);
	
/*!
	\brief \~french
	\fn keyShortcut
	\return QKeySequence
	*/
	QKeySequence keyShortcut() const { return m_shortcut; }
	
/*!
	\brief \~french
	\fn setKeyShortcut
	\param shortcut
	*/
	void setKeyShortcut(const Qt::Key &shortcut);
	
/*!
	\brief \~french
	\fn setMnemonicFromText
	\param mnemonic
	*/
	void setMnemonicFromText(const QString &mnemonic);
	
/*!
	\brief \~french
	\fn iconName
	\return QString
	*/
	QString iconName() const;
	
/*!
	\brief \~french
	\fn setIconName
	\param iconName
	*/
	void setIconName(const QString &iconName);
	
/*!
	\brief \~french
	\fn iconSource
	\return QUrl
	*/
	QUrl iconSource() const { return m_iconSource; }
	
/*!
	\brief \~french
	\fn setIconSource
	\param iconSource
	*/
	void setIconSource(const QUrl &iconSource);
	
/*!
	\brief \~french
	\fn tooltip
	\return QString
	*/
	QString tooltip() const { return m_tooltip; }
	
/*!
	\brief \~french
	\fn setTooltip
	\param tooltip
	*/
	void setTooltip(const QString &tooltip);
	
/*!
	\brief \~french
	\fn isEnabled
	\return bool
	*/
	bool isEnabled() const { return m_enabled; }
	
/*!
	\brief \~french
	\fn setEnabled
	\param e
	*/
	void setEnabled(bool e);
	
/*!
	\brief \~french
	\fn icon
	\return QIcon
	*/
	QIcon icon() const { return m_icon; }
	
/*!
	\brief \~french
	\fn iconVariant
	\return QVariant
	*/
	QVariant iconVariant() const { return QVariant(m_icon); }
	
/*!
	\brief \~french
	\fn setIcon
	\param icon
	*/
	void setIcon(QIcon icon) { m_icon = icon; emit iconChanged(); }
	
/*!
	\brief \~french
	\fn event
	\param e
	\return bool
	*/
	bool event(QEvent *e);
public Q_SLOTS:
	
/*!
	\brief \~french
	\fn trigger
	*/
	void trigger();
Q_SIGNALS:
	
/*!
	\brief \~french
	\fn triggered
	*/
	void triggered();
	
/*!
	\brief \~french
	\fn toggled
	\param checked
	*/
	void toggled(bool checked);
	
/*!
	\brief \~french
	\fn textChanged
	*/
	void textChanged();
	
/*!
	\brief \~french
	\fn shortcutChanged
	\param shortcut
	*/
	void shortcutChanged(QString shortcut);
	
/*!
	\brief \~french
	\fn keyShortcutChanged
	\param keyShortcut
	*/
	void keyShortcutChanged(Qt::Key keyShortcut);
	
/*!
	\brief \~french
	\fn iconChanged
	*/
	void iconChanged();
	
/*!
	\brief \~french
	\fn iconNameChanged
	*/
	void iconNameChanged();
	
/*!
	\brief \~french
	\fn iconSourceChanged
	*/
	void iconSourceChanged();
	
/*!
	\brief \~french
	\fn tooltipChanged
	\param arg
	*/
	void tooltipChanged(QString arg);
	
/*!
	\brief \~french
	\fn enabledChanged
	*/
	void enabledChanged();
protected:
	
/*!
	\brief \~french
	\fn setKeySequence
	\param sequence
	*/
	void setKeySequence(const QKeySequence &sequence);
private:
	
/*!
	*\brief \~french m_text
	*/
	QString m_text;
	
/*!
	*\brief \~french m_iconSource
	*/
	QUrl m_iconSource;
	
/*!
	*\brief \~french m_iconName
	*/
	QString m_iconName;
	
/*!
	*\brief \~french m_icon
	*/
	QIcon m_icon;
	
/*!
	*\brief \~french m_enabled
	*/
	bool m_enabled;
	
/*!
	*\brief \~french m_shortcut
	*/
	QKeySequence m_shortcut;
	
/*!
	*\brief \~french m_mnemonic
	*/
	QKeySequence m_mnemonic;
	
/*!
	*\brief \~french m_tooltip
	*/
	QString m_tooltip;
};
/*}*/
#endif /* QQQuickAction_H*/
