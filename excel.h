#ifndef EXCEL_H
#define EXCEL_H

#include <QObject>
#include <QTreeView>
#include <QStringList>
#include <QSqlDatabase>
#include"exportexcel.h"

/*class EEO_Field
   {
   public:
       EEO_Field(const int ic, const QString &sf, const QString &st):
               iCol(ic),sFieldName(sf),sFieldType(st){}

       int     iCol;
       QString sFieldName;
       QString sFieldType;
   };
*/
class Export : public QObject
{
    Q_OBJECT
public:
    Export(const QString &filepath, const QString &sheettitle,
                QTreeView *treeview):excelFilePath(filepath),
                sheetName(sheettitle), treeView(treeview){}

    ~Export() {QSqlDatabase::removeDatabase("excelexport");}

public:
void setOutputFilePath(const QString &spath) {excelFilePath = spath;}
void setOutputSheetTitle(const QString &ssheet) {sheetName = ssheet;}
void setTableView(QTreeView *treeview) {treeView = treeview;}

void addField(const int iCol, const QString &fieldname, const QString &fieldtype)
   {fieldList << new EEO_Field(iCol, fieldname, fieldtype);}

void removeAllFields()
   {while (!fieldList.isEmpty()) delete fieldList.takeFirst();}

int export2Excel();

signals:
void exportedRowCount(int row);

private:
QString excelFilePath;
QString sheetName;
QTreeView *treeView;
QList<EEO_Field *> fieldList;
};

#endif // EXCEL_H
