#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListView>
#include <QStringListModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void num0Pressed();
    void num1Pressed();
    void num2Pressed();
    void num3Pressed();
    void num4Pressed();
    void num5Pressed();
    void num6Pressed();
    void num7Pressed();
    void num8Pressed();
    void num9Pressed();
    void spacePressed();
    void pointPressed();
    void plusPressed();
    void lessPressed();
    void mulPressed();
    void divPressed();
    void supprPressed();

    void enterPressed();
    
private:
    QStringListModel *modele;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
