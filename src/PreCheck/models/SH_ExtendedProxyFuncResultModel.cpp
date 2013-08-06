#include "SH_ExtendedProxyFuncResultModel.h"
#include "SH_MessageManager.h"

SH_ExtendedProxyFuncResultModel::SH_ExtendedProxyFuncResultModel(QObject *parent) :
    SH_ExtendedProxyModel(parent)
{
    this->model = new SH_SqlFuncResultModel(parent);
    this->setSourceModel(this->model);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::fetch
*/
bool SH_ExtendedProxyFuncResultModel::fetch()
{
    SH_MessageManager::debugMessage("entering proxy function result fetch method");
    this->m_fetched = this->model->fetch();
    this->m_roles= this->model->roleNames();
    this->setSourceModel(this->model);
    return this->m_fetched;
}

void SH_ExtendedProxyFuncResultModel::setSourceModel(QAbstractItemModel* sourceModel) {
    this->model = qobject_cast<SH_SqlFuncResultModel *>(sourceModel);
    int nbFields = this->model->fieldsCount();
    for(int i = 0; i < nbFields; i++) {
        this->modelFields.append(this->model->field(i));
    }
    QSortFilterProxyModel::setSourceModel(this->model);
}
