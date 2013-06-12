#include "views/messageManager.h"
#include "fileHandler.h"
/**
 *File handles class
 *Manages the files used in the database
 */
/**
 *removes a FILE
 *@param fileName is a string variable
 *@param ret is a boolean
 *@return the statement whether the removal was succesful or not
 */
bool FileHandler::removeFile(QString fileName)
{
    bool ret = false;
    ret = QFile::remove(fileName);
    if(ret == false)
    {
        MessageManager::errorMessage(fileNotRemovedStr);

    } else {
        //QMessageBox::information(0,fileHandlerstr,fileRemovedStr);
    }
    return ret;
}
/**
 *checks if a file exist
 *@param fileName is a string variable
 *@param ret is a boolean
 *@return the statement whether file exists or not
 */
bool FileHandler::fileExists(QString fileName)
{
    bool ret= false;
    ret = QFile::exists(fileName);
    if(ret == false)
    {
        MessageManager::errorMessage(fileNotExistStr);
    }
    return ret;
}
