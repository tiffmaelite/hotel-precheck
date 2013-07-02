import QtQuick 2.1
import QtQuick.Window 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import QtQuick.Layouts 1.0
import PreCheck 1.0

SH_ContentView {
    property variant activeFilterIndicatorIndexes
    /*!
          \fn
          \param
          \return

          \brief
          \details
          */
    function removeFilterIndex(index) {
        if(!dataView.activeFilterIndicatorIndexes) {
            dataView.activeFilterIndicatorIndexes = [];
        }
        var tmp = dataView.activeFilterIndicatorIndexes
        var pos = tmp.indexOf(index);
        tmp.splice(pos, 1);
        return tmp;
    }
    /*!
          \fn
          \param
          \return

          \brief
          \details
          */
    function addFilterIndex(index) {
        if(!dataView.activeFilterIndicatorIndexes) {
            dataView.activeFilterIndicatorIndexes = [];
        }
        var tmp = dataView.activeFilterIndicatorIndexes
        tmp.push(index);
        return tmp;
    }
    /*!
          \fn
          \param
          \return

          \brief
          \details
          */
    function sort(index) {
        repeater.model.setSortKeyKolumn(index);
    }
    /*!
          \fn
          \param
          \return

          \brief
          \details
          */
    function filter(index, remove) {
        if(remove) {
            dataView.activeFilterIndicatorIndexes = dataView.addFilterIndex(index);
            repeater.model.addHiddenColumn(index);
        } else {
            dataView.activeFilterIndicatorIndexes = dataView.removeFilterIndex(index);
            var nbFilters = dataView.activeFilterIndicatorIndexes.length;
            repeater.model.resetColumnsList(index);
            for(var i = 0; i < nbFilters; i++) {
                repeater.model.addHiddenColumn(dataView.activeFilterIndicatorIndexes.at(i));
            }
        }
    }

}
