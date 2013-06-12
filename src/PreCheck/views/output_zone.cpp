#include "output_zone.h"
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>

OutputZone::OutputZone(QWidget *parent) :
    QFrame(parent)
{
    QPalette colors;
    colors.setColor(QPalette::Window, Qt::white);
    colors.setColor(QPalette::WindowText, Qt::gray);

    QLabel *output = new QLabel(this);
    output->setAutoFillBackground(true);
    output->setPalette(colors);

    output->setAlignment(Qt::AlignCenter);
    output->setText(QObject::tr("SORTIE"));
    QHBoxLayout *outputLayout = new QHBoxLayout(this);
    outputLayout->stretch(true);
    outputLayout->addWidget(output);
    this->setLayout(outputLayout);
    qWarning("hauteur de l'intérieur de l'output : %d, largeur de l'intérieur de l'output : %d", output->height(), output->width());
}
