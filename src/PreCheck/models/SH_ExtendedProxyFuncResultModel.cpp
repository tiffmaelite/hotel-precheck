#include "SH_ExtendedProxyFuncResultModel.h"
#include "SH_MessageManager.h"

SH_ExtendedProxyFuncResultModel::SH_ExtendedProxyFuncResultModel(QObject *parent) :
    SH_ExtendedProxyModel(parent)
{
    this->model = new SH_SqlFuncResultModel(parent);
}

/*!
 \details \~french

 \fn SH_ExtendedProxyModel::fetch
*/
bool SH_ExtendedProxyFuncResultModel::fetch()
{
    //this->m_fetching.tryLock(100);
    SH_MessageManager::debugMessage("entering proxy function result fetch method");
    if(!this->m_fetched) {
    this->m_fetched = this->model->fetch();
    }
    if(this->m_fetched) {
        this->m_count = this->model->rowCount();
        this->m_roles= this->model->roleNames();
        //emit emptinessChanged();
    }
    this->setSourceModel(this->model);
    //this->m_fetching.unlock();
    return this->m_fetched;
}

void SH_ExtendedProxyFuncResultModel::setSourceModel(QAbstractItemModel* sourceModel) {
    this->model = qobject_cast<SH_SqlFuncResultModel *>(sourceModel);
    if(this->m_fetched ) {
        int nbFields = this->model->fieldsCount();
        for(int i = 0; i < nbFields; i++) {
            this->modelFields.append(this->model->field(i));
        }
    }
    QSortFilterProxyModel::setSourceModel(this->model);
}
