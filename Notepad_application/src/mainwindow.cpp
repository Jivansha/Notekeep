#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
#include<QFile>
#include<QFileDialog>
#include<QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_triggered()
{
    file_path = "";
    ui->textEdit->setText("");
}


void MainWindow::on_actionOpen_triggered()
{
    QString file_name=QFileDialog::getOpenFileName(this,"Open File");

    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::ReadOnly | QFile :: Text)){
        QMessageBox::warning(this,"Open File","File can't be opened");
        return;
    }
    QTextStream in(&file);
    QString text= in.readAll();
    ui->textEdit->setText(text);
    file.close();
}

void MainWindow::on_actionSave_triggered()
{
    QFile file(file_path);
    if(!file.open(QFile::WriteOnly | QFile :: Text)){
        on_actionSave_As_triggered();
        return;
    }
    QTextStream out(&file);
    QString text= ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionSave_As_triggered()
{
    QString file_name=QFileDialog::getSaveFileName(this,"Save As");

    QFile file(file_name);
    file_path=file_name;
    if(!file.open(QFile::WriteOnly | QFile :: Text)){
        QMessageBox::warning(this,"Save As","File can't be Saved");
        return;
    }
    QTextStream out(&file);
    QString text= ui->textEdit->toPlainText();
    out<<text;
    file.flush();
    file.close();
}

void MainWindow::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void MainWindow::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void MainWindow::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redoAvailable(true);
    ui->textEdit->redo();
}

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undoAvailable(true);
    ui->textEdit->undo();
}

void MainWindow::on_actionAbout_Notepad_triggered()
{
    QString about_text;
    about_text="Notekeep Version : 1.0.1\n";
    about_text+="Date : 21st March, 2019\n";
    about_text+="About :\n";
    about_text+="This application is developed in C++.\n";
    about_text+="This application is under open source project development\n";
    about_text+="Copyright (c) 2019 Jivansha";
    QMessageBox::about(this,"About Notekeep",about_text);
}

void MainWindow::on_actionExit_2_triggered()
{

    QMessageBox:: StandardButton reply = QMessageBox :: question(this, "Quit","Quit application?",
                           QMessageBox::Yes | QMessageBox::No);
    if(reply==QMessageBox::Yes){
        QApplication::quit();
    }
    else{
        return;
    }
}

void MainWindow::on_actionLicense_triggered()
{
    QString license_text;
    license_text="MIT License\n";

    license_text+="Copyright (c) 2019 Jivansha\n";

    license_text+="Permission is hereby granted, free of charge, to any person obtaining a copy\n";
    license_text+="of this software and associated documentation files (the Software), to deal\n";
    license_text+="in the Software without restriction, including without limitation the rights\n";
    license_text+="to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n";
    license_text+="copies of the Software, and to permit persons to whom the Software is\n";
    license_text+="furnished to do so, subject to the following conditions:\n\n";

    license_text+="The above copyright notice and this permission notice shall be included in all\n";
    license_text+="copies or substantial portions of the Software.\n";

    license_text+="THE SOFTWARE IS PROVIDED AS IS, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n";
    license_text+="IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n";
    license_text+="FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n";
    license_text+="AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n";
    license_text+="LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n";
    license_text+="OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n";
    license_text+="SOFTWARE.";

    QMessageBox::about(this,"License",license_text);
}
