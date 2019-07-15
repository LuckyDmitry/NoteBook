#ifndef NOTEBOOK_H
#define NOTEBOOK_Hd

#include <QMainWindow>
#include<QtWidgets>
#include <QtGui>


class NoteBook : public QMainWindow
{
    Q_OBJECT


public:
     NoteBook();


private slots:

     void Save_File_As();
     void Open_File();
     bool Save_File();
     void Create_File();
     bool Maybe_Save_File();
     void closeEvent(QCloseEvent *event);
     void Search_word();
     void Text_Changed_Find(QString str);
     void onSearchText();
     void Text_Edit_Change_Find();
     void Back_Color_Word();
     void Copy_all();
     void Open_Information();

private:

    void Create_Menu();
    void Create_Action();
    void Connect();
    void Hot_Key();



    QTextEdit *text_Edit;
    QLineEdit *line_Edit;
    QAction *action_Save_As;
    QAction *action_Open;
    QAction *action_save_file;
    QAction *action_create_file;
    QAction *action_exit;
    QAction *action_search;
    QAction *action_about;
    QAction *action_back;
    QAction *action_select_all;
    QAction *action_word_background;

    QFile *file = new QFile;

    QMenu *menu_File;
    QMenu *menu_Correction;
    QMenu *menu_help;
    QMessageBox msBox;
    QMessageBox *msAbout;

    QString *nameFile = new QString();
    QString curFile;

    QPushButton *button_find;
    QDialog *dialog_find;
    QHBoxLayout *layout_find;
    QLabel *label_find;
    QLineEdit *line_edit_find;
    QPushButton *button_close;


};



#endif // NOTEBOOK_H
