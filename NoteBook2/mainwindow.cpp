#include "mainwindow.h"
#include "ui_mainwindow.h"



NoteBook::NoteBook() :QMainWindow ()

{
    NoteBook::Create_Action();        //create action button
    NoteBook::Connect();             //signals and slots
    NoteBook::Create_Menu();       // create window menu
    NoteBook::Hot_Key();           //create hot_key


    statusBar()->showMessage("Hello!",4000);


    setWindowTitle(tr("New document")); //Title main window

}

void NoteBook::Connect()            //signals and slots
{
    connect(action_Open, SIGNAL(triggered()), this, SLOT(Open_File()));
    connect(action_Save_As, SIGNAL(triggered()), this, SLOT(Save_File_As()));
    connect(action_exit, SIGNAL(triggered()), qApp, SLOT(quit()));
    connect(action_search, SIGNAL(triggered()), this, SLOT(onSearchText()));
    connect(action_save_file, SIGNAL(triggered()), this, SLOT(Save_File()));
    connect(action_create_file, SIGNAL(triggered()), this, SLOT(Create_File()));
    connect(action_select_all,SIGNAL(triggered()),this,SLOT(Copy_all()));
    connect(action_about,SIGNAL(triggered()),this,SLOT(Open_Information));
    connect(text_Edit,SIGNAL(textChanged()),this,SLOT(Text_Edit_Change_Find()));
    connect(action_word_background,SIGNAL(triggered),this,SLOT(Word_background()));




}
void NoteBook::Open_Information()
{
}

void NoteBook::Hot_Key()
{

    action_Open->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));                //HOT KEY
    action_create_file->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_N));
    action_save_file->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    action_search->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_F));
    action_exit->setShortcut(QKeySequence(Qt::ALT+Qt::Key_F4));
    action_select_all->setShortcut(QKeySequence(Qt::ALT+Qt::Key_A ));
    action_word_background->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_B));

}

void NoteBook::Text_Changed_Find(QString str)// check if there are characters in lineEdit
{

    button_find->setEnabled(!str.isEmpty());

}

void NoteBook::Text_Edit_Change_Find()// check if there are characters in textEdit
{

    action_search->setEnabled(!text_Edit->document()->isEmpty());

}

void NoteBook::Copy_all()
{
    text_Edit->selectAll();

}
void NoteBook::onSearchText()
{

    label_find = new QLabel("Find word");
    button_find = new QPushButton("Find");
    dialog_find = new QDialog();
    layout_find = new QHBoxLayout();
    line_edit_find = new QLineEdit;

    button_find->setEnabled(false);
    button_close = new QPushButton("Close");

    layout_find->addWidget(label_find);
    layout_find->addWidget(line_edit_find);
    layout_find->addWidget(button_find);
    layout_find->addWidget(button_close);

    dialog_find->setLayout(layout_find);
    dialog_find->setWindowTitle("Find words");
    dialog_find->show();



    QObject::connect(line_edit_find,SIGNAL(textChanged(QString)),this,SLOT(Text_Changed_Find(QString)));
    QObject::connect(button_find, SIGNAL(clicked()),this,SLOT(Search_word()));
    QObject::connect(button_close, SIGNAL(clicked()),this,SLOT(Back_Color_Word()));



}
void NoteBook::Back_Color_Word()    //FUNCTION FOR DELETE BACKGROUND COLOR WORD
{

    QList<QTextEdit::ExtraSelection> clear;
    text_Edit->setExtraSelections(clear);
    dialog_find->close();

}

void NoteBook::Search_word()            //FUNCTION WHICH YOUR WORD IN TEXT
{

    QList<QTextEdit::ExtraSelection> sel;
    text_Edit->moveCursor(QTextCursor::Start);
    QString s  =line_edit_find->text();
    while(text_Edit->find(s))
    {
        QTextEdit::ExtraSelection extra;
        extra.format.setBackground(QColor(Qt::yellow).lighter(150)); //colors the background
        extra.cursor = text_Edit->textCursor();
        sel.append(extra);
    }

    text_Edit->setExtraSelections(sel);
    text_Edit->moveCursor(QTextCursor::End);

}

void NoteBook::Create_Action()           //INITIALIZATION ACTION
{
    action_Open = new QAction(tr("&Open"));
    action_Save_As = new QAction(tr("&Save as"));
    action_save_file = new QAction(tr("&Save"));
    action_exit = new QAction(tr("&Exit"));
    action_search = new QAction(tr("&Find"));
    action_back = new QAction(tr("Back"));
    action_create_file = new QAction("&New file");
    action_about = new QAction(tr("&Information"));
    action_select_all = new QAction(tr("Select all"));
    action_word_background = new QAction(tr("Color"));




    text_Edit = new QTextEdit();
    nameFile = new QString();

    setCentralWidget(text_Edit);             //setting location in window

}

void NoteBook::Create_Menu()    //CREATE MENU BAR
{
    menu_File= menuBar()->addMenu(tr("&File"));
    menu_File->addAction(action_create_file);
    menu_File->addAction(action_Open);
    menu_File->addAction(action_save_file);
    menu_File->addAction(action_Save_As);
    menu_File->addSeparator();
    menu_File->addAction(action_exit);

    menu_Correction = menuBar()->addMenu(tr("Edit"));
    menu_Correction->addAction(action_back);
    menu_Correction->addAction(action_search);
    menu_Correction->addAction(action_word_background);
    menu_Correction->addSeparator();
    menu_Correction->addAction(action_select_all);

    action_search->setEnabled(false);

    menu_help = new QMenu();
    menu_help = menuBar()->addMenu("&Help");
    menu_help->addAction(action_about);


}

void NoteBook::Open_File()      //YOUR FILE OPEN
{
       *nameFile = QFileDialog::getOpenFileName(this,tr("Open file"),"","*.txt");  //file mask
       curFile = *nameFile;
       setWindowTitle(*nameFile);

       if (*nameFile != "")//check namefile
       {
           QFile file(*nameFile);
           if (!file.open(QIODevice::ReadOnly))//check open file
           {
                QMessageBox::warning(this,"Warning!","File not open!");//If not open then warning
           }
           else
           {
           QTextStream TextIn(&file);//read file
           text_Edit->setText(TextIn.readAll());//add text file to text_edit
           file.close(); //close file

           }
       }

}

bool NoteBook::Maybe_Save_File()        //offer save your file
{
    if(text_Edit->document()->isModified())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this,"Save change?","Content will be lost!",QMessageBox::Save|QMessageBox::Cancel|QMessageBox::Discard);

        if(ret==QMessageBox::Save)
        {

           Save_File_As();
        }

        if(ret==QMessageBox::Cancel)
        {
            return false;
        }
        if(ret==QMessageBox::Discard)
        {
            return true;
        }


    }
}

void NoteBook::Save_File_As()
{
    *nameFile = QFileDialog::getSaveFileName(this,"Save_File","New document","*.txt");
    QFile file(*nameFile);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this,"Warning","File is't save!");
        statusBar()->showMessage("File is't save!",5000);
    }
    else
    {
        QTextStream out(&file);
        out<<text_Edit->toPlainText();
        out.flush();
        file.close();
        statusBar()->showMessage("File save!",4000);
    }
}

void NoteBook::closeEvent(QCloseEvent *event)
{
    if(!(text_Edit->document()->isModified()))        //check change text
    {
        qApp->closeAllWindows();//close window
    }

   else if(text_Edit->document()->isModified())
    {
        QMessageBox::StandardButton ret;
        ret = QMessageBox::warning(this,"Save change?","Content will be lost!",QMessageBox::Save|QMessageBox::Cancel|QMessageBox::Discard);

        if(ret==QMessageBox::Save)
        {

           Save_File_As();
        }

        if(ret==QMessageBox::Cancel)
        {
            event->ignore();
        }
        if(ret==QMessageBox::Discard)
        {
            qApp->closeAllWindows();
        }


    }

}

void NoteBook::Create_File()
{
    if(Maybe_Save_File())           //if file was n't no save
    {
    text_Edit->clear();
    setWindowTitle("New document");
    statusBar()->showMessage("New document!",3500);
    }
}

bool NoteBook::Save_File()
{
    if(curFile.isEmpty())           //if puth file empty
    {
        Save_File_As();         //function call save As
    }
    if (*nameFile != "")        //name file checks
    {
        QFile file(*nameFile);

        if (!file.open(QIODevice::WriteOnly))   //  check file open
        {
            QMessageBox::warning(this,"Warning","File not open!");
            return false;
        }

        else
        {
            QTextStream TextOut(&file);
            TextOut << text_Edit->toPlainText();
            TextOut.flush();            //write from buffer to file
            file.close();               //close file
            statusBar()->showMessage("File save!",2500);
            return true;

        }
    }

}
