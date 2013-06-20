import QtQuick 2.1
import QtQuick.Controls 1.0
import QtQuick.Controls.Styles 1.0
import PreCheck 1.0

SH_Keyboard {
    property string keyString:""
    id: keyboard
    signal loaded
    model : ListModel {
        id:keyList
        Component.onCompleted: {
            var keys = keyboard.keyString.split(" ");
            var size = keys.length
            for(var i = 0; i < size; i++) {
                var symbol = keys[i];
                keyList.append( {"KEY":symbol,"ID":symbol} );
            }
            keyboard.loaded();
        }
    }
}
