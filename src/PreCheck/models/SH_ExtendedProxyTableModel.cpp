#include "SH_ExtendedProxyTableModel.h"
#include "SH_MessageManager.h"

SH_ExtendedProxyTableModel::SH_ExtendedProxyTableModel(QObject *parent) :
    SH_ExtendedProxyModel(parent)
{
    this->model=new SH_SqlDataModel(parent);
    this->setSourceModel(this->model);
    this->fetch();
}

bool SH_ExtendedProxyTableModel::fetch() {
    SH_MessageManager::debugMessage("entering proxy fetch method");
    this->m_fetched = this->model->fetch();
    if (this->m_fetched)
    {
        this->m_roles= this->model->roleNames();
        //emit emptinessChanged();
        this->setSourceModel(this->model);
        this->fillModel();
        foreach(SH_SqlDataFields* field, this->modelFields) {
            int fieldIndex = this->modelFields.indexOf(field);
            if(this->headerData(fieldIndex, Qt::Horizontal).toString() == field->text()) {
                this->addHiddenColumn(fieldIndex);
            }
        }
    }
    return this->m_fetched;
}

void SH_ExtendedProxyTableModel::setSourceModel(QAbstractItemModel* sourceModel) {
    this->model = qobject_cast<SH_SqlDataModel *>(sourceModel);
    if(this->m_fetched) {
        int nbFields = this->model->fieldsCount();
        for(int i = 0; i < nbFields; i++) {
            this->modelFields.append(this->model->field(i));
        }
    }
    QSortFilterProxyModel::setSourceModel(this->model);
}
