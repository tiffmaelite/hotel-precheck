#ifndef FIXEDGRIDLAYOUT_H
#define FIXEDGRIDLAYOUT_H

#include <QtWidgets/QGridLayout>
#include <QPoint>


/*!
 \brief

*/
class FixedGridLayout : public QGridLayout
{
    Q_OBJECT
public:

/*!
 \brief

 \param rows
 \param columns
 \param parent
*/
    FixedGridLayout(int rows,int columns, QWidget *parent = 0);

    /*!
     \brief

     \param widget
    */
    void addWidget(QWidget *widget);

    /*!
     \brief

     \param widget
     \param row
     \param column
     \param rowSpan
     \param columnSpan
     \param align
    */
    void addWidget(QWidget *widget, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align);

    /*!
     \brief

     \param index
     \param widget
    */
    void insertWidget(int index, QWidget *widget);

    /*!
     \brief

     \param layout
    */
    void addLayout(QLayout *layout);

    /*!
     \brief

     \param layout
     \param row
     \param column
     \param rowSpan
     \param columnSpan
     \param align
    */
    void addLayout(QLayout *layout, int row, int column, int rowSpan, int columnSpan, Qt::Alignment align);

    /*!
     \brief

     \param index
     \param layout
    */
    void insertLayout(int index, QLayout *layout);

    /*!
     \brief

     \return int
    */
    int getRowsCount();

    /*!
     \brief

     \return int
    */
    int getColumnsCount();

signals:
    
public slots:

protected:
    int rowsCount; /*!< TODO */
    int columnsCount; /*!< TODO */
    int currentRow; /*!< TODO */
    int currentColumn; /*!< TODO */

private:

    /*!
     \brief

     \param col
     \param row
     \return QPoint
    */
    QPoint* computePosition(int col, int row);
};

#endif // FIXEDGRIDLAYOUT_H
